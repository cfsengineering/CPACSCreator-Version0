project(CPACSCreatorLib)

# Create the target
add_library(CPACSCreatorLib)


# Add the third party library easylogging
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/easyloggingpp-9.96.4/src/)
target_sources( CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/easyloggingpp-9.96.4/src/easylogging++.cc)

# Add the third party library quartic
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/quartic/)
target_sources( CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/quartic/poly34.cpp)


#Add tigl Lib

# TIGL link

# add all subdirectories to include path
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(TIGL_INCLUDES_MD ${BASE_DIR}/src/)
subdirlist(SUBDIRS ${TIGL_INCLUDES_MD})
foreach(subdir ${SUBDIRS})
    set(TIGL_INCLUDES_MD ${TIGL_INCLUDES_MD} ${BASE_DIR}/src/${subdir}/)
endforeach()

target_include_directories(CPACSCreatorLib PUBLIC ${TIGL_INCLUDES_MD})
target_link_libraries(CPACSCreatorLib tigl3_static)


# boost
include_directories(${BASE_DIR}/thirdparty/boost_1_63_0)

#STRANGE
include_directories( ${PROJECT_BINARY_DIR}/../../src/)

#occ
include_directories( ${OpenCASCADE_INCLUDE_DIR} )

# opengl
include_directories(${OPENGL_INCLUDE_DIR})


# Add the third party header only library easylogging
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/eigen-eigen-5a0156e40feb/)


target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ )
target_sources( CPACSCreatorLib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSFile.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CreatorException.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MCPACSTransformation.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/MCPACSPositioning.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LoggerSetUp.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSTreeItem.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSTree.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/UniqueXPath.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Helper.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/AircraftTree.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSPointsProfile.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSSegment.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSProfilesDB.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/ConfigWriter.cpp
        )




# TIXI link
unset(TIXI_LIB_LOCATION CACHE) # clear variable
find_library(TIXI_LIB_LOCATION tixi3 )
message(TIXI_LIB_LOCATION: ${TIXI_LIB_LOCATION})
target_link_libraries(CPACSCreatorLib ${TIXI_LIB_LOCATION} )
find_path(TIXI_PATH_MD tixi.h /usr/local/include/tixi3 /usr/include/)
message(TIXI_PATH_MD ${TIXI_PATH_MD} )
target_include_directories(CPACSCreatorLib PRIVATE ${TIXI_PATH_MD})





get_target_property(SOURCES_TEMP CPACSCreatorLib SOURCES)
message("SOURCES USED TO BUILD CPACSCreator:" ${SOURCES_TEMP})


get_target_property(INCLUDE_DIRS_TEMP CPACSCreatorLib INCLUDE_DIRECTORIES)
message("INCLUDE DIRS USED TO BUILD CPACSCreator:" ${INCLUDE_DIRS_TEMP})
