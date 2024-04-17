add_subdirectory(Board)
add_subdirectory(Cell)
add_subdirectory(Gary)

set(sources
	FindGary.cpp
)

set(target FindGary)

include_directories(Board Cell Gary)
add_executable(${target} ${sources})
target_link_libraries(${target} 
	Board
	Cell
	Gary
	${Boost_LIBRARIES}
)