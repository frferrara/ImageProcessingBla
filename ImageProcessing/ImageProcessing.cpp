/*
 * ImageProcessing.cpp
 *
 *  Created on: May 3, 2012
 *      Author: frferrara
 */

#include "ImageProcessing.hpp"
#include "IPState.hpp"
#include "FullImg.hpp"

ImageProcessing::ImageProcessing() {
    state = NULL;
}

ImageProcessing::ImageProcessing( const char * FullImgPropertyFile,
                                  const char * ROIPropertyFile ) {
    ROI::Instance( ROIPropertyFile );

    state = FullImg::Instance( FullImgPropertyFile );
}

ImageProcessing::~ImageProcessing() {
    delete state;
}

Eigen::MatrixXd ImageProcessing::processImg( const cv::Mat & img ) {
    return state->processImg( this, img );
}

void ImageProcessing::changeState( IPState * state ) {
    this->state = state;
}
