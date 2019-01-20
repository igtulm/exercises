cmake_minimum_required(VERSION 3.0)

project(freqdict)

set(TARGET freqdict)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(BENCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bench)

file(GLOB_RECURSE SRCS ${RESOURCES_DIR}/*.cc ${SRC_DIR}/*.cc)

include_directories(${RESOURCES_DIR} ${SRC_DIR})

add_executable(${TARGET} ${SRCS})

find_package(GTest)
if (GTEST_FOUND)
   include_directories(${TEST_DIR})
   add_subdirectory(${TEST_DIR})
endif()

find_package(GBenchmark)
if (benchmark_FOUND)
  include_directories(${BENCH_DIR})
  add_subdirectory(${BENCH_DIR})
endif()
