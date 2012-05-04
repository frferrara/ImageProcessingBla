cmake_minimum_required( VERSION 2.8 )

project( ImageProcessing )

set( CMAKE_BUILD_TYPE "Debug" )

set( CMAKE_CXX_FLAGS_DEBUG "-W -Wextra -g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "" )

include_directories( /opt/local/include
                     /opt/local/include/opencv2
                     ImageProcessing
                     IPState
                     FullImg 
                     ROI )
                     
add_subdirectory( ImageProcessing )
add_subdirectory( IPState )
add_subdirectory( FullImg )
add_subdirectory( ROI )

add_executable( main main.cpp )
target_link_libraries( main ImageProcessing )