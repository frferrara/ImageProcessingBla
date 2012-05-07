/*
 * FullImg.hpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#ifndef FULLIMG_HPP_
#define FULLIMG_HPP_

#include <stdexcept>

#include <opencv.hpp>
#include <Eigen/Eigen>

#include "IPState.hpp"
#include "ROI.hpp"

class ROI;

class FullImg : public IPState {
public:
    virtual ~FullImg() {
    }

    static IPState * Instance();

    virtual Eigen::MatrixXd processImg( ImageProcessing * ip,
                                        const cv::Mat & img );

protected:
    FullImg();

private:
    static IPState * instance;

    IPState * roi;
};

#endif /* FULLIMG_HPP_ */
