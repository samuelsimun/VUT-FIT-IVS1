# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build"

# Include any dependencies generated for this target.
include CMakeFiles/black_box_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/black_box_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/black_box_test.dir/flags.make

CMakeFiles/black_box_test.dir/black_box_tests.cpp.o: CMakeFiles/black_box_test.dir/flags.make
CMakeFiles/black_box_test.dir/black_box_tests.cpp.o: ../black_box_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/black_box_test.dir/black_box_tests.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/black_box_test.dir/black_box_tests.cpp.o -c "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/black_box_tests.cpp"

CMakeFiles/black_box_test.dir/black_box_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/black_box_test.dir/black_box_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/black_box_tests.cpp" > CMakeFiles/black_box_test.dir/black_box_tests.cpp.i

CMakeFiles/black_box_test.dir/black_box_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/black_box_test.dir/black_box_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/black_box_tests.cpp" -o CMakeFiles/black_box_test.dir/black_box_tests.cpp.s

# Object files for target black_box_test
black_box_test_OBJECTS = \
"CMakeFiles/black_box_test.dir/black_box_tests.cpp.o"

# External object files for target black_box_test
black_box_test_EXTERNAL_OBJECTS =

black_box_test: CMakeFiles/black_box_test.dir/black_box_tests.cpp.o
black_box_test: CMakeFiles/black_box_test.dir/build.make
black_box_test: ../libs/libblack_box_lib.a
black_box_test: lib/libgtest_main.a
black_box_test: lib/libgtest.a
black_box_test: CMakeFiles/black_box_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable black_box_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/black_box_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/black_box_test.dir/build: black_box_test

.PHONY : CMakeFiles/black_box_test.dir/build

CMakeFiles/black_box_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/black_box_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/black_box_test.dir/clean

CMakeFiles/black_box_test.dir/depend:
	cd "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment" "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment" "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build" "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build" "/home/samuel/Desktop/IVS 1/ivs_project_1_2022 (1)/assignment/build/CMakeFiles/black_box_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/black_box_test.dir/depend

