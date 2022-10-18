# ===============================================
# ===============================================
# *\CMakeLists.txt
# ===============================================
# ===============================================

cmake_minimum_required(VERSION 3.10)

project(Arduino_Task_Creator)

add_subdirectory(src)
# link .\src

include_directories(${PROJECT_SOURCE_DIR}/include)
# include headers in .\include

include_directories(${PROJECT_SOURCE_DIR}/lib/jsoncpp/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/jsoncpp/lib)
# include headers and link jsoncpp static lib

#include_directories(${PROJECT_SOURCE_DIR}/lib/gflags/include)
#link_directories(${PROJECT_SOURCE_DIR}/lib/gflags/lib)
# include headers and link gflags static lib 

find_package(gflags REQUIRED)
# find gflags package

include_directories(${PROJECT_SOURCE_DIR}/lib/CSerialPort/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/CSerialPort/lib)
# include headers and link CSerialPort static lib

#set(SRC_MAIN main.cpp)

set(SRC_MAIN test.cpp)
# use to test functions

message(STATUS ${SRC_MAIN})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# set .exe output folder as .\bin

add_executable(Arduino_Task ${SRC_LIST} ${SRC_MAIN})
# link src files and main program

target_link_libraries(Arduino_Task libjsoncpp.a libjsoncpp.dll.a gflags liblibcserialport.dll.a)
# link jsoncpp static lib, gflags static lib and CSerialPort static libto target