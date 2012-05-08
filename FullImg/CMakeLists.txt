add_library( FullImg STATIC FullImg.cpp FullImg.hpp )
target_link_libraries( FullImg
                       ${OpenCV_LIBS}
                       IPState
                       ROI
                       IPXMLParser )

install( TARGETS FullImg DESTINATION lib )
install( FILES FullImg.hpp DESTINATION include )