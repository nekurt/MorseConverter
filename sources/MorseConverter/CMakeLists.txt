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

if (WIN)
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET MorseConverter POST_BUILD
       COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --verbose 1 $<TARGET_FILE_DIR:MorseConverter>
COMMENT "Deploying Qt libraries using windeployqt for compilation target MorseConverter ...")
endif(WIN)
