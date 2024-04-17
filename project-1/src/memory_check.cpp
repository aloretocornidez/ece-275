#include "List.hpp"

namespace ec = ECE275Lib::containers;


// Program to check for memory leaks with, e.g., valgrind
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./executable exampleParam1
int main(void) {
	// Construct a list holding integer data types
	ec::List<int>* l = new ec::List<int> ();
	
	// Push back 100 times a modulo-10 counter
	for (unsigned int i = 0; i < 100; i++)
		l -> push_back(i % 10);

	// Now remove an element at index 3
	l -> remove(3);
	
	// Add an element with data 55 at element 50
	l -> insert(50, 55);
	
	// Assign some value
	l -> assign(1, 45);
	
	// Construct another linked list
	ec::List<int>* ins = new ec::List<int> (10);
	for (unsigned int i = 0; i < ins -> size(); i++)
		ins -> assign(i, ins -> size() - i);
	
	// Insert this list into the other list
	l -> insert(2, *ins);
	
	// Delete ins
	delete ins;
	
	// Now remove between some indicies
	l -> remove(10, 20);
	
	delete l;
	
	return 0;
	
}