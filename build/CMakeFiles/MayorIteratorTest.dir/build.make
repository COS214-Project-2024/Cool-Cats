# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/sean/COS 214/Project/Cool-Cats"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sean/COS 214/Project/Cool-Cats/build"

# Include any dependencies generated for this target.
include CMakeFiles/MayorIteratorTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MayorIteratorTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MayorIteratorTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MayorIteratorTest.dir/flags.make

CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o: CMakeFiles/MayorIteratorTest.dir/flags.make
CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o: ../tests/MayorIteratorTest.cpp
CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o: CMakeFiles/MayorIteratorTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o -MF CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o.d -o CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o -c "/home/sean/COS 214/Project/Cool-Cats/tests/MayorIteratorTest.cpp"

CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sean/COS 214/Project/Cool-Cats/tests/MayorIteratorTest.cpp" > CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.i

CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sean/COS 214/Project/Cool-Cats/tests/MayorIteratorTest.cpp" -o CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.s

# Object files for target MayorIteratorTest
MayorIteratorTest_OBJECTS = \
"CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o"

# External object files for target MayorIteratorTest
MayorIteratorTest_EXTERNAL_OBJECTS =

MayorIteratorTest: CMakeFiles/MayorIteratorTest.dir/tests/MayorIteratorTest.cpp.o
MayorIteratorTest: CMakeFiles/MayorIteratorTest.dir/build.make
MayorIteratorTest: lib/libgtest.a
MayorIteratorTest: lib/libgtest_main.a
MayorIteratorTest: libCitizen.a
MayorIteratorTest: lib/libgtest.a
MayorIteratorTest: CMakeFiles/MayorIteratorTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MayorIteratorTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MayorIteratorTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MayorIteratorTest.dir/build: MayorIteratorTest
.PHONY : CMakeFiles/MayorIteratorTest.dir/build

CMakeFiles/MayorIteratorTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MayorIteratorTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MayorIteratorTest.dir/clean

CMakeFiles/MayorIteratorTest.dir/depend:
	cd "/home/sean/COS 214/Project/Cool-Cats/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sean/COS 214/Project/Cool-Cats" "/home/sean/COS 214/Project/Cool-Cats" "/home/sean/COS 214/Project/Cool-Cats/build" "/home/sean/COS 214/Project/Cool-Cats/build" "/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles/MayorIteratorTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MayorIteratorTest.dir/depend
