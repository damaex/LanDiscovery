find_package(Threads REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/src/landiscovery)

set(SOURCE_FILES
        main.cpp)

add_executable(client ${SOURCE_FILES})

target_link_libraries(client
		landiscovery
		${WINSOCK_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})