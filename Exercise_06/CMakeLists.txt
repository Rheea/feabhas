cmake_minimum_required(VERSION 3.5)

project(Exercise_06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Exercise_06 main.cpp alarm.cpp pipe.cpp generator.cpp display.cpp pipeline.cpp alarm_list.cpp alarm_filter.cpp)
#configure_file(alarm.h in alarm.h)
#configure_file(pipe.h in pipe.h)
#configure_file(generator.h in generator.h)
#configure_file(display.h in display.h)
