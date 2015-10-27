#----------------------------------------------------------------------------------
#cmake_minimum_required( VERSION 2.8 )
#这里写解决方案名称，不是项目的名称，但此处不应该写，因为这是一个包含于解决方案的项目，解决方案在父级目录
#project(SLNName)
#----------------------------------------------------------------------------------

# 查找并包含VTK工具包
#由于外层CMakeLists.txt文件已经存在该命令，所以内层去掉find_package
#但最好是保留内层find_package命令，因为不同的项目需要不同的包
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
PMPWindowsClientMFC.cpp
PMPWindowsClientMFC.h
PMPWindowsClientMFC.rc
PMPWindowsClientMFCDoc.cpp
PMPWindowsClientMFCDoc.h
PMPWindowsClientMFCView.cpp
PMPWindowsClientMFCView.h
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
PMPDlgJobs.cpp
PMPDlgJobs.h
PMPSocket.h
NETPMP.cpp
NETPMP.h
PMPServers.h
PMPServers.cpp

#parameter.in
#struct.in


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
res/PMPWindowsClientMFC.ico
res/PMPWindowsClientMFC.rc2
res/PMPWindowsClientMFCDoc.ico
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
#这里就要填写项目的名称，也就是项目所在文件夹的名称，这与外层CMakeLists.txt文件中子文件是一致的。
#${PROJECT_NAME}最好不要用，因为这个变量表示解决方案的名称
ADD_EXECUTABLE(PMPWindowsClientMFC WIN32 ${PROJECT_SRCS} )

TARGET_LINK_LIBRARIES(PMPWindowsClientMFC ${VTK_LIBRARIES})
