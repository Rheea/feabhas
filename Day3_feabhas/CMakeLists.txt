cmake_minimum_required(VERSION 3.5)

project(Day3_feabhas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day3_feabhas main.cpp alarm.cpp pipe.cpp generator.cpp display.cpp)
#configure_file(alarm.h in alarm.h)
#configure_file(pipe.h in pipe.h)
#configure_file(generator.h in generator.h)
#configure_file(display.h in display.h)
