cmake_minimum_required(VERSION 3.27)
project(CA2bugsProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2bugsProject main.cpp
        Bug.h
        Bug.cpp
        Crawler.h
        Crawler.cpp
        Hopper.cpp
        Hopper.h
        Board.h
        Board.cpp)
