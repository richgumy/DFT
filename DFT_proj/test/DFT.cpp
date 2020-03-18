// DFT.cpp
// Discrete Fourier Transform
// Author - Richie Ellingham
// March 2020

#include <Arduino.h>
#include <math.h>
#include <complex.h>

complex* DFT (complex* x_samples, double freq_sampling) {
  int N = sizeof(x_samples)/sizeof(x_samples[0]);
  complex X_f; // malloc here for N samples?
  for(int k = 0; k < (N-1); k++) {
    double complex X_k;
    for(int n = 0 ; n < (N-1); n++) {
      X_k += x_samples[n] * cmplxexponential(-(2*M_PI*k*n)/N);
    }
    X_f[k] = X_k;
  }
  return X_f;
}
