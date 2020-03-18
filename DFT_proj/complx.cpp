// complx.cpp
// Author - Richie Ellingham
// March 2020
// A simple implementation of complx operations and representation
#include "complx.h"

// Constructor
complx::complx(double a_real, double a_imag) {
  real = a_real;
  imag = a_imag;
}

// Add operator overloading so that '*,/,+,-' can be used with 'complx' classes

complx complx::operator+ (double b){
  // Operator overloading for use with a non-complx double value 'b'
  // out = a + b
  complx out(0,0);
  out.real = real + b;
  out.imag = imag;
  return out;
}

complx complx::cmplx_add(complx b){
  // out = a + b
  complx out(0,0);
  out.real = real + b.real;
  out.imag = imag + b.imag;
  return out;
}
complx complx::cmplx_sub(complx b){
  // out = a - b
  complx out(0,0);
  out.real = real - b.real;
  out.imag = imag - b.imag;
  return out;
}

complx complx::cmplx_mul(complx b) {
  // out = a * b
  complx out(0,0);
  out.real = real*b.real - imag*b.imag;
  out.imag = real*b.imag + imag*b.real;
  return out;
}

complx complx::cmplx_div(complx b) {
  // out = a / b
  complx out(0,0);
  out.real = (real*b.real + imag*b.imag)/(b.real*b.real + b.imag*b.imag);
  out.imag = (imag*b.real - real*b.imag)/(b.real*b.real + b.imag*b.imag);
  return out;
}

complx complx::cmplx_exp(double a) {
  // out = exp^(j*a) = cos(a) + j*sin(a)
  complx out(0,0);
  out.real = cos(a);
  out.imag = sin(a);
  return out;
}
