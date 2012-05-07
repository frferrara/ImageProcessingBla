add_library( IPState STATIC IPState.cpp IPState.hpp )
target_link_libraries( IPState
                       ${OpenCV_LIBS}
                       ImageProcessing )

install( TARGETS IPState DESTINATION lib )
install( FILES IPState.hpp DESTINATION include )