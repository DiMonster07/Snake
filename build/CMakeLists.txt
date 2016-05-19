cmake_minimum_required(VERSION 2.8)
project(Snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ../src/main.cpp
    ../src/gamemanager.cpp
    ../src/objects.cpp
    ../src/point.cpp
    ../src/map.cpp
   )

add_executable(Snake ${SOURCE_FILES})
target_link_libraries( Snake ncurses panel )
