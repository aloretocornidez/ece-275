set(sources
	Gary.cpp
)
set(headers
	Gary.hpp
)

set(target Gary)

include_directories(../Cell)

add_library(${target} SHARED ${sources} ${headers})
target_link_libraries(${target} Cell)