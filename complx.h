// complx.h
// Author - Richie Ellingham
// March 2020
// A simple implementation of complx operations and representation
// Todo:  1.  Implement operator overloading better only 'complx + double'
//            operations can be achieved with current implementation
//        2.  Implement operator overloading for all complx operation functions

#ifndef complx_h
#define complx_h

#include <math.h>

// Class
class complx
{
private:

public:
  double real = 0;
  double imag = 0;
  complx(double a_real, double a_imag);
  complx operator+ (double b); // Operator overloading with a double 'b'
  complx cmplx_add(complx b); // out = self + b
  complx cmplx_sub(complx b); // out = self - b
  complx cmplx_mul(complx b); // out = self * b
  complx cmplx_div(complx b); // out = self / b
  complx cmplx_exp(double a); // out = exp^(j*a) = cos(a) + j*sin(a)
};

// Functions all here

#endif
