add_library(Base base.cpp)

target_include_directories(Base 
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                            )