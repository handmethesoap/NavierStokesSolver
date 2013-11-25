#ifndef __FLUID_SIMULATOR_H__
#define __FLUID_SIMULATOR_H__


#include "FileReader.hh"
#include "StaggeredGrid.hh"
#include "SORSolver.hh"
#include "Debug.hh"

class FluidSimulator
{
  public:
      FluidSimulator( const FileReader & conf ) : grid_(conf),
						  solve_(conf),
						  gamma_(conf.getRealParameter("gamma")),
						  dt_(conf.getRealParameter("dt")),
						  Re_(conf.getRealParameter("Re")),
						  gx_(conf.getRealParameter("gx")),
						  gy_(conf.getRealParameter("gy")),
						  safetyfactor_(conf.getRealParameter("safetyfactor")){
	grid_.initialiseP(conf.getRealParameter("P_init"));
	grid_.initialiseU(conf.getRealParameter("U_init"));
	grid_.initialiseV(conf.getRealParameter("V_init"));
	
	CHECK_MSG(dt_ > 0.0, "The timestep must be a positive value");
	CHECK_MSG( 0.0 < gamma_ && gamma_ < 1.0, "gamma must lie between 0 and 1");
	CHECK_MSG( safetyfactor_ != 0, "the safetyfactor cannot be zero");
      }

      /// Simulates a given time-length
      void simulate             ( real duration              );
      void simulateTimeStepCount( unsigned int nrOfTimeSteps );


      // Getter functions for the internally stored StaggeredGrid
            StaggeredGrid & grid() { return grid_; };
      const StaggeredGrid & grid() const { return grid_; };
      
  private:    
    
      void computeFG();
      void composeRHS();
      void updateVelocities();
      void determineNextDT( real const & limit );  //What is limit supposed to do?
      void refreshBoundaries();
      
      StaggeredGrid grid_;
      SORSolver solve_;
      
      real gamma_;
      real dt_;
      real Re_;
      real gx_;
      real gy_;
      real safetyfactor_;

};



#endif
