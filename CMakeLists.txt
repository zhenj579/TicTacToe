cmake_minimum_required(VERSION 3.17)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp Board.cpp Board.h Player.cpp Player.h Game.cpp Game.h test.cpp test.h)