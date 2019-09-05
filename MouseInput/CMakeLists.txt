cmake_minimum_required(VERSION 3.14)
project(MouseInput)

set(CMAKE_CXX_STANDARD 17)

add_executable(MouseInput main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})