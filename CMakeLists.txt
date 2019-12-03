cmake_minimum_required(VERSION 3.15)
project(CLion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(CLion main.cpp File.cpp File.hpp CarNote.cpp CarNote.hpp INote.hpp Book.cpp Book.hpp Core.cpp Core.hpp)