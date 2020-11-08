add_library(gbcpu inc/cpu/cpu.h src/cpu.cpp)
target_include_directories(gbcpu PUBLIC inc/ PRIVATE inc/cpu)
