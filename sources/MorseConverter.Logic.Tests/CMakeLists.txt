cmake_minimum_required(VERSION 3.8)
project(Tests)

file(GLOB Headers ./*.h)
file(GLOB Sources ./*.cpp)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

add_executable(MorseConverter.Logic.Tests ${Headers} ${Sources})

set_target_properties(MorseConverter.Logic.Tests
  PROPERTIES
    FOLDER "tests"
)

target_link_libraries(MorseConverter.Logic.Tests 
  PRIVATE
    gtest
    gmock
    Qt5::Core
    Qt5::Test

  PUBLIC
    MorseConverter.Logic
)

add_test(NAME MorseConverter.Logic.Tests COMMAND MorseConverter.Logic.Tests)
