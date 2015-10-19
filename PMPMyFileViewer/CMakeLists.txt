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
FileView.cpp
FileView.h
MainFrm.cpp
MainFrm.h
OutputWnd.cpp
OutputWnd.h
PMPMyFileViewer.cpp
PMPMyFileViewer.h
PMPMyFileViewer.rc
PMPMyFileViewerDoc.cpp
PMPMyFileViewerDoc.h
PMPMyFileViewerView.cpp
PMPMyFileViewerView.h
PropertiesWnd.cpp
PropertiesWnd.h
ReadMe.txt
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
res/PMPMyFileViewer.ico
res/PMPMyFileViewer.rc2
res/PMPMyFileViewerDoc.ico
res/properties.bmp
res/properties_hc.bmp
res/properties_wnd.ico
res/properties_wnd_hc.ico
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

ADD_EXECUTABLE(PMPMyFileViewer WIN32 ${PROJECT_SRCS} )

TARGET_LINK_LIBRARIES(PMPMyFileViewer ${VTK_LIBRARIES})
