cmake_minimum_required( VERSION 3.0 )
project(lab6)
include_directories( ./include ./src )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/HRMS.cpp ./src/employee.cpp)