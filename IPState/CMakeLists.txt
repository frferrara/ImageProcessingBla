add_library( IPState STATIC IPState.cpp IPState.hpp )
target_link_libraries( IPState
                       /opt/local/lib/libopencv_core.dylib
                       ImageProcessing )

install( TARGETS IPState DESTINATION lib )
install( FILES IPState.hpp DESTINATION include )