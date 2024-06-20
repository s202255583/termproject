set(SOURCES
	../libs/linkedList.c
	../libs/textfilewriter.c
	Player.c
)

add_executable(MyExecutable ${SOURCES})

target_include_directories(MyExecutable PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(MyExecutable PRIVATE my_lib)

// Player.c