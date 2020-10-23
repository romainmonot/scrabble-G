cmake_minimum_required(VERSION 3.17)
project(scrabble_G C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(scrabble_G
        biblio_scrable.c
        biblio_scrable.h
        main.c)
