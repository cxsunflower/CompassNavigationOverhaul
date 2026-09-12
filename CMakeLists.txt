cmake_minimum_required(VERSION 3.21)

# 项目

# CMake 与 build.bat 共用 vcpkg.json 中的版本号。
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json" CNO_VERSION_LINE REGEX "version-string")
string(REGEX MATCH "version-string[^\"]*\"[ ]*:[ ]*\"([^\"]+)\"" _ "${CNO_VERSION_LINE}")
set(CNO_VERSION "${CMAKE_MATCH_1}")

project(
	CompassNavigationOverhaulVR
	VERSION ${CNO_VERSION}
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.rc.in
	${CMAKE_CURRENT_BINARY_DIR}/version.rc
	@ONLY
)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS "include/*.h" "source/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "source/*.cpp")

option(CNO_BUILD_PALMTEST "Build the experimental independent PalmTest panel" OFF)
if(NOT CNO_BUILD_PALMTEST)
    list(FILTER sources EXCLUDE REGEX "/palmtest/")
    list(FILTER headers EXCLUDE REGEX "/palmtest/")
endif()


source_group(
	TREE
		${CMAKE_CURRENT_SOURCE_DIR}
	FILES
		${headers}
		${sources}
)

# DLL 目标

# CommonLib PUBLIC definitions are the sole source of runtime macros for the plugin.
option(ENABLE_SKYRIM_SE "Build with Skyrim SE support" ON)
option(ENABLE_SKYRIM_AE "Build with Skyrim AE support" ON)
option(ENABLE_SKYRIM_VR "Build with Skyrim VR support" ON)
if(NOT ENABLE_SKYRIM_SE AND NOT ENABLE_SKYRIM_AE AND NOT ENABLE_SKYRIM_VR)
    message(FATAL_ERROR "At least one Skyrim runtime must be enabled")
endif()
set(CNO_ALL_RUNTIMES OFF)
if(ENABLE_SKYRIM_SE AND ENABLE_SKYRIM_AE AND ENABLE_SKYRIM_VR)
    set(CNO_ALL_RUNTIMES ON)
endif()
# The upstream explicit bundle override precedes its runtime compatibility guard.
if(NOT CNO_ALL_RUNTIMES AND COMMONLIB_PREBUILT_DIR)
    message(FATAL_ERROR "Restricted runtimes require CommonLib source; unset COMMONLIB_PREBUILT_DIR")
endif()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/CommonLibSSE-NG/CMakeLists.txt")
	message(STATUS "Using local CommonLibSSE-NG from lib/CommonLibSSE-NG")
	set(BUILD_TESTS OFF CACHE BOOL "Disable CommonLibSSE-NG tests" FORCE)
	set(SKSE_SUPPORT_XBYAK ON CACHE BOOL "Enable Xbyak trampoline support" FORCE)
	add_subdirectory(
		lib/CommonLibSSE-NG
		${CMAKE_CURRENT_BINARY_DIR}/CommonLibSSE-NG
		EXCLUDE_FROM_ALL
	)
	include(${CMAKE_CURRENT_SOURCE_DIR}/lib/CommonLibSSE-NG/cmake/CommonLibSSE.cmake)
else()
	if(NOT CNO_ALL_RUNTIMES)
		message(FATAL_ERROR "Restricted runtimes require the CommonLibSSE-NG submodule; run git submodule update --init --recursive")
	endif()
	find_package(CommonLibSSE CONFIG REQUIRED)
endif()
find_package(spdlog REQUIRED CONFIG)
find_package(directxtk CONFIG REQUIRED)

add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${headers} ${sources})
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS "${PROJECT_NAME}")
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<BOOL:${CNO_BUILD_PALMTEST}>:CNO_BUILD_PALMTEST=1>")
# A hash-bound sidecar prevents package-only runs from shipping an experimental DLL.
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY LINK_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/write_build_profile.cmake")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND}
        "-DDLL=$<TARGET_FILE:${PROJECT_NAME}>"
        "-DPALMTEST=${CNO_BUILD_PALMTEST}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/write_build_profile.cmake"
    VERBATIM)


target_include_directories(
	${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
		CommonLibSSE::CommonLibSSE
		spdlog::spdlog_header_only
		Microsoft::DirectXTK
)

if (MSVC)
	target_link_options(
		${PROJECT_NAME}
		PRIVATE
			"$<$<CONFIG:DEBUG>:/INCREMENTAL;/OPT:NOREF;/OPT:NOICF>"
			"$<$<CONFIG:RELEASE>:/INCREMENTAL:NO;/OPT:REF;/OPT:ICF>"
	)
endif()

target_precompile_headers(
	${PROJECT_NAME}
	PRIVATE
		include/pch.h
)

# 自动部署

# 可通过 -DSKYRIM_*_DIR=... 指定安装目录；目录不存在时仅生成 DLL，不自动部署。
set(SKYRIM_SE_DIR "C:/Program Files (x86)/Steam/steamapps/common/Skyrim Special Edition" CACHE PATH "Skyrim SE 安装目录")
set(SKYRIM_VR_DIR "C:/Program Files (x86)/Steam/steamapps/common/Skyrim VR" CACHE PATH "Skyrim VR 安装目录")

# Deployment selection follows the same options as the dependency and plugin.
set(COPY_SE OFF)
if(ENABLE_SKYRIM_SE OR ENABLE_SKYRIM_AE)
    set(COPY_SE ON)
endif()
set(COPY_VR ${ENABLE_SKYRIM_VR})

if (COPY_SE AND EXISTS "${SKYRIM_SE_DIR}/Data/SKSE/Plugins")
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}>
		"${SKYRIM_SE_DIR}/Data/SKSE/Plugins/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
	)
endif()
if (COPY_VR AND EXISTS "${SKYRIM_VR_DIR}/Data/SKSE/Plugins")
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}>
		"${SKYRIM_VR_DIR}/Data/SKSE/Plugins/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
	)
endif()
