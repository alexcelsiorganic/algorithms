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
CMAKE_SOURCE_DIR = C:\games\roads

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\games\roads\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/roads.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roads.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roads.dir/flags.make

CMakeFiles/roads.dir/main.cpp.obj: CMakeFiles/roads.dir/flags.make
CMakeFiles/roads.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\games\roads\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roads.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roads.dir\main.cpp.obj -c C:\games\roads\main.cpp

CMakeFiles/roads.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roads.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\games\roads\main.cpp > CMakeFiles\roads.dir\main.cpp.i

CMakeFiles/roads.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roads.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\games\roads\main.cpp -o CMakeFiles\roads.dir\main.cpp.s

# Object files for target roads
roads_OBJECTS = \
"CMakeFiles/roads.dir/main.cpp.obj"

# External object files for target roads
roads_EXTERNAL_OBJECTS =

roads.exe: CMakeFiles/roads.dir/main.cpp.obj
roads.exe: CMakeFiles/roads.dir/build.make
roads.exe: CMakeFiles/roads.dir/linklibs.rsp
roads.exe: CMakeFiles/roads.dir/objects1.rsp
roads.exe: CMakeFiles/roads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\games\roads\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roads.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\roads.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roads.dir/build: roads.exe

.PHONY : CMakeFiles/roads.dir/build

CMakeFiles/roads.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\roads.dir\cmake_clean.cmake
.PHONY : CMakeFiles/roads.dir/clean

CMakeFiles/roads.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\games\roads C:\games\roads C:\games\roads\cmake-build-debug C:\games\roads\cmake-build-debug C:\games\roads\cmake-build-debug\CMakeFiles\roads.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roads.dir/depend

