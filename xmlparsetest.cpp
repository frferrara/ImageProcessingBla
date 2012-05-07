/*
 * main.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#include <stdexcept>
#include <string>

#include "IPXMLParser.hpp"
#include "ImageProcessing.hpp"

int main( int argc,
          char * argv[] ) {
    if ( argc < 2 ) {
        std::cout << "\nNot enough input arguments! argc = " << argc
                << std::endl;

        return -1;
    }

    std::string arg1 = argv[ 1 ], arg2;

    IPXMLParser * parser = NULL;

    if ( strcmp( arg1.c_str(), "nofile" ) == 0 )
        parser = new IPXMLParser;

    if ( strcmp( arg1.c_str(), "wrongfile" ) == 0 )
        parser = new IPXMLParser( "/dummy.xml" );

    if ( strcmp( arg1.c_str(), "sfn" ) == 0 && argc == 2 ) {
        std::cout << "\nNot enough input arguments! argc = " << argc
                << std::endl;

        return -2;
    }

    if ( strcmp( arg1.c_str(), "sfn" ) == 0 && argc >= 3 ) {
        parser = new IPXMLParser;

        arg2 = argv[ 2 ];

        parser->setFileName( arg2.c_str() );
    }

    try {
        if ( parser != NULL )
            parser->parseXML();
    } catch ( std::runtime_error & e ) {
        std::cout << std::endl << e.what() << std::endl;
    }

    cv::Scalar hsvMin, hsvMax;

    try {
        if ( parser != NULL ) {
            parser->getProperties( hsvMin, hsvMax );

            delete parser;
        }
    } catch ( std::runtime_error & e ) {
        delete parser;

        std::cout << std::endl << e.what() << std::endl;
    }

    return 0;
}
