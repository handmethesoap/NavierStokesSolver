
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

void StaggeredGrid::initialiseU(real(* initialiser)(real, real)){
  for(int y = 0; y < (u_.getSize(1)); ++y)
  {
    for(int x = 0; x < (u_.getSize(0)); ++x)
    {
      u_(x,y) = initialiser((real(x)+0.5)*dx_, (real(y)+0.5)*dy_);
    }
  }
}

void StaggeredGrid::initialiseV(real(* initialiser)(real, real)){
  for(int y = 0; y < (v_.getSize(1)); ++y)
  {
    for(int x = 0; x < (v_.getSize(0)); ++x)
    {
      v_(x,y) = initialiser((real(x)+0.5)*dx_, (real(y)+0.5)*dy_);
    }
  }
}

void StaggeredGrid::initialiseP(real value){

  for(int y = 1; y < (p_.getSize(1) - 1); ++y)
  {
    for(int x = 1; x < (p_.getSize(0) - 1); ++x)
    {
      p_(x,y) = value;
    }
  }

}

void StaggeredGrid::initialiseRHS(real value){
  for(int y = 0; y < (rhs_.getSize(1)); ++y)
  {
    for(int x = 0; x < (rhs_.getSize(0)); ++x)
    {
      rhs_(x,y) = value;
    }
  }
}

void StaggeredGrid::initialiseU(real value){
  for(int y = 0; y < (u_.getSize(1)); ++y)
  {
    for(int x = 0; x < (u_.getSize(0)); ++x)
    {
      u_(x,y) = value;
    }
  }
}

void StaggeredGrid::initialiseV(real value){
  for(int y = 0; y < (v_.getSize(1)); ++y)
  {
    for(int x = 0; x < (v_.getSize(0)); ++x)
    {
      v_(x,y) = value;
    }
  }
}

void StaggeredGrid::initialiseF(real value){
  for(int y = 0; y < (f_.getSize(1)); ++y)
  {
    for(int x = 0; x < (f_.getSize(0)); ++x)
    {
      f_(x,y) = value;
    }
  }
}

void StaggeredGrid::initialiseG(real value){
  for(int y = 0; y < (g_.getSize(1)); ++y)
  {
    for(int x = 0; x < (g_.getSize(0)); ++x)
    {
      g_(x,y) = value;
    }
  }
}

void StaggeredGrid::normalizeP(){
  
  real sum = 0.0;
  real average;
  

  for( int y = 1; y <=  ySize_ ; ++y )
  {
    for( int x = 1; x <= xSize_; ++x ) 
    {
      sum += p_(x, y);
    }
  }
  
  average = sum / double(ySize_*xSize_);
  
  for( int y = 1; y <= ySize_ ; ++y )
  {
    for( int x = 1; x <= xSize_ ; ++x ) 
    {
      p_(x, y) = p_(x, y) - average;
    }
  }
}
