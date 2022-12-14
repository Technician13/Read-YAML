cmake_minimum_required(VERSION 3.2)

set(PROJ_NAME Read-YAML)
project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O3")

FILE(GLOB HEADER_LIST "${CMAKE_SOURCE_DIR}/*.hpp")
FILE(GLOB SOURCE_LIST "${CMAKE_SOURCE_DIR}/*.cpp")

# 设置输出
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJ_NAME} ${SOURCE_LIST} ${HEADER_LIST})

include_directories(${CMAKE_SOURCE_DIR})

set(YAML_LIBRARY_DIRS /usr/local/lib)
set(YAML_INCLUDE_DIRS /usr/local/include)

include_directories(${YAML_INCLUDE_DIRS})

link_directories(${YAML_LIBRARY_DIRS})
target_link_libraries(${PROJ_NAME} yaml-cpp)