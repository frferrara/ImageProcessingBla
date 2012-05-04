add_library( ImageProcessing STATIC ImageProcessing.cpp ImageProcessing.cpp )
target_link_libraries( ImageProcessing
                       /opt/local/lib/libopencv_core.dylib
                       FullImg )

install( TARGETS ImageProcessing DESTINATION lib )
install( FILES ImageProcessing.hpp DESTINATION include )