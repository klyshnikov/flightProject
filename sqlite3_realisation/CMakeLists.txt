cmake_minimum_required(VERSION 3.27)
project(sqlite3_realisation)

set(CMAKE_CXX_STANDARD 17)

add_executable(sqlite3_realisation main.cpp
        sqlite3.h)
