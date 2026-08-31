# Overlay port: alandtse/CommonLibSSE-NG (ng branch), pinned to the commit that
# carries the binary-verified VR PlayerCharacter layout fix (VR_PLAYER_RUNTIME_DATA
# anchored at this+0x3F0 with the issue #207 pre-objectives gaps corrected). The old
# 4.0.0 pin anchored the VR block at 0x3E0, so GetVRPlayerRuntimeData().objectives
# read the wrong address and came back size 0 -> compass quest markers lost their title.
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO alandtse/CommonLibSSE-NG
    REF 70c1acd5261210982bd52f6d4468a082fe04d798
    SHA512 4b13f15f05c220f9754260086efa1688566ad8c60c9f8002110f342976d0dc653deffd39745b8398360092e21b83c40040c6a88d02aec2c1ee1eef98396e53a2
    HEAD_REF ng
)

# Get submodule and copy to extern/ folder (done manually because Vcpkg does not support Git submodules)
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH_OPENVR
    REPO ValveSoftware/openvr
    REF ebdea152f8aac77e9a6db29682b81d762159df7e
    SHA512 4fb668d933ac5b73eb4e97eb29816176e500a4eaebe2480cd0411c95edfb713d58312036f15db50884a2ef5f4ca44859e108dec2b982af9163cefcfc02531f63
    HEAD_REF master
)
file(COPY "${SOURCE_PATH_OPENVR}/" DESTINATION "${SOURCE_PATH}/extern/openvr")
file(REMOVE_RECURSE "${SOURCE_PATH_OPENVR}/")

# Configure options to build.
#   BUILD_TESTS off               -> skip Catch2 test target (we don't ship tests).
#   SKSE_SUPPORT_XBYAK on         -> the mod's hooks build Xbyak trampolines.
#   SKSE_SUPPORT_PATCH_SAFETY off -> 关键。该开关默认 ON，会在 CMakeLists.txt:121-136 里用
#       FetchContent 从 GitHub 拉取 MinHook 的 hde64 指令长度解码器（仅供 Trampoline 写入前
#       校验补丁点用）。但 vcpkg 构建期设了 FETCHCONTENT_FULLY_DISCONNECTED=true（离线），
#       FetchContent 无法联网克隆，导致 _deps/hde64-src 为空 → 258 行 target_sources 找不到
#       hde64.c → generate 失败。关掉后整段 if(SKSE_SUPPORT_PATCH_SAFETY) 都不编译，hde64
#       依赖随之消失。本 MOD 自己的钩子安装前已逐点校验目标字节是 0xE8(call rel32)，不依赖
#       CommonLib 的这层额外校验，故关闭无功能损失。
# REX_OPTION_INI/JSON/TOML are left at their OFF defaults; the mod has its own INI layer
# and does not use REX config, so the ini/json/toml deps are only pulled to satisfy the
# manifest and are otherwise unused.
vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DBUILD_TESTS=OFF
        -DSKSE_SUPPORT_XBYAK=ON
        -DSKSE_SUPPORT_PATCH_SAFETY=OFF
)

vcpkg_cmake_install()

# NG installs its package config to lib/cmake/CommonLibSSE.
vcpkg_cmake_config_fixup(PACKAGE_NAME CommonLibSSE CONFIG_PATH lib/cmake/CommonLibSSE)
vcpkg_copy_pdbs()

# The config includes CommonLibSSE.cmake (add_commonlibsse_plugin helper), which the
# upstream CMakeLists does not install itself -- ship it next to the fixed-up config.
file(INSTALL "${SOURCE_PATH}/cmake/CommonLibSSE.cmake" DESTINATION "${CURRENT_PACKAGES_DIR}/share/CommonLibSSE")

# openvr.h is consumed directly by VR code paths.
file(INSTALL "${SOURCE_PATH}/extern/openvr/headers/openvr.h" DESTINATION "${CURRENT_PACKAGES_DIR}/include")

# 上游 CMake 导出的 INTERFACE_LINK_LIBRARIES 引用的是 vcpkg 构建源码树里的绝对路径
# （extern/openvr 预编译库）。构建树在安装后被删除，二进制缓存恢复的包里也没有该文件，
# 消费者链接时会报 openvr_api.lib 缺失。这里把预编译库装进包内，并把导出引用改写为
# ${_IMPORT_PREFIX}/lib/openvr_api.lib。
file(INSTALL "${SOURCE_PATH}/extern/openvr/lib/win64/openvr_api.lib" DESTINATION "${CURRENT_PACKAGES_DIR}/lib")
file(INSTALL "${SOURCE_PATH}/extern/openvr/lib/win64/openvr_api.lib" DESTINATION "${CURRENT_PACKAGES_DIR}/debug/lib")
set(CLS_TARGETS "${CURRENT_PACKAGES_DIR}/share/CommonLibSSE/CommonLibSSE-targets.cmake")
file(READ "${CLS_TARGETS}" CLS_TARGETS_TEXT)
string(REGEX REPLACE
    [==[\\\$<\\\$<BOOL:ON>:[^;"]*extern/openvr/lib/win64/openvr_api\.lib>]==]
    [==[${_IMPORT_PREFIX}/lib/openvr_api.lib]==]
    CLS_TARGETS_TEXT "${CLS_TARGETS_TEXT}")
file(WRITE "${CLS_TARGETS}" "${CLS_TARGETS_TEXT}")

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

# ng 仓库遵循 GPL-3.0-or-later，许可证全文以 COPYING 命名（旧的 CommonLibVR 4.0.0 是 LICENSE）。
file(INSTALL "${SOURCE_PATH}/COPYING" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)
