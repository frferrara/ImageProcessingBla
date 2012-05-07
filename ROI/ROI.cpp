/*
 * FullImg.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#include "ROI.hpp"
#include <iostream>

IPState * ROI::Instance() {
    if ( instance == NULL )
        instance = new ROI;

    return instance;
}

Eigen::MatrixXd ROI::processImg( ImageProcessing * ip,
                                 const cv::Mat & img ) {
    std::cout << "\nSTATE 2\n";

    changeState( ip, FullImg::Instance() );

    return Eigen::MatrixXd::Zero( 1, 1 );
}

IPState * ROI::instance = NULL;
