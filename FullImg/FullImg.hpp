/*
 * FullImg.hpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#ifndef FULLIMG_HPP_
#define FULLIMG_HPP_


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


#endif /* FULLIMG_HPP_ */
