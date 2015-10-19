// PMPTensorDatDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTensorDatDoc.h"

#include "PMPTensorDatView.h"
#include "PMPTensorDatTensoView.h"
#include "PMPTensorDatMultiView.h"

// CPMPTensorDatDoc

IMPLEMENT_DYNCREATE(CPMPTensorDatDoc, CDocument)

CPMPTensorDatDoc::CPMPTensorDatDoc()
{
}

BOOL CPMPTensorDatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPTensorDatDoc::~CPMPTensorDatDoc()
{
}


BEGIN_MESSAGE_MAP(CPMPTensorDatDoc, CDocument)
END_MESSAGE_MAP()


// CPMPTensorDatDoc diagnostics

#ifdef _DEBUG
void CPMPTensorDatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPTensorDatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPTensorDatDoc serialization

void CPMPTensorDatDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		filename = ar.m_strFileName;
		POSITION pos = this->GetFirstViewPosition();
		CView * tensorView= this->GetNextView(pos);
		if (tensorView->IsKindOf(RUNTIME_CLASS(CPMPTensorDatView)))
		{
			((CPMPTensorDatView *) tensorView)->filename = filename;
		}else if(tensorView->IsKindOf(RUNTIME_CLASS(CPMPTensorDatTensoView))){

			((CPMPTensorDatTensoView *) tensorView)->filename = filename;
		}else if(tensorView->IsKindOf(RUNTIME_CLASS(CPMPTensorDatMultiView))){

			((CPMPTensorDatMultiView *) tensorView)->filename = filename;
		}


	}
}
#endif


// CPMPTensorDatDoc commands
