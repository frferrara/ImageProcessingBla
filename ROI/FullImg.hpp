/*
 * FullImg.hpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#ifndef ROI_HPP_
#define ROI_HPP_


#include "IPState.hpp"


class FullImg : public IPState {
public:
	virtual ~FullImg() {}

	static IPState * Instance();

	virtual cv::Mat processImg( ImageProcessing * ip, \
								const cv::Mat & img );

protected:
	FullImg() {}

private:
	static IPState * instance;
};


#endif /* ROI_HPP_ */
