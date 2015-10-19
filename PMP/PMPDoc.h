
// PMPDoc.h : interface of the CPMPDoc class
//


#pragma once

#include "vtkActor2D.h"
#include "vtkTextMapper.h"
#include "vtkBMPReader.h"
#include "vtkImageActor.h"
#include "vtkTextProperty.h"


class CPMPDoc : public CDocument
{
protected: // create from serialization only
	CPMPDoc();
	DECLARE_DYNCREATE(CPMPDoc)

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
	virtual ~CPMPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public :
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

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};
