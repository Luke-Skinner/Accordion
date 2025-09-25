#!/bin/bash

# Accordion Solitaire Build Script

echo "Building Accordion Solitaire..."

# Check if compiler exists
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found!"
    echo "Please install a C++ compiler (g++, clang++, etc.)"
    exit 1
fi

# Compile the main game
echo "Compiling accordion..."
g++ -o accordion main.cpp -std=c++11 -Wall

if [ $? -eq 0 ]; then
    echo "✓ Accordion compiled successfully!"
else
    echo "✗ Compilation failed!"
    exit 1
fi

# Compile test programs
echo "Compiling test programs..."

g++ -o lltest LLTest.cpp -std=c++11 -Wall
if [ $? -eq 0 ]; then
    echo "✓ Linked list test compiled successfully!"
else
    echo "✗ Linked list test compilation failed!"
fi

g++ -o stacktest stackMain.cpp -std=c++11 -Wall
if [ $? -eq 0 ]; then
    echo "✓ Stack test compiled successfully!"
else
    echo "✗ Stack test compilation failed!"
fi

echo ""
echo "Build complete! Try these commands:"
echo "  echo 'AC AS AD' | ./accordion"
echo "  echo '2H 3H 4D 5H' | ./accordion"
echo "  ./lltest"
echo "  ./stacktest"