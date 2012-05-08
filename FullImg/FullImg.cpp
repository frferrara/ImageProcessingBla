/*
 * FullImg.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#include "FullImg.hpp"
#include <iostream>

FullImg::~FullImg() {
    delete propertyParser;

    delete roi;
}

IPState * FullImg::Instance() {
    try {
        if ( instance == NULL )
            throw std::runtime_error( "Exception: instance == NULL" );
    } catch ( std::runtime_error & e ) {
        std::cout << std::endl << e.what() << std::endl;
    }
    return instance;
}

IPState * FullImg::Instance( const char * fileName ) {
    if ( instance == NULL )
        instance = new FullImg( fileName );

    return instance;
}

Eigen::MatrixXd FullImg::processImg( ImageProcessing * ip,
                                     const cv::Mat & img ) {
    std::cout << "\nSTATE 1\n";

    changeState( ip, roi );

    return Eigen::MatrixXd::Zero( 1, 1 );
}

FullImg::FullImg() {
    propertyParser = NULL;

    roi = NULL;
}

FullImg::FullImg( const char * fileName ) {
    propertyParser = new IPXMLParser( fileName );

    roi = ROI::Instance();

    propertyParser->parseXML();
    propertyParser->getProperties( hsvMin, hsvMax );
}

IPState * FullImg::instance = NULL;
