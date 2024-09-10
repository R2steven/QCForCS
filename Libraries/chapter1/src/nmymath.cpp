#include "nmymath.h"

unsigned int nmymath::Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}