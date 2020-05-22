cmake_minimum_required(VERSION 3.12)
project(TactiledTest)

set(TEST_FILES
        unittest/test_main.cpp
        unittest/tiled_map_test.cpp)

add_executable(${TACTILED_TEST_TARGET} ${TEST_FILES})
add_dependencies(${TACTILED_TEST_TARGET} ${TACTILED_LIB_TARGET})

set_target_properties(${TACTILED_TEST_TARGET} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE catch)

include(CTest)
include(Catch)

add_test(NAME ${TACTILED_TEST_TARGET}
        COMMAND ${TACTILED_TEST_TARGET})

target_include_directories(${TACTILED_TEST_TARGET} PUBLIC unittests)
target_include_directories(${TACTILED_TEST_TARGET} SYSTEM PUBLIC ${TACTILED_LIBRARY_DIR})
target_include_directories(${TACTILED_TEST_TARGET} SYSTEM PUBLIC ${TACTILED_INCLUDE_DIR})
target_include_directories(${TACTILED_TEST_TARGET} SYSTEM PUBLIC ${TACTILED_SOURCE_DIR})

target_link_libraries(${TACTILED_TEST_TARGET}
        PUBLIC ${TACTILED_LIBRARIES}
        PUBLIC Catch)

catch_discover_tests(${TACTILED_TEST_TARGET})

#copy_directory_post_build(
#        ${TACTILED_TEST_TARGET}
#        ${TACTILED_RESOURCES_DIR}
#        ${CMAKE_CURRENT_BINARY_DIR}/resources)

if (WIN32)
    copy_file_post_build(
            ${TACTILED_TEST_TARGET}
            ${TACTILED_DYNAMIC_LIB}
            ${CMAKE_CURRENT_BINARY_DIR})

    #    copy_directory_post_build(
    #            ${TACTILED_TEST_TARGET}
    #            ${TACTILED_BINARIES_DIR}
    #            ${CMAKE_CURRENT_BINARY_DIR})
endif ()