cmake_minimum_required(VERSION 3.20)
project(L2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(L2
        main.cpp
        ConsoleIO.h
        List.h
        List.cpp
        Stack.h
        Stack.cpp
        StackIO.h
        StackIO.cpp
        ../L5/main.cpp
)