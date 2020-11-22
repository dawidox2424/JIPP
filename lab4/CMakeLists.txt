cmake_minimum_required( VERSION 3.0 )
project(matrix VERSION 1.0.0)
include_directories( ./include ./src )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/matrix.cpp)