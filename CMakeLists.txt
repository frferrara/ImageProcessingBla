cmake_minimum_required( VERSION 2.8 )

project( ImageProcessing )

set( CMAKE_BUILD_TYPE "Debug" )

set( CMAKE_CXX_FLAGS_DEBUG "-W -Wextra -g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "" )

include_directories( /opt/local/include
                     ImageProcessing )
                     
add_subdirectory( ImageProcessing )