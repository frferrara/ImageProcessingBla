/*
 * iptest.cpp
 *
 *  Created on: May 8, 2012
 *      Author: frferrara
 */

#include <stdexcept>

#include "ImageProcessing.hpp"

const char * fileName =
        "/Users/frferrara/Documents/workspace_cpp/ImageProcessing/testip.xml";

ImageProcessing * ip = NULL;

int main( int argc,
          char * argv[] ) {
    try {
        ip = new ImageProcessing( fileName, fileName );
    } catch ( std::runtime_error & e ) {
        std::cout << std::endl << e.what() << std::endl;
    }

    delete ip;

    return 0;
}
