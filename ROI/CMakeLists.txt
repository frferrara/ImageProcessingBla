add_library( ROI STATIC ROI.cpp ROI.hpp )
target_link_libraries( ROI
                       ${OpenCV_LIBS}
                       IPState
                       IPXMLParser )

install( TARGETS ROI DESTINATION lib )
install( FILES ROI.hpp DESTINATION include )