cmake_minimum_required(VERSION 3.8)
project(MorseConverter)

file(GLOB_RECURSE headers ./*.h)
file(GLOB_RECURSE sources ./*.cpp)

find_package(Qt5 COMPONENTS Core Concurrent REQUIRED)

set(CMAKE_AUTOMOC ON)

add_library(MorseConverter.Logic SHARED ${headers} ${sources})

generate_export_header(MorseConverter.Logic
  EXPORT_MACRO_NAME MORSECONVERTER_LOGIC_API
  EXPORT_FILE_NAME ${MORSECONVERTER_EXPORT_HEADER_DIR}/MorseConverter.Logic/MorseConverter.Logic.API.h
)

set_target_properties(MorseConverter.Logic
  PROPERTIES
    FOLDER "sources"
)

target_link_libraries(MorseConverter.Logic
  PRIVATE
    Qt5::Core
    Qt5::Concurrent
)

target_include_directories(MorseConverter.Logic
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:MorseConverter.Logic>
    ${Qt5Core_INCLUDE_DIRS}
  PRIVATE
    MorseConverter.Logic
)
