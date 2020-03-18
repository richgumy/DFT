// complex.cpp
// Author - Richie Ellingham
// March 2020
// A simple implementation of complex operations and representation
#include "complex.h"

// Constructor
complex::complex(double a_real, double a_imag) {
  real = a_real;
  imag = a_imag;
}

// Add operator overloading so that '*,/,+,-' can be used with 'complex' classes

complex complex::operator+ (double b){
  // Operator overloading for use with a non-complex double value 'b'
  // out = a + b
  complex out(0,0);
  out.real = real + b;
  out.imag = imag;
  return out;
}

complex complex::cmplx_add(complex b){
  // out = a + b
  complex out(0,0);
  out.real = real + b.real;
  out.imag = imag + b.imag;
  return out;
}
complex complex::cmplx_sub(complex b){
  // out = a - b
  complex out(0,0);
  out.real = real - b.real;
  out.imag = imag - b.imag;
  return out;
}

complex complex::cmplx_mul(complex b) {
  // out = a * b
  complex out(0,0);
  out.real = real*b.real - imag*b.imag;
  out.imag = real*b.imag + imag*b.real;
  return out;
}

complex complex::cmplx_div(complex b) {
  // out = a / b
  complex out(0,0);
  out.real = (real*b.real + imag*b.imag)/(b.real*b.real + b.imag*b.imag);
  out.imag = (imag*b.real - real*b.imag)/(b.real*b.real + b.imag*b.imag);
  return out;
}

complex complex::cmplx_exp(double a) {
  // out = exp^(j*a) = cos(a) + j*sin(a)
  complex out(0,0);
  out.real = cos(a);
  out.imag = sin(a);
  return out;
}
