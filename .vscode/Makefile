CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment

# Compile the main executable
Matrix_tests.exe: Matrix_tests.c Matrix.c
	$(CXX) $(CXXFLAGS) Matrix_tests.c -o Matrix_tests.exe

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump