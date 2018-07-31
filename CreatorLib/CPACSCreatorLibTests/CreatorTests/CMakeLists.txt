
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



target_link_libraries(runCPACSCreatorLibTests CPACSCreatorLib)
target_link_libraries(runCPACSCreatorLibTests gtest gtest_main)