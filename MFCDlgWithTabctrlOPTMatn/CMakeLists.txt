#----------------------------------------------------------------------------------
#cmake_minimum_required( VERSION 2.8 )
#����д����������ƣ�������Ŀ�����ƣ����˴���Ӧ��д����Ϊ����һ�������ڽ����������Ŀ����������ڸ���Ŀ¼
#project(SLNName)
#----------------------------------------------------------------------------------

# ���Ҳ�����VTK���߰�
#�������CMakeLists.txt�ļ��Ѿ����ڸ���������ڲ�ȥ��find_package
#������Ǳ����ڲ�find_package�����Ϊ��ͬ����Ŀ��Ҫ��ͬ�İ�
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

ChildFrm.cpp
ChildFrm.h
ClassView.cpp
ClassView.h
CMakeLists.txt
ElectricModelingDLGChild1.cpp
ElectricModelingDLGChild1.h
ElectricModelingDLGDielectric.cpp
ElectricModelingDLGDielectric.h
ElectricModelingDLGDielectricExternal.cpp
ElectricModelingDLGDielectricExternal.h
ElectricModelingDLGDiffusivity.cpp
ElectricModelingDLGDiffusivity.h
ElectricModelingDLGDiffusivityExternal.cpp
ElectricModelingDLGDiffusivityExternal.h
ElectricModelingDLGElastic.cpp
ElectricModelingDLGElastic.h
ElectricModelingDLGElasticExternal.cpp
ElectricModelingDLGElasticExternal.h
ElectricModelingDLGFather.cpp
ElectricModelingDLGFather.h
ElectricModelingDLGMagnetic.cpp
ElectricModelingDLGMagnetic.h
ElectricModelingDLGMagneticExternal.cpp
ElectricModelingDLGMagneticExternal.h
ElectricModelingDLGMagnetoelectric.cpp
ElectricModelingDLGMagnetoelectric.h
ElectricModelingDLGMagnetoelectricExternal.cpp
ElectricModelingDLGMagnetoelectricExternal.h
ElectricModelingDLGMoreDielectric.cpp
ElectricModelingDLGMoreDielectric.h
ElectricModelingDLGMoreDiffusivity.cpp
ElectricModelingDLGMoreDiffusivity.h
ElectricModelingDLGMoreElastic.cpp
ElectricModelingDLGMoreElastic.h
ElectricModelingDLGMoreMagnetic.cpp
ElectricModelingDLGMoreMagnetic.h
ElectricModelingDLGMoreMagnetoelectric.cpp
ElectricModelingDLGMoreMagnetoelectric.h
ElectricModelingDLGMorePiezoelectric.cpp
ElectricModelingDLGMorePiezoelectric.h
ElectricModelingDLGMorePiezomagnetic.cpp
ElectricModelingDLGMorePiezomagnetic.h
ElectricModelingDLGMoreThermal.cpp
ElectricModelingDLGMoreThermal.h
ElectricModelingDLGPiezoelectric.cpp
ElectricModelingDLGPiezoelectric.h
ElectricModelingDLGPiezoelectricExternal.cpp
ElectricModelingDLGPiezoelectricExternal.h
ElectricModelingDLGPiezomagnetic.cpp
ElectricModelingDLGPiezomagnetic.h
ElectricModelingDLGPiezomagneticExternal.cpp
ElectricModelingDLGPiezomagneticExternal.h
ElectricModelingDLGThermal.cpp
ElectricModelingDLGThermal.h
ElectricModelingDLGThermalExternal.cpp
ElectricModelingDLGThermalExternal.h
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
TestMFCDlgWithTabctrl.cpp
TestMFCDlgWithTabctrl.h
TestMFCDlgWithTabctrl.rc
TestMFCDlgWithTabctrlDoc.cpp
TestMFCDlgWithTabctrlDoc.h
TestMFCDlgWithTabctrlView.cpp
TestMFCDlgWithTabctrlView.h
UserImages.bmp
ViewTree.cpp
ViewTree.h
ElectricModelingDLGSharedData.cpp
ElectricModelingDLGSharedData.h


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
res/TestMFCDlgWithTabctrl.ico
res/TestMFCDlgWithTabctrl.rc2
res/TestMFCDlgWithTabctrlDoc.ico
res/Toolbar.bmp
res/Toolbar256.bmp


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
#�����Ҫ��д��Ŀ�����ƣ�Ҳ������Ŀ�����ļ��е����ƣ��������CMakeLists.txt�ļ������ļ���һ�µġ�
#${PROJECT_NAME}��ò�Ҫ�ã���Ϊ���������ʾ�������������
ADD_EXECUTABLE(MFCDlgWithTabctrlOPTMatn WIN32 ${PROJECT_SRCS} )

TARGET_LINK_LIBRARIES(MFCDlgWithTabctrlOPTMatn ${VTK_LIBRARIES})