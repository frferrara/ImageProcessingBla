/*
 * main.cpp
 *
 *  Created on: May 4, 2012
 *      Author: frferrara
 */


#include <stdexcept>

#include "IPXMLParser.hpp"
#include "ImageProcessing.hpp"


const char * WRONGFILENAME = "/Users/frferrara/Documents/workspace_cpp/ImageProcessing/text.xml";


int main() {
	IPXMLParser * parser = new IPXMLParser;

	try {
		parser->parseXML();
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	parser->setFileName( WRONGFILENAME );

	try {
		parser->parseXML();
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	cv::Scalar hsvMin, hsvMax;

	try {
		parser->getProperties( hsvMin, hsvMax );
	} catch ( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;
	}

	delete parser;


	ImageProcessing * ip = new ImageProcessing;

	cv::Mat bla;

	for ( int i = 0; i < 10; i++ ) {
		try {
			ip->processImg( bla );
		} catch ( std::runtime_error & e ) {
			std::cout << std::endl << e.what() << std::endl;
		}
	}

	delete ip;

	return 0;
}
