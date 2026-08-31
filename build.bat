@echo off
chcp 65001 > nul
setlocal

rem ======================================================================
rem  Compass Navigation Overhaul VR：编译并打包
rem
rem  build.bat          编译并打包（增量）
rem  build.bat nobuild  使用现有 DLL 打包
rem  build.bat clean    清理后重新编译并打包
rem
rem  本机配置见下方；7-Zip 与中文包为可选，缺省时自动跳过。
rem ======================================================================

rem ---- 本机配置 ---------------------------------------------------------
set "VS_VCVARS=D:\Development\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
set "SDK_ROOT=D:\Development\Windows Kits\10"
set "SDK_VER=10.0.26100.0"
set "VS_CMAKE_BIN=D:\Development\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin"
set "VS_NINJA_BIN=D:\Development\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja"
set "VCPKG_ROOT_CFG=D:\Development\Microsoft Visual Studio\18\Community\VC\vcpkg"
set "SEVENZIP=D:\Program Files\7-Zip\7z.exe"
rem MAKE_CHS=0 时只生成英文主包。
set "MAKE_CHS=1"

rem ---- 工程路径（自动推导，无需修改） -----------------------------------
set "ROOT=%~dp0"
set "PROJ=%ROOT:~0,-1%"
set "DLL=%ROOT%build\relwithdebinfo-vr-only\CompassNavigationOverhaulVR.dll"
set "ASSET_MAIN=%ROOT%assets\main"
set "CFGDIR=MCM\Config\Compass Navigation Overhaul VR"
set "CONFIG_ZH=%ASSET_MAIN%\%CFGDIR%\config.zh-CN.json"
set "PKG=%ROOT%build\package\main"
set "PKGZH=%ROOT%build\package\chs"
set "DIST=%ROOT%dist"
set "MODNAME=Compass Navigation Overhaul VR"
set "MODE=%~1"

set "VER="
for /f "usebackq delims=" %%v in ("%ROOT%VERSION") do if not defined VER set "VER=%%v"
if not defined VER (
    echo [错误] 无法从 VERSION 读取版本号。
    goto :fail
)
set "ZIP=%DIST%\%MODNAME% %VER%.zip"
set "ZIPZH=%DIST%\%MODNAME% %VER%-CHS.zip"

echo.
echo ==== %MODNAME% %VER% ====

rem ---- 编译 -------------------------------------------------------------
if /i "%MODE%"=="nobuild" goto :package

call "%VS_VCVARS%" > nul 2>&1
if errorlevel 1 (
    echo [错误] 无法加载 VS 编译环境：%VS_VCVARS%
    goto :fail
)

rem vcvars64.bat 会设置自己的 VCPKG_ROOT，加载后恢复本机配置。
set "VCPKG_ROOT=%VCPKG_ROOT_CFG%"
set "X_VCPKG_ASSET_SOURCES=x-script,curl -L -o {dst} {url}"

rem SDK 不在默认位置时补齐；SDK_ROOT 留空即可跳过。
if not "%SDK_ROOT%"=="" (
    set "INCLUDE=%SDK_ROOT%\Include\%SDK_VER%\cppwinrt;%SDK_ROOT%\Include\%SDK_VER%\winrt;%SDK_ROOT%\Include\%SDK_VER%\shared;%SDK_ROOT%\Include\%SDK_VER%\um;%SDK_ROOT%\Include\%SDK_VER%\ucrt;%INCLUDE%"
    set "LIB=%SDK_ROOT%\Lib\%SDK_VER%\um\x64;%SDK_ROOT%\Lib\%SDK_VER%\ucrt\x64;%LIB%"
    set "PATH=%SDK_ROOT%\bin\%SDK_VER%\x64;%PATH%"
)
if not "%VS_CMAKE_BIN%"=="" set "PATH=%VS_CMAKE_BIN%;%PATH%"
if not "%VS_NINJA_BIN%"=="" set "PATH=%VS_NINJA_BIN%;%PATH%"

if /i "%MODE%"=="clean" (
    if not defined ROOT goto :fail
    if not defined PROJ goto :fail
    if /i not "%PROJ%\build"=="%ROOT%build" goto :fail
    echo [清理] %ROOT%build
    if exist "%ROOT%build" rmdir /s /q "%ROOT%build"
    if exist "%ROOT%build" goto :fail
)

echo [1/3] 配置
pushd "%PROJ%"
cmake --preset build-relwithdebinfo-vr-only
if errorlevel 1 (popd & goto :fail)
echo [2/3] 编译
cmake --build --preset relwithdebinfo-vr-only
if errorlevel 1 (popd & goto :fail)
popd

:package
rem ---- 打包 -------------------------------------------------------------
echo [3/3] 打包
if not exist "%DLL%" (
    echo [错误] 缺少编译产物：%DLL%
    goto :fail
)

set "STAGE=%ROOT%build\package"
if exist "%STAGE%" rmdir /s /q "%STAGE%"
mkdir "%PKG%" || goto :fail
if not "%MAKE_CHS%"=="0" mkdir "%PKGZH%" || goto :fail

robocopy "%ASSET_MAIN%" "%PKG%" /E /COPY:DAT /DCOPY:DAT /R:2 /W:1 /XF config.zh-CN.json /NFL /NDL /NJH /NJS /NP > nul
if errorlevel 8 (
    echo [错误] 复制静态资源失败：%ASSET_MAIN%
    goto :fail
)
copy /y "%DLL%" "%PKG%\SKSE\Plugins\" > nul || goto :fail
copy /y "%ROOT%LICENSE" "%PKG%\LICENSE" > nul || goto :fail

if not "%MAKE_CHS%"=="0" (
    if not exist "%CONFIG_ZH%" (
        echo [错误] 缺少 MCM 中文配置母本：%CONFIG_ZH%
        goto :fail
    )
    mkdir "%PKGZH%\%CFGDIR%"
    copy /y "%CONFIG_ZH%" "%PKGZH%\%CFGDIR%\config.json" > nul || goto :fail
)

if not exist "%DIST%" mkdir "%DIST%"

rem 7-Zip 可选：找不到时跳过压缩包生成，仅保留打包目录。
set "SZEXE="
if exist "%SEVENZIP%" set "SZEXE=%SEVENZIP%"
if not defined SZEXE where 7z > nul 2> nul && set "SZEXE=7z"

echo.
echo 完成：
if defined SZEXE (
    call :makezip "%PKG%" "%ZIP%"
    if errorlevel 1 goto :fail
    if not "%MAKE_CHS%"=="0" (
        call :makezip "%PKGZH%" "%ZIPZH%"
        if errorlevel 1 goto :fail
    )
) else (
    echo [提示] 未找到 7-Zip，跳过压缩包生成：
    echo   %PKG%
    if not "%MAKE_CHS%"=="0" echo   %PKGZH%
)
endlocal
exit /b 0

:makezip
rem 排除调试符号与中文配置母本。
if exist "%~2" del /q "%~2"
"%SZEXE%" a -tzip "%~2" "%~1\*" -xr!*.pdb -xr!config.zh-CN.json > nul
if errorlevel 1 exit /b 1
if not exist "%~2" exit /b 1
echo   已生成 %~nx2
exit /b 0

:fail
echo.
echo ==== 构建失败 ====
endlocal
exit /b 1
