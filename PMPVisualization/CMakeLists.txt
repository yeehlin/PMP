cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)

find_package( VTK )
if (VTK_FOUND)
	include (${VTK_USE_FILE})
else(VTK_FOUND)
	message (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR")
endif(VTK_FOUND)

SET( PROJECT_SRCS
CMakeLists.txt
#eleField.00000000.dat
#elePlrz.00000000.dat
pmptransformation.cpp
pmpvisualization.cxx
#strain.00000000.dat
#stress.00000000.dat
#struct.in
)

include(${VTK_USE_FILE})

add_executable(PMPVisualization MACOSX_BUNDLE ${PROJECT_SRCS})
target_link_libraries(PMPVisualization ${VTK_LIBRARIES})
