# DFT
### A discrete fourier transform function with custom complex numbers lib attached to be compatable with an Atmel AVR toolchain.

To do:
1. Make a DFT .h & .cpp file and re-write with more modularity
2. Return the frequency binning (i.e. f_bin = freq_sampling/N ?)
3. Test on Atmel AVR micro
4. Make buffering system for input samples


* The complex library is called 'complx.h' to avoid confusion with 'complex.h' included in C11 and C99.
