# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Pico\pico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Pico\pico\build

# Include any dependencies generated for this target.
include CMakeFiles\kiss_fft.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\kiss_fft.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\kiss_fft.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\kiss_fft.dir\flags.make

CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj: CMakeFiles\kiss_fft.dir\flags.make
CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj: ..\src\kiss_fft\kiss_fft.c
CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj: CMakeFiles\kiss_fft.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Pico\pico\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/kiss_fft.dir/src/kiss_fft/kiss_fft.c.obj"
	C:\PROGRA~2\GNUARM~1\102020~1\bin\AR19DD~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj -MF CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj.d -o CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj -c C:\Pico\pico\src\kiss_fft\kiss_fft.c

CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kiss_fft.dir/src/kiss_fft/kiss_fft.c.i"
	C:\PROGRA~2\GNUARM~1\102020~1\bin\AR19DD~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Pico\pico\src\kiss_fft\kiss_fft.c > CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.i

CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kiss_fft.dir/src/kiss_fft/kiss_fft.c.s"
	C:\PROGRA~2\GNUARM~1\102020~1\bin\AR19DD~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Pico\pico\src\kiss_fft\kiss_fft.c -o CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.s

# Object files for target kiss_fft
kiss_fft_OBJECTS = \
"CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj"

# External object files for target kiss_fft
kiss_fft_EXTERNAL_OBJECTS =

libkiss_fft.a: CMakeFiles\kiss_fft.dir\src\kiss_fft\kiss_fft.c.obj
libkiss_fft.a: CMakeFiles\kiss_fft.dir\build.make
libkiss_fft.a: CMakeFiles\kiss_fft.dir\link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Pico\pico\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libkiss_fft.a"
	$(CMAKE_COMMAND) -P CMakeFiles\kiss_fft.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kiss_fft.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles\kiss_fft.dir\build: libkiss_fft.a
.PHONY : CMakeFiles\kiss_fft.dir\build

CMakeFiles\kiss_fft.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kiss_fft.dir\cmake_clean.cmake
.PHONY : CMakeFiles\kiss_fft.dir\clean

CMakeFiles\kiss_fft.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Pico\pico C:\Pico\pico C:\Pico\pico\build C:\Pico\pico\build C:\Pico\pico\build\CMakeFiles\kiss_fft.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\kiss_fft.dir\depend

