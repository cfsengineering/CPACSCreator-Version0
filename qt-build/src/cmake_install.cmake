# Install script for directory: /home/cfse/Stage_Malo/CPACSCreatorTotal/src

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so.0.0rc1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/lib/libtigl3.so.0.0rc1"
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/lib/libtigl3.so.0"
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/lib/libtigl3.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so.0.0rc1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtigl3.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "::::::::::::::"
           NEW_RPATH "/usr/local/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3/tigl-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3/tigl-targets.cmake"
         "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/CMakeFiles/Export/lib/cmake/tigl3/tigl-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3/tigl-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3/tigl-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3" TYPE FILE FILES "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/CMakeFiles/Export/lib/cmake/tigl3/tigl-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3" TYPE FILE FILES "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/CMakeFiles/Export/lib/cmake/tigl3/tigl-targets-release.cmake")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tigl3" TYPE FILE FILES
    "/home/cfse/Stage_Malo/CPACSCreatorTotal/src/api/tigl.h"
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/api/tigl_version.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tigl3" TYPE FILE FILES
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/tigl-config.cmake"
    "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/src/tigl-config-version.cmake"
    )
endif()

