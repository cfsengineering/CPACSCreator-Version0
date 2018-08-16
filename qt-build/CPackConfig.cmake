# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_IFW "")
SET(CPACK_BINARY_NSIS "")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_PRODUCTBUILD "")
SET(CPACK_BINARY_RPM "")
SET(CPACK_BINARY_STGZ "")
SET(CPACK_BINARY_TBZ2 "")
SET(CPACK_BINARY_TGZ "")
SET(CPACK_BINARY_TXZ "")
SET(CPACK_BINARY_TZ "")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_BUILD_SOURCE_DIRS "/home/cfse/Stage_Malo/CPACSCreatorTotal;/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENTS_ALL "Unspecified;docu;headers;interfaces;viewer")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_CUSTOM_INITIAL_DEFINITIONS "!define CPACK_REQUIRIRE_64BIT")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Martin Siggel")
SET(CPACK_GENERATOR "TGZ")
SET(CPACK_INSTALL_CMAKE_PROJECTS "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build;TiGL;ALL;/")
SET(CPACK_INSTALL_PREFIX "/usr/local")
SET(CPACK_MODULE_PATH "/home/cfse/Stage_Malo/CPACSCreatorTotal/cmake")
SET(CPACK_NSIS_CREATE_ICONS_EXTRA "
        CreateShortCut \"$SMPROGRAMS\\$STARTMENU_FOLDER\\Documentation.lnk\" \"$INSTDIR\\share\\doc\\tigl3\\html\\index.html\"
        ;
          CreateShortCut \"$SMPROGRAMS\\$STARTMENU_FOLDER\\TiGL-Reference.lnk\" \"$INSTDIR\\share\\doc\\tigl3\\tiglRef.pdf\"
        ")
SET(CPACK_NSIS_DELETE_ICONS_EXTRA "
          !insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
          Delete \"$SMPROGRAMS\\$MUI_TEMP\\Documentation.lnk\"
        ;
          !insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
          Delete \"$SMPROGRAMS\\$MUI_TEMP\\TiGL-Reference.lnk\"
        ")
SET(CPACK_NSIS_DISPLAY_NAME "TiGL 3.0.0rc1")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
SET(CPACK_NSIS_MODIFY_PATH "ON")
SET(CPACK_NSIS_MUI_ICON "/home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/TIGLViewer.ico")
SET(CPACK_NSIS_MUI_UNIICON "/home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/TIGLViewer.ico")
SET(CPACK_NSIS_PACKAGE_NAME "TiGL 3.0.0rc1")
SET(CPACK_OUTPUT_CONFIG_FILE "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CPackConfig.cmake")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/share/cmake-3.9/Templates/CPack.GenericDescription.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "TiGL built using CMake")
SET(CPACK_PACKAGE_EXECUTABLES "tiglviewer-3;TiGL Viewer 3")
SET(CPACK_PACKAGE_FILE_NAME "TiGL-3.0.0rc1-Linux")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "TiGL 3.0.0rc1")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "TIGL")
SET(CPACK_PACKAGE_NAME "TiGL")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "www.dlr.de/sc")
SET(CPACK_PACKAGE_VERSION "3.0.0rc1")
SET(CPACK_PACKAGE_VERSION_MAJOR "3")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0rc1")
SET(CPACK_RESOURCE_FILE_LICENSE "/home/cfse/Stage_Malo/CPACSCreatorTotal/LICENSE.txt")
SET(CPACK_RESOURCE_FILE_README "/users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/share/cmake-3.9/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/users/disk9/cfse/Stage_Malo/clion-2017.3.3/bin/cmake/share/cmake-3.9/Templates/CPack.GenericWelcome.txt")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_RPM "OFF")
SET(CPACK_SOURCE_TBZ2 "ON")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TXZ "ON")
SET(CPACK_SOURCE_TZ "ON")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux")
SET(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/qt-build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()

# Configuration for component "viewer"

SET(CPACK_COMPONENTS_ALL Unspecified docu headers interfaces viewer)
set(CPACK_COMPONENT_VIEWER_DISPLAY_NAME "TiGL Viewer + 3rd Party DLLs")

# Configuration for component "headers"

SET(CPACK_COMPONENTS_ALL Unspecified docu headers interfaces viewer)
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "Headers")

# Configuration for component "interfaces"

SET(CPACK_COMPONENTS_ALL Unspecified docu headers interfaces viewer)
set(CPACK_COMPONENT_INTERFACES_DISPLAY_NAME "Interfaces/Bindings")

# Configuration for component "docu"

SET(CPACK_COMPONENTS_ALL Unspecified docu headers interfaces viewer)
set(CPACK_COMPONENT_DOCU_DISPLAY_NAME "Documentation")
