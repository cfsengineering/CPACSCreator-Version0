# Install script for directory: /home/cfse/Stage_Malo/CPACSCreatorTotal/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "docu" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/tigl3/examples" TYPE FILE FILES "/home/cfse/Stage_Malo/CPACSCreatorTotal/tests/unittests/TestData/simpletest.cpacs.xml")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "docu" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/tigl3/examples" TYPE FILE RENAME "README.txt" FILES "/home/cfse/Stage_Malo/CPACSCreatorTotal/examples/README.md")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/examples/c_demo/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/examples/matlab_demo/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/examples/python_demo/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/examples/java_demo/cmake_install.cmake")

endif()

