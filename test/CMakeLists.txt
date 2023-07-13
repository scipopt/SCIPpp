find_package(Boost CONFIG REQUIRED)

file(GLOB TEST_SOURCES *.cpp)
add_executable(testScipPP ${TEST_SOURCES})
target_include_directories(testScipPP SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(testScipPP PRIVATE ScipPP Boost::unit_test_framework)
