
// VTKMFCCreateBMPActorsDoc.cpp : implementation of the CVTKMFCCreateBMPActorsDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VTKMFCCreateBMPActors.h"
#endif

#include "VTKMFCCreateBMPActorsDoc.h"
#include "VTKMFCCreateBMPActorsView.h"

#include "vtkTextProperty.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CVTKMFCCreateBMPActorsDoc

IMPLEMENT_DYNCREATE(CVTKMFCCreateBMPActorsDoc, CDocument)

BEGIN_MESSAGE_MAP(CVTKMFCCreateBMPActorsDoc, CDocument)
	ON_COMMAND(ID_CREATEACTORS_CREATEBMPACTOR, &CVTKMFCCreateBMPActorsDoc::OnCreateactorsCreatebmpactor)
	ON_COMMAND(ID_DESTROYACTORS_DESTROYBMPACTOR, &CVTKMFCCreateBMPActorsDoc::OnDestroyactorsDestroybmpactor)
//	ON_COMMAND(ID_RUN_GO, &CVTKMFCCreateBMPActorsDoc::OnRunGo)
END_MESSAGE_MAP()


// CVTKMFCCreateBMPActorsDoc construction/destruction

CVTKMFCCreateBMPActorsDoc::CVTKMFCCreateBMPActorsDoc()
{
	// TODO: add one-time construction code here

	//this->pvtkActor = NULL;
	this->pvtkActor2D    = NULL;
	this->pvtkTextMapper  = NULL;

	this->pvtkBMPReader = NULL;
	this->pvtkImageActor = NULL;

	//this->pvtkDataSetReader = NULL;
	//this->pvtkDataSetMapper = NULL;


}

CVTKMFCCreateBMPActorsDoc::~CVTKMFCCreateBMPActorsDoc()
{
}

BOOL CVTKMFCCreateBMPActorsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CVTKMFCCreateBMPActorsDoc serialization

void CVTKMFCCreateBMPActorsDoc::Serialize(CArchive& ar)
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
void CVTKMFCCreateBMPActorsDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CVTKMFCCreateBMPActorsDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CVTKMFCCreateBMPActorsDoc::SetSearchContent(const CString& value)
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

// CVTKMFCCreateBMPActorsDoc diagnostics

#ifdef _DEBUG
void CVTKMFCCreateBMPActorsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVTKMFCCreateBMPActorsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ����actor��ȡ�����캯��


bool CVTKMFCCreateBMPActorsDoc::CreateActors()
{
	//this->pvtkDataSetReader = NULL;

	// ��������ģ��
	//if (!this->pvtkActor) this->pvtkActor = vtkActor::New();
	if (!this->pvtkActor2D)this->pvtkActor2D    = vtkActor2D::New();
	if (!this->pvtkTextMapper)this->pvtkTextMapper  = vtkTextMapper::New();

	this->pvtkBMPReader = NULL;
	if (!this->pvtkImageActor)this->pvtkImageActor = vtkImageActor::New();

	//this->pvtkDataSetReader = NULL;
	//if (!this->pvtkDataSetMapper)this->pvtkDataSetMapper = vtkDataSetMapper::New();

	return true;
}


void CVTKMFCCreateBMPActorsDoc::OnCreateactorsCreatebmpactor()
{
	// TODO: Add your command handler code here

	this->CreateActors();
	//MessageBox(NULL,_T("Create Successfully!"),_T("Create"),NULL);
}

