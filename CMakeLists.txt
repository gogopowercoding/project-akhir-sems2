cmake_minimum_required(VERSION 3.4)
project(test)

add_subdirectory(module/pybind11)

pybind11_add_module(cpp main.cpp)


