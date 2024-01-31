cmake_minimum_required(VERSION 3.27)
project(sqlite3_realisation)
set(CMAKE_CXX_STANDARD 17)
include_directories(sqlite3_library)


add_executable(sqlite3_realisation
				sqlite3_library/sqlite3.c
 				main.cpp)
