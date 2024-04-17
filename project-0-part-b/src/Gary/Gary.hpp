#ifndef HAVEYOUSEENTHSISNAIL_GARY
#define HAVEYOUSEENTHSISNAIL_GARY

#include "Cell.hpp"

enum orientation {up, right, down, left};

class Gary {
public:
	//Constructors
	Gary() {
		direction = up;
	}
	Gary(unsigned int boardSize) {
		row = boardSize / 2;
		column = boardSize / 2;
		cellMapSize = boardSize;
		direction = up;
	}

	//Functions
	
	void setGaryPosition(int rows, int columns) {
		row = rows/ 2;
		column = columns / 2;
		cellMapSize = rows;
	}
	

	void changeOrientation(Cell cell) {
		if (cell.get_color() == white) {
			if (direction == up) {
				direction = right;
			}
			else if (direction == right) {
				direction = down;
			}
			else if (direction == down) {
				direction = left;
			}
			else if (direction == left) {
				direction = up;
			}
		}

		else if (cell.get_color() == black) {
			if (direction == up) {
				direction = left;
			}
			else if (direction == left) {
				direction = down;
			}
			else if (direction == down) {
				direction = right;
			}
			else if (direction == right) {
				direction = up;
			}
		}
	}

	void move(Cell *cell) {
		//Change orientation by checking the color of the cell
		this->changeOrientation(*cell);

		//Change the color of the cell that gary is on
		cell->change_color();

		if (this->direction == up) {
			if (row > 0) {
				row--;
			}
			else {
				row = (cellMapSize - 1);
			}
		}
		else if (this->direction == down) {
			if (row < (cellMapSize - 1)) {
				row++;
			}
			else {
				row = 0;
			}
		}
		else if (this->direction == left) {
			if (column > 0) {
				column--;
			}
			else {
				column = (cellMapSize - 1);
			}
		}
		else if (this->direction == right) {
			if (column < (cellMapSize - 1)) {
				column++;
			}
			else {
				column = 0;
			}
		}
	}
	//Getter Functions
	int get_row() {return row;}
	int get_col() {return column;}
	orientation get_orientation() { return direction;}
	std::string get_orientation_string() {
		if (direction == up) {
			return "up";
		}
		else if (direction == left) {
			return "left";
		}
		else if (direction == down) {
			return "down";
		}
		else if (direction == right) {
			return "right";
		}
		else {
			return "Error in getOrientationString";
		}
	}

private:
	orientation direction;
	int row;
	int column;
	int cellMapSize;
};

#endif
