project(CPACSCreatorLib)

# Create the target
add_library(CPACSCreatorLib)


# Add the third party library easylogging
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/easyloggingpp-9.96.4/src/)
target_sources( CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/easyloggingpp-9.96.4/src/easylogging++.cc)

# Add the third party library quartic
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/quartic/)
target_sources( CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/quartic/poly34.cpp)



# Add the third party header only library easylogging
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdPartyLib/eigen-eigen-5a0156e40feb/)


target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ )
target_sources( CPACSCreatorLib
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSFile.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CreatorException.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSTransformation.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSPositioning.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LoggerSetUp.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSTreeItem.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSTree.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/UniqueXPath.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Helper.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/AircraftTree.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSPointsProfile.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSSegment.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CPACSProfilesDB.cpp
        )




# TIXI link
unset(TIXI_LIB_LOCATION CACHE) # clear variable
find_library(TIXI_LIB_LOCATION tixi3 )
message(TIXI_LIB_LOCATION: ${TIXI_LIB_LOCATION})
target_link_libraries(CPACSCreatorLib ${TIXI_LIB_LOCATION} )
find_path(TIXI_PATH_MD tixi.h /usr/local/include/tixi3 /usr/include/)
message(TIXI_PATH_MD ${TIXI_PATH_MD} )
target_include_directories(CPACSCreatorLib PRIVATE ${TIXI_PATH_MD})



# TIGL link
target_include_directories(CPACSCreatorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../src/api)
target_link_libraries(CPACSCreatorLib tigl3)



get_target_property(SOURCES_TEMP CPACSCreatorLib SOURCES)
message("SOURCES USED TO BUILD CPACSCreator:" ${SOURCES_TEMP})


get_target_property(INCLUDE_DIRS_TEMP CPACSCreatorLib INCLUDE_DIRECTORIES)
message("INCLUDE DIRS USED TO BUILD CPACSCreator:" ${INCLUDE_DIRS_TEMP})
