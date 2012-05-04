add_library( FullImg STATIC FullImg.cpp FullImg.hpp )
target_link_libraries( FullImg
                       /opt/local/lib/libopencv_core.dylib
                       IPState
                       ROI )

install( TARGETS FullImg DESTINATION lib )
install( FILES FullImg.hpp DESTINATION include )