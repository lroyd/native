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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lroyd/ndk/workspace/native

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lroyd/ndk/workspace/native/build

# Include any dependencies generated for this target.
include CMakeFiles/NativeJNI_CPP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NativeJNI_CPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NativeJNI_CPP.dir/flags.make

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o: CMakeFiles/NativeJNI_CPP.dir/flags.make
CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o: ../jni/native_cpp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lroyd/ndk/workspace/native/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o"
	/home/lroyd/my_ndk_toolchain/4.4/bin/arm-linux-androideabi-g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o -c /home/lroyd/ndk/workspace/native/jni/native_cpp.cpp

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.i"
	/home/lroyd/my_ndk_toolchain/4.4/bin/arm-linux-androideabi-g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lroyd/ndk/workspace/native/jni/native_cpp.cpp > CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.i

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.s"
	/home/lroyd/my_ndk_toolchain/4.4/bin/arm-linux-androideabi-g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lroyd/ndk/workspace/native/jni/native_cpp.cpp -o CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.s

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.requires:
.PHONY : CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.requires

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.provides: CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.requires
	$(MAKE) -f CMakeFiles/NativeJNI_CPP.dir/build.make CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.provides.build
.PHONY : CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.provides

CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.provides.build: CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o

# Object files for target NativeJNI_CPP
NativeJNI_CPP_OBJECTS = \
"CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o"

# External object files for target NativeJNI_CPP
NativeJNI_CPP_EXTERNAL_OBJECTS =

libNativeJNI_CPP.so: CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o
libNativeJNI_CPP.so: CMakeFiles/NativeJNI_CPP.dir/build.make
libNativeJNI_CPP.so: CMakeFiles/NativeJNI_CPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libNativeJNI_CPP.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NativeJNI_CPP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NativeJNI_CPP.dir/build: libNativeJNI_CPP.so
.PHONY : CMakeFiles/NativeJNI_CPP.dir/build

CMakeFiles/NativeJNI_CPP.dir/requires: CMakeFiles/NativeJNI_CPP.dir/jni/native_cpp.cpp.o.requires
.PHONY : CMakeFiles/NativeJNI_CPP.dir/requires

CMakeFiles/NativeJNI_CPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NativeJNI_CPP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NativeJNI_CPP.dir/clean

CMakeFiles/NativeJNI_CPP.dir/depend:
	cd /home/lroyd/ndk/workspace/native/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lroyd/ndk/workspace/native /home/lroyd/ndk/workspace/native /home/lroyd/ndk/workspace/native/build /home/lroyd/ndk/workspace/native/build /home/lroyd/ndk/workspace/native/build/CMakeFiles/NativeJNI_CPP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NativeJNI_CPP.dir/depend

