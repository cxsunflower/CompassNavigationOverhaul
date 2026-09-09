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

source_group(
	TREE
		${CMAKE_CURRENT_SOURCE_DIR}
	FILES
		${headers}
		${sources}
)

# DLL 目标

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
	find_package(CommonLibSSE CONFIG REQUIRED)
endif()
find_package(spdlog REQUIRED CONFIG)
find_package(directxtk CONFIG REQUIRED)

add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${headers} ${sources})
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS "${PROJECT_NAME}")

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

if ("$ENV{RUNTIME_DISABLE_FLAGS}" STREQUAL "")
	set(COPY_SE YES)
	set(COPY_VR YES)
elseif ("$ENV{RUNTIME_DISABLE_FLAGS}" STREQUAL "-UENABLE_SKYRIM_VR")
	set(COPY_SE YES)
	set(COPY_VR NO)
elseif ("$ENV{RUNTIME_DISABLE_FLAGS}" STREQUAL "-UENABLE_SKYRIM_SE -UENABLE_SKYRIM_AE")
	set(COPY_SE NO)
	set(COPY_VR YES)
endif()

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
