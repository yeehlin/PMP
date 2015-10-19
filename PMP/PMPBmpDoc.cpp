// PMPBmpDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMPBmpDoc.h"
#include "PMPBmpView.h"

// CPMPBmpDoc

IMPLEMENT_DYNCREATE(CPMPBmpDoc, CDocument)

CPMPBmpDoc::CPMPBmpDoc()
{
	//***********初始化VTK数据*****************
	this->m_pvtkActor2D    = NULL;
	this->m_pvtkTextMapper  = NULL;
	this->m_pvtkBMPReader = NULL;
	this->m_pvtkImageActor = NULL;
}

BOOL CPMPBmpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPBmpDoc::~CPMPBmpDoc()
{
	if (this->m_pvtkActor2D != NULL){this->m_pvtkActor2D->Delete();}
	if (this->m_pvtkTextMapper != NULL){this->m_pvtkTextMapper->Delete();}
	if (this->m_pvtkBMPReader != NULL){this->m_pvtkBMPReader->Delete();}
	if (this->m_pvtkImageActor != NULL){this->m_pvtkImageActor->Delete();}
}


BEGIN_MESSAGE_MAP(CPMPBmpDoc, CDocument)
END_MESSAGE_MAP()


// CPMPBmpDoc diagnostics

#ifdef _DEBUG
void CPMPBmpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPBmpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPBmpDoc serialization

void CPMPBmpDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		if (this->m_pvtkBMPReader==NULL){
			this->m_pvtkBMPReader = vtkBMPReader::New();
		}
		this->m_pvtkBMPReader->SetFileName(ar.m_strFileName);
		// 执行管线显示图片
		this->CreateActors();
		this->ExecutePipeline(ar.m_strFileName);
		this->AddActors();
	}
}
#endif


// CPMPBmpDoc commands
bool CPMPBmpDoc::CreateActors()
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

void CPMPBmpDoc::ExecutePipeline(CString bmpname)
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPBmpView * pCPMPView = (CPMPBmpView *)this->GetNextView(pos);

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

bool CPMPBmpDoc::AddActors()
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPBmpView * pCPMPView = (CPMPBmpView *)this->GetNextView(pos);
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

bool CPMPBmpDoc::RemoveActors()
{
	POSITION pos = this->GetFirstViewPosition();
	CPMPBmpView * pCPMPView = (CPMPBmpView *)this->GetNextView(pos);
	pCPMPView->GetRenderer()->RemoveActor(this->m_pvtkActor2D);
	pCPMPView->GetRenderer()->RemoveActor(this->m_pvtkImageActor);
	return true;
}

bool CPMPBmpDoc::DestroyActors()
{
	if (this->m_pvtkActor2D){      this->m_pvtkActor2D->Delete();this->m_pvtkActor2D=NULL;}
	if (this->m_pvtkTextMapper){    this->m_pvtkTextMapper->Delete();this->m_pvtkTextMapper=NULL;}
	if (this->m_pvtkBMPReader){ this->m_pvtkBMPReader->Delete();this->m_pvtkBMPReader=NULL;}
	if (this->m_pvtkImageActor){ this->m_pvtkImageActor->Delete();this->m_pvtkImageActor=NULL;}

	return true;
}