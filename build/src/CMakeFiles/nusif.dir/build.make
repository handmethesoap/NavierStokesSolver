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
include src/CMakeFiles/nusif.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/nusif.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/nusif.dir/flags.make

src/CMakeFiles/nusif.dir/FileReader.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/FileReader.cc.o: ../src/FileReader.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/FileReader.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/FileReader.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc

src/CMakeFiles/nusif.dir/FileReader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/FileReader.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc > CMakeFiles/nusif.dir/FileReader.cc.i

src/CMakeFiles/nusif.dir/FileReader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/FileReader.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FileReader.cc -o CMakeFiles/nusif.dir/FileReader.cc.s

src/CMakeFiles/nusif.dir/FileReader.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/FileReader.cc.o.requires

src/CMakeFiles/nusif.dir/FileReader.cc.o.provides: src/CMakeFiles/nusif.dir/FileReader.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/FileReader.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/FileReader.cc.o.provides

src/CMakeFiles/nusif.dir/FileReader.cc.o.provides.build: src/CMakeFiles/nusif.dir/FileReader.cc.o

src/CMakeFiles/nusif.dir/Debug.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/Debug.cc.o: ../src/Debug.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/Debug.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/Debug.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc

src/CMakeFiles/nusif.dir/Debug.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/Debug.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc > CMakeFiles/nusif.dir/Debug.cc.i

src/CMakeFiles/nusif.dir/Debug.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/Debug.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Debug.cc -o CMakeFiles/nusif.dir/Debug.cc.s

src/CMakeFiles/nusif.dir/Debug.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/Debug.cc.o.requires

src/CMakeFiles/nusif.dir/Debug.cc.o.provides: src/CMakeFiles/nusif.dir/Debug.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/Debug.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/Debug.cc.o.provides

src/CMakeFiles/nusif.dir/Debug.cc.o.provides.build: src/CMakeFiles/nusif.dir/Debug.cc.o

src/CMakeFiles/nusif.dir/Array.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/Array.cc.o: ../src/Array.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/Array.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/Array.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc

src/CMakeFiles/nusif.dir/Array.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/Array.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc > CMakeFiles/nusif.dir/Array.cc.i

src/CMakeFiles/nusif.dir/Array.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/Array.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/Array.cc -o CMakeFiles/nusif.dir/Array.cc.s

src/CMakeFiles/nusif.dir/Array.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/Array.cc.o.requires

src/CMakeFiles/nusif.dir/Array.cc.o.provides: src/CMakeFiles/nusif.dir/Array.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/Array.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/Array.cc.o.provides

src/CMakeFiles/nusif.dir/Array.cc.o.provides.build: src/CMakeFiles/nusif.dir/Array.cc.o

src/CMakeFiles/nusif.dir/main.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/main.cc.o: ../src/main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/main.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/main.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/main.cc

src/CMakeFiles/nusif.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/main.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/main.cc > CMakeFiles/nusif.dir/main.cc.i

src/CMakeFiles/nusif.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/main.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/main.cc -o CMakeFiles/nusif.dir/main.cc.s

src/CMakeFiles/nusif.dir/main.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/main.cc.o.requires

src/CMakeFiles/nusif.dir/main.cc.o.provides: src/CMakeFiles/nusif.dir/main.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/main.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/main.cc.o.provides

src/CMakeFiles/nusif.dir/main.cc.o.provides.build: src/CMakeFiles/nusif.dir/main.cc.o

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o: ../src/StaggeredGrid.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/StaggeredGrid.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/StaggeredGrid.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc > CMakeFiles/nusif.dir/StaggeredGrid.cc.i

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/StaggeredGrid.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/StaggeredGrid.cc -o CMakeFiles/nusif.dir/StaggeredGrid.cc.s

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.requires

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.provides: src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.provides

src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.provides.build: src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o

src/CMakeFiles/nusif.dir/SORSolver.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/SORSolver.cc.o: ../src/SORSolver.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/SORSolver.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/SORSolver.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc

src/CMakeFiles/nusif.dir/SORSolver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/SORSolver.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc > CMakeFiles/nusif.dir/SORSolver.cc.i

src/CMakeFiles/nusif.dir/SORSolver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/SORSolver.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/SORSolver.cc -o CMakeFiles/nusif.dir/SORSolver.cc.s

src/CMakeFiles/nusif.dir/SORSolver.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/SORSolver.cc.o.requires

src/CMakeFiles/nusif.dir/SORSolver.cc.o.provides: src/CMakeFiles/nusif.dir/SORSolver.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/SORSolver.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/SORSolver.cc.o.provides

src/CMakeFiles/nusif.dir/SORSolver.cc.o.provides.build: src/CMakeFiles/nusif.dir/SORSolver.cc.o

