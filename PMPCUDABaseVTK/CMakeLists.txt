SET( PROJECT_SRCS
CMakeLists.txt
volumeRender.cpp
volumeRender_kernel.cu
)

set(VTK_LIBS ${vtk_libraries}
	vtkIO
	vtkRendering 
	vtkGraphics 
	vtkHybrid 
	vtkFiltering 
	vtkCommon 
	vtkImaging 
)


add_executable(PMPCUDABaseVTK MACOSX_BUNDLE ${PROJECT_SRCS})


TARGET_LINK_LIBRARIES(PMPCUDABaseVTK ${VTK_LIBRARIES})
