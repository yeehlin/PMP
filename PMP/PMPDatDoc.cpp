// PMPDatDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPDatDoc.h"
#include "PMPDatView.h"
#include "PMPDatStreamlineView.h"
#include "PMPVectorDatVolumeView.h"

// CPMPDatDoc

IMPLEMENT_DYNCREATE(CPMPDatDoc, CDocument)

CPMPDatDoc::CPMPDatDoc()
{
	m_viewType = -1;
}

BOOL CPMPDatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPDatDoc::~CPMPDatDoc()
{
}


BEGIN_MESSAGE_MAP(CPMPDatDoc, CDocument)
END_MESSAGE_MAP()


// CPMPDatDoc diagnostics

#ifdef _DEBUG
void CPMPDatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPDatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPDatDoc serialization

void CPMPDatDoc::Serialize(CArchive& ar)
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
		CView * vectorView= this->GetNextView(pos);
		if(vectorView->IsKindOf(RUNTIME_CLASS(CPMPDatView))){
			((CPMPDatView * )vectorView)->filename =  filename;
		}else if(vectorView->IsKindOf(RUNTIME_CLASS(CPMPDatStreamlineView))) {
			((CPMPDatStreamlineView * )vectorView)->filename =  filename;
		}else if(vectorView->IsKindOf(RUNTIME_CLASS(CPMPVectorDatVolumeView))) {
			((CPMPVectorDatVolumeView * )vectorView)->filename =  filename;
		}

	}
}
#endif


// CPMPDatDoc commands
