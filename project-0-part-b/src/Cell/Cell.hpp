#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL
#include <iostream>

//Cell Class Template:

// Declare an enumaration data type to store the Cell's color
enum CellColor {white, black};

// Declare the Cell Class
class Cell {
public:
	//Constructors
	Cell() { color = white; }

	//Functions
	void change_color() {
		if (color == white) {
			color = black;
		}
		else if (color == black) {
			color = white;
		}
	}

	void setCoords(unsigned int rows, unsigned int columns, unsigned int boardSize) {
		this->row = rows;
		this->column = columns;
		this->size = boardSize;
	}

	void print_Color() {
		if (color == white) {
			std::cout << "0" << std::endl;
		}
		else if (color == black) {
			std::cout << "1" << std::endl;
		}
	}

	//Getter Functions
	std::string get_color_string() {
		if (color == white) {
			return "0";
		}
		else if (color == black) {
			return "1";
		}
		else {
			return "Error in Cell::get_color_string()\n";
		}
	}
	CellColor get_color() { return color; }
	int get_row(){ return row; }
	int get_column() { return column; }
	int get_size() { return size; }
private:
	CellColor color;
	int row;
	int column;
	int size;
};

#endif