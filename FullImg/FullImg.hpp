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
#include "IPXMLParser.hpp"

class ROI;

class FullImg : public IPState {
public:
    virtual ~FullImg();

    static IPState * Instance();

    static IPState * Instance( const char * fileName );

    virtual Eigen::MatrixXd processImg( ImageProcessing * ip,
                                        const cv::Mat & img );

protected:
    FullImg();

    FullImg( const char * fileName );

private:
    static IPState * instance;

    IPXMLParser * propertyParser;

    IPState * roi;

    cv::Scalar hsvMin, hsvMax;
};

#endif /* FULLIMG_HPP_ */
