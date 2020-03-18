// DFT.cpp
// Discrete Fourier Transform
// Author - Richie Ellingham
// March 2020

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

// Use vectors.h? pointers suck
complex* DFT (double *x_samples, double freq_sampling) {
  int N = (sizeof(x_samples)/sizeof(x_samples[0]));
  complex *X_f; // malloc here for N samples?
	X_f = (complex*) malloc(N+1);
  for(int k = 0; k < (N+1); k++) {
    complex X_k(0,0);
    for(int n = 0 ; n < (N+1); n++) {
			complex x_n(x_samples[n],0);
      X_k = X_k.cmplx_add(x_n.cmplx_mul(X_k.cmplx_exp(-(2*M_PI*k*n)/N)));
    }
		Serial.println(N);
    X_f[k+1] = X_k;
  }
  return X_f;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
	double x[5] = {0,1,2,3,4};
	// double x[9] = {sin(2*M_PI*0/8),sin(2*M_PI*1/8),sin(2*M_PI*2/8),sin(2*M_PI*3/8),sin(2*M_PI*4/8),sin(2*M_PI*5/8),sin(2*M_PI*6/8),sin(2*M_PI*7/8),sin(2*M_PI*8/8)};
	complex *X_f = DFT(x,1);
	for (int i = 0; i < (sizeof(X_f)/sizeof(X_f[0]));)
	delay(1000);
	Serial.println();
}
