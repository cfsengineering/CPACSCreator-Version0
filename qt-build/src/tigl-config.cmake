# - Config file for the TIGL package
# It defines the following variables
#  TIGL_INCLUDE_DIRS - include directories for TiXI
#  TIGL_LIBRARIES    - libraries to link against


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was tigl-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# Compute paths
set_and_check(TIGL_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set_and_check(TIGL_CMAKE_DIR "${PACKAGE_PREFIX_DIR}/lib/cmake/tigl3")
 
# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET TIGL)
  include("${TIGL_CMAKE_DIR}/tigl-targets.cmake")
endif()
 
# These are IMPORTED targets created by tigl-targets.cmake
set(TIGL_LIBRARIES TIGL)
