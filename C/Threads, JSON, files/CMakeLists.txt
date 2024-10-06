cmake_minimum_required(VERSION 3.10)

project(ThreadsExample C)

find_package(Threads REQUIRED)
find_package(cJSON REQUIRED)

add_executable(threads src/threads.c src/threads.h)

target_link_libraries(threads ${CMAKE_THREAD_LIBS_INIT} /lib/x86_64-linux-gnu/libcjson.so)
