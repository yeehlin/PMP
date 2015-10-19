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

	// �µ���ʾ����
	// �������ݵĵ�ֵ��
	void PMPVisualizeIsosurface(CString filename,vtkRenderer * renderer);
	// �������ݵ������
	void PMPVisualizeVolumn(CString filename,vtkRenderer * renderer);
	// Scalar���ݿ��ӻ�
	void PMPVisualizeScalar1D(CString filename,vtkRenderer * renderer);
	// Vector���ݿ��ӻ�
	void PMPVisualizeVector3D(CString filename,vtkRenderer * renderer);
	// Tensor���ݿ��ӻ�
	void PMPVisualizeTensor33D(CString filename,vtkRenderer * renderer);
	// Vector����Streamline���ӻ�
	void PMPVisualizeVector3DStreamline(CString filename,vtkRenderer * renderer);
	// Tensor����Multiview
	void PMPVisualizeTensor33DMultiview(CString filename,vtkRenderer * renderer[9]);
public :
	////////////////////////////////////////������//////////////////////////////////
	// Scalar��ͼ������
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
	// Vecotr��ͼ������
	vtkGlyph3D * glyph;
	double scaleFactor;
	double m_Vector3Dscalar_range0;
	double m_Vector3Dscalar_range1;
	// Streamline��ͼ������
	int x;
	int y;
	int z;
	int nPoints;
	int radius;
	vtkPointSource * m_pVectorSeeds;
	// ʹ�ù�������
	vtkColorTransferFunction * color;
	vtkPiecewiseFunction * opacity;
	vtkVolumeProperty * volumeProperty;
	double scalar_range0;
	double scalar_range1;
	double * scalar_range;
	double diff;
	vtkScalarBarActor * scaleBar;
	vtkTensorGlyph * tensorglyph;
	////////////////////////////////////////������//////////////////////////////////
public:
	////////////////////////////////////////��������//////////////////////////////////
	void IsosurfaceCreator();
	void ScalarCreator();
	void VectorCreator();
	void VectorStreamlineCreator();
	void TensorCreator();
	void TensorMultiviewCreator();
	void VolumeCreator();
	////////////////////////////////////////��������//////////////////////////////////
public:
	////////////////////////////////////////��������//////////////////////////////////
	void IsosurfaceDestroy();
	void ScalarDestroy();
	void VectorDestroy();
	void VectorStreamlineDestroy();
	void TensorDestroy();
	void TensorMultiviewDestroy();
	void VolumeDestroy();
	////////////////////////////////////////��������//////////////////////////////////
};


