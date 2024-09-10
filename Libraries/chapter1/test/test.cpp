// tester lib
#include <catch2/catch_test_macros.hpp>

// testee lib
#include "nmymath.h"


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    unsigned int ans = nmymath::Factorial(1);
    REQUIRE( nmymath::Factorial(1) == 1 );
    REQUIRE( nmymath::Factorial(2) == 2 );
    REQUIRE( nmymath::Factorial(3) == 6 );
    REQUIRE( nmymath::Factorial(10) == 3628800 );
}

TEST_CASE( "Factorials are computed second", "[factorial]" ) {
    unsigned int ans = nmymath::Factorial(1);
    REQUIRE( nmymath::Factorial(1) == 1 );
    REQUIRE( nmymath::Factorial(2) == 2 );
    REQUIRE( nmymath::Factorial(3) == 6 );
    REQUIRE( nmymath::Factorial(10) == 3628800 );
}