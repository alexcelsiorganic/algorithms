# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\games\ones

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\games\ones\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ones.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ones.dir/flags.make

CMakeFiles/ones.dir/main.cpp.obj: CMakeFiles/ones.dir/flags.make
CMakeFiles/ones.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\games\ones\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ones.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ones.dir\main.cpp.obj -c C:\games\ones\main.cpp

CMakeFiles/ones.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ones.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\games\ones\main.cpp > CMakeFiles\ones.dir\main.cpp.i

CMakeFiles/ones.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ones.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\games\ones\main.cpp -o CMakeFiles\ones.dir\main.cpp.s

# Object files for target ones
ones_OBJECTS = \
"CMakeFiles/ones.dir/main.cpp.obj"

# External object files for target ones
ones_EXTERNAL_OBJECTS =

ones.exe: CMakeFiles/ones.dir/main.cpp.obj
ones.exe: CMakeFiles/ones.dir/build.make
ones.exe: CMakeFiles/ones.dir/linklibs.rsp
ones.exe: CMakeFiles/ones.dir/objects1.rsp
ones.exe: CMakeFiles/ones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\games\ones\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ones.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ones.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ones.dir/build: ones.exe

.PHONY : CMakeFiles/ones.dir/build

CMakeFiles/ones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ones.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ones.dir/clean

CMakeFiles/ones.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\games\ones C:\games\ones C:\games\ones\cmake-build-debug C:\games\ones\cmake-build-debug C:\games\ones\cmake-build-debug\CMakeFiles\ones.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ones.dir/depend