// ִ�й��߲���
void CVTKMFCCreateBMPActorsDoc::ExecutePipeline(CString bmpname)
{
		/*
	// �����ڵ��ĵ�
	// get our renderer first
	POSITION pos = this->GetFirstViewPosition();
	CShowHelloWorldShowVTKFileView *pCShowHelloWorldShowVTKFileView = NULL;

	if (pos)
	{
		pCShowHelloWorldShowVTKFileView = (CShowHelloWorldShowVTKFileView *)GetNextView(pos);
	}
	else  // return
	{
		ASSERT(FALSE);
		return;
	}
	*/
	// �����ڶ��ĵ�
	POSITION pos = this->GetFirstViewPosition();
	CVTKMFCCreateBMPActorsView * pCVTKMFCCreateBMPActorsView = (CVTKMFCCreateBMPActorsView *)this->GetNextView(pos);

	//if (hasfile)  // have file
	//{
		// ������ļ��鿴��BMP�ļ�����VTK�����ļ�
		// �����VTK�����ļ�
	/*
	if (this->pvtkDataSetReader){

		this->pvtkDataSetMapper->SetInputConnection(this->pvtkDataSetReader->GetOutputPort());
		this->pvtkActor->SetMapper(this->pvtkDataSetMapper);

		this->pvtkTextMapper->SetInput(this->pvtkDataSetReader->GetFileName());
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(12);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);

		pCVTKMFCCreateBMPActorsView->GetRenderer()->SetBackground(0.0,0.0,0.4);
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor);
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor2D);
	}else*/ if (this->pvtkBMPReader){
		// �����bmpͼƬ������ʾͼƬ

		MessageBox(NULL,_T("Show BMP image"),_T("Show BMP"),NULL);

		double origin[3] = {0, 0, 0};
		int extent[6] = {0, 256, 0, 256, 0, 1};
		int i =1;
		pvtkBMPReader->SetNumberOfScalarComponents(1);
		pvtkBMPReader->SetHeaderSize(0);
		pvtkBMPReader->UpdateWholeExtent();
		pvtkImageActor->SetInputData(pvtkBMPReader->GetOutput());
		pvtkImageActor->SetDisplayExtent(extent[0], extent[1], extent[2], extent[3], 0, 1);

		this->pvtkTextMapper->SetInput(this->pvtkBMPReader->GetFileName());
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(12);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);


		//pCVTKMFCCreateBMPActorsView->GetRenderer()->SetBackground(0.0, 0.0, 0.4);
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(pvtkImageActor);
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor2D);
	}
	//}
	else  // have no file
	{
		// ���û���ļ�����ʾһ��Ĭ�ϵ�ͼƬ
		// ���û��ͼƬ������һ����ס����һ��vtkBMPReader������ֿ�ָ��
		//MessageBox(NULL,_T("Show BMP image"),_T("Show BMP"),NULL);
		double origin[3] = {0, 0, 0};
		int extent[6] = {-256, 256, -256, 256, 1, 1};
		int i =1;
		this->pvtkBMPReader = vtkBMPReader::New();
		this->pvtkBMPReader->SetDataByteOrderToLittleEndian();
		this->pvtkBMPReader->SetDataScalarTypeToUnsignedChar();
		//m_reader->SetFileDimensionality(3);
		//this->pvtkBMPReader->SetDataExtent(extent);
		//this->pvtkBMPReader->SetDataOrigin(origin);
		//CString bmpname;
		//bmpname.Format("%s","D:/001comp.bmp");
		pvtkBMPReader->SetFileName(bmpname);
		//pvtkBMPReader->SetFileName(EXAMPLE_DATA);
		pvtkBMPReader->SetNumberOfScalarComponents(0);
		pvtkBMPReader->SetHeaderSize(0);
		pvtkBMPReader->UpdateWholeExtent();
		//pvtkBMPReader->SetDataOrigin(origin);
		pvtkImageActor->SetInputData(pvtkBMPReader->GetOutput());
		// ��Ȼ���Բ�Ҫ��������û����������ͼƬ�Լ����塣
		//pvtkImageActor->SetDisplayExtent(extent[0], extent[1], extent[2], extent[3],0, 2);
		//pCVTKMFCCreateBMPActorsView->GetRenderer()->SetBackground(0.0, 0.0, 0.4);
		//pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(pvtkImageActor);

		

		this->pvtkTextMapper->SetInput("Hello,vtk show BMP");
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(24);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);
		//pCVTKMFCCreateBMPActorsView->GetRenderer()->SetBackground(0.0,0.0,0.4);
		//pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor2D);

	}
}

// ����Actor��صĶ���
bool CVTKMFCCreateBMPActorsDoc::DestroyActors()
{
	// ɾ�����ڿ��ӻ������ݶ���ģ��

	//if (this->pvtkActor){ this->pvtkActor->Delete();this->pvtkActor=NULL;}
	if (this->pvtkActor2D){      this->pvtkActor2D->Delete();this->pvtkActor2D=NULL;}
	if (this->pvtkTextMapper){    this->pvtkTextMapper->Delete();this->pvtkTextMapper=NULL;}


	if (this->pvtkBMPReader){ this->pvtkBMPReader->Delete();this->pvtkBMPReader=NULL;}
	if (this->pvtkImageActor){ this->pvtkImageActor->Delete();this->pvtkImageActor=NULL;}


	//if (this->pvtkDataSetReader){ this->pvtkDataSetReader->Delete();this->pvtkDataSetReader=NULL;}
	//if (this->pvtkDataSetMapper){ this->pvtkDataSetMapper->Delete();this->pvtkDataSetMapper=NULL;}
	return true;
}


void CVTKMFCCreateBMPActorsDoc::OnDestroyactorsDestroybmpactor()
{
	// TODO: Add your command handler code here
	// ����֮��������ʾ������Ѿ������ˣ����д��ڵı�Ҫ��
	// ����view��ˢ�²�����ˢ�½���
	POSITION pos = this->GetFirstViewPosition();
	CVTKMFCCreateBMPActorsView * pCVTKMFCCreateBMPActorsView = (CVTKMFCCreateBMPActorsView *)this->GetNextView(pos);
	this->RemoveActors();
	pCVTKMFCCreateBMPActorsView->RefreshActors();

	// �����Destroy֮ǰ���Ƴ�����ˢ����ʾ������������ݶ���
	this->DestroyActors();
	//MessageBox(NULL,_T("Destroy Successfully!"),_T("Destroy"),NULL);
}


