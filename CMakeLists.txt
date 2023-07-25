cmake_minimum_required(VERSION 3.16)
project(ScipPP LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

option(USE_COVERAGE "Create coverage report." OFF)
option(BUILD_TESTS "Build tests." OFF)
option(BUILD_UTILS "Build utils." OFF)

message(STATUS "${PROJECT_NAME} version derived from git is ${scippp_version}")
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/source/version.cpp.in
        ${CMAKE_CURRENT_BINARY_DIR}/source/version.cpp)

find_package(scip CONFIG REQUIRED)

# enable coverage analysis by setting USE_COVERAGE to ON
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(COVERAGE_COMPILER_FLAGS "-fprofile-instr-generate -fcoverage-mapping" CACHE INTERNAL "")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(COVERAGE_COMPILER_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0 -g" CACHE INTERNAL "")
else ()
    message(WARNING "We do not support coverage with this compiler: ${CMAKE_CXX_COMPILER_ID}")
endif ()
function(append_coverage_compiler_flags)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COVERAGE_COMPILER_FLAGS}" PARENT_SCOPE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILER_FLAGS}" PARENT_SCOPE)
    message(STATUS "Appending code coverage compiler flags: ${COVERAGE_COMPILER_FLAGS}")
endfunction()
if (USE_COVERAGE)
    append_coverage_compiler_flags()
endif ()

# Lib
file(GLOB SCIPPP_SRC source/*.cpp ${CMAKE_CURRENT_BINARY_DIR}/source/version.cpp)
file(GLOB SCIPPP_HDR include/**/*.hpp)
add_library(ScipPP ${SCIPPP_SRC})
target_include_directories(ScipPP PUBLIC include)
target_link_libraries(ScipPP PUBLIC scip::scip)

# install
include(GNUInstallDirs)
install(TARGETS ScipPP LIBRARY DESTINATION lib)
set_target_properties(ScipPP PROPERTIES PUBLIC_HEADER "${SCIPPP_HDR}")
install(TARGETS ScipPP PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/scippp)

if (BUILD_TESTS)
    add_subdirectory(test)
endif ()

if (BUILD_TESTS)
    add_subdirectory(utils)
endif ()
