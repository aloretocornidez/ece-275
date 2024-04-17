# ECE 275 Project 0: Have you seen this snail?? 
> Can You help Gary get home?? 
 
[![pipeline status](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-0-part-a/badges/master/pipeline.svg)](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-0-part-a/-/commits/master)
 
 [![Gary Come Home](https://img.youtube.com/vi/Ju8Nz2cmCp0/0.jpg)](https://www.youtube.com/watch?v=Ju8Nz2cmCp0)
 
 Gary the snail is lost and scared in Bikini Bottom. Can you help Gary get home?? This project will be broken into two discint parts, A and B. Part A will consist of creating one user-defined class in support of Gary's journey home. Part A will be implimented in one week. Part B will see the completion of Langton's Ant implimenting two more user-defined classes. This will take two weeks. 
 
## Project 0 Background: 
Project 0 will see students impliment a solution to "Langton's Ant", a cellular automata existing on a 2 Dimensinal *N* by *N* grid where each grid cell is colored white or black and the "ant" cell can be described as one of eight states (cell colore + ant orientaiton). 

### Rules of Langton's Ant
*Note that the rules are slightly modified for our purposes*

Initialize an *N* by *N* squre grid of "Cell"s that are either white or black. Start the "Ant" (or Gary the snail in our case) at the center of the grid (note that *N* must be an odd integer). Start Gary in an "up" orientation in the middle of the board. Perform *K* steps where each step follows a simple rule:
(1) If Gary is on a white squre turn 90 deg clockwise, flip the color of the squre, and move forward one unit
(2) If Gary is on a black squre turn 90 deg counterclockwise, flip the color of the squre, and move forward one unit. 

### Links/References to Langton's Ant
Below you will find links for more informatin on Langton's Ant. Note that there are many solutions to this problem available on the internet but we will design to a specific set of criteria and it will be impossible to copy-paste a solution. 

* [Langton's Ant Wikipedia](https://en.wikipedia.org/wiki/Langton's_ant)
* [Langton's Ant WolframMathworld](https://mathworld.wolfram.com/LangtonsAnt.html)
* [Coding Challenge Video: Langton's Ant (in Python)](https://www.youtube.com/watch?v=G1EgjgMo48U)

Below you will find examples of Langton's Ant in various programming languages (since y'all will Google this anyways). Note that these will proabably not be very helpful...

* [Langton's Ant implimentation in Python](https://www.geeksforgeeks.org/python-langtons-ant/)
* [Langton's Ant implimentation in C++](https://github.com/jeinhorn787/Langtons-Ant)
* [Langton's Ant Rosetta Code](https://rosettacode.org/wiki/Langton%27s_ant) 
* [Langton's Ant solution in C++](https://euler.stephan-brumme.com/349/)
* [Langton's Ant C++ solution in REPL](https://repl.it/@Ronald_MaxMax/Langtons-Ant#main.cpp)

The above links might be helpful conceptually but do *not* impliment Langton's Ant in accordance with the design guidelines for Project 0. 

## Project 0 Part A:
Part A will test the student's abililty to create the `Cell` class. This class will be used to define the *N* by *N* board in the final solution (there will be *N* <sup>2</sup> Cell objects which define the board). You are to program the `Cell` class according to the following design criteia:

### CellColor
The `Cell` class **shall** store the cell's color as a private member variable named `color` of type `CellColor` where `CellColor` is an [enumaration data type](https://en.cppreference.com/w/cpp/language/enum) defined as

```C++
enum CellColor {white, black};
```
### Constructor 
The `Cell` class **shall** be construced using the [default constructor](https://en.cppreference.com/w/cpp/language/default_constructor), i.e., will not accept any arguments. The constructor **shall** set `color` to `white` upon construction. 
### Cell Color Mutator
The `Cell` class **shall** contain a public member function named `change_color` to toggle the `color` member. I.e., if `color` is currently set to `white`, calling `change_color( )` will change `color` to `black`. The member function `change_color` will return type `void` and will accept no input parameters. 
### Cell Color Accessors
The `Cell` class **shall** contain two "getter" functions to access `color`. 

(1) **shall** be named `get_color`, **shall** return type `CellColor`, **shall** return the value of `color`, and **shall** accept no input parameters. `get_color` **shall** return the value of `Cell`'s `color` member. 

(2) **shall** be named `get_color_string`, **shall** return type `std::string`, and **shall** accept no input. `get_color_string` **shall** return `"1"` if `color` is `black` and **shall** return `"0"` if `color` is `white`. 


## Cell Template
Find below a template for declaring the `Cell` class. This template exists in the assignment repository.

*Cell.hpp*:

```C++
#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL

#include <string>

// Declare an enumaration data type to store the Cell's color
enum CellColor {white, black};

// Declare the Cell Class
class Cell {
public:
	// Declare default constructor to initialize color to white

	// Declare member function getter for the color (get_color). Returns CellColor

	// Declare a member to flip the color (change_color)

	// Declare a member to print the string for this color.
	// white = "0", black = "1"

private:
	// Declare the color of this cell (color) as type CellColor

};

#endif

```

## Cell Class Tests
The `Cell` class will be graded in accordance to the following tests: 

1. Test that construction sets `color` to `white`
2. Tests that `change_color` flips the `color` member from `white` to `black` or visa-vera
3. Test that `get_color` returns the correct value of member `color` and is of type `CellColor`
4. Tests that `get_color_string` returns the correct string, i.e., `"0"` or `"1"` for `white` and `black` respectively. 


## Generate Project files
> Note this is experimental

# XCode
To generate an XCode project create a directory at the same level of the source code directory. You may want to name this directory XCodeBuild. Open a Terminal window and navigate to XCodeBuild and execute the following command
`cmake ../{the directory your code is in} -G"Xcode"`. 
This should result in a .xcodeproj file being generated which contains proper filenames and compiler settings. 

This is tested on MacOS 10.15.16. 

# Visual Studio 2019
To generate a Visual Studio 2019 project create a directory at the same level of the source code directory. You may want to name this directory VSBuild. Open a Powershell window and navigate to VSBuild and execute the following command
`cmake ../{the directory your code is in} -G"Visual Studio 16 2019"`. 
This should result in a Visual Studio file being generated which contains proper filenames and compiler settings. (Note that I am a trusted source when it asks)

This is tested on Windows 10 Education. 

# Other Environments
Please refer to the [CMake documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) for information on other generators. 