#----------------------------------------------------------------------------------
# cmake_minimum_required( VERSION 2.8 )
#----------------------------------------------------------------------------------

# 设置工程包含的vtk模块，这里根据需要加载对应的模块
include("${VTK_DIR}/GUISupport/MFC/VTKMFCSettings.cmake")
IF(VTK_MFC_DELAYLOAD_VTK_DLLS)
  VTK_MFC_ADD_DELAYLOAD_FLAGS(CMAKE_EXE_LINKER_FLAGS
    vtkMFC.dll
    vtkRendering.dll
    vtkIO.dll
    vtkFiltering.dll
    vtkCommon.dll
    )
ENDIF(VTK_MFC_DELAYLOAD_VTK_DLLS)
set(VTK_LIBS ${vtk_libraries}
	vtkMFC
	vtkIO
	vtkRendering
	vtkGraphics
	vtkHybrid
	vtkFiltering
	vtkCommon
	vtkImaging
	vtkVolumeRendering
)
#----------------------------------------------------------------------------------

# 查找并包含VTK工具包
#find_package( VTK )
#if (VTK_FOUND)
#	include (${VTK_USE_FILE})
#else(VTK_FOUND)
#	message (FATAL_ERROR "Cannot build without VTK. Please set VTK_DIR")
#endif(VTK_FOUND)
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
PMP.cpp
PMP.h
PMP.rc
PMPDoc.cpp
PMPDoc.h
PMPView.cpp
PMPView.h
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
#added in 20140730
CalculateDlgChild1.cpp
CalculateDlgChild1.h
CalculateDlgChild2.cpp
CalculateDlgChild2.h
CalculateDlgChild3.cpp
CalculateDlgChild3.h
CalculateDlgFather.cpp
CalculateDlgFather.h
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
PMPBmpDoc.cpp
PMPBmpDoc.h
PMPBmpView.cpp
PMPBmpView.h
PMPDatDoc.cpp
PMPDatDoc.h
PMPDatView.cpp
PMPDatView.h
PMPTxtDoc.cpp
PMPTxtDoc.h
PMPTxtView.cpp
PMPTxtView.h
PMPDatStreamlineView.cpp
PMPDatStreamlineView.h
PMPTensorDatMultiView.cpp
PMPTensorDatMultiView.h
PMPTensorDatTensoView.cpp
PMPTensorDatTensoView.h
PMPTensorDatDoc.cpp
PMPTensorDatDoc.h
PMPTensorDatView.cpp
PMPTensorDatView.h
PMPTransformer.cpp
PMPTransformer.h
PMPVisualization.cpp
PMPVisualization.h
DialogOpenwith.cpp
DialogOpenwith.h
PMPScalarDatDoc.cpp
PMPScalarDatDoc.h
PMPScalarDatView.cpp
PMPScalarDatView.h
PMPVisualizationDLG.cpp
PMPVisualizationDLG.h
PMPScalarDatGridView.cpp
PMPScalarDatGridView.h
PMPVectorDatVolumeView.cpp
PMPVectorDatVolumeView.h
IsosurfaceDlg.cpp
IsosurfaceDlg.h
ProcessCreater.cpp
ProcessCreater.h
WorkSpaceDlg.cpp
WorkSpaceDlg.h
StreamlineSeedsDlg.cpp
StreamlineSeedsDlg.h
PointsColorDlg.cpp
PointsColorDlg.h
ScaleFactorDlg.cpp
ScaleFactorDlg.h

#bin/spin/input.dat
#bin/spin/spinodal01.exe
#bin/piez/pieze.exe
#bin/piez/parameter.in
#bin/piez/struct.in

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
res/PMP.ico
res/PMP.rc2
res/PMPDoc.ico
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


ADD_EXECUTABLE(PMP WIN32 ${PROJECT_SRCS})

IF(VTK_MFC_EXTRA_LIBS)
  TARGET_LINK_LIBRARIES(PMP ${VTK_MFC_EXTRA_LIBS})
ENDIF(VTK_MFC_EXTRA_LIBS)

TARGET_LINK_LIBRARIES(PMP ${VTK_LIBS})
