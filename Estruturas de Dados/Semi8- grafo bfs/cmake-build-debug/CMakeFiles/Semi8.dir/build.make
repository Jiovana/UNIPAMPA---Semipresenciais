# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\Semi8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Semi8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Semi8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Semi8.dir/flags.make

CMakeFiles/Semi8.dir/main.c.obj: CMakeFiles/Semi8.dir/flags.make
CMakeFiles/Semi8.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Semi8.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi8.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\Semi8\main.c

CMakeFiles/Semi8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi8.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi8\main.c > CMakeFiles\Semi8.dir\main.c.i

CMakeFiles/Semi8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi8.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi8\main.c -o CMakeFiles\Semi8.dir\main.c.s

CMakeFiles/Semi8.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Semi8.dir/main.c.obj.requires

CMakeFiles/Semi8.dir/main.c.obj.provides: CMakeFiles/Semi8.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi8.dir\build.make CMakeFiles/Semi8.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Semi8.dir/main.c.obj.provides

CMakeFiles/Semi8.dir/main.c.obj.provides.build: CMakeFiles/Semi8.dir/main.c.obj


CMakeFiles/Semi8.dir/grafo.c.obj: CMakeFiles/Semi8.dir/flags.make
CMakeFiles/Semi8.dir/grafo.c.obj: ../grafo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Semi8.dir/grafo.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi8.dir\grafo.c.obj   -c C:\Users\gomes\CLionProjects\Semi8\grafo.c

CMakeFiles/Semi8.dir/grafo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi8.dir/grafo.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi8\grafo.c > CMakeFiles\Semi8.dir\grafo.c.i

CMakeFiles/Semi8.dir/grafo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi8.dir/grafo.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi8\grafo.c -o CMakeFiles\Semi8.dir\grafo.c.s

CMakeFiles/Semi8.dir/grafo.c.obj.requires:

.PHONY : CMakeFiles/Semi8.dir/grafo.c.obj.requires

CMakeFiles/Semi8.dir/grafo.c.obj.provides: CMakeFiles/Semi8.dir/grafo.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi8.dir\build.make CMakeFiles/Semi8.dir/grafo.c.obj.provides.build
.PHONY : CMakeFiles/Semi8.dir/grafo.c.obj.provides

CMakeFiles/Semi8.dir/grafo.c.obj.provides.build: CMakeFiles/Semi8.dir/grafo.c.obj


# Object files for target Semi8
Semi8_OBJECTS = \
"CMakeFiles/Semi8.dir/main.c.obj" \
"CMakeFiles/Semi8.dir/grafo.c.obj"

# External object files for target Semi8
Semi8_EXTERNAL_OBJECTS =

Semi8.exe: CMakeFiles/Semi8.dir/main.c.obj
Semi8.exe: CMakeFiles/Semi8.dir/grafo.c.obj
Semi8.exe: CMakeFiles/Semi8.dir/build.make
Semi8.exe: CMakeFiles/Semi8.dir/linklibs.rsp
Semi8.exe: CMakeFiles/Semi8.dir/objects1.rsp
Semi8.exe: CMakeFiles/Semi8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Semi8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Semi8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Semi8.dir/build: Semi8.exe

.PHONY : CMakeFiles/Semi8.dir/build

CMakeFiles/Semi8.dir/requires: CMakeFiles/Semi8.dir/main.c.obj.requires
CMakeFiles/Semi8.dir/requires: CMakeFiles/Semi8.dir/grafo.c.obj.requires

.PHONY : CMakeFiles/Semi8.dir/requires

CMakeFiles/Semi8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Semi8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Semi8.dir/clean

CMakeFiles/Semi8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\Semi8 C:\Users\gomes\CLionProjects\Semi8 C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug C:\Users\gomes\CLionProjects\Semi8\cmake-build-debug\CMakeFiles\Semi8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Semi8.dir/depend

