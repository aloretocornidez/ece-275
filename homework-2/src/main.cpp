// Main function included for your testing. Main function is not considered
// in the autograder - only Ackermann.cpp and Ackermann.hpp

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
