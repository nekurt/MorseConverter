cmake_minimum_required(VERSION 3.8)

project(MorseConverter)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE headers ./*.h)
file(GLOB_RECURSE sources ./*.cpp)

add_executable(MorseConverter ${headers} ${sources})

target_link_libraries(MorseConverter
  PRIVATE
    Qt5::Core
    Qt5::Widgets

  PUBLIC
    MorseConverter.Logic
    MorseConverter.Ui
)

set_target_properties(MorseConverter
  PROPERTIES
    FOLDER "sources"
)
