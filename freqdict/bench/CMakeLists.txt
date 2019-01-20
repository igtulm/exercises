cmake_minimum_required(VERSION 3.0)

project(bench)

SET(TARGET bench)

include_directories(${RESOURCES_DIR} ${SRC_DIR})
include_directories(${benchmark_INCLUDE_DIRS})

file (GLOB_RECURSE SRCS  *.cc *.h ${RESOURCES_DIR}/*.cc)

add_executable(${TARGET} ${SRCS})
target_link_libraries(${TARGET} ${benchmark_LIBRARY})
