# Add a library for testing
add_library(Ackermann Ackermann.cpp Ackermann.hpp)

# Add an executable 
add_executable(AckermannExe main.cpp)
target_link_libraries(AckermannExe Ackermann)