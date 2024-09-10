# test Executable
add_executable(tests test.cpp)
add_executable(myComplex myComplexTest.cpp)

find_package(Catch2 REQUIRED)

# link against tester and testee libs
target_link_libraries(tests 
        PRIVATE 
            Catch2::Catch2WithMain 
            chapter1
            )

target_link_libraries(myComplex 
        PRIVATE 
            Catch2::Catch2WithMain 
            chapter1
        )

include(CTest)
include(Catch)

enable_testing()

catch_discover_tests(tests)

catch_discover_tests(myComplex)


