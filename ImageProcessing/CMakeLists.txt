add_library( ImageProcessing SHARED ImageProcessing.cpp ImageProcessing.cpp )

install( TARGETS ImageProcessing DESTINATION lib )
install( FILES ImageProcessing.hpp DESTINATION include )