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
    if ( !initialized )
        initialize( img );

    std::cout << "\nSTATE 1\n";

    changeState( ip, roi );

    return Eigen::MatrixXd::Zero( 1, 1 );
}

cv::Mat FullImg::getImg( int type ) {
    switch ( type ) {
    case HSV:
        return hsv;

    case THR:
        return thr;

    case DIL:
        return dil;

    default:
        throw std::runtime_error( "Exception: type must be HSV, THR or DIL!" );
    }
}

FullImg::FullImg() {
    propertyParser = NULL;

    roi = NULL;

    initialized = false;
}

FullImg::FullImg( const char * fileName ) {
    propertyParser = new IPXMLParser( fileName );

    roi = ROI::Instance();

    initialized = false;

    propertyParser->parseXML();
    propertyParser->getProperties( hsvMin, hsvMax );
}

void FullImg::initialize( const cv::Mat & img ) {
    if ( img.cols <= 0 || img.rows <= 0 )
        throw std::runtime_error( "Exception: Wrong image size!" );

    imgSize = cv::Size( img.cols, img.rows );

    morphKernel = cv::getStructuringElement( CV_SHAPE_RECT, cv::Size( 5, 5 ),
            cv::Point( 1, 1 ) );

    initialized = true;
}

IPState * FullImg::instance = NULL;
