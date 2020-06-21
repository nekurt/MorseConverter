cmake_minimum_required(VERSION 3.8)
project(MorseConverter)

file(GLOB_RECURSE headers ./*.h)
file(GLOB_RECURSE sources ./*.cpp)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)

add_library(MorseConverter.Ui SHARED ${headers} ${sources})

generate_export_header(MorseConverter.Ui
  EXPORT_MACRO_NAME MORSECONVERTER_UI_API
  EXPORT_FILE_NAME ${MORSECONVERTER_EXPORT_HEADER_DIR}/MorseConverter.Ui/MorseConverter.Ui.API.h
)

set_target_properties(MorseConverter.Ui
  PROPERTIES
    FOLDER "sources"
)

target_link_libraries(MorseConverter.Ui
  PRIVATE
    Qt5::Core
    Qt5::Widgets

  PUBLIC
    MorseConverter.Logic
)

target_include_directories(MorseConverter.Ui
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:MorseConverter.Ui>
    ${CMAKE_CURRENT_BINARY_DIR}
)
