cmake_minimum_required(VERSION 3.26)
project(Sem_2_Lab_2_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fdump-record-layouts")

add_executable(Sem_2_Lab_2_3 main.cpp
        Expression.cpp
        Expression.h
        BinaryOperation.cpp
        BinaryOperation.h
        Number.cpp
        Number.h)
