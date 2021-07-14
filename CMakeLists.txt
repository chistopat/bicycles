cmake_minimum_required(VERSION 3.19)
project(bicycles)

set(CMAKE_CXX_STANDARD 17)

add_executable(bicycles src/main.cpp src/linked_list.h test/test_runner.h src/mylinkedlist.h test/linked_list.h)