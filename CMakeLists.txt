cmake_minimum_required(VERSION 3.10)
project(qlego VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/qubit.cpp
    src/circuit.cpp
    src/simulator.cpp
)

set(HEADERS
    include/qlego/qubit.hpp
    include/qlego/gate.hpp
    include/qlego/circuit.hpp
    include/qlego/simulator.hpp
)

add_library(qlego STATIC ${SOURCES})

set_target_properties(qlego PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..
)

target_include_directories(qlego PUBLIC ${PROJECT_SOURCE_DIR}/include)
