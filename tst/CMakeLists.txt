include(FetchContent)

FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

set(TEST_SOURCES
	PlayerTest.cc
)

add_executable(MyTests ${TEST_SOURCES})

target_include_directories(MyTests PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_include_directories(MyTests PUBLIC ${CMAKE_SOURCE_DIR}/libs)

target_sources(MyTests PRIVATE
	${CMAKE_SOURCE_DIR}/libs/linkedList.c
	${CMAKE_SOURCE_DIR}/libs/textfilewriter.c
)

target_link_libraries(
	MyTests
	GTest::gtest_main
)
gtest_discover_tests(MyTests)