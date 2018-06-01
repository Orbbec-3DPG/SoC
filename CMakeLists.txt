cmake_minimum_required(VERSION 2.8)
project(sdk)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include(${PROJECT_SOURCE_DIR}/cmake/Common.cmake)
# flags

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")

include(${PROJECT_SOURCE_DIR}/cmake/DetectCXX11.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/DetectOpenCV.cmake)

add_executable(${PROJECT_NAME} "main.cpp")
