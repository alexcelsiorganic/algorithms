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
CMAKE_SOURCE_DIR = C:\games\palindrom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\games\palindrom\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/palindrom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/palindrom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/palindrom.dir/flags.make

CMakeFiles/palindrom.dir/main.cpp.obj: CMakeFiles/palindrom.dir/flags.make
CMakeFiles/palindrom.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\games\palindrom\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/palindrom.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\palindrom.dir\main.cpp.obj -c C:\games\palindrom\main.cpp

CMakeFiles/palindrom.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/palindrom.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\games\palindrom\main.cpp > CMakeFiles\palindrom.dir\main.cpp.i

CMakeFiles/palindrom.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/palindrom.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\games\palindrom\main.cpp -o CMakeFiles\palindrom.dir\main.cpp.s

# Object files for target palindrom
palindrom_OBJECTS = \
"CMakeFiles/palindrom.dir/main.cpp.obj"

# External object files for target palindrom
palindrom_EXTERNAL_OBJECTS =

palindrom.exe: CMakeFiles/palindrom.dir/main.cpp.obj
palindrom.exe: CMakeFiles/palindrom.dir/build.make
palindrom.exe: CMakeFiles/palindrom.dir/linklibs.rsp
palindrom.exe: CMakeFiles/palindrom.dir/objects1.rsp
palindrom.exe: CMakeFiles/palindrom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\games\palindrom\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable palindrom.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\palindrom.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/palindrom.dir/build: palindrom.exe

.PHONY : CMakeFiles/palindrom.dir/build

CMakeFiles/palindrom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\palindrom.dir\cmake_clean.cmake
.PHONY : CMakeFiles/palindrom.dir/clean

CMakeFiles/palindrom.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\games\palindrom C:\games\palindrom C:\games\palindrom\cmake-build-debug C:\games\palindrom\cmake-build-debug C:\games\palindrom\cmake-build-debug\CMakeFiles\palindrom.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/palindrom.dir/depend

