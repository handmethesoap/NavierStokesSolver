#include "GrayScaleImage.hh"
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

void StaggeredGrid::initialiseFlags(bool value){
  for(int y = 0; y < (flags_.getSize(1)); ++y)
  {
    for(int x = 0; x < (flags_.getSize(0)); ++x)
    {
      flags_(x,y) = value;
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
      if( isFluid(x,y) ){
	sum += p_(x, y);
      }
	
    }
  }
  
  average = sum / getNumFluid();
  
  for( int y = 1; y <= ySize_ ; ++y )
  {
    for( int x = 1; x <= xSize_ ; ++x ) 
    {
      if( isFluid(x,y) ){
	p_(x, y) = p_(x, y) - average;
      }    	
    }
  }
}

void StaggeredGrid::normalizeRHS(){
  
  real sum = 0.0;
  real average;
  

  for( int y = 0; y <  ySize_ ; ++y )
  {
    for( int x = 0; x < xSize_; ++x ) 
    {
      if( isFluid(x,y) ){
	sum += rhs_(x, y);
      }
	
    }
  }
  
  average = sum / getNumFluid();
  
  for( int y = 0; y < ySize_ ; ++y )
  {
    for( int x = 0; x < xSize_ ; ++x ) 
    {
      if( isFluid(x,y) ){
	rhs_(x, y) = rhs_(x, y) - average;
      }    	
    }
  }
}

void StaggeredGrid::createRectangle( int x1, int y1, int x2, int y2 ){
  
  for( int y = 1; y <= ySize_; ++y ){
    for( int x = 1; x <= xSize_; ++x ){
      if( (x >= x1 ) && 
	  (y >= y1 ) && 
	  (x <= x2 ) && 
	  (y <= y2 ) ){
	setCellToObstacle(x,y);
      }
    }
  }
  
  
}
void StaggeredGrid::createCircle( int x, int y, int r){
 
  for( int i = 1; i <= ySize_; ++i ){
    for( int j = 1; j <= xSize_; ++j ){
      if( ((x - i)*(x - i) + 
	   (y - j)*(y - j)) <=
	   (r*r) ){
	setCellToObstacle(i,j);
      }
    }
  }  
  
}

void StaggeredGrid::readPNG(const std::string & pngFilename){
  
  GrayScaleImage png(pngFilename);
  
  for ( int i = 1; i <= xSize_; ++i ){
    for ( int j = 1; j <= ySize_; ++j ){

	flags_(i,j) = png(i-1,j-1);
	
    }
  }
  
}

void StaggeredGrid::writePNG(const std::string & pngFilename){
  
  GrayScaleImage png(xSize_, ySize_);
  
  for ( int i = 1; i <= xSize_; ++i ){
    for ( int j = 1; j <= ySize_; ++j ){
      png(i-1,j-1) = (unsigned char)(flags_(i,j)*255);
    }
  }
  png.save(pngFilename);
  
}



