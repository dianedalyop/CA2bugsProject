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

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries( CA2bugsProject sfml-system sfml-window sfml-graphics sfml-audio)