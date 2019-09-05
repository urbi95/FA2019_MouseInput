cmake_minimum_required(VERSION 3.14)
project(FA2019_MouseInput)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})