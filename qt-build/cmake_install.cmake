# Install script for directory: /home/cfse/Stage_Malo/CPACSCreatorTotal

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/tigl3" TYPE DIRECTORY OPTIONAL FILES "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/doc/html")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "docu" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/tigl3" TYPE FILE OPTIONAL FILES "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/doc/tiglRef.pdf")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/TIGLViewer/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/bindings/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/examples/cmake_install.cmake")
  include("/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CreatorLib/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
