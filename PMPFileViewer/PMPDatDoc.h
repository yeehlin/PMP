#pragma once

// CPMPDatDoc document

#include "vtkActor2D.h"
#include "vtkTextMapper.h"
#include "vtkBMPReader.h"
#include "vtkImageActor.h"
#include "vtkTextProperty.h"

// for visualization
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



class CPMPDatDoc : public CDocument
{
	DECLARE_DYNCREATE(CPMPDatDoc)

public:
	CPMPDatDoc();
	virtual ~CPMPDatDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public :
	// 数据转换接口
	void PMPTransformToVTKForVolume(CString filename);
	void PMPTransformToVTKForPolarization(CString filename);
	void pmpvisualizationvolume(CString filename);
	void pmpvisualizationpolarization(CString filename);
};
