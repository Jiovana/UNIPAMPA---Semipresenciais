# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\Fibonacci

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fibonacci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fibonacci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fibonacci.dir/flags.make

CMakeFiles/Fibonacci.dir/main.c.obj: CMakeFiles/Fibonacci.dir/flags.make
CMakeFiles/Fibonacci.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fibonacci.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Fibonacci.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\Fibonacci\main.c

CMakeFiles/Fibonacci.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fibonacci.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Fibonacci\main.c > CMakeFiles\Fibonacci.dir\main.c.i

CMakeFiles/Fibonacci.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fibonacci.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Fibonacci\main.c -o CMakeFiles\Fibonacci.dir\main.c.s

CMakeFiles/Fibonacci.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Fibonacci.dir/main.c.obj.requires

CMakeFiles/Fibonacci.dir/main.c.obj.provides: CMakeFiles/Fibonacci.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Fibonacci.dir\build.make CMakeFiles/Fibonacci.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Fibonacci.dir/main.c.obj.provides

CMakeFiles/Fibonacci.dir/main.c.obj.provides.build: CMakeFiles/Fibonacci.dir/main.c.obj


# Object files for target Fibonacci
Fibonacci_OBJECTS = \
"CMakeFiles/Fibonacci.dir/main.c.obj"

# External object files for target Fibonacci
Fibonacci_EXTERNAL_OBJECTS =

Fibonacci.exe: CMakeFiles/Fibonacci.dir/main.c.obj
Fibonacci.exe: CMakeFiles/Fibonacci.dir/build.make
Fibonacci.exe: CMakeFiles/Fibonacci.dir/linklibs.rsp
Fibonacci.exe: CMakeFiles/Fibonacci.dir/objects1.rsp
Fibonacci.exe: CMakeFiles/Fibonacci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Fibonacci.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fibonacci.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fibonacci.dir/build: Fibonacci.exe

.PHONY : CMakeFiles/Fibonacci.dir/build

CMakeFiles/Fibonacci.dir/requires: CMakeFiles/Fibonacci.dir/main.c.obj.requires

.PHONY : CMakeFiles/Fibonacci.dir/requires

CMakeFiles/Fibonacci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fibonacci.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fibonacci.dir/clean

CMakeFiles/Fibonacci.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\Fibonacci C:\Users\gomes\CLionProjects\Fibonacci C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug C:\Users\gomes\CLionProjects\Fibonacci\cmake-build-debug\CMakeFiles\Fibonacci.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fibonacci.dir/depend
