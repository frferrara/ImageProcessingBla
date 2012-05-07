cmake_minimum_required( VERSION 2.8 )

project( ImageProcessing )

set( CMAKE_BUILD_TYPE "Debug" )

set( CMAKE_CXX_FLAGS_DEBUG "-W -Wextra -g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "" )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} 
     /opt/local/share/OpenCV 
     /Users/frferrara/Documents/workspace_cpp/cmake )

find_package( OpenCV 2 REQUIRED )
find_package( Eigen3 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIR}
                     ${EIGEN3_INCLUDE_DIR}
                     ImageProcessing
                     IPState
                     FullImg 
                     ROI 
                     IPXMLParser )
                     
add_subdirectory( ImageProcessing )
add_subdirectory( IPState )
add_subdirectory( FullImg )
add_subdirectory( ROI )
add_subdirectory( IPXMLParser )

add_executable( main main.cpp )
target_link_libraries( main ImageProcessing IPXMLParser )