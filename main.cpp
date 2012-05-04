/*
 * main.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */


#include "ImageProcessing.hpp"


int main() {
	ImageProcessing * ip = new ImageProcessing;

	cv::Mat bla;

	for ( int i = 0; i < 10; i++ ) {
		ip->processImg( bla );
	}

	delete ip;

	return 0;
}
