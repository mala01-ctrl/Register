# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Software\RegisterQt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Software\RegisterQt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RegisterQt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RegisterQt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RegisterQt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RegisterQt.dir/flags.make

RegisterQt_autogen/timestamp: C:/Qt/6.8.1/mingw_64/bin/moc.exe
RegisterQt_autogen/timestamp: C:/Qt/6.8.1/mingw_64/bin/uic.exe
RegisterQt_autogen/timestamp: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target RegisterQt"
	"C:\Program Files\JetBrains\CLion 2024.3.1\bin\cmake\win\x64\bin\cmake.exe" -E cmake_autogen C:/Software/RegisterQt/cmake-build-debug/CMakeFiles/RegisterQt_autogen.dir/AutogenInfo.json Debug
	"C:\Program Files\JetBrains\CLion 2024.3.1\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Software/RegisterQt/cmake-build-debug/RegisterQt_autogen/timestamp

CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj: CMakeFiles/RegisterQt.dir/flags.make
CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj: CMakeFiles/RegisterQt.dir/includes_CXX.rsp
CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj: RegisterQt_autogen/mocs_compilation.cpp
CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\RegisterQt.dir\RegisterQt_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\RegisterQt.dir\RegisterQt_autogen\mocs_compilation.cpp.obj -c C:\Software\RegisterQt\cmake-build-debug\RegisterQt_autogen\mocs_compilation.cpp

CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Software\RegisterQt\cmake-build-debug\RegisterQt_autogen\mocs_compilation.cpp > CMakeFiles\RegisterQt.dir\RegisterQt_autogen\mocs_compilation.cpp.i

CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Software\RegisterQt\cmake-build-debug\RegisterQt_autogen\mocs_compilation.cpp -o CMakeFiles\RegisterQt.dir\RegisterQt_autogen\mocs_compilation.cpp.s

CMakeFiles/RegisterQt.dir/main.cpp.obj: CMakeFiles/RegisterQt.dir/flags.make
CMakeFiles/RegisterQt.dir/main.cpp.obj: CMakeFiles/RegisterQt.dir/includes_CXX.rsp
CMakeFiles/RegisterQt.dir/main.cpp.obj: C:/Software/RegisterQt/main.cpp
CMakeFiles/RegisterQt.dir/main.cpp.obj: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RegisterQt.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RegisterQt.dir/main.cpp.obj -MF CMakeFiles\RegisterQt.dir\main.cpp.obj.d -o CMakeFiles\RegisterQt.dir\main.cpp.obj -c C:\Software\RegisterQt\main.cpp

CMakeFiles/RegisterQt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RegisterQt.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Software\RegisterQt\main.cpp > CMakeFiles\RegisterQt.dir\main.cpp.i

CMakeFiles/RegisterQt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RegisterQt.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Software\RegisterQt\main.cpp -o CMakeFiles\RegisterQt.dir\main.cpp.s

CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj: CMakeFiles/RegisterQt.dir/flags.make
CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj: CMakeFiles/RegisterQt.dir/includes_CXX.rsp
CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj: C:/Software/RegisterQt/mainwindow.cpp
CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj -MF CMakeFiles\RegisterQt.dir\mainwindow.cpp.obj.d -o CMakeFiles\RegisterQt.dir\mainwindow.cpp.obj -c C:\Software\RegisterQt\mainwindow.cpp

CMakeFiles/RegisterQt.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RegisterQt.dir/mainwindow.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Software\RegisterQt\mainwindow.cpp > CMakeFiles\RegisterQt.dir\mainwindow.cpp.i

CMakeFiles/RegisterQt.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RegisterQt.dir/mainwindow.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Software\RegisterQt\mainwindow.cpp -o CMakeFiles\RegisterQt.dir\mainwindow.cpp.s

CMakeFiles/RegisterQt.dir/Activity.cpp.obj: CMakeFiles/RegisterQt.dir/flags.make
CMakeFiles/RegisterQt.dir/Activity.cpp.obj: CMakeFiles/RegisterQt.dir/includes_CXX.rsp
CMakeFiles/RegisterQt.dir/Activity.cpp.obj: C:/Software/RegisterQt/Activity.cpp
CMakeFiles/RegisterQt.dir/Activity.cpp.obj: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RegisterQt.dir/Activity.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RegisterQt.dir/Activity.cpp.obj -MF CMakeFiles\RegisterQt.dir\Activity.cpp.obj.d -o CMakeFiles\RegisterQt.dir\Activity.cpp.obj -c C:\Software\RegisterQt\Activity.cpp

