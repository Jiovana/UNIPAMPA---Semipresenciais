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
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\RevisaoLP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RevisaoLP2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RevisaoLP2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RevisaoLP2.dir/flags.make

CMakeFiles/RevisaoLP2.dir/main.c.obj: CMakeFiles/RevisaoLP2.dir/flags.make
CMakeFiles/RevisaoLP2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RevisaoLP2.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RevisaoLP2.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\RevisaoLP2\main.c

CMakeFiles/RevisaoLP2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RevisaoLP2.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\RevisaoLP2\main.c > CMakeFiles\RevisaoLP2.dir\main.c.i

CMakeFiles/RevisaoLP2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RevisaoLP2.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\RevisaoLP2\main.c -o CMakeFiles\RevisaoLP2.dir\main.c.s

CMakeFiles/RevisaoLP2.dir/main.c.obj.requires:

.PHONY : CMakeFiles/RevisaoLP2.dir/main.c.obj.requires

CMakeFiles/RevisaoLP2.dir/main.c.obj.provides: CMakeFiles/RevisaoLP2.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\RevisaoLP2.dir\build.make CMakeFiles/RevisaoLP2.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/RevisaoLP2.dir/main.c.obj.provides

CMakeFiles/RevisaoLP2.dir/main.c.obj.provides.build: CMakeFiles/RevisaoLP2.dir/main.c.obj


CMakeFiles/RevisaoLP2.dir/pilha.c.obj: CMakeFiles/RevisaoLP2.dir/flags.make
CMakeFiles/RevisaoLP2.dir/pilha.c.obj: ../pilha.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RevisaoLP2.dir/pilha.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RevisaoLP2.dir\pilha.c.obj   -c C:\Users\gomes\CLionProjects\RevisaoLP2\pilha.c

CMakeFiles/RevisaoLP2.dir/pilha.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RevisaoLP2.dir/pilha.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\RevisaoLP2\pilha.c > CMakeFiles\RevisaoLP2.dir\pilha.c.i

CMakeFiles/RevisaoLP2.dir/pilha.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RevisaoLP2.dir/pilha.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\RevisaoLP2\pilha.c -o CMakeFiles\RevisaoLP2.dir\pilha.c.s

CMakeFiles/RevisaoLP2.dir/pilha.c.obj.requires:

.PHONY : CMakeFiles/RevisaoLP2.dir/pilha.c.obj.requires

CMakeFiles/RevisaoLP2.dir/pilha.c.obj.provides: CMakeFiles/RevisaoLP2.dir/pilha.c.obj.requires
	$(MAKE) -f CMakeFiles\RevisaoLP2.dir\build.make CMakeFiles/RevisaoLP2.dir/pilha.c.obj.provides.build
.PHONY : CMakeFiles/RevisaoLP2.dir/pilha.c.obj.provides

CMakeFiles/RevisaoLP2.dir/pilha.c.obj.provides.build: CMakeFiles/RevisaoLP2.dir/pilha.c.obj


# Object files for target RevisaoLP2
RevisaoLP2_OBJECTS = \
"CMakeFiles/RevisaoLP2.dir/main.c.obj" \
"CMakeFiles/RevisaoLP2.dir/pilha.c.obj"

# External object files for target RevisaoLP2
RevisaoLP2_EXTERNAL_OBJECTS =

RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/main.c.obj
RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/pilha.c.obj
RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/build.make
RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/linklibs.rsp
RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/objects1.rsp
RevisaoLP2.exe: CMakeFiles/RevisaoLP2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable RevisaoLP2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RevisaoLP2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RevisaoLP2.dir/build: RevisaoLP2.exe

.PHONY : CMakeFiles/RevisaoLP2.dir/build

CMakeFiles/RevisaoLP2.dir/requires: CMakeFiles/RevisaoLP2.dir/main.c.obj.requires
CMakeFiles/RevisaoLP2.dir/requires: CMakeFiles/RevisaoLP2.dir/pilha.c.obj.requires

.PHONY : CMakeFiles/RevisaoLP2.dir/requires

CMakeFiles/RevisaoLP2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RevisaoLP2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RevisaoLP2.dir/clean

CMakeFiles/RevisaoLP2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\RevisaoLP2 C:\Users\gomes\CLionProjects\RevisaoLP2 C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug C:\Users\gomes\CLionProjects\RevisaoLP2\cmake-build-debug\CMakeFiles\RevisaoLP2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RevisaoLP2.dir/depend

