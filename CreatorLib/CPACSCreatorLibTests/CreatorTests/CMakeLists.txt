
message(gtest_SOURCE_DIR: ${gtest_SOURCE_DIR})

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runCPACSCreatorLibTests
        CreatorPointTest.cpp
        CPACSFileTest.cpp
        CPACSPositioningTests.cpp
        CPACSTransformationTests.cpp
        CPACSTreeTest.cpp
        CPACSTreeItemTest.cpp
        UniqueXPathTest.cpp
        AircraftTreeTests.cpp
        HelperTests.cpp
        MyTestHelperFunctions.h
        MyTestHelperFunctions.cpp
        MyTestHelperFunctionsTests.cpp
        GenerateFilesForCFD.cpp
        ProfileTests.cpp
        CPACSSegmentTest.cpp
        CPACSProfilesDBTest.cpp
        )

target_include_directories(runCPACSCreatorLibTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdPartyLib/easyloggingpp-9.96.4/src/)
target_sources( runCPACSCreatorLibTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdPartyLib/easyloggingpp-9.96.4/src/easylogging++.cc)

# Copy the data file to execution folder (relative path usage)
add_custom_command(
        TARGET runCPACSCreatorLibTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/Data $<TARGET_FILE_DIR:runCPACSCreatorLibTests>/Data
)

add_custom_target(
        TARGET runCPACSCreatorLibTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "suppper $<TARGET_FILE:runCPACSCreatorLibTests>"
        VERBATIM
)

message(asfsdsdfa  $<TARGET_FILE_DIR:runCPACSCreatorLibTests>)
message(ss   ${CMAKE_SOURCE_DIR}/Data )
message(dd ${CMAKE_COMMAND})

# TIXI link
unset(TIXI_LIB_LOCATION CACHE) # clear variable
find_library(TIXI_LIB_LOCATION tixi3 )
message(TIXI_LIB_LOCATION: ${TIXI_LIB_LOCATION})
target_link_libraries(runCPACSCreatorLibTests ${TIXI_LIB_LOCATION} )
find_path(TIXI_PATH_MD tixi.h /usr/local/include/tixi3 /usr/include/)
message(TIXI_PATH_MD ${TIXI_PATH_MD} )
target_include_directories(runCPACSCreatorLibTests PRIVATE ${TIXI_PATH_MD})

target_link_libraries(runCPACSCreatorLibTests CPACSCreatorLib)
target_link_libraries(runCPACSCreatorLibTests gtest gtest_main)