src/CMakeFiles/nusif.dir/FluidSimulator.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/FluidSimulator.cc.o: ../src/FluidSimulator.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/FluidSimulator.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/FluidSimulator.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FluidSimulator.cc

src/CMakeFiles/nusif.dir/FluidSimulator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/FluidSimulator.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FluidSimulator.cc > CMakeFiles/nusif.dir/FluidSimulator.cc.i

src/CMakeFiles/nusif.dir/FluidSimulator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/FluidSimulator.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/FluidSimulator.cc -o CMakeFiles/nusif.dir/FluidSimulator.cc.s

src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.requires

src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.provides: src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.provides

src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.provides.build: src/CMakeFiles/nusif.dir/FluidSimulator.cc.o

src/CMakeFiles/nusif.dir/VTKWriter.cc.o: src/CMakeFiles/nusif.dir/flags.make
src/CMakeFiles/nusif.dir/VTKWriter.cc.o: ../src/VTKWriter.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/nusif.dir/VTKWriter.cc.o"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nusif.dir/VTKWriter.cc.o -c /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/VTKWriter.cc

src/CMakeFiles/nusif.dir/VTKWriter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nusif.dir/VTKWriter.cc.i"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/VTKWriter.cc > CMakeFiles/nusif.dir/VTKWriter.cc.i

src/CMakeFiles/nusif.dir/VTKWriter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nusif.dir/VTKWriter.cc.s"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src/VTKWriter.cc -o CMakeFiles/nusif.dir/VTKWriter.cc.s

src/CMakeFiles/nusif.dir/VTKWriter.cc.o.requires:
.PHONY : src/CMakeFiles/nusif.dir/VTKWriter.cc.o.requires

src/CMakeFiles/nusif.dir/VTKWriter.cc.o.provides: src/CMakeFiles/nusif.dir/VTKWriter.cc.o.requires
	$(MAKE) -f src/CMakeFiles/nusif.dir/build.make src/CMakeFiles/nusif.dir/VTKWriter.cc.o.provides.build
.PHONY : src/CMakeFiles/nusif.dir/VTKWriter.cc.o.provides

src/CMakeFiles/nusif.dir/VTKWriter.cc.o.provides.build: src/CMakeFiles/nusif.dir/VTKWriter.cc.o

# Object files for target nusif
nusif_OBJECTS = \
"CMakeFiles/nusif.dir/FileReader.cc.o" \
"CMakeFiles/nusif.dir/Debug.cc.o" \
"CMakeFiles/nusif.dir/Array.cc.o" \
"CMakeFiles/nusif.dir/main.cc.o" \
"CMakeFiles/nusif.dir/StaggeredGrid.cc.o" \
"CMakeFiles/nusif.dir/SORSolver.cc.o" \
"CMakeFiles/nusif.dir/FluidSimulator.cc.o" \
"CMakeFiles/nusif.dir/VTKWriter.cc.o"

# External object files for target nusif
nusif_EXTERNAL_OBJECTS =

src/nusif: src/CMakeFiles/nusif.dir/FileReader.cc.o
src/nusif: src/CMakeFiles/nusif.dir/Debug.cc.o
src/nusif: src/CMakeFiles/nusif.dir/Array.cc.o
src/nusif: src/CMakeFiles/nusif.dir/main.cc.o
src/nusif: src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o
src/nusif: src/CMakeFiles/nusif.dir/SORSolver.cc.o
src/nusif: src/CMakeFiles/nusif.dir/FluidSimulator.cc.o
src/nusif: src/CMakeFiles/nusif.dir/VTKWriter.cc.o
src/nusif: src/CMakeFiles/nusif.dir/build.make
src/nusif: src/CMakeFiles/nusif.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable nusif"
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nusif.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/nusif.dir/build: src/nusif
.PHONY : src/CMakeFiles/nusif.dir/build

src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/FileReader.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/Debug.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/Array.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/main.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/StaggeredGrid.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/SORSolver.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/FluidSimulator.cc.o.requires
src/CMakeFiles/nusif.dir/requires: src/CMakeFiles/nusif.dir/VTKWriter.cc.o.requires
.PHONY : src/CMakeFiles/nusif.dir/requires

src/CMakeFiles/nusif.dir/clean:
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src && $(CMAKE_COMMAND) -P CMakeFiles/nusif.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/nusif.dir/clean

src/CMakeFiles/nusif.dir/depend:
	cd /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/src /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src /auto-home/stud/zo99vyha/Documents/NuSiF/Assignment4/NavierStokesSolver/build/src/CMakeFiles/nusif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/nusif.dir/depend

