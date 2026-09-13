#!/usr/bin/bash

rm -rf build/
cmake -B build -G Ninja -DTARGET=STM32C031
cmake --build build
