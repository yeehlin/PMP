cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)

find_package( VTK )
if (VTK_FOUND)
	include (${VTK_USE_FILE})
else(VTK_FOUND)
	message (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR")
endif(VTK_FOUND)

SET( PROJECT_SRCS
	ShowImage.cxx
	CMakeLists.txt
	001comp.bmp
)

include(${VTK_USE_FILE})

add_executable(VTKShowBMP MACOSX_BUNDLE ${PROJECT_SRCS})
target_link_libraries(VTKShowBMP ${VTK_LIBRARIES})
