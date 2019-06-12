

wxWidgets tutorial  http://zetcode.com/gui/wxwidgets/




https://wiki.wxwidgets.org/CMake

How to use it with wxWidgets ?

Ok, now how to use it. First download the latest version from Cmake Homepage. Depending on what OS, install it. I will refer to the Windows version here, but on Linux (use ccmake command for visual setup) it will look similar. On windows the executable you need is CMake-GUI.exe or CMakeSetup.exe in older versions.

The CMake 2.6.4 installation comes with the file FindwxWidgets.cmake which is used by Cmake for finding any installed wxWidgets on the system.

To change the default search path of the wxWidgets installation, use SET(wxWidgets_ROOT_DIR <wxWidgets Directory>).

Use SET(wxWidgets_CONFIGURATION mswud) to find appropriate configuration.

Then use FIND_PACKAGE(wxWidgets COMPONENTS core base REQUIRED).

You may configure the FIND_PACKAGE line as per your needs.

Then use INCLUDE(${wxWidgets_USE_FILE}).

At the end, don't forget to use TARGET_LINK_LIBRARIES(<YourTarget> ${wxWidgets_LIBRARIES}). See the example:

project(myGreatProject)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})




This is (probably) all that is needed to work with wxWidgets using cmake. Much of the information below related to FindWxWin.cmake is OUTDATED and not required with the new CMake versions.

If all is installed, we need one thing, which I took from wxArt2D. It is a macro that can be used to determine the install dir for wxWidgets, what libs are used, what type of builds are compiled, etc. You can find this file here FindWxWin.Cmake. Save this file in {CMAKE_INSTALL}\Modules. As you can see in this directory, there are a lot of helper macros that can determine if certain tools are installed, compiler flags / functions are supported, etc. This is really extensive and very handy.

Now that we have the macro we need in place, we can make our first CMakeLists.txt file, which will allow us to generate a minimal sample that can be compiled. Go to the minimal sample directory (usually {WXWIN}\samples\minimal\), and start up your editor.

NOTE: This CMakeLists.txt file is compatible with the CMake 2.6.2 If you find any problems with it, please contact me jorgb [at] xs4all.nl

The following file can be copied and pasted. In this CMake file the comments will explain what all sections mean: