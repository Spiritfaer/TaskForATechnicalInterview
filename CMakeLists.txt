cmake_minimum_required(VERSION 3.15)
project(CLion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_DIR "./")

file(GLOB all
        "${SOURCE_DIR}src/*.cpp"
        "${SOURCE_DIR}includes/*.hpp")

add_executable(${PROJECT_NAME} ${all})