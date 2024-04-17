cmake_minimum_required (VERSION 3.8)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

# Execute CMake for Eclipse as:
# cmake ../{dir}/ -G"Eclipse CDT4 - Unix Makefiles" 
#	-DCMAKE_ECLIPSE_VERSION=4.14 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_ARG1=-std=c++17

project(HaveYouSeenThisSnail CXX)

if ( ENABLE_TESTING )
	# Find the Boost library
	find_package(Boost REQUIRED)
	message(STATUS "     I got Boost Version ${Boost_VERSION_MAJOR}.${Boost_VERSION_MINOR}.${Boost_VERSION_PATCH}")
	message(STATUS "     I got Boost Include Directories as  ${Boost_INCLUDE_DIRS}")
	# Include those directories 
	include_directories(${Boost_INCLUDE_DIRS})
endif()

cmake_policy(SET CMP0079 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build the source directory 
add_subdirectory(src)

# If we're testing build the Tester directory 
if ( ENABLE_TESTING )
	add_subdirectory(Tester)
endif()