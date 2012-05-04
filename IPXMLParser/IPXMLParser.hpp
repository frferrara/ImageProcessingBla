/*
 * XMLParser.hpp
 *
 *  Created on: Apr 25, 2012
 *      Author: frferrara
 */

#ifndef XMLPARSER_HPP_
#define XMLPARSER_HPP_


#include <iostream>
#include <string>
#include <stdexcept>

#include <tinyxml.h>

#include <opencv2/opencv.hpp>


class IPXMLParser {
public:
	IPXMLParser();

	IPXMLParser( const char * fileName );

	~IPXMLParser();

	void parseXML();

	void getProperties( cv::Scalar & hsvMin, \
						cv::Scalar & hsvMax );

	void setFileName( const char * fileName );

private:
	std::string fileName;

	TiXmlDocument doc;

	TiXmlElement * el;

	cv::Scalar hsvMin, hsvMax;
};


#endif /* XMLPARSER_HPP_ */
