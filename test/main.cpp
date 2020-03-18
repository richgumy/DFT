#include <stdio.h>
#include <stdlib.h>
#include "complx.h"

complx* DFT (size_t N, double x_samples[], double freq_sampling) {
  // int N = (sizeof(x_samples)/sizeof(x_samples[0]));
  complx *X_f; // malloc here for N samples?
	X_f = (complx*) malloc(N);
  for(int k = 0; k < (N); k++) {
    complx X_k(0,0);
    for(int n = 0 ; n < (N); n++) {
			complx x_n(x_samples[n],0);
      // printf("x%d=%lf\n",n,x_samples[n]);
      X_k = X_k.cmplx_add(x_n.cmplx_mul(X_k.cmplx_exp(-(2*M_PI*k*n)/N)));
      // X_k = X_k.cmplx_add(x_n);
      // printf("xk%dn%d = %lf + %lfj\n",k,n,X_k.real,X_k.imag);
    }
    X_f[k+1] = X_k;
  }
  return X_f;
}

int main() {
	double x[100];
  size_t N = sizeof(x)/sizeof(x[0]);
  for (int i = 0 ; i < N ; i++) {
    x[i] = sin(2*M_PI*i/8) + sin(2*M_PI*i/32);
  }
  printf("x=%d\n",N);
	complx *X_f = DFT(N,x,1);
	for (int i = 0; i < N/2; i++) {
    double mag = sqrt(X_f[i].real*X_f[i].real + X_f[i].imag*X_f[i].imag);
    // printf("%lf + %lfj\n", X_f[i].real, X_f[i].imag);
    printf("%.2lf\n", mag);
  }
  return 0;
}

// int main(){
//   complx a(1,2);
//   complx b(3,4);
//   complx c(0,0);
//
//   c = a.cmplx_add(b);
//
//   printf("%lf+",c.real);
//   printf("%lfj",c.imag);
//
//   return 0;
// }
