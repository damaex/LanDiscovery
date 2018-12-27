cmake_minimum_required(VERSION 3.10)
project(LanDiscovery)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if (WIN32)
    find_package(WINSOCK REQUIRED)
endif (WIN32)

add_subdirectory(src)