
#include "StaggeredGrid.hh"

void StaggeredGrid::initialiseP(double(* initialiser)(double, double)){

  for(int y = 1; y < (p_.getSize(1) - 1); ++y)
  {
    for(int x = 1; x < (p_.getSize(0) - 1); ++x)
    {
      p_(x,y) = initialiser((double(x-1) + 0.5)*dx_, (double(y-1) + 0.5)*dy_);
    }
  }

}

void StaggeredGrid::initialiseRHS(double(* initialiser)(double, double)){
  for(int y = 0; y < (rhs_.getSize(1)); ++y)
  {
    for(int x = 0; x < (rhs_.getSize(0)); ++x)
    {
      rhs_(x,y) = initialiser((double(x)+0.5)*dx_, (double(y)+0.5)*dy_);
    }
  }
}