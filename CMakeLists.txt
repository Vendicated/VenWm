cmake_minimum_required(VERSION 3.21)
project(VenWM)

link_libraries(X11)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}, "src/*.c")
add_executable(venwm ${SOURCES} src/wm.c src/wm.h src/util.h)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif ()