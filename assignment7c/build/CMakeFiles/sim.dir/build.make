# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/karen/apps/geant4/ne697-geant4/assignment7c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karen/apps/geant4/ne697-geant4/assignment7c/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/src/actioninitialization.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/actioninitialization.cpp.o: ../src/actioninitialization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/src/actioninitialization.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/actioninitialization.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/actioninitialization.cpp

CMakeFiles/sim.dir/src/actioninitialization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/actioninitialization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/actioninitialization.cpp > CMakeFiles/sim.dir/src/actioninitialization.cpp.i

CMakeFiles/sim.dir/src/actioninitialization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/actioninitialization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/actioninitialization.cpp -o CMakeFiles/sim.dir/src/actioninitialization.cpp.s

CMakeFiles/sim.dir/src/detectorconstruction.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/detectorconstruction.cpp.o: ../src/detectorconstruction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/src/detectorconstruction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/detectorconstruction.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/detectorconstruction.cpp

CMakeFiles/sim.dir/src/detectorconstruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/detectorconstruction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/detectorconstruction.cpp > CMakeFiles/sim.dir/src/detectorconstruction.cpp.i

CMakeFiles/sim.dir/src/detectorconstruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/detectorconstruction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/detectorconstruction.cpp -o CMakeFiles/sim.dir/src/detectorconstruction.cpp.s

CMakeFiles/sim.dir/src/eventaction.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/eventaction.cpp.o: ../src/eventaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/src/eventaction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/eventaction.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/eventaction.cpp

CMakeFiles/sim.dir/src/eventaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/eventaction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/eventaction.cpp > CMakeFiles/sim.dir/src/eventaction.cpp.i

CMakeFiles/sim.dir/src/eventaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/eventaction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/eventaction.cpp -o CMakeFiles/sim.dir/src/eventaction.cpp.s

CMakeFiles/sim.dir/src/geometrymessenger.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/geometrymessenger.cpp.o: ../src/geometrymessenger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/src/geometrymessenger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/geometrymessenger.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/geometrymessenger.cpp

CMakeFiles/sim.dir/src/geometrymessenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/geometrymessenger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/geometrymessenger.cpp > CMakeFiles/sim.dir/src/geometrymessenger.cpp.i

CMakeFiles/sim.dir/src/geometrymessenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/geometrymessenger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/geometrymessenger.cpp -o CMakeFiles/sim.dir/src/geometrymessenger.cpp.s

CMakeFiles/sim.dir/src/hit.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/hit.cpp.o: ../src/hit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/src/hit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/hit.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/hit.cpp

CMakeFiles/sim.dir/src/hit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/hit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/hit.cpp > CMakeFiles/sim.dir/src/hit.cpp.i

CMakeFiles/sim.dir/src/hit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/hit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/hit.cpp -o CMakeFiles/sim.dir/src/hit.cpp.s

CMakeFiles/sim.dir/src/main.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sim.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/main.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/main.cpp

CMakeFiles/sim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/main.cpp > CMakeFiles/sim.dir/src/main.cpp.i

CMakeFiles/sim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/main.cpp -o CMakeFiles/sim.dir/src/main.cpp.s

CMakeFiles/sim.dir/src/pga.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/pga.cpp.o: ../src/pga.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sim.dir/src/pga.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/pga.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/pga.cpp

CMakeFiles/sim.dir/src/pga.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/pga.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/pga.cpp > CMakeFiles/sim.dir/src/pga.cpp.i

CMakeFiles/sim.dir/src/pga.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/pga.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/pga.cpp -o CMakeFiles/sim.dir/src/pga.cpp.s

CMakeFiles/sim.dir/src/run.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/run.cpp.o: ../src/run.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sim.dir/src/run.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/run.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/run.cpp

CMakeFiles/sim.dir/src/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/run.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/run.cpp > CMakeFiles/sim.dir/src/run.cpp.i

CMakeFiles/sim.dir/src/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/run.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/run.cpp -o CMakeFiles/sim.dir/src/run.cpp.s

CMakeFiles/sim.dir/src/runaction.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/runaction.cpp.o: ../src/runaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sim.dir/src/runaction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/runaction.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runaction.cpp

CMakeFiles/sim.dir/src/runaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/runaction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runaction.cpp > CMakeFiles/sim.dir/src/runaction.cpp.i

CMakeFiles/sim.dir/src/runaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/runaction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runaction.cpp -o CMakeFiles/sim.dir/src/runaction.cpp.s

CMakeFiles/sim.dir/src/runmessenger.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/runmessenger.cpp.o: ../src/runmessenger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sim.dir/src/runmessenger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/runmessenger.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runmessenger.cpp

CMakeFiles/sim.dir/src/runmessenger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/runmessenger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runmessenger.cpp > CMakeFiles/sim.dir/src/runmessenger.cpp.i

CMakeFiles/sim.dir/src/runmessenger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/runmessenger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/runmessenger.cpp -o CMakeFiles/sim.dir/src/runmessenger.cpp.s

CMakeFiles/sim.dir/src/sensitivedetector.cpp.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/src/sensitivedetector.cpp.o: ../src/sensitivedetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sim.dir/src/sensitivedetector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim.dir/src/sensitivedetector.cpp.o -c /home/karen/apps/geant4/ne697-geant4/assignment7c/src/sensitivedetector.cpp

