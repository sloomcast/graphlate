# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davisow/Desktop/Graphlate/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davisow/Desktop/Graphlate/build

# Include any dependencies generated for this target.
include CMakeFiles/otests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/otests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/otests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/otests.dir/flags.make

CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o: CMakeFiles/otests.dir/flags.make
CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o: /Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp
CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o: CMakeFiles/otests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/davisow/Desktop/Graphlate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o -MF CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o.d -o CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o -c /Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp

CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp > CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.i

CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp -o CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.s

# Object files for target otests
otests_OBJECTS = \
"CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o"

# External object files for target otests
otests_EXTERNAL_OBJECTS =

bin/otests: CMakeFiles/otests.dir/Users/davisow/Desktop/Graphlate/tests/matrix_tests.cpp.o
bin/otests: CMakeFiles/otests.dir/build.make
bin/otests: CMakeFiles/otests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/davisow/Desktop/Graphlate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/otests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/otests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/otests.dir/build: bin/otests
.PHONY : CMakeFiles/otests.dir/build

CMakeFiles/otests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/otests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/otests.dir/clean

CMakeFiles/otests.dir/depend:
	cd /Users/davisow/Desktop/Graphlate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davisow/Desktop/Graphlate/build /Users/davisow/Desktop/Graphlate/build /Users/davisow/Desktop/Graphlate/build /Users/davisow/Desktop/Graphlate/build /Users/davisow/Desktop/Graphlate/build/CMakeFiles/otests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/otests.dir/depend

