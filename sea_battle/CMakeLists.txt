cmake_minimum_required(VERSION 3.20)
project(tp_sea_battle)

set(CMAKE_CXX_STANDARD 20)

add_executable(tp_sea_battle src/main.cpp headers/square.h headers/field.h headers/player.h headers/game.h src/game.cpp src/field.cpp src/player.cpp headers/interface.h src/interface.cpp)
