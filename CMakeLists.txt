cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 20)
project(antiwasm)

#codecov.io for code coverage
set(--coverage)

include_directories(src)

# Boost (logging + unit test)
find_package(Boost 1.70 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
find_package(Boost COMPONENTS program_options REQUIRED)

#Testing subdirectory
add_subdirectory(test)

file(GLOB SOURCES "src/*.cpp")

add_executable(antiwasm ${SOURCES})

target_link_libraries(antiwasm pthread boost_log boost_program_options)