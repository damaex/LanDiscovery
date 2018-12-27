set(SOURCE_FILES
		LanDiscovery.cpp LanDiscovery.h
        main.cpp)

find_package(Threads REQUIRED)

add_executable(client ${SOURCE_FILES})
target_link_libraries(client
		${WINSOCK_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})