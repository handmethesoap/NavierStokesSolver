
include_directories( ../src )
add_executable( array_test      ../src/Array.cc      ../src/Debug.cc ArrayTest.cc      )
add_executable( filereader_test ../src/FileReader.cc ../src/Debug.cc FileReaderTest.cc )
add_executable( sor_test 	../src/SORSolver.cc  ../src/StaggeredGrid.cc	../src/Array.cc	../src/FileReader.cc    ../src/Debug.cc ../src/GrayScaleImage.cc ../src/lodepng.cc SORTest.cc )
add_executable( fluidsim_test ../src/FileReader.cc ../src/Debug.cc ../src/FluidSimulator.cc ../src/Array.cc ../src/StaggeredGrid.cc ../src/SORSolver.cc ../src/VTKWriter.cc ../src/GrayScaleImage.cc ../src/lodepng.cc FluidSimTest.cc )
add_executable( obstacle_test ../src/FileReader.cc ../src/Debug.cc ../src/FluidSimulator.cc ../src/Array.cc ../src/StaggeredGrid.cc ../src/SORSolver.cc ../src/VTKWriter.cc ../src/GrayScaleImage.cc ../src/lodepng.cc ObstacleTest.cc )
add_executable( 3b_simulation ../src/FileReader.cc ../src/Debug.cc ../src/FluidSimulator.cc ../src/Array.cc ../src/StaggeredGrid.cc ../src/SORSolver.cc ../src/VTKWriter.cc ../src/GrayScaleImage.cc ../src/lodepng.cc 3b_simulation.cc )
