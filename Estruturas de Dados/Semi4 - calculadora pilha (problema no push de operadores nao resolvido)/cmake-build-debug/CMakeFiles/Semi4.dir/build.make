# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\Semi4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Semi4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Semi4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Semi4.dir/flags.make

CMakeFiles/Semi4.dir/main.c.obj: CMakeFiles/Semi4.dir/flags.make
CMakeFiles/Semi4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Semi4.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi4.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\Semi4\main.c

CMakeFiles/Semi4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi4.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi4\main.c > CMakeFiles\Semi4.dir\main.c.i

CMakeFiles/Semi4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi4.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi4\main.c -o CMakeFiles\Semi4.dir\main.c.s

CMakeFiles/Semi4.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Semi4.dir/main.c.obj.requires

CMakeFiles/Semi4.dir/main.c.obj.provides: CMakeFiles/Semi4.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi4.dir\build.make CMakeFiles/Semi4.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Semi4.dir/main.c.obj.provides

CMakeFiles/Semi4.dir/main.c.obj.provides.build: CMakeFiles/Semi4.dir/main.c.obj


CMakeFiles/Semi4.dir/calculadora.c.obj: CMakeFiles/Semi4.dir/flags.make
CMakeFiles/Semi4.dir/calculadora.c.obj: ../calculadora.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Semi4.dir/calculadora.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Semi4.dir\calculadora.c.obj   -c C:\Users\gomes\CLionProjects\Semi4\calculadora.c

CMakeFiles/Semi4.dir/calculadora.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Semi4.dir/calculadora.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\Semi4\calculadora.c > CMakeFiles\Semi4.dir\calculadora.c.i

CMakeFiles/Semi4.dir/calculadora.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Semi4.dir/calculadora.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\Semi4\calculadora.c -o CMakeFiles\Semi4.dir\calculadora.c.s

CMakeFiles/Semi4.dir/calculadora.c.obj.requires:

.PHONY : CMakeFiles/Semi4.dir/calculadora.c.obj.requires

CMakeFiles/Semi4.dir/calculadora.c.obj.provides: CMakeFiles/Semi4.dir/calculadora.c.obj.requires
	$(MAKE) -f CMakeFiles\Semi4.dir\build.make CMakeFiles/Semi4.dir/calculadora.c.obj.provides.build
.PHONY : CMakeFiles/Semi4.dir/calculadora.c.obj.provides

CMakeFiles/Semi4.dir/calculadora.c.obj.provides.build: CMakeFiles/Semi4.dir/calculadora.c.obj


# Object files for target Semi4
Semi4_OBJECTS = \
"CMakeFiles/Semi4.dir/main.c.obj" \
"CMakeFiles/Semi4.dir/calculadora.c.obj"

# External object files for target Semi4
Semi4_EXTERNAL_OBJECTS =

Semi4.exe: CMakeFiles/Semi4.dir/main.c.obj
Semi4.exe: CMakeFiles/Semi4.dir/calculadora.c.obj
Semi4.exe: CMakeFiles/Semi4.dir/build.make
Semi4.exe: CMakeFiles/Semi4.dir/linklibs.rsp
Semi4.exe: CMakeFiles/Semi4.dir/objects1.rsp
Semi4.exe: CMakeFiles/Semi4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Semi4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Semi4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Semi4.dir/build: Semi4.exe

.PHONY : CMakeFiles/Semi4.dir/build

CMakeFiles/Semi4.dir/requires: CMakeFiles/Semi4.dir/main.c.obj.requires
CMakeFiles/Semi4.dir/requires: CMakeFiles/Semi4.dir/calculadora.c.obj.requires

.PHONY : CMakeFiles/Semi4.dir/requires

CMakeFiles/Semi4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Semi4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Semi4.dir/clean

CMakeFiles/Semi4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\Semi4 C:\Users\gomes\CLionProjects\Semi4 C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug C:\Users\gomes\CLionProjects\Semi4\cmake-build-debug\CMakeFiles\Semi4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Semi4.dir/depend
