[![pipeline status](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/homework-2/badges/master/pipeline.svg)](https://git.engr.arizona.edu/ece-275-fs-2020/individual-student-groups/alan-manuel-loreto-cornidez/homework-2/-/commits/master)

# ECE 275 Homework 2: Ackermann Function

[![Ackermann](https://upload.wikimedia.org/wikipedia/commons/6/6b/Ackermann_Wilhelm.jpg)](https://en.wikipedia.org/wiki/Wilhelm_Ackermann)

"Wilhelm Friedrich Ackermann (/ˈækərmən/; German: [ˈakɐˌman]; 29 March 1896 – 24 December 1962) was a German mathematician best known for the Ackermann function, an important example in the theory of computation." [Wikipedia link in image]

## Recursion

This homework will cover the concept of recursion. To understand [recursion](https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_programming/Recursion) you must have working knowledge on the concept of [stack frames](https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_programming/Stack_Frames). 

## Assignment
Impliment the Ackermann function in C++. A main function is provided for you in the initial repository but is inconsequential for testing. 

```
#include "Ackermann.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (not (argc == 3)){
        // Write to the standard error stream
        // http://www.cplusplus.com/reference/iostream/cerr/
        std::cerr << "Call program as ./AckermannExe M N" << std::endl;
        return 2;
    }
    
    int i = atoi(*(argv + 1)); // Parse first command arg
    int j = atoi(*(argv + 2)); // Parse second command arg
    
    std::cout << "Ack(" << i << ", " << j << ") = " << ackermann(i, j) << std::endl;
    
    return 0;
}

```

### Homework Requirements
The Ackermann function must accept two integer values. The Ackermann function is defined as 

![AckermannFunction](https://mathworld.wolfram.com/images/equations/AckermannFunction/NumberedEquation1.gif)

as found [here](https://mathworld.wolfram.com/AckermannFunction.html). 

- The Ackermann function **shall** be called as `ackermann(x, y)` where `x` and `y` are integer values. 
- The Ackermann function **shall** be included through `#include "Ackermann.hpp"` as shown in the main program

#### Testing of Ackermann Function
The Ackermann function *will* be tested using C++ unit-testing against the function `tester::ackermann(int, int)` which represents the solution. The tester will only rely on the function defined in `Ackermann.hpp`.

## Example: FORTRAN
Consider the following example written in modern FORTRAN: 

```
! Expanded on from http://fortranwiki.org/fortran/show/recursion
! gfortran -ffree-form AckermanFunction.f -o AckermanFunction

program ackermann
	integer :: argc, result, m, n, i, j, ack
	character(len=32) :: argv
	
	! Check the number of command line arguments
	argc = command_argument_count()
	if (.not. argc == 2) then 
		write(*,*) "ERROR: Call program as ./AckermannFunction M N"
		call exit(1)
	endif 
	! Get M and N from command arguments
	call get_command_argument(1, argv)
	read(argv, *) m
	call get_command_argument(2, argv)
	read(argv, *) n
	
	do i = 0, m
		do j = 0, n
			write(*,*) "Ackermann(", i , j, ") = ", ack(i,j)
		end do
	end do
	
end program ackermann

recursive function ack(m, n) result(a)
	integer, intent(in) :: m,n
	integer :: a
	if (m == 0) then
	 a=n+1
	else if (n == 0) then
	 a=ack(m-1,1)
	else
	 a=ack(m-1, ack(m, n-1))
	end if
end function ack
```
The program can be compiled using `gfortran -ffree-form AckermanFunction.f -o AckermanFunction` assuming that gfortran is the FORTRAN compiler. Run the program via [onlineGDB](https://onlinegdb.com/B11zHWkFv) within your web browser. 

## Extra Credit
For an extra homework grade, impliment the Ackermann function in a languge *other* than C/C++ or FORTRAN (as the example is given above). Note this *must* be a function in whatever language you choose. Submit this code and a short explanation of your implimentation and screenshots of output calculating `Ackermann(m, n)` where `m` goes from 0 to 3 and `n` goes from 0 to 12. 

Suggestions include, but are not limited to, 

- Python (swiss army knife of languages)
- MATLAB (great for prototyping)
- Julia (one of my favorite new languages)
- Java (incredibly useful language)
- Rust (a competator to C++)