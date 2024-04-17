#include "Cell.hpp"
#include <iostream>

// Declare member function getter for the color (get_color). Returns CellColor
CellColor Cell::get_color() {
	return color;
}

// Declare a member to flip the color (change_color)
void Cell::change_color() {
	if (color == white) {
		color = black;
	}
	else if (color == black) {
		color = white;
	}
	else {
		std::cout << "Error in \"change_color\" function." << std::endl;
	}
}

// Declare a member to print the string for this color. white = "0", black = "1"
void Cell::print_Color() {
	if (color == white) {
		std::cout << "0" << std::endl;
	}
	else if (color == black) {
		std::cout << "1" << std::endl;
	}
	else {
		std::cout << "Error in \"print_color\" Function." << std::endl;
	}
}

//Get color string
std::string Cell::get_color_string() {
	if (color == white) {
		return "0";
	}
	else if (color == black) {
		return "1";
	}
	else {
		std::cout << "Error in \"get_color_string\" Function." << std::endl;
	}
}
