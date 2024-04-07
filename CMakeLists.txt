cmake_minimum_required(VERSION 3.00)
project(ParallelTest)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/data_gen.cpp
    src/log.cpp
    src/main.cpp
    src/merge_sort.cpp
    src/parallel_sort.cpp
    )

set(HEADERS
    src/data_gen.h
    src/log.h
    src/merge_sort.h
    src/parallel_sort.h
    )

add_executable(ParallelTest ${SOURCES} ${HEADERS})
target_link_libraries(ParallelTest PRIVATE Threads::Threads)