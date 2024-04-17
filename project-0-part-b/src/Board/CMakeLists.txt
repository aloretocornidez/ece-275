set(sources
	Board.cpp
)
set(headers
	Board.hpp
)

set(target Board)

include_directories(../Cell ../Gary)

add_library(${target} SHARED ${sources} ${headers})
target_link_libraries(${target} Cell Gary)
