// tester lib
#include <catch2/catch_test_macros.hpp>

// testee lib
#include "myComplex.h"

TEST_CASE("default myComplex constructor", "[myComplex]") {
  myComplex fcomplex;
  myComplex scomplex(0.0,0.0);
  REQUIRE(fcomplex == scomplex);
}

TEST_CASE("myComplex basic algebra", "[myComplex][algebra]")  {
  myComplex real(1.0, 0.0);
  myComplex nreal(-1.0, 0.0);
  myComplex imag(0.0,1.0);
  myComplex nimag(0.0,-1.0);

  myComplex first(1.0, 2.0);
  myComplex second(2.0,1.0);

  myComplex im(0.0, 1.0);

  SECTION("imaginary properties: i^2 == -1")  {
    REQUIRE(nreal == (im*im));
    REQUIRE(nimag == (im*im*im));
    REQUIRE(real == (im*im*im*im));
  }

  SECTION("imaginary add")  {
    auto ans = first+second;
    REQUIRE(3.0 == ans.real());
    REQUIRE(3.0 == ans.imag());
  }

  SECTION("imaginary subtract") {
    auto ans = first-second;
    REQUIRE(-1.0 == ans.real());
    REQUIRE(1.0 == ans.imag()); 
  }
  
  SECTION("imaginary mult") {
    auto ans = first*second;
    REQUIRE(0.0 == ans.real());
    REQUIRE(5.0 == ans.imag());

    auto ans2 = first*2.0;
    REQUIRE(2.0 == ans2.real());
    REQUIRE(4.0 == ans2.imag());

    auto ans3 = 2.0 * first;
    REQUIRE(2.0 == ans3.real());
    REQUIRE(4.0 == ans3.imag());
  }

  SECTION("imaginary div") {
    myComplex third(-2.0,1.0);
    auto ans = third/first;
    REQUIRE(0.0/5.0 == ans.real());
    REQUIRE(5.0/5.0 == ans.imag());

    auto ans2 = first/2.0;
    REQUIRE(1.0/2.0 == ans2.real());
    REQUIRE(2.0/2.0 == ans2.imag());
  }

  SECTION("complex unary")  {
    REQUIRE(sqrt(5.0) == myComplex::modulus(first));
    REQUIRE(5.0 == myComplex::modSqrd(first));
    REQUIRE(nreal == -real);
    REQUIRE(nimag == myComplex::conj(imag));
  }
}