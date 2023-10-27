project(MyGit)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Repository)
add_subdirectory(Commit)

add_executable(MyGit main.cpp)

target_link_libraries(MyGit PUBLIC Repository)
target_link_libraries(MyGit PUBLIC Commit)

target_include_directories(MyGit PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Commit"
                          "${PROJECT_SOURCE_DIR}/Repository"
                          )

