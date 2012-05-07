add_library( ImageProcessing STATIC ImageProcessing.cpp ImageProcessing.cpp )
target_link_libraries( ImageProcessing
                       ${OpenCV_LIBS}
                       FullImg )

install( TARGETS ImageProcessing DESTINATION lib )
install( FILES ImageProcessing.hpp DESTINATION include )