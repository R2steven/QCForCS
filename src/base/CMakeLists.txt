add_library(Base base.cpp)

target_include_directories(Base 
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/math
                            )


option(USE_MYCOMPLEX "Use custom complex implementation" ON)

add_library(ComplexLib STATIC
"math/myComplex.cpp"
            )

if(USE_MYCOMPLEX)
target_compile_definitions(ComplexLib PRIVATE "USE_MYCOMPLEX")
endif()

target_link_libraries(ComplexLib PUBLIC tutorial_compiler_flags)

target_link_libraries(Base PRIVATE ComplexLib)