# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/sor_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/sor_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/sor_test.dir/flags.make

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o: ../src/SORSolver.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/__/src/SORSolver.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc > CMakeFiles/sor_test.dir/__/src/SORSolver.cc.i

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/__/src/SORSolver.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc -o CMakeFiles/sor_test.dir/__/src/SORSolver.cc.s

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.requires

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.provides: tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.provides

tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o: ../src/StaggeredGrid.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc > CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.i

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc -o CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.s

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.requires

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.provides: tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.provides

tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o: ../src/Array.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/__/src/Array.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/__/src/Array.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc > CMakeFiles/sor_test.dir/__/src/Array.cc.i

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/__/src/Array.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc -o CMakeFiles/sor_test.dir/__/src/Array.cc.s

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.requires

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.provides: tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.provides

tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o: ../src/FileReader.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/__/src/FileReader.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/__/src/FileReader.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc > CMakeFiles/sor_test.dir/__/src/FileReader.cc.i

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/__/src/FileReader.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc -o CMakeFiles/sor_test.dir/__/src/FileReader.cc.s

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.requires

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.provides: tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.provides

tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o: ../src/Debug.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/__/src/Debug.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/__/src/Debug.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc > CMakeFiles/sor_test.dir/__/src/Debug.cc.i

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/__/src/Debug.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc -o CMakeFiles/sor_test.dir/__/src/Debug.cc.s

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.requires

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.provides: tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.provides

tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o

tests/CMakeFiles/sor_test.dir/SORTest.cc.o: tests/CMakeFiles/sor_test.dir/flags.make
tests/CMakeFiles/sor_test.dir/SORTest.cc.o: ../tests/SORTest.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/CMakeFiles/sor_test.dir/SORTest.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sor_test.dir/SORTest.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/tests/SORTest.cc

tests/CMakeFiles/sor_test.dir/SORTest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sor_test.dir/SORTest.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/tests/SORTest.cc > CMakeFiles/sor_test.dir/SORTest.cc.i

tests/CMakeFiles/sor_test.dir/SORTest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sor_test.dir/SORTest.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/tests/SORTest.cc -o CMakeFiles/sor_test.dir/SORTest.cc.s

tests/CMakeFiles/sor_test.dir/SORTest.cc.o.requires:
.PHONY : tests/CMakeFiles/sor_test.dir/SORTest.cc.o.requires

tests/CMakeFiles/sor_test.dir/SORTest.cc.o.provides: tests/CMakeFiles/sor_test.dir/SORTest.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/sor_test.dir/build.make tests/CMakeFiles/sor_test.dir/SORTest.cc.o.provides.build
.PHONY : tests/CMakeFiles/sor_test.dir/SORTest.cc.o.provides

tests/CMakeFiles/sor_test.dir/SORTest.cc.o.provides.build: tests/CMakeFiles/sor_test.dir/SORTest.cc.o

# Object files for target sor_test
sor_test_OBJECTS = \
"CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o" \
"CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o" \
"CMakeFiles/sor_test.dir/__/src/Array.cc.o" \
"CMakeFiles/sor_test.dir/__/src/FileReader.cc.o" \
"CMakeFiles/sor_test.dir/__/src/Debug.cc.o" \
"CMakeFiles/sor_test.dir/SORTest.cc.o"

# External object files for target sor_test
sor_test_EXTERNAL_OBJECTS =

tests/sor_test: tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/SORTest.cc.o
tests/sor_test: tests/CMakeFiles/sor_test.dir/build.make
tests/sor_test: tests/CMakeFiles/sor_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sor_test"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sor_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/sor_test.dir/build: tests/sor_test
.PHONY : tests/CMakeFiles/sor_test.dir/build

tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/__/src/SORSolver.cc.o.requires
tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/__/src/StaggeredGrid.cc.o.requires
tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/__/src/Array.cc.o.requires
tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/__/src/FileReader.cc.o.requires
tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/__/src/Debug.cc.o.requires
tests/CMakeFiles/sor_test.dir/requires: tests/CMakeFiles/sor_test.dir/SORTest.cc.o.requires
.PHONY : tests/CMakeFiles/sor_test.dir/requires

tests/CMakeFiles/sor_test.dir/clean:
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/sor_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/sor_test.dir/clean

tests/CMakeFiles/sor_test.dir/depend:
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/tests /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/tests/CMakeFiles/sor_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/sor_test.dir/depend
