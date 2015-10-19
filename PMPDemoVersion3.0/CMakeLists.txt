#----------------------------------------------------------------------------------
cmake_minimum_required( VERSION 2.8 )
#----------------------------------------------------------------------------------

# ���Ҳ�����VTK���߰�
find_package( VTK )
if (VTK_FOUND)
	include (${VTK_USE_FILE})
else(VTK_FOUND)
	message (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR")
endif(VTK_FOUND)
#----------------------------------------------------------------------------------

# �������ӱ����̵��ļ�
# ��Ҫ��Ϊ������:
# һ���½��Ķ��ĵ������еķǹ����ļ�
# �����û��������ӵ����ļ�

SET( PROJECT_SRCS

CalculateDlgChild1.cpp
CalculateDlgChild1.h
CalculateDlgChild2.cpp
CalculateDlgChild2.h
CalculateDlgChild3.cpp
CalculateDlgChild3.h
CalculateDlgFather.cpp
CalculateDlgFather.h
ChildFrm.cpp
ChildFrm.h
ClassView.cpp
ClassView.h
CMakeLists.txt
ElectricModelingDLGChild1.cpp
ElectricModelingDLGChild1.h
ElectricModelingDLGChild2.cpp
ElectricModelingDLGChild2.h
ElectricModelingDLGChild3.cpp
ElectricModelingDLGChild3.h
ElectricModelingDLGDielectric.cpp
ElectricModelingDLGDielectric.h
ElectricModelingDLGElastic.cpp
ElectricModelingDLGElastic.h
ElectricModelingDLGExternal.cpp
ElectricModelingDLGExternal.h
ElectricModelingDLGFather.cpp
ElectricModelingDLGFather.h
ElectricModelingDLGMechanical.cpp
ElectricModelingDLGMechanical.h
ElectricModelingDLGMoreDielectric.cpp
ElectricModelingDLGMoreDielectric.h
ElectricModelingDLGMoreElastic.cpp
ElectricModelingDLGMoreElastic.h
ElectricModelingDLGMorePiezoelectric.cpp
ElectricModelingDLGMorePiezoelectric.h
ElectricModelingDLGPiezoelectric.cpp
ElectricModelingDLGPiezoelectric.h
FileView.cpp
FileView.h
MainFrm.cpp
MainFrm.h
OutputWnd.cpp
OutputWnd.h
PropertiesWnd.cpp
PropertiesWnd.h
ReadMe.txt
resource.h
stdafx.cpp
stdafx.h
targetver.h
UserImages.bmp
ViewTree.cpp
ViewTree.h
VTKMFCCreateBMPActors.cpp
VTKMFCCreateBMPActors.h
VTKMFCCreateBMPActors.rc
VTKMFCCreateBMPActorsDoc.cpp
VTKMFCCreateBMPActorsDoc.h
VTKMFCCreateBMPActorsView.cpp
VTKMFCCreateBMPActorsView.h

bin/spin/input.dat
bin/spin/spinodal01.exe
bin/piez/pieze.exe
bin/piez/parameter.in
bin/piez/struct.in

res/classview.bmp
res/classview_hc.bmp
res/class_view.ico
res/class_view_hc.ico
res/explorer.bmp
res/explorer_hc.bmp
res/fileview.bmp
res/fileview_hc.bmp
res/file_view.ico
res/file_view_hc.ico
res/menuimages.bmp
res/menuimages_hc.bmp
res/output_wnd.ico
res/output_wnd_hc.ico
res/properties.bmp
res/properties_hc.bmp
res/properties_wnd.ico
res/properties_wnd_hc.ico
res/sort.bmp
res/sort_hc.bmp
res/Toolbar.bmp
res/Toolbar256.bmp
res/VTKMFCCreateBMPActors.ico
res/VTKMFCCreateBMPActors.rc2
res/VTKMFCCreateBMPActorsDoc.ico
	) 
#----------------------------------------------------------------------------------

# ���ù��̰�����vtkģ�飬���������Ҫ���ض�Ӧ��ģ��
include("${VTK_DIR}/GUISupport/MFC/VTKMFCSettings.cmake")
set(VTK_LIBS ${vtk_libraries}
	vtkMFC
	vtkIO
	vtkRendering 
	vtkGraphics 
	vtkHybrid 
	vtkFiltering 
	vtkCommon 
	vtkImaging 
)
#----------------------------------------------------------------------------------

ADD_EXECUTABLE(PMPDemoVersion3.0 WIN32 ${PROJECT_SRCS} )

TARGET_LINK_LIBRARIES(PMPDemoVersion3.0 ${VTK_LIBRARIES})