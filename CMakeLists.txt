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

add_executable( iptest iptest.cpp )
target_link_libraries( iptest ImageProcessing )

enable_testing()

macro( do_xmltest arg result )
  add_test( XMLParser${arg} xmlparsetest ${arg} )
  set_tests_properties( XMLParser${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result} )
endmacro( do_xmltest )

macro( do_xmltest2 arg1 arg2 arg3 result )
  add_test( XMLParser${arg1} xmlparsetest ${arg2} ${arg3} )
  set_tests_properties( XMLParser${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result} )
endmacro( do_xmltest2 )

do_xmltest( nofile "fileName.empty()" )
do_xmltest( wrongfile "XML file cannot be loaded" )
do_xmltest2( 1 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test1.xml "opened successfully" )
do_xmltest2( 2 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test1.xml "2 4 3" )
do_xmltest2( 3 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test1.xml "25 150 230" )
do_xmltest2( 4 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test2.xml "XML file empty or 'Properties' missing" )
do_xmltest2( 5 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test3.xml "'Properties' is empty" )
do_xmltest2( 6 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test4.xml "HSV values are zero" )
do_xmltest2( 7 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test5.xml "hMin >= hMax" )
do_xmltest2( 8 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test6.xml "sMin >= sMax" )
do_xmltest2( 9 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test7.xml "vMin >= vMax" )
do_xmltest2( 10 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test8.xml "hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" )
do_xmltest2( 11 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test9.xml "hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" )
do_xmltest2( 12 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test10.xml "hsvMin( 1 ) < 0 || hsvMax( 1 ) > 255" )
do_xmltest2( 13 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test11.xml "hsvMin( 1 ) < 0 || hsvMax( 1 ) > 255" )
do_xmltest2( 14 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test12.xml "hsvMin( 2 ) < 0 || hsvMax( 2 ) > 255" )
do_xmltest2( 15 sfn /Users/frferrara/Documents/workspace_cpp/ImageProcessing/test13.xml "hsvMin( 2 ) < 0 || hsvMax( 2 ) > 255" )