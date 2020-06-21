cmake_minimum_required(VERSION 3.8)
project(MorseConverter)

add_subdirectory(gtest)

set_target_properties(gtest gmock gtest_main gmock_main PROPERTIES FOLDER "3rd-party")
