
include_directories( . )

add_executable( nusif FileReader.cc Debug.cc Array.cc main.cc StaggeredGrid.cc SORSolver.cc FluidSimulator.cc VTKWriter.cc GrayScaleImage.cc lodepng.cc)