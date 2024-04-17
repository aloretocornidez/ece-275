#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL
#include <iostream>

//Cell Class Template:

// Declare an enumaration data type to store the Cell's color
enum CellColor {white, black};

// Declare the Cell Class
class Cell {

public:
	// Declare default constructor to initialize color to white
	Cell() {
		color = white;
	}

	// Declare member function getter for the color (get_color). Returns CellColor
	CellColor get_color();

	// Declare a member to flip the color (change_color)
	void change_color();

	// Declare a member to print the string for this color.
	// white = "0", black = "1"
	void print_Color();

	std::string get_color_string();

private:
	// Declare the color of this cell (color) as type CellColor
	CellColor color;
};

#endif