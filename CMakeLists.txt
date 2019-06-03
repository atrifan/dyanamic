cmake_minimum_required(VERSION 3.13)
project(dynamic)

set(CMAKE_CXX_STANDARD 14)

add_executable(dynamic main.cpp generic.h test.cpp test.h)