# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/corentinvasseur/Downloads/source_dir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/corentinvasseur/Downloads/source_dir/build_dir

# Include any dependencies generated for this target.
include doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/depend.make

# Include the progress variables for this target.
include doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/progress.make

# Include the compile flags for this target's objects.
include doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/flags.make

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/flags.make
doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o: ../doc/examples/QuickStart_example2_fixed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/corentinvasseur/Downloads/source_dir/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o"
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o -c /Users/corentinvasseur/Downloads/source_dir/doc/examples/QuickStart_example2_fixed.cpp

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.i"
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corentinvasseur/Downloads/source_dir/doc/examples/QuickStart_example2_fixed.cpp > CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.i

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.s"
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corentinvasseur/Downloads/source_dir/doc/examples/QuickStart_example2_fixed.cpp -o CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.s

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.requires:

.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.requires

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.provides: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.requires
	$(MAKE) -f doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/build.make doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.provides.build
.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.provides

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.provides.build: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o


# Object files for target QuickStart_example2_fixed
QuickStart_example2_fixed_OBJECTS = \
"CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o"

# External object files for target QuickStart_example2_fixed
QuickStart_example2_fixed_EXTERNAL_OBJECTS =

doc/examples/QuickStart_example2_fixed: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o
doc/examples/QuickStart_example2_fixed: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/build.make
doc/examples/QuickStart_example2_fixed: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/corentinvasseur/Downloads/source_dir/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable QuickStart_example2_fixed"
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QuickStart_example2_fixed.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && ./QuickStart_example2_fixed >/Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples/QuickStart_example2_fixed.out

# Rule to build all files generated by this target.
doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/build: doc/examples/QuickStart_example2_fixed

.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/build

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/requires: doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/QuickStart_example2_fixed.cpp.o.requires

.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/requires

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/clean:
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/QuickStart_example2_fixed.dir/cmake_clean.cmake
.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/clean

doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/depend:
	cd /Users/corentinvasseur/Downloads/source_dir/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/corentinvasseur/Downloads/source_dir /Users/corentinvasseur/Downloads/source_dir/doc/examples /Users/corentinvasseur/Downloads/source_dir/build_dir /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples /Users/corentinvasseur/Downloads/source_dir/build_dir/doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/examples/CMakeFiles/QuickStart_example2_fixed.dir/depend
