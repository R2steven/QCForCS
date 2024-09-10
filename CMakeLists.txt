cmake_minimum_required(VERSION 3.29.0)

project(QC4CS VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# get Catch2 from its git repo
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
    GIT_TAG         v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)

add_subdirectory(Libraries)