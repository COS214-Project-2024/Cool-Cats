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
CMAKE_SOURCE_DIR = "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build"

# Include any dependencies generated for this target.
include CMakeFiles/HighCitizenTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HighCitizenTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HighCitizenTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HighCitizenTest.dir/flags.make

CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o: CMakeFiles/HighCitizenTest.dir/flags.make
CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o: ../Tests/HighCitizenTest.cpp
CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o: CMakeFiles/HighCitizenTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o -MF CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o.d -o CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o -c "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/Tests/HighCitizenTest.cpp"

CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/Tests/HighCitizenTest.cpp" > CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.i

CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/Tests/HighCitizenTest.cpp" -o CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.s

# Object files for target HighCitizenTest
HighCitizenTest_OBJECTS = \
"CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o"

# External object files for target HighCitizenTest
HighCitizenTest_EXTERNAL_OBJECTS =

HighCitizenTest: CMakeFiles/HighCitizenTest.dir/Tests/HighCitizenTest.cpp.o
HighCitizenTest: CMakeFiles/HighCitizenTest.dir/build.make
HighCitizenTest: lib/libgtest.a
HighCitizenTest: lib/libgtest_main.a
HighCitizenTest: libCitizen.a
HighCitizenTest: lib/libgtest.a
HighCitizenTest: CMakeFiles/HighCitizenTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HighCitizenTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HighCitizenTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HighCitizenTest.dir/build: HighCitizenTest
.PHONY : CMakeFiles/HighCitizenTest.dir/build

CMakeFiles/HighCitizenTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HighCitizenTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HighCitizenTest.dir/clean

CMakeFiles/HighCitizenTest.dir/depend:
	cd "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats" "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats" "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build" "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build" "/mnt/c/Users/User/OneDrive/Desktop/School/Semester 2/COS214/project/Cool-Cats/build/CMakeFiles/HighCitizenTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/HighCitizenTest.dir/depend

