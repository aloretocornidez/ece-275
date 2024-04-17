[![pipeline status](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-0-part-b/badges/master/pipeline.svg)](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-0-part-b/-/commits/master)

# ECE 275 Project 0: Have you seen this snail?? 
> Can You help Gary get home?? 
 
 [![Gary Come Home](https://img.youtube.com/vi/Ju8Nz2cmCp0/0.jpg)](https://www.youtube.com/watch?v=Ju8Nz2cmCp0)
 
 Gary the snail is lost and scared in Bikini Bottom. Can you help Gary get home?? This project will be broken into two discint parts, A and B. Part A will consist of creating one user-defined class in support of Gary's journey home. Part A will be implimented in one week. Part B will see the completion of Langton's Ant implimenting two more user-defined classes. This will take two weeks. 
 
## Useful Reading:
- Optional Stroustrup Text: Chapters 16 and 17 (optionally 18)
- [Wikibooks C++](https://en.wikibooks.org/wiki/C%2B%2B_Programming) Chapter 3 [link](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Classes)
 
## Project 0 Background: 
Project 0 will see students impliment a solution to "Langton's Ant", a cellular automata existing on a 2 Dimensinal *N* by *N* grid where each grid cell is colored white or black and the "ant" cell can be described as one of eight states (cell colore + ant orientaiton). 

### Rules of Langton's Ant
*Note that the rules are slightly modified for our purposes*

Initialize an *N* by *N* squre grid of "Cell"s that are either white or black. Start the "Ant" (or Gary the snail in our case) at the center of the grid (note that *N* must be an odd integer). Start Gary in an "up" orientation. Perform *K* steps where each step follows a simple rule:
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
The `Cell` class **shall** contain two "getter" functions to access `color`. (1) **shall** be named `get_color`, **shall** return type `CellColor`, and **shall** accept no input parameters. `get_color` **shall** return the value of `Cell`'s `color` member. (2) **shall** be named `get_color_string`, **shall** return type `std::string`, and **shall** accept no input. `get_color_string` **shall** return `"1"` if `color` is `black` and **shall** return `"0"` if `color` is `white`. 


### Cell Template
Find below a template for declaring the `Cell` class:

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

### Cell Class Tests
The `Cell` class will be graded in accordance to the following tests: 

1. Test that construction sets `color` to `white`
2. Tests that `change_color` flips the `color` member from `white` to `black` or visa-vera
3. Test that `get_color` returns the correct value of member `color` and is of type `CellColor`
4. Tests that `get_color_string` returns the correct string, i.e., `"0"` or `"1"` for `white` and `black` respectively. 

## Project 0 Part B:
Part B will see the full completion of Langon's ant and test student's ability to create multiple user-defined classes. You will create (at minimum) two more classes in support of ECE 275 Project 0. Outlined herein will be the design requirements, i.e., any sentence marked with **shall** absolutely must be completed. Note that there will be more freedom to design your programs and therefore more opportunities to think algorithmically. 
#### Disclaimer:
Note that this document is in addition to the introduction given via Panopto 20201013. 

### Project Requirements Overview:
- Firsly the `Cell` class will be tested using the same tests as in Part A. Note that the Cell class can remain unchanged from Part A to Part B
- Two additional classes **shall** be created to accomplish Project 0: `Gary` and `Board` which will represent Langon's ant and the grid on which the ant exists. 
- Project 0 will consist of 3 C++ unit-tests which test the Cell class (from Part A) and the Gary class (introduced in Part B). Note that the results of the Cell test will be averaged between Part A and Part B.
- Project 0 will also be tested via output-comparison tests as in previous homework assignments


### Main Program:
The main function will be compiled into an executable named *FindGary*. The main function **shall** accept two (2) or three (3) command line arguments and will be called either as `./FindGary BoardSize Steps` or `./FindGary BoardSize Steps OutputFilename` where `BoardSize` and `Steps` will be unsigned integer values and `OutputFilename` will be a string (or, technically, an array or chars but C++ can implicitly convert between std::string and char* or char[ ]). Note that students are free to use either int main(int argc, char** argv) or int main(int argc, char* argv[ ]). The main program should construct a *Board* object, optionally **shall** set the output filename if given as a command line argument, and **shall** execute Gary's movement through Board's member function. 
#### Main Program's grading:
Student's main program will be used to generate output files. These output files will be compared to the solution output files and also to output files generated through instructor code, i.e., C++ code that will call the appropriate members of the Board class with the appropriate command line arguments. Students are free to impliment their main program however they like but the output must be correct (according to the solution) and must match the output using student's Board class. Pseudocode for generating the output files from the instructor's end is shown below

``` 
#include "Cell.hpp"
#include "Board.hpp"
#include "Gary.hpp"

int main(int argc, char** argv){
	unsigned int boardSize = (from command line arguments)
	unsigned int numberSteps = (from command line arguments)
	std::string outputFilename = (from optional command line argument)
	
	Board B(boardSize);
	if (an output filename is given){
		B.setOutputFilename(outputFilename);
	}
	
	B.move_gary(numberSteps);

	return 0;
}
```
and student code must be capable of generating the correct output in the correct location when calling these member functions of the Board class. Please note that the only "pseudo" above is the parsing of command line arguments and the if statement - the member functions and construction of variable B of type Board is valid C++ syntax that is used during testing. 

### Board Class:
Note that there are no structural requirements for the Board class beyond the member functions called via the above psuedo-main program. These include:

(1) The Board class **shall** be constructed given an unsigned integer parameter that defines the number of rows and columns, i.e., 'N' in the N by N board. Note that N must be odd. If N is given as even, students **shall** display a message stating "Board dimension must be an odd number!! Got {N} and adding 1 to equal {N+1}" (note that parameters within { } must be printed as their values) and **shall** add 1 to N to satisfy the requirement that N must be odd. Note that this message must be printed only to the console, i.e., should not be printed to the output file. 
(2) Gary **shall** move around the board when the `move_gary(steps)` function is called. Each step **shall** be one step of Langton's ant as defined above, i.e., change Gary's orientation based on the Cell input, change the cell color, and move Gary forward one unit. The board class **shall** print the state of the board at every step. See the below example with a boardSize input of 5 for 10 steps:

```
[Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
[Gary Location] {2, 3} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 0 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
[Gary Location] {3, 3} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 0 0 [Row 4] 0 0 0 0 0
[Gary Location] {3, 2} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 0 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {2, 2} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 0 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {1, 1} [Gary Orientation] up [Row 0] 0 0 0 0 0 [Row 1] 0 0 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {1, 2} [Gary Orientation] right [Row 0] 0 0 0 0 0 [Row 1] 0 1 0 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {2, 2} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 0 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {2, 1} [Gary Orientation] left [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 1 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
[Gary Location] {3, 1} [Gary Orientation] down [Row 0] 0 0 0 0 0 [Row 1] 0 1 1 0 0 [Row 2] 0 0 1 1 0 [Row 3] 0 0 1 1 0 [Row 4] 0 0 0 0 0
```
the format is givn by `[Gary Location] {(row), (col)} (orientation) [Row 0] (col 0 color) (col 1 color) ...` `(col N-1 color) [Row 1] ... [Row (N-1)] ... (col N-1 color)` where values within ( ) are to be filled in with program values. `(col i color)` *shall* be either "0" for "white" or "1" for "black". Note that students may want to call `Cell::get_color_string( )` to print this value (or just `Cell::get_color()` as pointed out by a student in office hours!). This output will either be to standard output, i.e., `std::cout`, if a filename command line argument is not provided or will be printed to the filename given in the argument (students should use the [`ofstream`](http://www.cplusplus.com/reference/fstream/ofstream/) object for file output. Note that C's [`fprintf`](http://www.cplusplus.com/reference/cstdio/fprintf/) will also be okay). The filename *shall* be set with the `setOutputFilename` member function. 

Students are free to impliment the remaining functionality of the Board class as desired. The class should store a representation of the actual grid of cells which define the environment for Langon's ant, i.e., the Cell class created in Part A (Hint: I utilized a vector of vectors where each element of the outer vector stores a "row" or the grid represented by a vector of class Cell). The board class must also store a variable of type `Gary` that "walks" about the board. (More information on `Gary` is given below) At each step in the `Gary::move_gary(Cell*)` function the Board must pass a pointer to the `Cell` that Gary currently occupies so that Gary can alter his orientaiton, flip the color of that cell, i.e., call the `change_color` member function, and change his position, i.e., "walk" (find a tutorial for pointers to objects [here](https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_class.htm)). 

### Gary Class:
Note that the `Gary` class is subject to C++ unit testing and therefore has stricter requirements for composition. Each required member function will be denoted. 

(1) `Gary` **shall** be constructed with a parameterized constructor accepting an unsigned integer input parameter representing the size of the board (denote here as BoardSize). Assume that BoardSize is odd! Gary **shall** initialize his position to be the middle cell of the board, e.g., if the BoardSize is given as 5 Gary would be initialized at index (2,2). 
(2) `Gary` **shall** contain public member functions which return an unsigned integer type and accept no input named `Gary::get_row()` and `Gary::get_col()` which return Gary's row and column position on the board respectively. 
(3) `Gary` **shall** contain a public member function which returns type void and accepts a Cell pointer called `Gary::move(Cell*)` which **shall** (a) alter Gary's orientation based on the Cell's color (b) change the Cell's color (c) move Gary one unit forward in the new orientation
(4) `Gary` **shall** contain a public member function which returns type `orientation` (defined as an enumeration `enum orientation {up, right, down, left};`) and accepts no input parameters called `Gary::get_orientation()`

#### A note on wrapping boundary conditions
Please be aware that the board size will be strictly less than 2<sup>32</sup>. Why is this important? Because Gary's location on the board should be stored as an unsigned integer value (note that we cannot have a negative number of cells) and how will we tell if Gary's moved off the left or top side of the board? If Gary is positioned at index (0,i) and moves in the up orientation he must wrap around to index (N-1, i). Consider the following piece of code:

```
#include <iostream>

int main(void){
	unsigned int i = 3;
	for (int j = 3; j > -4; j--) {
		std::cout << "i = " << i << std::endl;
		i--; // Decriment i
	}	
	
	return 0;
}
```

what might happent to an unsigned integer when it's assigned a value of -1? Rememeber that numbers are represented in binary and in the absence of a [sign bit](https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html) we experience over/underflow. So can we compare an unsigned integer with -1? What value is that really? Consider the following code snippet:

```
#include <iostream>
int main(void) {
	unsigned int i = -1;
	if (i == -1)
		std::cout << "i = " << i << std::endl;

	return 0;
}
```
This may be useful when considering how to "wrap" Gary's movement around the rows and columns. 

## Testing Framework:
There has been much improvement to the testing framework. There are no changes on the student's end but the instructor has now bundled testing code and other non-neccesary pieces into a Docker container which will be used to test your code. This testing includes improved output, e.g., 

```
ss << "Given a board size of " << bs << " Gary should be initialized at index " << lc
		<< " but was initialized at index " << l;

```
and

```
ss << "Gary's orientation should be " << GaryTester::get_orientation_string(correctNewOrientation)
		<< " and Gary's location should be " << correctNewLocation
		<< " given a starting orientation of " << GaryTester::get_orientation_string(initialOrientation)
		<< " and a starting location of " << garyInitialLocation
		<< " under input of cell color " << c.get_color() << ". "
		<< "Your Gary's location after this input Cell was " << garyNewLocation
		<< " and your Gary's orientation under this input was " << GaryTester::get_orientation_string(gary.get_orientation());
```

### Grading:
The score will be computed as follows
(Part A + Cell tests from Part B)*0.5 + Part B Unit Tests + Part B Output tests
where the maximum score is 3 (each test is weighted equally). 

### Due Date:
Project 0 is due Tuesday October 27 @ 2359. Please refer to the Syllabus for the weight of Projects in ECE 275 and be sure to ***start early*** :) 