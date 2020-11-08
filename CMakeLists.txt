cmake_minimum_required(VERSION 3.10)
project(gbchan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs)

add_executable(gbchan src/main.cpp)
target_link_libraries(gbchan gbcpu)
