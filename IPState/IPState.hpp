/*
 * IPState.hpp
 *
 *  Created on: May 3, 2012
 *      Author: frferrara
 */

#ifndef IPSTATE_HPP_
#define IPSTATE_HPP_


#include <opencv.hpp>

#include "ImageProcessing.hpp"


class IPState {
public:
	virtual ~IPState() {};

	virtual cv::Mat processImg( ImageProcessing * ip, \
								const cv::Mat & img ) = 0;

protected:
	IPState() {}

	void changeState( ImageProcessing * ip, \
					  IPState * state );
};


#endif /* IPSTATE_HPP_ */