CMakeFiles/RegisterQt.dir/Activity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RegisterQt.dir/Activity.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Software\RegisterQt\Activity.cpp > CMakeFiles\RegisterQt.dir\Activity.cpp.i

CMakeFiles/RegisterQt.dir/Activity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RegisterQt.dir/Activity.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Software\RegisterQt\Activity.cpp -o CMakeFiles\RegisterQt.dir\Activity.cpp.s

CMakeFiles/RegisterQt.dir/Register.cpp.obj: CMakeFiles/RegisterQt.dir/flags.make
CMakeFiles/RegisterQt.dir/Register.cpp.obj: CMakeFiles/RegisterQt.dir/includes_CXX.rsp
CMakeFiles/RegisterQt.dir/Register.cpp.obj: C:/Software/RegisterQt/Register.cpp
CMakeFiles/RegisterQt.dir/Register.cpp.obj: CMakeFiles/RegisterQt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RegisterQt.dir/Register.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RegisterQt.dir/Register.cpp.obj -MF CMakeFiles\RegisterQt.dir\Register.cpp.obj.d -o CMakeFiles\RegisterQt.dir\Register.cpp.obj -c C:\Software\RegisterQt\Register.cpp

CMakeFiles/RegisterQt.dir/Register.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/RegisterQt.dir/Register.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Software\RegisterQt\Register.cpp > CMakeFiles\RegisterQt.dir\Register.cpp.i

CMakeFiles/RegisterQt.dir/Register.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/RegisterQt.dir/Register.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Software\RegisterQt\Register.cpp -o CMakeFiles\RegisterQt.dir\Register.cpp.s

# Object files for target RegisterQt
RegisterQt_OBJECTS = \
"CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/RegisterQt.dir/main.cpp.obj" \
"CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj" \
"CMakeFiles/RegisterQt.dir/Activity.cpp.obj" \
"CMakeFiles/RegisterQt.dir/Register.cpp.obj"

# External object files for target RegisterQt
RegisterQt_EXTERNAL_OBJECTS =

RegisterQt.exe: CMakeFiles/RegisterQt.dir/RegisterQt_autogen/mocs_compilation.cpp.obj
RegisterQt.exe: CMakeFiles/RegisterQt.dir/main.cpp.obj
RegisterQt.exe: CMakeFiles/RegisterQt.dir/mainwindow.cpp.obj
RegisterQt.exe: CMakeFiles/RegisterQt.dir/Activity.cpp.obj
RegisterQt.exe: CMakeFiles/RegisterQt.dir/Register.cpp.obj
RegisterQt.exe: CMakeFiles/RegisterQt.dir/build.make
RegisterQt.exe: C:/Qt/6.8.1/mingw_64/lib/libQt6Widgets.a
RegisterQt.exe: C:/Qt/6.8.1/mingw_64/lib/libQt6Gui.a
RegisterQt.exe: C:/Qt/6.8.1/mingw_64/lib/libQt6Core.a
RegisterQt.exe: C:/Qt/6.8.1/mingw_64/lib/libQt6EntryPoint.a
RegisterQt.exe: CMakeFiles/RegisterQt.dir/linkLibs.rsp
RegisterQt.exe: CMakeFiles/RegisterQt.dir/objects1.rsp
RegisterQt.exe: CMakeFiles/RegisterQt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Software\RegisterQt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RegisterQt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RegisterQt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RegisterQt.dir/build: RegisterQt.exe
.PHONY : CMakeFiles/RegisterQt.dir/build

CMakeFiles/RegisterQt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RegisterQt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RegisterQt.dir/clean

CMakeFiles/RegisterQt.dir/depend: RegisterQt_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Software\RegisterQt C:\Software\RegisterQt C:\Software\RegisterQt\cmake-build-debug C:\Software\RegisterQt\cmake-build-debug C:\Software\RegisterQt\cmake-build-debug\CMakeFiles\RegisterQt.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/RegisterQt.dir/depend

