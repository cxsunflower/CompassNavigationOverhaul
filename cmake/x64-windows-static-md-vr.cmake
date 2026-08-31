# VR 插件使用 x64、动态 CRT 与静态三方库，以匹配 CommonLibVR 的推荐 ABI。
set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE static)

# 支持安装在非系统盘的 Visual Studio / Windows SDK。
set(VCPKG_ENV_PASSTHROUGH_UNTRACKED PATH INCLUDE LIB LIBPATH WindowsSdkDir WindowsSDKVersion)
