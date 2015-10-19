
// VTKMFCCreateBMPActorsDoc.h : interface of the CVTKMFCCreateBMPActorsDoc class
//


#pragma once

#include "vtkActor.h"
#include "vtkActor2D.h"
#include "vtkTextMapper.h"
#include "vtkBMPReader.h"
#include "vtkImageActor.h"
#include "vtkDataSetReader.h"
#include "vtkDataSetMapper.h"


//#include "PMPSpindecomCalculateDlgFather.h"

class CVTKMFCCreateBMPActorsDoc : public CDocument
{
protected: // create from serialization only
	CVTKMFCCreateBMPActorsDoc();
	DECLARE_DYNCREATE(CVTKMFCCreateBMPActorsDoc)

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
	virtual ~CVTKMFCCreateBMPActorsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

private :
	//vtkActor            *pvtkActor;
	vtkActor2D            *pvtkActor2D;
	vtkTextMapper          *pvtkTextMapper;

	// ��ʾBMPͼƬ

	vtkBMPReader *pvtkBMPReader;
	vtkImageActor *pvtkImageActor;

	// ��ʾVTK����
	//vtkDataSetReader * pvtkDataSetReader;
	//vtkDataSetMapper * pvtkDataSetMapper;
public:
	// ִ�й��߲���
	void ExecutePipeline(CString bmpname);	
	// ��ȡactor2D�Ľӿ�
	vtkActor2D * GetActor2D(){
		//ASSERT(this->pvtkActor2D);
		return this->pvtkActor2D;
	};
	// ��ȡactor�Ľӿ�
	//vtkActor * GetActor(){
		//ASSERT(this->pvtkActor);
	//	return this->pvtkActor;
	//};
	// ��ȡimageactor�Ľӿ�
	vtkImageActor * GetImageActor(){
		//ASSERT(this->pvtkImageActor);
		return this->pvtkImageActor;
	};
	bool CreateActors();
	afx_msg void OnCreateactorsCreatebmpactor();
	// ����Actor��صĶ���
	bool DestroyActors();
	afx_msg void OnDestroyactorsDestroybmpactor();
	// �Ƴ�actor
	bool RemoveActors();
	// ���actor
	bool AddActors();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
//	afx_msg void OnSpinodaldecompositionCalculate();
//	afx_msg void OnRunGo();
//	afx_msg void OnRunGo();
	CFile bmpfile;
};
