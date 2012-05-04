/*
 * ImageProcessing.hpp
 *
 *  Created on: May 3, 2012
 *      Author: frferrara
 */

#ifndef IMAGEPROCESSING_HPP_
#define IMAGEPROCESSING_HPP_


#include <opencv.hpp>


class IPState;

class ImageProcessing {
public:
	ImageProcessing();

	~ImageProcessing();

	cv::Mat processImg( const cv::Mat & img );

private:
	friend class IPState;

	void changeState( IPState * state );

	IPState * state;
};


#endif /* IMAGEPROCESSING_HPP_ */
