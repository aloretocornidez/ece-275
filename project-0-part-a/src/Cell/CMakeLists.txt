# Build Cell into a library 
set(sources
	Cell.cpp
)
set(headers
	Cell.hpp
)

set(target Cell)

add_library(${target} SHARED ${sources} ${headers})
