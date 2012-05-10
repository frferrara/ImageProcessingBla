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

    cv::Mat getImg( int type );

protected:
    FullImg();

    FullImg( const char * fileName );

private:
    void initialize( const cv::Mat & img );

    bool initialized;

    static IPState * instance;

    IPXMLParser * propertyParser;

    IPState * roi;

    cv::Size imgSize;

    cv::Scalar hsvMin, hsvMax;

    cv::Mat morphKernel, hsv, thr, dil;

    enum {
        HSV = 0,
        THR = 1,
        DIL = 2
    };
};

#endif /* FULLIMG_HPP_ */
