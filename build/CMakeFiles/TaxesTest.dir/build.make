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
include CMakeFiles/TaxesTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TaxesTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TaxesTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TaxesTest.dir/flags.make

CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o: CMakeFiles/TaxesTest.dir/flags.make
CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o: ../Tests/TaxesTest.cpp
CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o: CMakeFiles/TaxesTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o -MF CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o.d -o CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o -c "/home/sean/COS 214/Project/Cool-Cats/Tests/TaxesTest.cpp"

CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sean/COS 214/Project/Cool-Cats/Tests/TaxesTest.cpp" > CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.i

CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sean/COS 214/Project/Cool-Cats/Tests/TaxesTest.cpp" -o CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.s

# Object files for target TaxesTest
TaxesTest_OBJECTS = \
"CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o"

# External object files for target TaxesTest
TaxesTest_EXTERNAL_OBJECTS =

TaxesTest: CMakeFiles/TaxesTest.dir/Tests/TaxesTest.cpp.o
TaxesTest: CMakeFiles/TaxesTest.dir/build.make
TaxesTest: lib/libgtest.a
TaxesTest: lib/libgtest_main.a
TaxesTest: libgovernment.a
TaxesTest: libCitizen.a
TaxesTest: lib/libgtest.a
TaxesTest: CMakeFiles/TaxesTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TaxesTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TaxesTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TaxesTest.dir/build: TaxesTest
.PHONY : CMakeFiles/TaxesTest.dir/build

CMakeFiles/TaxesTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TaxesTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TaxesTest.dir/clean

CMakeFiles/TaxesTest.dir/depend:
	cd "/home/sean/COS 214/Project/Cool-Cats/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sean/COS 214/Project/Cool-Cats" "/home/sean/COS 214/Project/Cool-Cats" "/home/sean/COS 214/Project/Cool-Cats/build" "/home/sean/COS 214/Project/Cool-Cats/build" "/home/sean/COS 214/Project/Cool-Cats/build/CMakeFiles/TaxesTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TaxesTest.dir/depend