// �Ƴ�actor
bool CVTKMFCCreateBMPActorsDoc::RemoveActors()
{
		/*
	// �����ڵ��ĵ�
	// get our renderer first
	POSITION pos = this->GetFirstViewPosition();
	CShowHelloWorldShowVTKFileView *pCShowHelloWorldShowVTKFileView = NULL;

	if (pos)
	{
		pCShowHelloWorldShowVTKFileView = (CShowHelloWorldShowVTKFileView *)GetNextView(pos);
	}
	else  // return
	{
		ASSERT(FALSE);
		return;
	}
	*/
	// �����ڶ��ĵ�
	POSITION pos = this->GetFirstViewPosition();
	CVTKMFCCreateBMPActorsView * pCVTKMFCCreateBMPActorsView = (CVTKMFCCreateBMPActorsView *)this->GetNextView(pos);
	//if (this->pvtkActor2D){
	//	pCVTKMFCCreateBMPActorsView->GetRenderer()->RemoveActor(this->pvtkActor);
	//}
	//if (this->pvtkActor2D){
		pCVTKMFCCreateBMPActorsView->GetRenderer()->RemoveActor(this->pvtkActor2D);
	//}
	//if (this->pvtkActor2D){
		pCVTKMFCCreateBMPActorsView->GetRenderer()->RemoveActor(this->pvtkImageActor);
	//}
	return true;
}


// ���actor
bool CVTKMFCCreateBMPActorsDoc::AddActors()
{
		/*
	// �����ڵ��ĵ�
	// get our renderer first
	POSITION pos = this->GetFirstViewPosition();
	CShowHelloWorldShowVTKFileView *pCShowHelloWorldShowVTKFileView = NULL;

	if (pos)
	{
		pCShowHelloWorldShowVTKFileView = (CShowHelloWorldShowVTKFileView *)GetNextView(pos);
	}
	else  // return
	{
		ASSERT(FALSE);
		return;
	}
	*/
	// �����ڶ��ĵ�
	POSITION pos = this->GetFirstViewPosition();
	CVTKMFCCreateBMPActorsView * pCVTKMFCCreateBMPActorsView = (CVTKMFCCreateBMPActorsView *)this->GetNextView(pos);
	//CMainFrame * pFrame = (CMainFrame*)AfxGetMainWnd();
	//CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();
	//CVTKMFCCreatePolyActorsView* pCVTKMFCCreatePolyActorsView = (CVTKMFCCreatePolyActorsView *)pFrame->GetActiveView();
	//if (this->pvtkActor){
	//	pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor);
	//}
	if (this->pvtkActor2D){
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor2D);
	}
	if (this->pvtkImageActor){
		pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkImageActor);
	}
	return true;
}


BOOL CVTKMFCCreateBMPActorsDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Add your specialized creation code here

	


	return TRUE;
}


//void CVTKMFCCreateBMPActorsDoc::OnSpinodaldecompositionCalculate()
//{
//	// TODO: Add your command handler code here
//	
//	// ��������öԻ���
//	// ������������������������ΪDOC������Ҫ�Ի����е�����
//	// Ϊ��ʹ��CalculateDlgFather.cppģ�飬��Ҫ������ģ���ͷ�ļ�
//	// һ��ע�⣺���ﴴ�������ǲ����ģ���ֻ�����ڴ������˶Ի������һ��Ҫ����DoModal��ʾ
//
//	PMPSpindecomCalculateDlgFather pMPSpindecomCalculateDlgFather;
//	if (pMPSpindecomCalculateDlgFather.DoModal()==IDOK){
//		// just show it ,do something if want.����Խ��ܶԻ����е����ݣ�����Ҫ��DOC���趨���ԡ�
//	}
//
//
//}


//void CVTKMFCCreateBMPActorsDoc::OnRunGo()
//{
//	// TODO: Add your command handler code here
//
//	// �����ⲿexe������������
//	WinExec("Spinodal01.exe input.dat",SW_SHOW);
//}


//void CVTKMFCCreateBMPActorsDoc::OnRunGo()
//{
//	// TODO: Add your command handler code here
//
//	// �����ⲿexe������������SW_SHOW��ʾ��ʾ���ڣ�SW_HIDE��ʾ���ش���
//	//WinExec("Spinodal01.exe input.dat",SW_SHOW);
//	WinExec("Spinodal01.exe input.dat",SW_HIDE);
//}

