


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
        ConfigWriterTests.cpp
        )

target_include_directories(runCPACSCreatorLibTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdPartyLib/easyloggingpp-9.96.4/src/)
target_sources( runCPACSCreatorLibTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdPartyLib/easyloggingpp-9.96.4/src/easylogging++.cc)

# add includes for gtest
message(gtest_SOURCE_DIR: ${gtest_SOURCE_DIR})
target_include_directories(runCPACSCreatorLibTests PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/../../../${gtest_SOURCE_DIR})
target_include_directories(runCPACSCreatorLibTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../${gtest_SOURCE_DIR}/include)


# add all subdirectories to include path
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../..)

set(TIGL_INCLUDES_MD ${BASE_DIR}/src/)
subdirlist(SUBDIRS ${TIGL_INCLUDES_MD})
foreach(subdir ${SUBDIRS})
        set(TIGL_INCLUDES_MD ${TIGL_INCLUDES_MD} ${BASE_DIR}/src/${subdir}/)
endforeach()

target_include_directories(CPACSCreatorLib PUBLIC ${TIGL_INCLUDES_MD})
#target_link_libraries(CPACSCreatorLib tigl3)


# boost
include_directories(${BASE_DIR}/thirdparty/boost_1_63_0)

#STRANGE
include_directories( ${PROJECT_BINARY_DIR}/../../src/)

#occ
include_directories( ${OpenCASCADE_INCLUDE_DIR} )

# opengl
include_directories(${OPENGL_INCLUDE_DIR})




# Copy the data file to execution folder (relative path usage)

add_custom_command(
        TARGET  runCPACSCreatorLibTests
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Data  "$<TARGET_FILE_DIR:runCPACSCreatorLibTests>/Data"
        COMMAND ${CMAKE_COMMAND} -E echo "Data directory is copyied"
        )


# Copy config log file to the executable folder
add_custom_command(
        TARGET  runCPACSCreatorLibTests
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/CreatorLib/CPACSCreatorLib/logger.conf
        $<TARGET_FILE_DIR:runCPACSCreatorLibTests>
)



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
