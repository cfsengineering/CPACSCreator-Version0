# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cfse/Stage_Malo/CPACSCreatorTotal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build

# Utility rule file for checkstyle_TIGLViewer.

# Include the progress variables for this target.
include TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/progress.make

TIGLViewer/CMakeFiles/checkstyle_TIGLViewer: TIGLViewer/TIGLViewer_checkstyle-report


TIGLViewer/TIGLViewer_checkstyle-report: /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/filefilter.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating TIGLViewer_checkstyle-report"
	/usr/bin/python /home/cfse/Stage_Malo/CPACSCreatorTotal/thirdparty/nsiqcppstyle/nsiqcppstyle.py -o /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer

/home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/filefilter.txt:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/filefilter.txt"
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer && /users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/bin/cmake -E copy /home/cfse/Stage_Malo/CPACSCreatorTotal/thirdparty/nsiqcppstyle/filefilter.txt /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/

checkstyle_TIGLViewer: TIGLViewer/CMakeFiles/checkstyle_TIGLViewer
checkstyle_TIGLViewer: TIGLViewer/TIGLViewer_checkstyle-report
checkstyle_TIGLViewer: /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/filefilter.txt
checkstyle_TIGLViewer: TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/build.make

.PHONY : checkstyle_TIGLViewer

# Rule to build all files generated by this target.
TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/build: checkstyle_TIGLViewer

.PHONY : TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/build

TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/clean:
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer && $(CMAKE_COMMAND) -P CMakeFiles/checkstyle_TIGLViewer.dir/cmake_clean.cmake
.PHONY : TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/clean

TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/depend:
	cd /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cfse/Stage_Malo/CPACSCreatorTotal /home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TIGLViewer/CMakeFiles/checkstyle_TIGLViewer.dir/depend

