# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Apps\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Apps\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Files\CPP\GitHub

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Files\CPP\GitHub\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyFirstProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyFirstProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyFirstProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyFirstProgram.dir/flags.make

CMakeFiles/MyFirstProgram.dir/main.c.obj: CMakeFiles/MyFirstProgram.dir/flags.make
CMakeFiles/MyFirstProgram.dir/main.c.obj: ../main.c
CMakeFiles/MyFirstProgram.dir/main.c.obj: CMakeFiles/MyFirstProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Files\CPP\GitHub\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyFirstProgram.dir/main.c.obj"
	"D:\Apps\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyFirstProgram.dir/main.c.obj -MF CMakeFiles\MyFirstProgram.dir\main.c.obj.d -o CMakeFiles\MyFirstProgram.dir\main.c.obj -c D:\Files\CPP\GitHub\main.c

CMakeFiles/MyFirstProgram.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyFirstProgram.dir/main.c.i"
	"D:\Apps\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Files\CPP\GitHub\main.c > CMakeFiles\MyFirstProgram.dir\main.c.i

CMakeFiles/MyFirstProgram.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyFirstProgram.dir/main.c.s"
	"D:\Apps\CLion 2022.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Files\CPP\GitHub\main.c -o CMakeFiles\MyFirstProgram.dir\main.c.s

# Object files for target MyFirstProgram
MyFirstProgram_OBJECTS = \
"CMakeFiles/MyFirstProgram.dir/main.c.obj"

# External object files for target MyFirstProgram
MyFirstProgram_EXTERNAL_OBJECTS =

MyFirstProgram.exe: CMakeFiles/MyFirstProgram.dir/main.c.obj
MyFirstProgram.exe: CMakeFiles/MyFirstProgram.dir/build.make
MyFirstProgram.exe: CMakeFiles/MyFirstProgram.dir/linklibs.rsp
MyFirstProgram.exe: CMakeFiles/MyFirstProgram.dir/objects1.rsp
MyFirstProgram.exe: CMakeFiles/MyFirstProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Files\CPP\GitHub\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MyFirstProgram.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyFirstProgram.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyFirstProgram.dir/build: MyFirstProgram.exe
.PHONY : CMakeFiles/MyFirstProgram.dir/build

CMakeFiles/MyFirstProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyFirstProgram.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyFirstProgram.dir/clean

CMakeFiles/MyFirstProgram.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Files\CPP\GitHub D:\Files\CPP\GitHub D:\Files\CPP\GitHub\cmake-build-debug D:\Files\CPP\GitHub\cmake-build-debug D:\Files\CPP\GitHub\cmake-build-debug\CMakeFiles\MyFirstProgram.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyFirstProgram.dir/depend

