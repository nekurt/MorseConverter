# MorseConverter
Desktop C++ application with Qt for UI for conversion of english text to morse code. MorseConverter accepts as input english letter a - z ignoring case and digits 0 - 9. All other letters will be replaced with ? symbol in the resulting text.

## Prerequisites
CMake
Qt

## How to build

### Specifying Qt path
MorseConverter can be build using CMake but you need to specify path to installed Qt library's cmake scripts. They are usualy located in 
> /Users/{user}/Qt/5.15.0/{compiler}/lib/cmake/Qt5
or 
> C:/Qt/5.15.0/{compiler}/lib/cmake/Qt5

This path can be specified by setting up CMake variable CMAKE_PREFIX_PATH in the CMakeLists.txt that is located in the root:
> set(CMAKE_PREFIX_PATH "/Users/user/Qt/5.15.0/clang_64/lib/cmake/Qt5")

or by providing it during cmake call
> cmake -DCMAKE_PREFIX_PATH=/Users/user/Qt/5.15.0/clang_64/lib/cmake/Qt5 ..

### Build
After you specify Qt path you can run cmake to generate build files (Visual Studio, Xcode, Makefile (by default)). To generate build files you need to do the following:

* create build folder:
``mkdir build``
* move to that build folder:
``cd build``
* run cmake:
the next line will generate build files with generator defined by default:
`` cmake ..``
or if you want to generate build files with specific generator:
`` cmake -G Xcode ..``
or if you want to specify path to Qt during generation of build files;
`` cmake -DCMAKE_PREFIX_PATH=/Users/user/Qt/5.15.0/clang_64/lib/cmake/Qt5 ..``

After that you can build solution.
To build solution using Automake build system you need to run:
`` make ``

binaries folder will be created in in source root folder.

To run tests using Automake build system you need to run:
`` make test``

