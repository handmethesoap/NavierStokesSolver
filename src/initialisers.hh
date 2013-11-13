#include <cmath>

const double pi = 3.14159;

double sin_function(double x, double y){
  double value = sin(x*pi) + sin(y*pi);
  return value;
}

double zero_function(double x, double y){
  double value = 0.0;
  return value;
}

double x_function(double x, double y){
  double value = x;
  return value;
}

double sinx_function(double x, double y){
  double value = sin(2*pi*x);
  return value;
}