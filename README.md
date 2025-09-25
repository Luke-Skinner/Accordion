# Accordion Solitaire

A C++ implementation of Accordion Patience solitaire using custom stack and linked list data structures.

## Quick Start

**Want to play immediately?** See [QUICKSTART.md](QUICKSTART.md)

### Build and Run
```bash
# Linux/Mac/WSL
chmod +x build.sh && ./build.sh
echo "AC AS AD" | ./accordion

# Windows
g++ -o accordion.exe main.cpp -std=c++11
echo "AC AS AD" | .\accordion.exe
```

## Game Rules

Accordion is a single-player solitaire card game where you try to collapse all cards into as few stacks as possible.

### How to Play
1. Cards are laid out in a row from left to right
2. You can move a card (or stack) onto another stack if:
   - **Same suit** OR **same rank**
   - The target stack is exactly **1 or 3 positions to the left**
3. Continue until no more moves are possible
4. **Goal**: Get down to 1 stack (perfect game!)

### Card Format
- Format: `RankSuit` (e.g., `AH` = Ace of Hearts, `KS` = King of Spades)
- Ranks: `A 2 3 4 5 6 7 8 9 T J Q K` (T = Ten)
- Suits: `H D C S` (Hearts, Diamonds, Clubs, Spades)

### Examples
```bash
# Perfect game - all cards collapse to 1 stack
echo "AC AS AD" | ./accordion
# Result: 1 Stack

# Partial collapse
echo "2H 3H 4D 5H" | ./accordion
# Result: 2 Stacks

# No moves possible
echo "2H 3C 4D 5S" | ./accordion
# Result: 4 Stacks (no matches)
```

## Project Structure

This implementation features custom C++ data structures:
- **Custom Linked List** (`LL.h/cpp`) - Doubly-linked list with iterators
- **Custom Stack** (`myStack.h/cpp`) - Dynamic array-based stack
- **Game Logic** (`main.cpp`) - Accordion solitaire implementation

## Testing

The build script compiles test programs:
```bash
./lltest    # Test linked list functionality
./stacktest # Test stack functionality
```

## Requirements

- C++ compiler with C++11 support (g++, clang++, etc.)
- Standard C++ library
