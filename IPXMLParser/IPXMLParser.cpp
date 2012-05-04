/*
 * XMLParser.cpp
 *
 *  Created on: Apr 25, 2012
 *      Author: frferrara
 */


#include "IPXMLParser.hpp"


IPXMLParser::IPXMLParser() {
	el = NULL;
}


IPXMLParser::IPXMLParser( const char * fileName ) {
	this->fileName = fileName;

	el = NULL;
}

IPXMLParser::~IPXMLParser() {
	delete el;
}

void IPXMLParser::parseXML() {
	if ( fileName.empty() )
		throw std::runtime_error( "Exception: fileName.empty()" );

	doc = TiXmlDocument( fileName );

	if ( !doc.LoadFile() )
		throw std::runtime_error( "Exception: XML file cannot be loaded!" );

	TiXmlHandle hDoc( &doc );
	TiXmlHandle hRoot( 0 );

	el = hDoc.FirstChildElement().Element();

	if ( !el )
		throw std::runtime_error( "Exception: XML file empty!" );

	if ( std::strcmp( el->Value(), "Properties" ) )
		throw std::runtime_error( "Exception: Root is not 'Properties'!" );

	hRoot = TiXmlHandle( el );

	el = hRoot.FirstChild().Element();

	if ( !el )
		throw std::runtime_error( "Exception: 'Properties' is empty!" );

	double * hMin = NULL;
	double * sMin = NULL;
	double * vMin = NULL;
	double * hMax = NULL;
	double * sMax = NULL;
	double * vMax = NULL;

	for ( ; el; el->NextSiblingElement() ) {
		const char * elName = el->Attribute( "name" );

		if ( !std::strcmp( elName, "hsvMin" ) || \
				!std::strcmp( elName, "hsvMax" ) )
			throw std::runtime_error( "Exception: hsvMin and/or hsvMax not available!" );

		if ( std::strcmp(elName, "hsvMin" ) ) {
			el->QueryDoubleAttribute( "hMin", hMin );
			el->QueryDoubleAttribute( "sMin", sMin );
			el->QueryDoubleAttribute( "vMin", vMin );

			break;
		}

		if ( std::strcmp(elName, "hsvMax" ) ) {
			el->QueryDoubleAttribute( "hMax", hMax );
			el->QueryDoubleAttribute( "sMax", sMax );
			el->QueryDoubleAttribute( "vMax", vMax );
		}
	}
	if ( hMin == NULL || sMin == NULL || vMin == NULL ||
			hMax == NULL || sMax == NULL || vMax == NULL )
		throw std::runtime_error( "Exception: Property missing!" );

	hsvMin = cv::Scalar( *hMin, *sMin, *vMin );
	hsvMax = cv::Scalar( *hMax, *sMax, *vMax );

	std::cout << "hsvMin: " << \
			hsvMin( 0 ) << ", " <<
			hsvMin( 1 ) << ", " <<
			hsvMin( 2 ) << ", " <<
			hsvMin( 3 ) << std::endl;
	std::cout << "hsvMax: " << \
			hsvMax( 0 ) << ", " <<
			hsvMax( 1 ) << ", " <<
			hsvMax( 2 ) << ", " <<
			hsvMax( 3 ) << std::endl;
}

void IPXMLParser::getProperties( cv::Scalar & hsvMin, \
							     cv::Scalar & hsvMax ) {
	if ( hsvMin( 0 ) >= hsvMax( 0 ) )
		throw std::runtime_error( "hMin >= hMax" );

	if ( hsvMin( 1 ) >= hsvMax( 1 ) )
		throw std::runtime_error( "sMin >= sMax" );

	if ( hsvMin( 2 ) >= hsvMax( 2 ) )
		throw std::runtime_error( "vMin >= vMax" );

	if ( hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255 )
		throw std::runtime_error( "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

	if ( hsvMin( 1 ) < 0 || hsvMax( 1 ) > 255 )
		throw std::runtime_error( "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

	if ( hsvMin( 2 ) < 0 || hsvMax( 2 ) > 255 )
		throw std::runtime_error( "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

	if ( hsvMin( 3 ) != 0.0 || hsvMax( 3 ) != 0.0 )
		throw std::runtime_error( "Exception: last value of threshold not 0!" );

	if ( hsvMin == cv::Scalar::zeros() && hsvMax == cv::Scalar::zeros() )
		throw std::runtime_error( "Exception: hsvMin == cv::Scalar::zeros() && hsvMax == cv::Scalar::zeros()" );

	hsvMin = this->hsvMin;
	hsvMax = this->hsvMax;
}

void IPXMLParser::setFileName( const char * fileName ) {
	this->fileName = fileName;
}
