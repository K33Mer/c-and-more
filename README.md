# c-and-more
Will be adding projects of multiple languages

# ASCII ENGINE 5.1

## Overview

ASCII ENGINE 5.1 is a terminal-based text rendering engine written in C++.

It converts normal text into large block-style ASCII characters using custom font patterns stored in memory.

The engine supports:

- Full A–Z alphabet rendering
- ANSI terminal colors
- Animated scrolling text
- Custom brush characters
- User-designed letters
- Saving/loading fonts from files
- Dynamic spacing and rendering behavior

This project evolved from a simple beginner exercise:
> “Print the letter E using asterisks.”

and expanded into a larger software-engineering style system for practicing:

- Object-Oriented Programming (OOP)
- Rendering systems
- File handling
- Animation
- Data structures
- Terminal graphics

---

# Features

## ASCII Letter Rendering

Render words using large block-style ASCII characters.

Example input:

HELLO

Example output:

```text
*   * ***** *     *      ***
*   * *     *     *     *   *
***** ***** *     *     *   *
*   * *     *     *     *   *
*   * ***** ***** *****  ***

map<char, vector<string>>

*
#
@
$
%

| Code | Color  |
| ---- | ------ |
| 31   | Red    |
| 32   | Green  |
| 34   | Blue   |
| 35   | Purple |
| 36   | Cyan   |

system("cls");
this_thread::sleep_for();

*****
*   *
*****
*   *
*   *

Save / Load Font System

Custom fonts can be saved to disk and loaded later.

Uses:

ofstream
ifstream

for file handling and serialization.

Technologies Used
Language
C++
Concepts
Object-Oriented Programming (OOP)
STL Containers
Maps
Vectors
File I/O
Animation Timing
ANSI Escape Codes
Nested Rendering Loops
Dynamic Data Structures
Program Architecture

The engine is built around the:

class BlockLetterEngine

This class manages:

alphabet storage
rendering
colors
animation
spacing
file operations
custom letter creation

map<char, vector<string>> alphabet;

alphabet['A']

 ***
*   *
*****
*   *
*   *

Rendering Pipeline

The rendering process works as follows:

INPUT WORD
    ↓
CONVERT TO UPPERCASE
    ↓
LOOKUP LETTER IN MAP
    ↓
READ EACH ROW
    ↓
READ EACH PIXEL
    ↓
PRINT BRUSH CHARACTER
    ↓
APPLY COLOR
    ↓
DISPLAY TO TERMINAL

Main Functions
printWord()

Renders ASCII words side-by-side.

scrollText()

Creates animated scrolling text.

setBrush()

Changes rendering character.

setColor()

Applies ANSI terminal colors.

saveFont()

Writes font data to a text file.

loadFont()

Loads font data from a file.

designLetter()

Allows user-created characters during runtime.

Example Menu
==== ASCII ENGINE 5.1 ====
1. Print word
2. Scroll text
3. Change brush
4. Change color
5. Save font
6. Load font
7. Design letter
8. Quit
Compilation
Windows (g++)
g++ main.cpp -o ascii_engine

Run:

./ascii_engine
Future Improvements

Potential upgrades:

Lowercase alphabet support
Numbers and punctuation
GUI version using SFML or Qt
Multiple font packs
Font scaling
Pixel-based rendering
Real-time keyboard interaction
Export ASCII art to image files
True game-engine style rendering loop
Educational Goals

This project was created to practice and understand:

Nested loops
Scope and braces
Object-Oriented Programming
Data structures
Rendering systems
File handling
Animation logic
Debugging structure errors
Terminal graphics
Lessons Learned

Key concepts reinforced during development:

Braces define scope
Rendering is row-based
Maps allow fast character lookup
File streams persist program data
Animation is timing + redraw
Most C++ bugs are structural, not logical
Author Notes

This project began as a simple programming exercise:

“Print the letter E using asterisks.”

It evolved into a customizable ASCII rendering engine with:

animation
persistence
color
dynamic font creation

The goal was not only to complete the assignment, but to extend it into a larger project for deeper coding practice and software engineering growth.
