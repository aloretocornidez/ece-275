set(BOOST_TEST_LOG_LEVEL message)


enable_testing()

include_directories(../src/Board ../src/Cell ../src/Gary)

# Add the Cell Tester executable
add_executable(CellTester CellTester.hpp CellTester.cpp)
target_link_libraries(CellTester Cell)
add_test(NAME TestCellClass COMMAND CellTester) 

# Add an executable to test the Cell's class composition
add_executable(CellCompositionTester CellCompositionTester.hpp CellCompositionTester.cpp)
target_link_libraries(CellCompositionTester Cell)
add_test(NAME TestCellClassComposition COMMAND CellCompositionTester) 
