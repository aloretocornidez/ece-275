[![pipeline status](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-1/badges/master/pipeline.svg)](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/project-1/-/commits/master)

# ECE 275 Project 1: Linked List 
> Fun with pointers!!  
 
 ![Gary Come Home](https://memegenerator.net/img/instances/68293172.jpg)
 
Project 1 will see students creating a singly linked list. 
 
## Useful Reading:
- General Linked Lists:
	- [Wikibooks Linked List (C example)] (https://en.wikibooks.org/wiki/Data_Structures/LinkedLists)
	- [Wikibooks Linked List] (https://en.wikibooks.org/wiki/A-level_Computing/OCR/Unit_1.4.2_Data_Structures#Linked_List)
	- [Comp Sci Linked List] (https://computersciencewiki.org/index.php/Linked_list)
	- [Templates Tutorial] (https://www.cplusplus.com/doc/oldtutorial/templates/)
	- [ISO C++ Templates FAQ] (https://isocpp.org/wiki/faq/templates)
- Useful Tools: 
	- [Microsoft Visual Studio Debugger] (https://docs.microsoft.com/en-us/visualstudio/debugger/?view=vs-2019)
	- [Apple XCode Debugging Tools] (https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/debugging_with_xcode/chapters/debugging_tools.html)
	- [GNU Debugger (UMichigan Tutorial)] (https://web.eecs.umich.edu/~sugih/pointers/gdbQS.html)
	- [GNU Debugger Documentation/Tutorial] (https://sourceware.org/gdb/current/onlinedocs/gdb/index.html#SEC_Contents)
	- [Valgrind Quickstart Guide (memory leak detector)] (https://www.valgrind.org/docs/manual/quick-start.html)
	- [Memory leak detection Visual Studio] (https://stackoverflow.com/questions/4790564/finding-memory-leaks-in-a-c-application-with-visual-studio)

## Linked List Requirements:
### Namespace:
The `List` class **shall** be declared within namespace `ECE275Lib::containers`

### Datatype/Composition:
- The `List` class **shall** be constructable with an arbitrary C++ datatype. Hint: The `List` class will be declared as `List<T> l` where `T` is an arbitrary data type. This should be accomplished through a template
- The `List` class **shall** be comprised of a user-defined type `Node` where the `Node` may similarly be constructed given an arbitrary data type, i.e., `Node<T>`. The `Node` class/struct **shall** point to the next node in the list with a member named `next` (Hint: delcare as `Node<T>* next`, i.e., `Node<T>::next` should be of type `Node<T>*` and should hold the memory location of the next `Node` in the list). 
- The `List` **shall** be null-terminated, i.e., the last `Node` will set `next` to `nullptr`, e.g., a `List<T>` of length 3 will look like

```
[HEAD] = N(0) {T data, next &N(1)} 
		       |
		       --> N(1) {T data, next &N(2)} 
		   			 |
		   			 --> N(2) {T data, next nullptr} 
		   			                   |
		   			                   --> nullptr

```

### Construction:
- The `List` class **shall** be constructable with a default constructor. This **shall** set the head of the list to `nullptr`
- The `List` class **shall** be constructable with a parameterized constructor accepting an `unsigned int` type which denotes the length of the list. This **shall** construct N `Node`s in the list where N is the input parameter. The last `Node` in the `List` **shall** always point to `nullptr`

### Access:
- The `List` class **shall** provide access to the memory location of the head, i.e., the first node in the linked list, through a member function `List<T>::front()`
- The `List` class **shall** provide access to the memory location of the tail, i.e., the last node in the linked list, through a member function `List<T>::back()`
- The `List` class **shall** provide access to the *i*<sup>th</sup> element through a member function `List<T>::at(i)` which returnes type `T` where `i` is of type `unsigned int` and the return value is the value stored in the *i* <sup>th</sup> node
- The `List` class **shall** provide a setting function to the *i* <sup>th</sup> element through a member function `List<T>::assign(i, d)` which returnes type `void` where `i` is of type `unsigned int` and `d` is of type `T`. The function shall assign the data stored in the  *i*<sup>th</sup> element of the list to be the value `d`. 
- The `List` **shall** return the length of the list as an unsigned integer through a member function `List<T>::size()` which accepts no input.

### Mutation:
- The `List` class **shall** remove one node in the list through a member function `List<T>::remove(unsigned int i`) where `i` denotes the index of the `Node` to remove. 
- The `List` class **shall** remove multiple nodes in the list through a member function `List<T>::remove(unsigned int s, unsigned int e`) where `s` denotes the starting index of the `Node` to remove and `e` denotes the ending index of the `Node` to remove. 
- The `List` **shall** insert an element at index `i` through a member function `List<T>::insert(unsigned int i, T d)` where `i` is the index of the new element to be inserted, e.g., the list before insertion may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, N)` where `N` represents the data stored in the new `Node` will look like `[HEAD] (index 0) A --> (index 1) N --> (index 2) B --> (index 3) C nullptr`
- The `List` **shall** insert a seperate `List` starting at index `i` through a member function `List<T>::insert(unsigned int i, List<T>& other)` (note the neccesity to pass by reference. Alternatively, students may chose to define a copy constructor for their `List` class). E.g., the list before insertion of another list may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, other)` where `other` may look like `[HEAD] (index 0) Z --> (index 1) Y --> nullptr` will look like `[HEAD] (index 0) A --> (index 1) Z --> (index 2) Y --> (index 3) B --> (index 4) C --> nullptr` 


## Testing Framework:
### Requirements:
- General:
	- Student code may ***NOT*** include any C++ STL sequence containers. Inclusion of `<vector>`, `<array>`, `<vector>`, or `<forward_list>`. The inclusion of any dissalowed header will result in zero credit as simply wrapping a library class does not satisfy the requirement to construct a linked list. Test name: "RequirementsTester"
- Node class:
	- The only requirement for testing is the member `Node<T>::next` be named `"next"` as this field is accessed in the tester
- List class:
	- The `List` class will be tested using the method names as defined above
	- The tester will compare each element of the solution and student list and will print a formatted table with both values of the list with a marking `__fail__` at each row (corresponding to the index) where the tester and solution differ. Note this may be useful to view in "raw" on GitLab as there could be a lot of output. Hint: search for the marking to find quickly. 
	- Each test will be run for various standard and non-standard data data types types, e.g., `List<unsigned int> l` or (a non-standard type for arbitrary precision arithmatic) `List<boost::multiprecision::gmp>`. Note that proper use of the C++ template can prodivde this functionality without further effort on the part of the student, i.e., you should not have to do anything special to prepare for the tested non-standard datatypes
	- 4 Tests are run for the `List` class: "constructionTest", "push_backMethodTest", "individual_operationsTest", and "list_operationsTest"
		- constructionTest will test that defualt construction of your `List` class sets the head of the list to `nullptr` and that parameterized construction initializes the correct number of `Node` objects. Note again that access to the next `Node` in the list will be accomplished through `Node<T>::next`
		- push_backMethodTest will test the push_back method by adding a random number of elements using `List<T>::push_back(elem)` where `elem` will be a randomly gene rated value of type `T`
		- individual_operationsTest will test the `List<T>::insert(i, elem)` and `List<T>::remove(i)` member functions where `elem` will be a randomly generated value of type `T` and `i` will be a randomly-generated index
		- list_operationsTest will test the `List<T>::insert(i, l)` and `List<T>::remove(i, j)` member functions where `l` will be a randomly generated other `List<T>` of type `T` and `i` and `j` will be randomly-generated indicies of the list

### Grading:
The score will be computed as follows
For submissions prior to the deadline:
`RequirementsTester` * (`constructionTest` + `push_backMethodTest` + `individual_operationsTest` + `list_operationsTest`) where the max score would be 4.

For submissions up to one week after the deadline:
`RequirementsTester` * (`{Tests passed prior to deadline}` + 0.75 `{Tests passed after dealine}`) where the max score is 4.

For submissions subsequent to one week after teh deadline:
`RequirementsTester` * (`{Tests passed prior to deadline}` + 0.75 `{Tests passed before one week after dealine}` + 0.5 `{Tests passed now}`) where the max score is 4. *Note that it is the student's responsability to notify the instructor of the need for a regrade via email.*

#### Sanity Check:
Student code will first be compiled against the include `example_main.cpp` code to ensure tester code will compile (tester code may take up to 2.5 minutes to compile). This code is shown below again

```
#define logmsg std::clog << __PRETTY_FUNCTION__ << " "

#include "List.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace ec = ECE275Lib::containers;

void printDivider() { std::cout << "==========================\n"; };

int main (void){

	printDivider();
	
	
	logmsg << "Creating in_list" << std::endl;
	ec::List<int> int_list;
	for (unsigned int i = 0; i < 10; i++)
		int_list.push_back(i);
		
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
		
	logmsg << "Removing element 3" << std::endl;
	// Test that delete is working
	int_list.remove(3); // Delete index 3
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
    
    printDivider();
    
    logmsg << "Adding data 125 at element 1" << std::endl;
    int_list.insert(1, 125);
    for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
	
	logmsg << "Inserting another list at element 3" << std::endl;
	ec::List<int> int_list2;
	for (unsigned int i = 100; i < 110; i++)
		int_list2.push_back(i);
	
	int_list.insert(3, int_list2);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	
	printDivider();
	
	logmsg << "Removing elements 1 through 5" << std::endl;
	int_list.remove(1, 5);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	printDivider();
	
	ec::List<char> char_list(5);
	logmsg << "Char list size = " << char_list.size() << std::endl;
	for (unsigned int i = 0; i < char_list.size(); i++){
		char_list.assign(i, 'a');
		std::cout << "element " << i << ": " << char_list.at(i) << std::endl;
	}
	
	printDivider();
	
    
    ec::List<std::string> str_list;
    str_list.push_back("ECE 275!");
    str_list.push_back("UArizona");
    str_list.push_back("Tucson, AZ");
    
    for (unsigned int i = 0; i < str_list.size(); i++)
        std::cout << "element i: " << str_list.at(i) << std::endl;

	printDivider();    
    
    return 0;
}
```

## Development Tips:
1. Draw with pen and paper the layout of the linked list so that you have a concrete reference
2. Draw an actual picture for the `List` operations. It is usefult to draw each opeartion and label using the variable names you intend to use in your code. 
2. Leverage member helper functions. Hint: The solution file includes a private helper function `List<T>::traverse(unsigned int i)` which returns a pointer to the *i* <sup>th</sup> `Node<T>` in the list
2. Design a flowchart for each opearation. This may help identify good candidates for a helper function. 

## Extra Credit:
For 50% extra credit, prove that your program has no memory leaks! The best tool for this job (in my opinion) is valgrind, an open-source debugger and code profiler. This is also possible via tools within Visual Studios and XCode as valgrind, to my knowledge, only runs on Linux. The extra credit will involve students to research C++ memory profiling tools, e.g., valgrind, to determine the functionality of the chosen profiling tool and decipher the output to determine that no memory leaks are present from the user's code. Students may use the provided memcheck program for this purpose.  

### Due Date:
Project 1 is due Tuesday December 1 @ 2359. Please refer to the Syllabus for the weight of Projects in ECE 275 and be sure to ***start early*** :) 