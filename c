#!/bin/bash

rm a
gcc main.c -o a $(pkg-config --cflags --libs sdl2 SDL2_mixer)
./a
