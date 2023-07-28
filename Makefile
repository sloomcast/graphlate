CC ?= gcc
CFLAGS ?= -I.

# Compile the main executable
Matrix_tests.exe: Matrix_tests.c Matrix.c
	$(CC) $(CFLAGS) Matrix_tests.c -o Matrix_tests.exe

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump