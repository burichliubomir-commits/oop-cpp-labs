cmake_minimum_required(VERSION 3.20)
project(L3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(L3
        main.cpp
        Word.h
        Word.cpp
        Dictionary.h
        Dictionary.cpp
)