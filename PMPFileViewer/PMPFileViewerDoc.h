
// PMPFileViewerDoc.h : interface of the CPMPFileViewerDoc class
//


#pragma once

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




class CPMPFileViewerDoc : public CDocument
{
protected: // create from serialization only
	CPMPFileViewerDoc();
	DECLARE_DYNCREATE(CPMPFileViewerDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CPMPFileViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public :
	CString m_text;
	CStringArray m_textArray;
	//***************vtk数据****************//
	void ExecutePipeline(CString bmpname);	
	vtkActor2D * m_pvtkActor2D;
	vtkTextMapper * m_pvtkTextMapper;
	vtkBMPReader *m_pvtkBMPReader;
	vtkImageActor *m_pvtkImageActor;
	vtkActor2D * GetActor2D(){
		return this->m_pvtkActor2D;
	};
	vtkImageActor * GetImageActor(){
		return this->m_pvtkImageActor;
	};
	//********动画操作接口**************
	bool CreateActors();
	bool AddActors();
	bool RemoveActors();
	bool DestroyActors();
	// 数据转换接口
	void PMPTransformToVTKForVolume(CString filename);
	void PMPTransformToVTKForPolarization(CString filename);
	void pmpvisualizationvolume(CString filename);
	void pmpvisualizationpolarization(CString filename);
	CString filename;
	CSize m_sizeDoc;
	CSize GetDocSize(){
		return m_sizeDoc;
	};
	CString txtFileContent;

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
