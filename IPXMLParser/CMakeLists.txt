add_library( IPXMLParser SHARED IPXMLParser.cpp IPXMLParser.hpp )
target_link_libraries( IPXMLParser 
                       ${OpenCV_LIBS}
                       /opt/local/lib/libtinyxml.dylib )

install( TARGETS IPXMLParser DESTINATION lib )
install( FILES IPXMLParser.hpp DESTINATION include )