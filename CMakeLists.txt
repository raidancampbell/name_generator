cmake_minimum_required(VERSION 3.2)
project(name_generator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES name_generator.cpp)
add_executable(name_generator ${SOURCE_FILES} name_generator.h test/test_name_generator.h test/test_name_generator.cpp)