
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

	// 显示BMP图片

	vtkBMPReader *pvtkBMPReader;
	vtkImageActor *pvtkImageActor;

	// 显示VTK数据
	//vtkDataSetReader * pvtkDataSetReader;
	//vtkDataSetMapper * pvtkDataSetMapper;
public:
	// 执行管线操作
	void ExecutePipeline(CString bmpname);	
	// 获取actor2D的接口
	vtkActor2D * GetActor2D(){
		//ASSERT(this->pvtkActor2D);
		return this->pvtkActor2D;
	};
	// 获取actor的接口
	//vtkActor * GetActor(){
		//ASSERT(this->pvtkActor);
	//	return this->pvtkActor;
	//};
	// 获取imageactor的接口
	vtkImageActor * GetImageActor(){
		//ASSERT(this->pvtkImageActor);
		return this->pvtkImageActor;
	};
	bool CreateActors();
	afx_msg void OnCreateactorsCreatebmpactor();
	// 销毁Actor相关的对象
	bool DestroyActors();
	afx_msg void OnDestroyactorsDestroybmpactor();
	// 移除actor
	bool RemoveActors();
	// 添加actor
	bool AddActors();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
//	afx_msg void OnSpinodaldecompositionCalculate();
//	afx_msg void OnRunGo();
//	afx_msg void OnRunGo();
	CFile bmpfile;
};
