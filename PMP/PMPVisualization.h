#pragma once


#include "vtkDataSetReader.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCommand.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkPointData.h"
#include "vtkContourFilter.h"
#include "vtkDataSetMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkArrowSource.h"
#include "vtkMaskPoints.h"
#include "vtkOutlineFilter.h"
#include "vtkGlyph3D.h"
#include "vtkTransform.h"
#include "vtkAxesActor.h"
#include "vtkCaptionActor2D.h"
#include "vtkProperty2D.h"
#include "vtkLookupTable.h"
#include "vtkSmartVolumeMapper.h"
#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkStructuredPointsReader.h"
#include "vtkSuperquadricSource.h"
#include "vtkTensorGlyph.h"
#include "vtkPointSource.h"
#include "vtkStreamLine.h"
#include "vtkStructuredPoints.h"
#include "vtkExtractTensorComponents.h"
#include "vtkScalarBarActor.h"
#include "vtkTextProperty.h"

// CPMPTransformer command target

class CPMPVisualization : public CObject
{
public:
	CPMPVisualization();
	virtual ~CPMPVisualization();
public:

	// 新的显示程序
	// 标量数据的等值面
	void PMPVisualizeIsosurface(CString filename,vtkRenderer * renderer);
	// 标量数据的体绘制
	void PMPVisualizeVolumn(CString filename,vtkRenderer * renderer);
	// Scalar数据可视化
	void PMPVisualizeScalar1D(CString filename,vtkRenderer * renderer);
	// Vector数据可视化
	void PMPVisualizeVector3D(CString filename,vtkRenderer * renderer);
	// Tensor数据可视化
	void PMPVisualizeTensor33D(CString filename,vtkRenderer * renderer);
	// Vector数据Streamline可视化
	void PMPVisualizeVector3DStreamline(CString filename,vtkRenderer * renderer);
	// Tensor数据Multiview
	void PMPVisualizeTensor33DMultiview(CString filename,vtkRenderer * renderer[9]);
public :
	////////////////////////////////////////数据区//////////////////////////////////
	// Scalar绘图数据区
	vtkColorTransferFunction * m_pScalar1Dcolor;
	int RGBPoint;
	int opacityPoint;
	double * RGBValue;
	double ** RGB;
	double * opValue;
	double * alpha;
	vtkActor * m_pScalar1Dactor;
	vtkActor * m_pScalar1Dactor1;
	vtkActor * m_pScalar1Dactor2;
	vtkContourFilter * m_pScalar1DContour;
	vtkContourFilter * m_pScalar1DContour1;
	double m_Scalar1DRange0;
	double m_Scalar1DRange1;
	double m_Scalar1DRange;
	double m_Scalar1DIsoValue1;
	double m_Scalar1DIsoValue2;
	double m_Scalar1DIso1Opacity;
	double m_Scalar1DIso2Opacity;
	// Vecotr绘图数据区
	vtkGlyph3D * glyph;
	double scaleFactor;
	double m_Vector3Dscalar_range0;
	double m_Vector3Dscalar_range1;
	// Streamline绘图数据区
	int x;
	int y;
	int z;
	int nPoints;
	int radius;
	vtkPointSource * m_pVectorSeeds;
	// 使用公共数据
	vtkColorTransferFunction * color;
	vtkPiecewiseFunction * opacity;
	vtkVolumeProperty * volumeProperty;
	double scalar_range0;
	double scalar_range1;
	double * scalar_range;
	double diff;
	vtkScalarBarActor * scaleBar;
	vtkTensorGlyph * tensorglyph;
	////////////////////////////////////////数据区//////////////////////////////////
public:
	////////////////////////////////////////创建数据//////////////////////////////////
	void IsosurfaceCreator();
	void ScalarCreator();
	void VectorCreator();
	void VectorStreamlineCreator();
	void TensorCreator();
	void TensorMultiviewCreator();
	void VolumeCreator();
	////////////////////////////////////////创建数据//////////////////////////////////
public:
	////////////////////////////////////////销毁数据//////////////////////////////////
	void IsosurfaceDestroy();
	void ScalarDestroy();
	void VectorDestroy();
	void VectorStreamlineDestroy();
	void TensorDestroy();
	void TensorMultiviewDestroy();
	void VolumeDestroy();
	////////////////////////////////////////销毁数据//////////////////////////////////
};


