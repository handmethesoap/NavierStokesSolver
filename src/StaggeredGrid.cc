
#include "StaggeredGrid.hh"

void StaggeredGrid::initialiseP(real(* initialiser)(real, real)){

  for(int y = 1; y < (p_.getSize(1) - 1); ++y)
  {
    for(int x = 1; x < (p_.getSize(0) - 1); ++x)
    {
      p_(x,y) = initialiser((real(x-1) + 0.5)*dx_, (real(y-1) + 0.5)*dy_);
    }
  }

}

void StaggeredGrid::initialiseRHS(real(* initialiser)(real, real)){
  for(int y = 0; y < (rhs_.getSize(1)); ++y)
  {
    for(int x = 0; x < (rhs_.getSize(0)); ++x)
    {
      rhs_(x,y) = initialiser((real(x)+0.5)*dx_, (real(y)+0.5)*dy_);
    }
  }
}