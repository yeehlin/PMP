SET( PROJECT_SRCS
	ImageProcess.cpp
	CMakeLists.txt
)
set(VTK_LIBS  ${vtk_libraries}
	vtkIO
	vtkRendering
	vtkGraphics
	vtkHybrid
	vtkFiltering
	vtkCommon
	vtkImaging
	vtkVolumeRendering
)
add_executable(PMPImageProcess MACOSX_BUNDLE ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES(PMPImageProcess ${VTK_LIBS})
