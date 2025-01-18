#!/bin/bash
echo "Compiling \"splitOS installer image builder\"..."

g++ src/main.cpp -o dist/splitos-iib

if [[$? != 0]]; then
    echo "Compilation failed."
else
    echo "Compilation successful!"
fi