#ifndef INITIALISERS_HH
#define INITIALISERS_HH

#include <cmath>
#include <cstdlib>

const real pi = 3.141592653589793238463;

real sin_function(real x, real y){
  real value = sin(x*pi) + sin(y*pi);
  return value;
}

real zero_function(real x, real y){
  real value = 0.0;
  return value;
}

real x_function(real x, real y){
  real value = x;
  return value;
}

real sinx_function(real x, real y){
  real value = sin(2*pi*x);
  return value;
}

real rand_function(real x, real y){
  real value = rand() % 100;
  return value;
}

#endif