/*
 * FullImg.hpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */

#ifndef ROI_HPP_
#define ROI_HPP_

#include <stdexcept>

#include <opencv.hpp>
#include <Eigen/Eigen>

#include "IPState.hpp"
#include "FullImg.hpp"

class ROI : public IPState {
public:
    virtual ~ROI() { }

    static IPState * Instance();

    virtual Eigen::MatrixXd processImg( ImageProcessing * ip,
                                        const cv::Mat & img );

protected:
    ROI() {}

private:
    static IPState * instance;
};

#endif /* ROI_HPP_ */
