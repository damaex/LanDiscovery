set(SOURCE_FILES
        main.cpp)

find_package(Threads REQUIRED)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests
        ${CMAKE_THREAD_LIBS_INIT})