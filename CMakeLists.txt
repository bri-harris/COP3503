cmake_minimum_required(VERSION 3.29)
project(CPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(CPP
        #        Modules/mod14/SortingEx.cpp
        #        Modules/mod14/Hero.cpp
        #        Modules/mod14/Random.cpp
        src/Labs/lab8/Color.cpp
        src/Labs/lab8/Color.h
        src/Labs/lab8/main.cpp
        src/Projects/Proj1/leaker.h
        #        Modules/mod14/lambdaLecture.cpp

)
include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(CPP sfml-system sfml-window sfml-graphics sfml-audio sfml-network)