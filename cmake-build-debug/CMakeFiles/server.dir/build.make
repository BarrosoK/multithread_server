# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/pedrito/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pedrito/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedrito/CLionProjects/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedrito/CLionProjects/server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/main.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cpp.o -c /home/pedrito/CLionProjects/server/main.cpp

CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/main.cpp > CMakeFiles/server.dir/main.cpp.i

CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/main.cpp -o CMakeFiles/server.dir/main.cpp.s

CMakeFiles/server.dir/src/Server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Server.cpp.o: ../src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/src/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/Server.cpp.o -c /home/pedrito/CLionProjects/server/src/Server.cpp

CMakeFiles/server.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/Server.cpp > CMakeFiles/server.dir/src/Server.cpp.i

CMakeFiles/server.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/Server.cpp -o CMakeFiles/server.dir/src/Server.cpp.s

CMakeFiles/server.dir/src/Client.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Client.cpp.o: ../src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/src/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/Client.cpp.o -c /home/pedrito/CLionProjects/server/src/Client.cpp

CMakeFiles/server.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/Client.cpp > CMakeFiles/server.dir/src/Client.cpp.i

CMakeFiles/server.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/Client.cpp -o CMakeFiles/server.dir/src/Client.cpp.s

CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o: ../src/handlers/ClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o -c /home/pedrito/CLionProjects/server/src/handlers/ClientHandler.cpp

CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/handlers/ClientHandler.cpp > CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.i

CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/handlers/ClientHandler.cpp -o CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.s

CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o: ../src/network/ReceivablePacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o -c /home/pedrito/CLionProjects/server/src/network/ReceivablePacket.cpp

CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/network/ReceivablePacket.cpp > CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.i

CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/network/ReceivablePacket.cpp -o CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.s

CMakeFiles/server.dir/src/network/SendablePacket.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/network/SendablePacket.cpp.o: ../src/network/SendablePacket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/src/network/SendablePacket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/network/SendablePacket.cpp.o -c /home/pedrito/CLionProjects/server/src/network/SendablePacket.cpp

CMakeFiles/server.dir/src/network/SendablePacket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/network/SendablePacket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/network/SendablePacket.cpp > CMakeFiles/server.dir/src/network/SendablePacket.cpp.i

CMakeFiles/server.dir/src/network/SendablePacket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/network/SendablePacket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/network/SendablePacket.cpp -o CMakeFiles/server.dir/src/network/SendablePacket.cpp.s

CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o: ../src/handlers/PacketHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o -c /home/pedrito/CLionProjects/server/src/handlers/PacketHandler.cpp

CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedrito/CLionProjects/server/src/handlers/PacketHandler.cpp > CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.i

CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedrito/CLionProjects/server/src/handlers/PacketHandler.cpp -o CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/main.cpp.o" \
"CMakeFiles/server.dir/src/Server.cpp.o" \
"CMakeFiles/server.dir/src/Client.cpp.o" \
"CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o" \
"CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o" \
"CMakeFiles/server.dir/src/network/SendablePacket.cpp.o" \
"CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/main.cpp.o
server: CMakeFiles/server.dir/src/Server.cpp.o
server: CMakeFiles/server.dir/src/Client.cpp.o
server: CMakeFiles/server.dir/src/handlers/ClientHandler.cpp.o
server: CMakeFiles/server.dir/src/network/ReceivablePacket.cpp.o
server: CMakeFiles/server.dir/src/network/SendablePacket.cpp.o
server: CMakeFiles/server.dir/src/handlers/PacketHandler.cpp.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/pedrito/CLionProjects/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedrito/CLionProjects/server /home/pedrito/CLionProjects/server /home/pedrito/CLionProjects/server/cmake-build-debug /home/pedrito/CLionProjects/server/cmake-build-debug /home/pedrito/CLionProjects/server/cmake-build-debug/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

