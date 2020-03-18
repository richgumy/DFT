// complex.h
// Author - Richie Ellingham
// March 2020
// A simple implementation of complex operations and representation
// Todo:  1.  Implement operator overloading better only 'complex + double'
//            operations can be achieved with current implementation
//        2.  Implement operator overloading for all complex operation functions

#ifndef complex_h
#define complex_h

#include <math.h>

// Class
class complex
{
private:

public:
  double real = 0;
  double imag = 0;
  complex(double a_real, double a_imag);
  complex operator+ (double b); // Operator overloading with a double 'b'
  complex cmplx_add(complex b); // out = self + b
  complex cmplx_sub(complex b); // out = self - b
  complex cmplx_mul(complex b); // out = self * b
  complex cmplx_div(complex b); // out = self / b
  complex cmplx_exp(double a); // out = exp^(j*a) = cos(a) + j*sin(a)
};

// Functions all here

#endif
