cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_COMPILER_WORKS 1)
set (CMAKE_C_COMPILER_WORKS 1)

project(Project_1_LinkedList CXX)

set(CMAKE_CXX_STANDARD 17)

if (NOT TESTING_ONLY)
	add_subdirectory(src)
	message(STATUS "    Adding src subdirectory")
endif()

if (TESTING OR TESTING_ONLY)
	message(STATUS "    Adding Tester subdirectory")
	if (LOCAL)
		add_subdirectory(Tester_l)
	else()
	add_subdirectory(Tester)
	endif()
endif()
