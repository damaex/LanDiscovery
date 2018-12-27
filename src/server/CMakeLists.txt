set(SOURCE_FILES
        main.cpp)

find_package(Threads REQUIRED)

add_executable(server ${SOURCE_FILES})
target_link_libraries(server
		${WINSOCK_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})