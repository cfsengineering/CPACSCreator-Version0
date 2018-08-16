#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tigl3" for configuration "Release"
set_property(TARGET tigl3 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tigl3 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libtigl3.so.0.0rc1"
  IMPORTED_SONAME_RELEASE "libtigl3.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS tigl3 )
list(APPEND _IMPORT_CHECK_FILES_FOR_tigl3 "${_IMPORT_PREFIX}/lib/libtigl3.so.0.0rc1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
