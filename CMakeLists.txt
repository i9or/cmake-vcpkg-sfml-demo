cmake_minimum_required(VERSION 3.26)

cmake_path(SET CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(sfml_demo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
endif()

set(PROJECT_OUTPUT_BIN_DIR "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_OUTPUT_BIN_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_OUTPUT_BIN_DIR}")


find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

file(GLOB_RECURSE CVSD_SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)

set(CVSD_META
  "README.md"
  "LICENSE"
  ".gitignore"
  "vcpkg.json")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CVSD_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CVSD_META})

add_executable(${PROJECT_NAME} ${CVSD_SOURCES} ${CVSD_META})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-graphics sfml-window)
