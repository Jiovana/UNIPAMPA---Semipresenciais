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
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\Semi5-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Semi5_b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Semi5_b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Semi5_b.dir/flags.make

CMakeFiles/Semi5_b.dir/main.c.obj: CMakeFiles/Semi5_b.dir/flags.make
CMakeFiles/Semi5_b.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Semi5_b.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi5_b.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\Semi5-2\main.c

CMakeFiles/Semi5_b.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi5_b.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi5-2\main.c > CMakeFiles\Semi5_b.dir\main.c.i

CMakeFiles/Semi5_b.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi5_b.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi5-2\main.c -o CMakeFiles\Semi5_b.dir\main.c.s

CMakeFiles/Semi5_b.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Semi5_b.dir/main.c.obj.requires

CMakeFiles/Semi5_b.dir/main.c.obj.provides: CMakeFiles/Semi5_b.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi5_b.dir\build.make CMakeFiles/Semi5_b.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Semi5_b.dir/main.c.obj.provides

CMakeFiles/Semi5_b.dir/main.c.obj.provides.build: CMakeFiles/Semi5_b.dir/main.c.obj


CMakeFiles/Semi5_b.dir/fila.c.obj: CMakeFiles/Semi5_b.dir/flags.make
CMakeFiles/Semi5_b.dir/fila.c.obj: ../fila.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Semi5_b.dir/fila.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi5_b.dir\fila.c.obj   -c C:\Users\gomes\CLionProjects\Semi5-2\fila.c

CMakeFiles/Semi5_b.dir/fila.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi5_b.dir/fila.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi5-2\fila.c > CMakeFiles\Semi5_b.dir\fila.c.i

CMakeFiles/Semi5_b.dir/fila.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi5_b.dir/fila.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi5-2\fila.c -o CMakeFiles\Semi5_b.dir\fila.c.s

CMakeFiles/Semi5_b.dir/fila.c.obj.requires:

.PHONY : CMakeFiles/Semi5_b.dir/fila.c.obj.requires

CMakeFiles/Semi5_b.dir/fila.c.obj.provides: CMakeFiles/Semi5_b.dir/fila.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi5_b.dir\build.make CMakeFiles/Semi5_b.dir/fila.c.obj.provides.build
.PHONY : CMakeFiles/Semi5_b.dir/fila.c.obj.provides

CMakeFiles/Semi5_b.dir/fila.c.obj.provides.build: CMakeFiles/Semi5_b.dir/fila.c.obj


# Object files for target Semi5_b
Semi5_b_OBJECTS = \
"CMakeFiles/Semi5_b.dir/main.c.obj" \
"CMakeFiles/Semi5_b.dir/fila.c.obj"

# External object files for target Semi5_b
Semi5_b_EXTERNAL_OBJECTS =

Semi5_b.exe: CMakeFiles/Semi5_b.dir/main.c.obj
Semi5_b.exe: CMakeFiles/Semi5_b.dir/fila.c.obj
Semi5_b.exe: CMakeFiles/Semi5_b.dir/build.make
Semi5_b.exe: CMakeFiles/Semi5_b.dir/linklibs.rsp
Semi5_b.exe: CMakeFiles/Semi5_b.dir/objects1.rsp
Semi5_b.exe: CMakeFiles/Semi5_b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Semi5_b.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Semi5_b.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Semi5_b.dir/build: Semi5_b.exe

.PHONY : CMakeFiles/Semi5_b.dir/build

CMakeFiles/Semi5_b.dir/requires: CMakeFiles/Semi5_b.dir/main.c.obj.requires
CMakeFiles/Semi5_b.dir/requires: CMakeFiles/Semi5_b.dir/fila.c.obj.requires

.PHONY : CMakeFiles/Semi5_b.dir/requires

CMakeFiles/Semi5_b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Semi5_b.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Semi5_b.dir/clean

CMakeFiles/Semi5_b.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\Semi5-2 C:\Users\gomes\CLionProjects\Semi5-2 C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug C:\Users\gomes\CLionProjects\Semi5-2\cmake-build-debug\CMakeFiles\Semi5_b.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Semi5_b.dir/depend