CMakeFiles/sim.dir/src/sensitivedetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim.dir/src/sensitivedetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karen/apps/geant4/ne697-geant4/assignment7c/src/sensitivedetector.cpp > CMakeFiles/sim.dir/src/sensitivedetector.cpp.i

CMakeFiles/sim.dir/src/sensitivedetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim.dir/src/sensitivedetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karen/apps/geant4/ne697-geant4/assignment7c/src/sensitivedetector.cpp -o CMakeFiles/sim.dir/src/sensitivedetector.cpp.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/src/actioninitialization.cpp.o" \
"CMakeFiles/sim.dir/src/detectorconstruction.cpp.o" \
"CMakeFiles/sim.dir/src/eventaction.cpp.o" \
"CMakeFiles/sim.dir/src/geometrymessenger.cpp.o" \
"CMakeFiles/sim.dir/src/hit.cpp.o" \
"CMakeFiles/sim.dir/src/main.cpp.o" \
"CMakeFiles/sim.dir/src/pga.cpp.o" \
"CMakeFiles/sim.dir/src/run.cpp.o" \
"CMakeFiles/sim.dir/src/runaction.cpp.o" \
"CMakeFiles/sim.dir/src/runmessenger.cpp.o" \
"CMakeFiles/sim.dir/src/sensitivedetector.cpp.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/src/actioninitialization.cpp.o
sim: CMakeFiles/sim.dir/src/detectorconstruction.cpp.o
sim: CMakeFiles/sim.dir/src/eventaction.cpp.o
sim: CMakeFiles/sim.dir/src/geometrymessenger.cpp.o
sim: CMakeFiles/sim.dir/src/hit.cpp.o
sim: CMakeFiles/sim.dir/src/main.cpp.o
sim: CMakeFiles/sim.dir/src/pga.cpp.o
sim: CMakeFiles/sim.dir/src/run.cpp.o
sim: CMakeFiles/sim.dir/src/runaction.cpp.o
sim: CMakeFiles/sim.dir/src/runmessenger.cpp.o
sim: CMakeFiles/sim.dir/src/sensitivedetector.cpp.o
sim: CMakeFiles/sim.dir/build.make
sim: /home/karen/apps/geant4/lib/libG4Tree.so
sim: /home/karen/apps/geant4/lib/libG4FR.so
sim: /home/karen/apps/geant4/lib/libG4GMocren.so
sim: /home/karen/apps/geant4/lib/libG4visHepRep.so
sim: /home/karen/apps/geant4/lib/libG4RayTracer.so
sim: /home/karen/apps/geant4/lib/libG4VRML.so
sim: /home/karen/apps/geant4/lib/libG4OpenGL.so
sim: /home/karen/apps/geant4/lib/libG4gl2ps.so
sim: /home/karen/apps/geant4/lib/libG4vis_management.so
sim: /home/karen/apps/geant4/lib/libG4modeling.so
sim: /home/karen/apps/geant4/lib/libG4interfaces.so
sim: /home/karen/apps/geant4/lib/libG4persistency.so
sim: /home/karen/apps/geant4/lib/libG4error_propagation.so
sim: /home/karen/apps/geant4/lib/libG4readout.so
sim: /home/karen/apps/geant4/lib/libG4physicslists.so
sim: /home/karen/apps/geant4/lib/libG4tasking.so
sim: /home/karen/apps/geant4/lib/libG4parmodels.so
sim: /usr/lib/x86_64-linux-gnu/libGL.so
sim: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
sim: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
sim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
sim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
sim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
sim: /home/karen/apps/geant4/lib/libG4run.so
sim: /home/karen/apps/geant4/lib/libG4event.so
sim: /home/karen/apps/geant4/lib/libG4tracking.so
sim: /home/karen/apps/geant4/lib/libG4processes.so
sim: /home/karen/apps/geant4/lib/libG4analysis.so
sim: /home/karen/apps/geant4/lib/libG4expat.so
sim: /home/karen/apps/geant4/lib/libG4digits_hits.so
sim: /home/karen/apps/geant4/lib/libG4track.so
sim: /home/karen/apps/geant4/lib/libG4particles.so
sim: /home/karen/apps/geant4/lib/libG4geometry.so
sim: /home/karen/apps/geant4/lib/libG4materials.so
sim: /home/karen/apps/geant4/lib/libG4zlib.so
sim: /home/karen/apps/geant4/lib/libG4graphics_reps.so
sim: /home/karen/apps/geant4/lib/libG4intercoms.so
sim: /home/karen/apps/geant4/lib/libG4global.so
sim: /home/karen/apps/geant4/lib/libG4clhep.so
sim: /home/karen/apps/geant4/lib/libG4ptl.so.0.0.2
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable sim"
	/usr/bin/cmake -E copy_directory /home/karen/apps/geant4/ne697-geant4/assignment7c/scripts /home/karen/apps/geant4/ne697-geant4/assignment7c/build/scripts
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim

.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/karen/apps/geant4/ne697-geant4/assignment7c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karen/apps/geant4/ne697-geant4/assignment7c /home/karen/apps/geant4/ne697-geant4/assignment7c /home/karen/apps/geant4/ne697-geant4/assignment7c/build /home/karen/apps/geant4/ne697-geant4/assignment7c/build /home/karen/apps/geant4/ne697-geant4/assignment7c/build/CMakeFiles/sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sim.dir/depend

