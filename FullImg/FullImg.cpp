/*
 * FullImg.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */


#include "FullImg.hpp"
#include <iostream>


IPState * FullImg::Instance() {
	if ( instance == NULL )
		instance = new FullImg;

	return instance;
}

cv::Mat FullImg::processImg( ImageProcessing * ip, \
							 const cv::Mat & img ) {
	std::cout << "\nSTATE 1\n";

	changeState( ip, roi );

	return img;
}

FullImg::FullImg() {
	roi = ROI::Instance();
}

IPState * FullImg::instance = NULL;
