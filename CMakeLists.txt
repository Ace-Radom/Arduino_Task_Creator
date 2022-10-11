cmake_minimum_required(VERSION 3.10)

project(Arduino_Task_Creator)

add_subdirectory(src bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/jsoncpp)

set(SRC_MAIN main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(Arduino_Task ${SRC_LIST} ${SRC_MAIN})