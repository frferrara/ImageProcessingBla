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

void IPXMLParser::parseXML() {
    if ( fileName.empty() )
        throw std::runtime_error( "Exception: fileName.empty()" );

    doc = TiXmlDocument( fileName );

    if ( !doc.LoadFile() )
        throw std::runtime_error( "Exception: XML file cannot be loaded!" );

    std::cout << fileName << " opened successfully!\n";

    TiXmlHandle hDoc( &doc );
    TiXmlHandle hRoot( NULL );

    el = hDoc.FirstChildElement( "Properties" ).ToElement();

    if ( !el )
        throw std::runtime_error(
                "Exception: XML file empty or 'Properties' missing!" );

    hRoot = TiXmlHandle( el );

    TiXmlElement * properties = hRoot.FirstChild( "Property" ).ToElement();

    if ( !properties )
        throw std::runtime_error( "Exception: 'Properties' is empty!" );

    for ( ; properties;
            properties = properties->NextSiblingElement( "Property" ) ) {
        const char * elName = properties->Attribute( "name" );

        if ( !properties )
            throw std::runtime_error( "Exception: no element named Property!" );

        if ( strcmp( elName, "hsvMin" ) != 0
                && std::strcmp( elName, "hsvMax" ) != 0 )
            throw std::runtime_error(
                    "Exception: hsvMin and hsvMax not available!" );

        if ( strcmp( elName, "hsvMin" ) == 0 ) {
            double hMin, sMin, vMin;

            properties->QueryDoubleAttribute( "hMin", &hMin );
            properties->QueryDoubleAttribute( "sMin", &sMin );
            properties->QueryDoubleAttribute( "vMin", &vMin );

            hsvMin = cv::Scalar( hMin, sMin, vMin );

            std::cout << "hsvMin: " << hsvMin( 0 ) << " " << hsvMin( 1 ) << " "
                    << hsvMin( 2 ) << " " << hsvMin( 3 ) << std::endl;
        }

        if ( strcmp( elName, "hsvMax" ) == 0 ) {
            double hMax, sMax, vMax;

            properties->QueryDoubleAttribute( "hMax", &hMax );
            properties->QueryDoubleAttribute( "sMax", &sMax );
            properties->QueryDoubleAttribute( "vMax", &vMax );

            hsvMax = cv::Scalar( hMax, sMax, vMax );

            std::cout << "hsvMax: " << hsvMax( 0 ) << " " << hsvMax( 1 ) << " "
                    << hsvMax( 2 ) << " " << hsvMax( 3 ) << std::endl;
        }
    }
}

void IPXMLParser::getProperties( cv::Scalar & hsvMin,
                                 cv::Scalar & hsvMax ) {
    if ( this->hsvMin == cv::Scalar::zeros()
            && this->hsvMax == cv::Scalar::zeros() )
        throw std::runtime_error( "Exception: HSV values are zero!" );

    if ( this->hsvMin( 0 ) >= this->hsvMax( 0 ) )
        throw std::runtime_error( "hMin >= hMax" );

    if ( this->hsvMin( 1 ) >= this->hsvMax( 1 ) )
        throw std::runtime_error( "sMin >= sMax" );

    if ( this->hsvMin( 2 ) >= this->hsvMax( 2 ) )
        throw std::runtime_error( "vMin >= vMax" );

    if ( this->hsvMin( 0 ) < 0 || this->hsvMax( 0 ) > 255 )
        throw std::runtime_error(
                "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

    if ( this->hsvMin( 1 ) < 0 || this->hsvMax( 1 ) > 255 )
        throw std::runtime_error(
                "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

    if ( this->hsvMin( 2 ) < 0 || this->hsvMax( 2 ) > 255 )
        throw std::runtime_error(
                "Exception: hsvMin( 0 ) < 0 || hsvMax( 0 ) > 255" );

    if ( this->hsvMin( 3 ) != 0.0 || this->hsvMax( 3 ) != 0.0 )
        throw std::runtime_error( "Exception: last value of threshold not 0!" );

    hsvMin = this->hsvMin;
    hsvMax = this->hsvMax;
}

void IPXMLParser::setFileName( const char * fileName ) {
    this->fileName = fileName;
}
