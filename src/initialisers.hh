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

real y_function(real x, real y){
  real value = y;
  return value;
}

real xy_function(real x, real y){
  real value = x+y;
  return value;
}

real sinx_function(real x, real y){
  real value = sin(2*pi*x);
  return value;
}

real siny_function(real x, real y){
  real value = sin(2*pi*y);
  return value;
}

real rand_function(real x, real y){
  real value = rand() % 100;
  return value;
}

real halfU(real x, real y){
  if(y > 1.2){
    return 1.0;
  }
  else{
    return 0.0;
  }
}

real test_function(real x, real y){
  real value = sin(4*pi*x) + sin(4*pi*y);
  return value;
}
#endif