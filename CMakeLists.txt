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

add_executable( xmlparsetest xmlparsetest.cpp )
target_link_libraries( xmlparsetest ImageProcessing IPXMLParser )

enable_testing()

macro( do_xmltest arg result )
  add_test( XMLParser${arg} xmlparsetest ${arg} )
  set_tests_properties( XMLParser${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result} )
endmacro( do_xmltest )

macro( do_xmltest2 arg1 arg2 result )
  add_test( XMLParser${arg1} xmlparsetest ${arg1} ${arg2} )
  set_tests_properties( XMLParser${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result} )
endmacro( do_xmltest2 )

do_xmltest( nofile "fileName.empty()" )
do_xmltest( wrongfile "XML file cannot be loaded" )
do_xmltest2( sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test1.xml "opened successfully" )