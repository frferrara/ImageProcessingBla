add_library( ROI STATIC ROI.cpp ROI.hpp )
target_link_libraries( ROI
                       /opt/local/lib/libopencv_core.dylib
                       IPState )

install( TARGETS ROI DESTINATION lib )
install( FILES ROI.hpp DESTINATION include )