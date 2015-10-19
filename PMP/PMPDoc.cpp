
// PMPDoc.cpp : implementation of the CPMPDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMP.h"
#endif

#include "PMPDoc.h"
#include "PMPView.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPMPDoc

IMPLEMENT_DYNCREATE(CPMPDoc, CDocument)

BEGIN_MESSAGE_MAP(CPMPDoc, CDocument)
END_MESSAGE_MAP()


// CPMPDoc construction/destruction

CPMPDoc::CPMPDoc()
{
	// TODO: add one-time construction code here
	//***********初始化VTK数据*****************
	this->m_pvtkActor2D    = NULL;
	this->m_pvtkTextMapper  = NULL;
	this->m_pvtkBMPReader = NULL;
	this->m_pvtkImageActor = NULL;

}

CPMPDoc::~CPMPDoc()
{
	this->DestroyActors();

}

BOOL CPMPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CPMPDoc serialization

void CPMPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CPMPDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CPMPDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPMPDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPMPDoc diagnostics

#ifdef _DEBUG
void CPMPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPMPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPMPDoc commands


BOOL CPMPDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Add your specialized creation code here
	// 读到图片文件
	if (this->m_pvtkBMPReader==NULL){
		this->m_pvtkBMPReader = vtkBMPReader::New();
	}
	this->m_pvtkBMPReader->SetFileName(lpszPathName);
	// 执行管线显示图片
	this->CreateActors();
	this->ExecutePipeline(lpszPathName);
	this->AddActors();
	return TRUE;
}

bool CPMPDoc::CreateActors()
{
	//this->pvtkDataSetReader = NULL;

	// 创建数据模型
	//if (!this->pvtkActor) this->pvtkActor = vtkActor::New();
	if (this->m_pvtkActor2D == NULL)this->m_pvtkActor2D    = vtkActor2D::New();
	if (this->m_pvtkTextMapper == NULL)this->m_pvtkTextMapper  = vtkTextMapper::New();
	//if (this->m_pvtkBMPReader == NULL) this->m_pvtkBMPReader = vtkBMPReader::New();

	if (this->m_pvtkImageActor==NULL)this->m_pvtkImageActor = vtkImageActor::New();

	return true;
}

void CPMPDoc::ExecutePipeline(CString bmpname)
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);

	if (this->m_pvtkBMPReader == NULL) this->m_pvtkBMPReader = vtkBMPReader::New();
		double origin[3] = {0, 0, 0};
		int extent[6] = {0, 256, 0, 256, 0, 0};
		int i =1;
		//this->m_pvtkBMPReader = vtkBMPReader::New();
		this->m_pvtkBMPReader->SetDataByteOrderToLittleEndian();
		this->m_pvtkBMPReader->SetDataScalarTypeToUnsignedChar();
		//m_reader->SetFileDimensionality(3);
		//this->pvtkBMPReader->SetDataExtent(extent);
		//this->pvtkBMPReader->SetDataOrigin(origin);
		//CString bmpname;
		//bmpname.Format("%s","D:/001comp.bmp");
		m_pvtkBMPReader->SetFileName(bmpname);
		m_pvtkBMPReader->SetNumberOfScalarComponents(0);
		m_pvtkBMPReader->SetHeaderSize(0);
		m_pvtkBMPReader->UpdateWholeExtent();
		//pvtkBMPReader->SetDataOrigin(origin);
		m_pvtkImageActor->SetInput(m_pvtkBMPReader->GetOutput());

		this->m_pvtkTextMapper->SetInput(bmpname+"Powered by VTK");
		this->m_pvtkTextMapper->GetTextProperty()->SetFontSize(24);
		this->m_pvtkActor2D->SetMapper(this->m_pvtkTextMapper);
}

bool CPMPDoc::AddActors()
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
	//CMainFrame * pFrame = (CMainFrame*)AfxGetMainWnd();
	//CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();
	//CVTKMFCCreatePolyActorsView* pCVTKMFCCreatePolyActorsView = (CVTKMFCCreatePolyActorsView *)pFrame->GetActiveView();
	//if (this->pvtkActor){
	//	pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor);
	//}
	if (this->m_pvtkActor2D){
		pCPMPView->GetRenderer()->AddActor(this->m_pvtkActor2D);
	}
	if (this->m_pvtkImageActor){
		pCPMPView->GetRenderer()->AddActor(this->m_pvtkImageActor);
	}
	return true;
}

bool CPMPDoc::RemoveActors()
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
	pCPMPView->GetRenderer()->RemoveActor(this->m_pvtkActor2D);
	pCPMPView->GetRenderer()->RemoveActor(this->m_pvtkImageActor);
	return true;
}

bool CPMPDoc::DestroyActors()
{
	if (this->m_pvtkActor2D){      this->m_pvtkActor2D->Delete();this->m_pvtkActor2D=NULL;}
	if (this->m_pvtkTextMapper){    this->m_pvtkTextMapper->Delete();this->m_pvtkTextMapper=NULL;}
	if (this->m_pvtkBMPReader){ this->m_pvtkBMPReader->Delete();this->m_pvtkBMPReader=NULL;}
	if (this->m_pvtkImageActor){ this->m_pvtkImageActor->Delete();this->m_pvtkImageActor=NULL;}

	return true;
}


