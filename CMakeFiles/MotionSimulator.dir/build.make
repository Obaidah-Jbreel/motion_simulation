# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /snap/cmake/1361/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1361/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linux/dev/motion_simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linux/dev/motion_simulation

# Include any dependencies generated for this target.
include CMakeFiles/MotionSimulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MotionSimulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MotionSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MotionSimulator.dir/flags.make

CMakeFiles/MotionSimulator.dir/src/canon.cpp.o: CMakeFiles/MotionSimulator.dir/flags.make
CMakeFiles/MotionSimulator.dir/src/canon.cpp.o: src/canon.cpp
CMakeFiles/MotionSimulator.dir/src/canon.cpp.o: CMakeFiles/MotionSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/linux/dev/motion_simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MotionSimulator.dir/src/canon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MotionSimulator.dir/src/canon.cpp.o -MF CMakeFiles/MotionSimulator.dir/src/canon.cpp.o.d -o CMakeFiles/MotionSimulator.dir/src/canon.cpp.o -c /home/linux/dev/motion_simulation/src/canon.cpp

CMakeFiles/MotionSimulator.dir/src/canon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MotionSimulator.dir/src/canon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linux/dev/motion_simulation/src/canon.cpp > CMakeFiles/MotionSimulator.dir/src/canon.cpp.i

CMakeFiles/MotionSimulator.dir/src/canon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MotionSimulator.dir/src/canon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linux/dev/motion_simulation/src/canon.cpp -o CMakeFiles/MotionSimulator.dir/src/canon.cpp.s

CMakeFiles/MotionSimulator.dir/src/main.cpp.o: CMakeFiles/MotionSimulator.dir/flags.make
CMakeFiles/MotionSimulator.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/MotionSimulator.dir/src/main.cpp.o: CMakeFiles/MotionSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/linux/dev/motion_simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MotionSimulator.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MotionSimulator.dir/src/main.cpp.o -MF CMakeFiles/MotionSimulator.dir/src/main.cpp.o.d -o CMakeFiles/MotionSimulator.dir/src/main.cpp.o -c /home/linux/dev/motion_simulation/src/main.cpp

CMakeFiles/MotionSimulator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MotionSimulator.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linux/dev/motion_simulation/src/main.cpp > CMakeFiles/MotionSimulator.dir/src/main.cpp.i

CMakeFiles/MotionSimulator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MotionSimulator.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linux/dev/motion_simulation/src/main.cpp -o CMakeFiles/MotionSimulator.dir/src/main.cpp.s

# Object files for target MotionSimulator
MotionSimulator_OBJECTS = \
"CMakeFiles/MotionSimulator.dir/src/canon.cpp.o" \
"CMakeFiles/MotionSimulator.dir/src/main.cpp.o"

# External object files for target MotionSimulator
MotionSimulator_EXTERNAL_OBJECTS =

bin/MotionSimulator: CMakeFiles/MotionSimulator.dir/src/canon.cpp.o
bin/MotionSimulator: CMakeFiles/MotionSimulator.dir/src/main.cpp.o
bin/MotionSimulator: CMakeFiles/MotionSimulator.dir/build.make
bin/MotionSimulator: CMakeFiles/MotionSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/linux/dev/motion_simulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/MotionSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MotionSimulator.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying data folder to build directory"
	/snap/cmake/1361/bin/cmake -E copy_directory /home/linux/dev/motion_simulation/assets/ /home/linux/dev/motion_simulation/bin/

# Rule to build all files generated by this target.
CMakeFiles/MotionSimulator.dir/build: bin/MotionSimulator
.PHONY : CMakeFiles/MotionSimulator.dir/build

CMakeFiles/MotionSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MotionSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MotionSimulator.dir/clean

CMakeFiles/MotionSimulator.dir/depend:
	cd /home/linux/dev/motion_simulation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linux/dev/motion_simulation /home/linux/dev/motion_simulation /home/linux/dev/motion_simulation /home/linux/dev/motion_simulation /home/linux/dev/motion_simulation/CMakeFiles/MotionSimulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MotionSimulator.dir/depend
