# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xdyun/xdyunGit/xdyunProject/HttpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xdyun/xdyunGit/xdyunProject/HttpServer/build

# Include any dependencies generated for this target.
include CMakeFiles/Pistache.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pistache.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pistache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pistache.dir/flags.make

CMakeFiles/Pistache.dir/restServer.cpp.o: CMakeFiles/Pistache.dir/flags.make
CMakeFiles/Pistache.dir/restServer.cpp.o: /home/xdyun/xdyunGit/xdyunProject/HttpServer/restServer.cpp
CMakeFiles/Pistache.dir/restServer.cpp.o: CMakeFiles/Pistache.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xdyun/xdyunGit/xdyunProject/HttpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pistache.dir/restServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pistache.dir/restServer.cpp.o -MF CMakeFiles/Pistache.dir/restServer.cpp.o.d -o CMakeFiles/Pistache.dir/restServer.cpp.o -c /home/xdyun/xdyunGit/xdyunProject/HttpServer/restServer.cpp

CMakeFiles/Pistache.dir/restServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pistache.dir/restServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xdyun/xdyunGit/xdyunProject/HttpServer/restServer.cpp > CMakeFiles/Pistache.dir/restServer.cpp.i

CMakeFiles/Pistache.dir/restServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pistache.dir/restServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xdyun/xdyunGit/xdyunProject/HttpServer/restServer.cpp -o CMakeFiles/Pistache.dir/restServer.cpp.s

CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o: CMakeFiles/Pistache.dir/flags.make
CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o: /home/xdyun/xdyunGit/xdyunProject/HttpServer/src/GetDisplayContent.cpp
CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o: CMakeFiles/Pistache.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/xdyun/xdyunGit/xdyunProject/HttpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o -MF CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o.d -o CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o -c /home/xdyun/xdyunGit/xdyunProject/HttpServer/src/GetDisplayContent.cpp

CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xdyun/xdyunGit/xdyunProject/HttpServer/src/GetDisplayContent.cpp > CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.i

CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xdyun/xdyunGit/xdyunProject/HttpServer/src/GetDisplayContent.cpp -o CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.s

# Object files for target Pistache
Pistache_OBJECTS = \
"CMakeFiles/Pistache.dir/restServer.cpp.o" \
"CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o"

# External object files for target Pistache
Pistache_EXTERNAL_OBJECTS =

Pistache: CMakeFiles/Pistache.dir/restServer.cpp.o
Pistache: CMakeFiles/Pistache.dir/src/GetDisplayContent.cpp.o
Pistache: CMakeFiles/Pistache.dir/build.make
Pistache: CMakeFiles/Pistache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/xdyun/xdyunGit/xdyunProject/HttpServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Pistache"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pistache.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pistache.dir/build: Pistache
.PHONY : CMakeFiles/Pistache.dir/build

CMakeFiles/Pistache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pistache.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pistache.dir/clean

CMakeFiles/Pistache.dir/depend:
	cd /home/xdyun/xdyunGit/xdyunProject/HttpServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xdyun/xdyunGit/xdyunProject/HttpServer /home/xdyun/xdyunGit/xdyunProject/HttpServer /home/xdyun/xdyunGit/xdyunProject/HttpServer/build /home/xdyun/xdyunGit/xdyunProject/HttpServer/build /home/xdyun/xdyunGit/xdyunProject/HttpServer/build/CMakeFiles/Pistache.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Pistache.dir/depend

