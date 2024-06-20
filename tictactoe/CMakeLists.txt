cmake_minimum_required(VERSION 3.27)
project(tictactoe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tictactoe main.cpp
        Board/Board.h
        Board/Board.cpp
        player/Player.h
        player/Player.cpp
        Strategies/Strategy.h
        Strategies/AnyOpenCorner.h
        Strategies/AnyOpenCorner.cpp
        Strategies/AnyOpenSquare.h
        Strategies/AnyOpenSquare.cpp
        Strategies/BlockOpponent.h
        Strategies/BlockOpponent.cpp
        Strategies/PlayToWin.h
        Strategies/PlayToWin.cpp
        Position.cpp
        Position.h)
