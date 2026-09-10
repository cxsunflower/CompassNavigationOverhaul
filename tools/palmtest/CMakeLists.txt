cmake_minimum_required(VERSION 3.21)
project(CNOPalmTestAsset LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Pure C++ tests do not need the heavyweight NIF generator or the game SDK.
add_executable(cno_palm_test_pose test_pose.cpp)
add_executable(cno_palm_test_config test_config.cpp)
enable_testing()
add_test(NAME palm_pose COMMAND cno_palm_test_pose)
add_test(NAME palm_config COMMAND cno_palm_test_config)

# Preserve existing asset-tool builds when an external nifly checkout is supplied.
if(NIFLY_SOURCE_DIR)
  set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
  add_subdirectory("${NIFLY_SOURCE_DIR}" nifly)
  add_executable(cno_palm_test_asset make_panel.cpp)
  target_link_libraries(cno_palm_test_asset PRIVATE nifly)
else()
  message(STATUS "NIFLY_SOURCE_DIR not set: building standalone tests only")
endif()

add_executable(cno_palm_test_scene test_scene.cpp ../../source/palmtest/Scene.cpp)
target_include_directories(cno_palm_test_scene PRIVATE stubs)
add_test(NAME palm_scene COMMAND cno_palm_test_scene)
