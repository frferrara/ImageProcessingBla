/*
 * FullImg.hpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#ifndef ROI_HPP_
#define ROI_HPP_


#include "IPState.hpp"
#include "FullImg.hpp"


class ROI : public IPState {
public:
	virtual ~ROI() {}

	static IPState * Instance();

	virtual cv::Mat processImg( ImageProcessing * ip, \
								const cv::Mat & img );

protected:
	ROI() {}

private:
	static IPState * instance;
};


#endif /* ROI_HPP_ */
