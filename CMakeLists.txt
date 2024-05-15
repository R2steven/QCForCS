cmake_minimum_required(VERSION 3.29.0)

project(QC4Quik VERSION 0.1.0 LANGUAGES C CXX)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

configure_file(QC4QuikConfig.h.in QC4QuikConfig.h)

# Add subdirectories
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/base" Base)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/math" ComplexLib)

# Build executable
add_executable(QC4Quik main.cpp)

# Link subdirs
target_link_libraries(QC4Quik PUBLIC ComplexLib Base tutorial_compiler_flags)

target_include_directories(QC4Quik PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            )