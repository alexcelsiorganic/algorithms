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
CMAKE_SOURCE_DIR = C:\games\roads_simple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\games\roads_simple\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/roads_simple.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roads_simple.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roads_simple.dir/flags.make

CMakeFiles/roads_simple.dir/main.cpp.obj: CMakeFiles/roads_simple.dir/flags.make
CMakeFiles/roads_simple.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\games\roads_simple\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roads_simple.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roads_simple.dir\main.cpp.obj -c C:\games\roads_simple\main.cpp

CMakeFiles/roads_simple.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roads_simple.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\games\roads_simple\main.cpp > CMakeFiles\roads_simple.dir\main.cpp.i

CMakeFiles/roads_simple.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roads_simple.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\games\roads_simple\main.cpp -o CMakeFiles\roads_simple.dir\main.cpp.s

# Object files for target roads_simple
roads_simple_OBJECTS = \
"CMakeFiles/roads_simple.dir/main.cpp.obj"

# External object files for target roads_simple
roads_simple_EXTERNAL_OBJECTS =

roads_simple.exe: CMakeFiles/roads_simple.dir/main.cpp.obj
roads_simple.exe: CMakeFiles/roads_simple.dir/build.make
roads_simple.exe: CMakeFiles/roads_simple.dir/linklibs.rsp
roads_simple.exe: CMakeFiles/roads_simple.dir/objects1.rsp
roads_simple.exe: CMakeFiles/roads_simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\games\roads_simple\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roads_simple.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\roads_simple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roads_simple.dir/build: roads_simple.exe

.PHONY : CMakeFiles/roads_simple.dir/build

CMakeFiles/roads_simple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\roads_simple.dir\cmake_clean.cmake
.PHONY : CMakeFiles/roads_simple.dir/clean

CMakeFiles/roads_simple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\games\roads_simple C:\games\roads_simple C:\games\roads_simple\cmake-build-debug C:\games\roads_simple\cmake-build-debug C:\games\roads_simple\cmake-build-debug\CMakeFiles\roads_simple.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roads_simple.dir/depend
