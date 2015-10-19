#pragma once

#include "vtkActor2D.h"
#include "vtkTextMapper.h"
#include "vtkBMPReader.h"
#include "vtkImageActor.h"
#include "vtkTextProperty.h"

// CPMPBmpDoc document

class CPMPBmpDoc : public CDocument
{
	DECLARE_DYNCREATE(CPMPBmpDoc)

public:
	CPMPBmpDoc();
	virtual ~CPMPBmpDoc();
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
	//***************vtk数据****************//
	void ExecutePipeline(CString bmpname);	
	vtkActor2D * m_pvtkActor2D;
	vtkTextMapper * m_pvtkTextMapper;
	vtkBMPReader *m_pvtkBMPReader;
	vtkImageActor *m_pvtkImageActor;
	//********动画操作接口**************
	bool CreateActors();
	bool AddActors();
	bool RemoveActors();
	bool DestroyActors();
};
