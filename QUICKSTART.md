# Quick Start Guide

## For the Impatient 🚀

### Linux/Mac/WSL:
```bash
chmod +x build.sh && ./build.sh
echo "AC AS AD" | ./accordion
```

### Windows (PowerShell):
```powershell
g++ -o accordion.exe main.cpp -std=c++11
echo "AC AS AD" | .\accordion.exe
```

## What is Accordion Solitaire?

A card game where you try to collapse all cards into one stack by matching suits or ranks with cards 1 or 3 positions to the left.

## Card Format

`Rank + Suit`: `AH` = Ace of Hearts, `KS` = King of Spades, `TC` = Ten of Clubs

## Try These Examples

```bash
# Perfect game (all cards collapse to 1 stack)
echo "AC AS AD" | ./accordion

# Partial collapse
echo "2H 3H 4D 5H" | ./accordion

# No moves possible
echo "2H 3C 4D 5S" | ./accordion

# Interactive mode
./accordion
# Type: 2H 3H 4D 5H
# Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows)
```

## Goal

Get the fewest stacks possible. **1 Stack = Perfect Game!**

Need more details? See the main [README.md](README.md).