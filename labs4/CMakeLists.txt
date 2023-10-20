cmake_minimum_required(VERSION 3.10)

project(classes)

add_subdirectory(headers)
include_directories(headers)

add_executable(classes main.cpp)

target_link_libraries(classes cat)
