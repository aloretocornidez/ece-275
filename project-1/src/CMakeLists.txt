set ( target LinkedList )


set (sources List.hpp)
add_executable(${target} example_main.cpp ${sources})
add_executable("${target}_memcheck" memory_check.cpp ${sources})