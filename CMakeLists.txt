cmake_minimum_required(VERSION 3.8)
project(MorseConverter)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_PREFIX_PATH "/Users/{user}/Qt/{version}/{platform}/lib/cmake/Qt5")

include(GenerateExportHeader)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(MORSECONVERTER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/../binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MORSECONVERTER_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MORSECONVERTER_BINARY_DIR})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(MORSECONVERTER_EXPORT_HEADER_DIR ${CMAKE_BINARY_DIR}/exports)
include_directories(${MORSECONVERTER_EXPORT_HEADER_DIR})

enable_testing()

add_subdirectory(sources)