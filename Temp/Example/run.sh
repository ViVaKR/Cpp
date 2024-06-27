#! /usr/bin/env zsh

test -d bin || mkdir bin
clang++ -std=c++23 -g -Wall -Wextra -Wpedantic -Werror -o bin/main main.cpp
./bin/main
