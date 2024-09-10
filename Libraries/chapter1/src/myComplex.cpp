#include <cstdlib>
#include <memory>

#include "myComplex.h"


myComplex::myComplex() : myComplex(0.0, 0.0){}

myComplex::myComplex(const double r, const double i)  {
  realn = r;
  imagn = i;
}

myComplex::myComplex(const myComplex& other) : 
realn(other.realn), imagn(other.imagn)  
{}

myComplex::~myComplex() {
}

double myComplex::real() const  {
  return realn;
}

double myComplex::imag() const  {
  return imagn;
}

myComplex operator+(const myComplex& a, const double b) {
  myComplex ret(a.realn, a.imagn);
  ret.realn += b;
  return ret;
}

myComplex operator+(const double b, const myComplex& a) {
  myComplex ret(a.realn, a.imagn);
  ret.realn += b;
  return ret;
}

myComplex operator+(const myComplex& a, const myComplex& b) {
  myComplex ret;
  ret.realn = a.realn + b.realn;
  ret.imagn = a.imagn + b.imagn;
  return ret;
}

myComplex operator-(const myComplex& a, const double b) {
  myComplex ret(a.realn, a.imagn);
  ret.realn -= b;
  return ret;
}

myComplex operator-(const double b, const myComplex& a) {
  myComplex ret(a.realn, a.imagn);
  ret.realn -= b;
  return ret;
}

myComplex operator-(const myComplex& a, const myComplex& b) {
  myComplex ret;
  ret.realn = a.realn - b.realn;
  ret.imagn = a.imagn - b.imagn;
  return ret;
}

myComplex operator*(const myComplex& a, const double b) {
  myComplex ret(a.realn, a.imagn);
  ret.realn *= b;
  ret.imagn *= b;
  return ret;
}

myComplex operator*(const double b, const myComplex& a) {
  myComplex ret(a.realn, a.imagn);
  ret.realn *= b;
  ret.imagn *= b;
  return ret;
}

myComplex operator*(const myComplex& a, const myComplex& b) {
  myComplex ret;
  ret.realn = a.realn * b.realn - a.imagn * b.imagn;
  ret.imagn = a.realn * b.imagn + a.imagn * b.realn;
  return ret;
}

myComplex operator/(const myComplex& a, const double b) {
  myComplex ret(a.realn, a.imagn);
  ret.realn /= b;
  ret.imagn /= b;
  return ret;
}

myComplex operator/(const double b, const myComplex& a) {
  myComplex ret(a.realn, a.imagn);
  ret.realn /= b;
  ret.imagn /= b;
  return ret;
}

myComplex operator/(const myComplex& a, const myComplex& b) {
  myComplex ret;
  double denom = myComplex::modSqrd(a);
  ret.realn = (a.realn*b.realn + a.imagn*b.imagn) / denom;
  ret.imagn = (a.imagn*b.realn - a.realn*b.imagn) / denom;
  return ret;
}

myComplex operator-(const myComplex& a) {
  myComplex ret(-a.realn, -a.imagn);
  return ret;
}

myComplex myComplex::conj(const myComplex& a) {
  myComplex ret(a.realn, -a.imagn);
  return ret;
}

double myComplex::modulus(const myComplex& a) {
  return sqrt(a.real()*a.real() + a.imag()*a.imag());
}

double myComplex::modSqrd(const myComplex& a)  {
  return magnitude(a * conj(a));
}

double myComplex::magnitude(const myComplex& a) {
  return (a.real()+a.imag());
}


myComplex &myComplex::operator=(const myComplex& other)  {
  realn = other.realn;
  imagn = other.imagn;
  return *this;
}

bool myComplex::operator==(const myComplex& other) const  {
  return realn==other.realn && imagn==other.imagn;
}