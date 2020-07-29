cmake_minimum_required(VERSION 3.16)
project(DS_Class)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(DS_Class
        condition_parser.cpp
        condition_parser.h
        condition_parser_test.cpp
        database.cpp
        database.h
        database_test.cpp
        date.cpp
        date.h
        main.cpp
        node.cpp
        node.h
        test_runner.cpp
        test_runner.h
        token.cpp
        token.h)
