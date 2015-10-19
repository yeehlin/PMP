// PMPScalarDatDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPScalarDatDoc.h"

#include "PMPScalarDatView.h"
#include "PMPScalarDatGridView.h"

// CPMPScalarDatDoc

IMPLEMENT_DYNCREATE(CPMPScalarDatDoc, CDocument)

CPMPScalarDatDoc::CPMPScalarDatDoc()
{
	m_viewType = 0;
}

BOOL CPMPScalarDatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPScalarDatDoc::~CPMPScalarDatDoc()
{
}


BEGIN_MESSAGE_MAP(CPMPScalarDatDoc, CDocument)
END_MESSAGE_MAP()


// CPMPScalarDatDoc diagnostics

#ifdef _DEBUG
void CPMPScalarDatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPScalarDatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPScalarDatDoc serialization
void CPMPScalarDatDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		// 
		filename = ar.m_strFileName;
		POSITION pos = this->GetFirstViewPosition();
		CView * scalarView= this->GetNextView(pos);
		if(scalarView->IsKindOf(RUNTIME_CLASS(CPMPScalarDatView))){
			((CPMPScalarDatView * )scalarView)->filename = filename;
		}else if(scalarView->IsKindOf(RUNTIME_CLASS(CPMPScalarDatGridView))){
			((CPMPScalarDatGridView * )scalarView)->filename = filename;
		}
	}
}
#endif


// CPMPScalarDatDoc commands
