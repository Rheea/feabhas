cmake_minimum_required(VERSION 3.5)

project(Day1_feabhas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day1_feabhas main.cpp alarm.cpp)
#configure_file(alarm.h in alarm.h)
