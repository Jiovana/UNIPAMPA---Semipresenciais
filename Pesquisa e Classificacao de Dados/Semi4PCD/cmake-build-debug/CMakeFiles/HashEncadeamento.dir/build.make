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
CMAKE_SOURCE_DIR = C:\Users\gomes\CLionProjects\HashEncadeamento

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HashEncadeamento.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HashEncadeamento.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HashEncadeamento.dir/flags.make

CMakeFiles/HashEncadeamento.dir/main.c.obj: CMakeFiles/HashEncadeamento.dir/flags.make
CMakeFiles/HashEncadeamento.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HashEncadeamento.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HashEncadeamento.dir\main.c.obj   -c C:\Users\gomes\CLionProjects\HashEncadeamento\main.c

CMakeFiles/HashEncadeamento.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HashEncadeamento.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\HashEncadeamento\main.c > CMakeFiles\HashEncadeamento.dir\main.c.i

CMakeFiles/HashEncadeamento.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HashEncadeamento.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\HashEncadeamento\main.c -o CMakeFiles\HashEncadeamento.dir\main.c.s

CMakeFiles/HashEncadeamento.dir/main.c.obj.requires:

.PHONY : CMakeFiles/HashEncadeamento.dir/main.c.obj.requires

CMakeFiles/HashEncadeamento.dir/main.c.obj.provides: CMakeFiles/HashEncadeamento.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\HashEncadeamento.dir\build.make CMakeFiles/HashEncadeamento.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/HashEncadeamento.dir/main.c.obj.provides

CMakeFiles/HashEncadeamento.dir/main.c.obj.provides.build: CMakeFiles/HashEncadeamento.dir/main.c.obj


CMakeFiles/HashEncadeamento.dir/hash.c.obj: CMakeFiles/HashEncadeamento.dir/flags.make
CMakeFiles/HashEncadeamento.dir/hash.c.obj: ../hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HashEncadeamento.dir/hash.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HashEncadeamento.dir\hash.c.obj   -c C:\Users\gomes\CLionProjects\HashEncadeamento\hash.c

CMakeFiles/HashEncadeamento.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HashEncadeamento.dir/hash.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\gomes\CLionProjects\HashEncadeamento\hash.c > CMakeFiles\HashEncadeamento.dir\hash.c.i

CMakeFiles/HashEncadeamento.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HashEncadeamento.dir/hash.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\gomes\CLionProjects\HashEncadeamento\hash.c -o CMakeFiles\HashEncadeamento.dir\hash.c.s

CMakeFiles/HashEncadeamento.dir/hash.c.obj.requires:

.PHONY : CMakeFiles/HashEncadeamento.dir/hash.c.obj.requires

CMakeFiles/HashEncadeamento.dir/hash.c.obj.provides: CMakeFiles/HashEncadeamento.dir/hash.c.obj.requires
	$(MAKE) -f CMakeFiles\HashEncadeamento.dir\build.make CMakeFiles/HashEncadeamento.dir/hash.c.obj.provides.build
.PHONY : CMakeFiles/HashEncadeamento.dir/hash.c.obj.provides

CMakeFiles/HashEncadeamento.dir/hash.c.obj.provides.build: CMakeFiles/HashEncadeamento.dir/hash.c.obj


# Object files for target HashEncadeamento
HashEncadeamento_OBJECTS = \
"CMakeFiles/HashEncadeamento.dir/main.c.obj" \
"CMakeFiles/HashEncadeamento.dir/hash.c.obj"

# External object files for target HashEncadeamento
HashEncadeamento_EXTERNAL_OBJECTS =

HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/main.c.obj
HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/hash.c.obj
HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/build.make
HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/linklibs.rsp
HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/objects1.rsp
HashEncadeamento.exe: CMakeFiles/HashEncadeamento.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable HashEncadeamento.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HashEncadeamento.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HashEncadeamento.dir/build: HashEncadeamento.exe

.PHONY : CMakeFiles/HashEncadeamento.dir/build

CMakeFiles/HashEncadeamento.dir/requires: CMakeFiles/HashEncadeamento.dir/main.c.obj.requires
CMakeFiles/HashEncadeamento.dir/requires: CMakeFiles/HashEncadeamento.dir/hash.c.obj.requires

.PHONY : CMakeFiles/HashEncadeamento.dir/requires

CMakeFiles/HashEncadeamento.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HashEncadeamento.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HashEncadeamento.dir/clean

CMakeFiles/HashEncadeamento.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gomes\CLionProjects\HashEncadeamento C:\Users\gomes\CLionProjects\HashEncadeamento C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug C:\Users\gomes\CLionProjects\HashEncadeamento\cmake-build-debug\CMakeFiles\HashEncadeamento.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HashEncadeamento.dir/depend

