cmake_minimum_required(VERSION 3.30)
cmake_policy(SET CMP0091 NEW)
project(
	fuckhudscale
	VERSION 0.1
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Plugin.lib uses the static MSVC runtime (/MT). Set this before loading
# dependencies so sampapi and this target use the same runtime as well.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include(cmake/dependencies.cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(PluginSDK REQUIRED COMPONENTS gtasa)

add_library(fuckhudscale SHARED Main.cpp)

target_link_libraries(fuckhudscale PRIVATE PluginSDK::gtasa
	sampapi)

set_target_properties(fuckhudscale PROPERTIES
    PREFIX ""
    SUFFIX ".asi"
)