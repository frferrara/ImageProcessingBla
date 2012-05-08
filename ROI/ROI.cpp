/*
 * FullImg.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#include "ROI.hpp"
#include <iostream>

ROI::~ROI() {
    delete propertyParser;
}

IPState * ROI::Instance() {
    try {
        if ( instance == NULL )
            throw std::runtime_error( "instance == NULL" );
    } catch ( std::runtime_error & e ) {
        std::cout << std::endl << e.what() << std::endl;
    }

    return instance;
}

IPState * ROI::Instance( const char * fileName ) {
    if ( instance == NULL )
        instance = new ROI( fileName );

    return instance;
}

Eigen::MatrixXd ROI::processImg( ImageProcessing * ip,
                                 const cv::Mat & img ) {
    std::cout << "\nSTATE 2\n";

    changeState( ip, FullImg::Instance() );

    return Eigen::MatrixXd::Zero( 1, 1 );
}

ROI::ROI() {
    propertyParser = NULL;
}

ROI::ROI( const char * fileName ) {
    propertyParser = new IPXMLParser( fileName );
}

IPState * ROI::instance = NULL;
