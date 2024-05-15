add_library(ComplexLib myComplex.cpp)

target_include_directories(ComplexLib 
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                            )

option(USE_MYCOMPLEX "Use custom complex implementation" ON)
option(USE_STD_COMPLEX "Use std::complex implementation" ON)

if(USE_MYCOMPLEX)
target_compile_definitions(ComplexLib PRIVATE "USE_MYCOMPLEX")
endif()
if(USE_STD_COMPLEX)
target_compile_definitions(ComplexLib PRIVATE "USE_STD_COMPLEX")
endif()

target_link_libraries(ComplexLib PUBLIC Base tutorial_compiler_flags)