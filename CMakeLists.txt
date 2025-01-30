cmake_minimum_required(VERSION 3.29)
project(CGame C)

set(CMAKE_C_STANDARD 11)

add_executable(CGame main.c
        Objects/Obstacle/Obstacle.h
        Objects/Obstacle/Obstacle.c
        Objects/Player/Player.h
        Objects/Player/Player.c
        Utils/Console/Reader/Reader.h
        Utils/Console/Reader/Reader.c
        Utils/Console/Writer/Writer.c
        Utils/Console/Writer/Writer.h)
