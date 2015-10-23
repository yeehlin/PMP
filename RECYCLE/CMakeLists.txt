#----------------------------------------------------------------------------------
cmake_minimum_required( VERSION 2.8 )
#----------------------------------------------------------------------------------

# 查找并包含VTK工具包
find_package( VTK )
if (VTK_FOUND)
	include (${VTK_USE_FILE})
else(VTK_FOUND)
	message (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR")
endif(VTK_FOUND)
#----------------------------------------------------------------------------------

# 这里添加本工程的文件
# 主要分为两部分:
# 一是新建的多文档程序中的非工程文件
# 二是用户后续添加的类文件

SET( PROJECT_SRCS

ChildFrm.cpp
ChildFrm.h
ClassView.cpp
ClassView.h
CMakeLists.txt
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
ElectricModelingDLGMore.cpp
ElectricModelingDLGMore.h
ElectricModelingDLGMoreDielectric.cpp
ElectricModelingDLGMoreDielectric.h
ElectricModelingDLGMoreElastic.cpp
ElectricModelingDLGMoreElastic.h
ElectricModelingDLGMorePiezoelectric.cpp
ElectricModelingDLGMorePiezoelectric.h
ElectricModelingDLGPhaseNo2.cpp
ElectricModelingDLGPhaseNo2.h
ElectricModelingDLGPhaseNo3.cpp
ElectricModelingDLGPhaseNo3.h
ElectricModelingDLGPhaseNo4.cpp
ElectricModelingDLGPhaseNo4.h
ElectricModelingDLGPhaseNo5.cpp
ElectricModelingDLGPhaseNo5.h
ElectricModelingDLGPhaseNo6.cpp
ElectricModelingDLGPhaseNo6.h
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
RECYCLE.cpp
RECYCLE.h
RECYCLE.rc
#RECYCLE.sdf
#RECYCLE.sln
#RECYCLE.vcxproj
#RECYCLE.vcxproj.filters
#RECYCLE.vcxproj.user
RECYCLEDoc.cpp
RECYCLEDoc.h
RECYCLEView.cpp
RECYCLEView.h
#res
Resource.h
stdafx.cpp
stdafx.h
targetver.h
UserImages.bmp
ViewTree.cpp
ViewTree.h
FileView.cpp
FileView.h
MainFrm.cpp
MainFrm.h
OutputWnd.cpp
OutputWnd.h
PropertiesWnd.cpp
PropertiesWnd.h
ReadMe.txt
RECYCLE.cpp
RECYCLE.h
RECYCLE.rc
#RECYCLE.sdf
#RECYCLE.sln
#RECYCLE.vcxproj
#RECYCLE.vcxproj.filters
#RECYCLE.vcxproj.user
RECYCLEDoc.cpp
RECYCLEDoc.h
RECYCLEView.cpp
RECYCLEView.h
#res
Resource.h
stdafx.cpp
stdafx.h
targetver.h
UserImages.bmp
ViewTree.cpp
ViewTree.h

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
res/RECYCLE.ico
res/RECYCLE.rc2
res/RECYCLEDoc.ico
res/sort.bmp
res/sort_hc.bmp
res/Toolbar.bmp
res/Toolbar256.bmp
	) 
#----------------------------------------------------------------------------------

# 设置工程包含的vtk模块，这里根据需要加载对应的模块
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

ADD_EXECUTABLE(RECYCLE WIN32 ${PROJECT_SRCS} )

TARGET_LINK_LIBRARIES(RECYCLE ${VTK_LIBRARIES})
