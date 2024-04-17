cmake_minimum_required (VERSION 3.8)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

# Execute CMake for Eclipse as:
# cmake ../{dir}/ -G"Eclipse CDT4 - Unix Makefiles" 
#	-DCMAKE_ECLIPSE_VERSION=4.14 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_ARG1=-std=c++17

project(AckermannFunction CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
if (ENABLE_TESTING)
	add_subdirectory(Tester)
endif()