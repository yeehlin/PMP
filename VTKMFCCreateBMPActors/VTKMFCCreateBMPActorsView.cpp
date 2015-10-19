
// VTKMFCCreateBMPActorsView.cpp : implementation of the CVTKMFCCreateBMPActorsView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VTKMFCCreateBMPActors.h"
#endif

#include "VTKMFCCreateBMPActorsDoc.h"
#include "VTKMFCCreateBMPActorsView.h"

#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"

#include "vtkInteractorStyleTrackballCamera.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMEER_SECOND 1

// CVTKMFCCreateBMPActorsView

IMPLEMENT_DYNCREATE(CVTKMFCCreateBMPActorsView, CView)

BEGIN_MESSAGE_MAP(CVTKMFCCreateBMPActorsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVTKMFCCreateBMPActorsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ADDACTORS_ADDBMPACTOR, &CVTKMFCCreateBMPActorsView::OnAddactorsAddbmpactor)
	ON_COMMAND(ID_REMOVEACTORS_REMOVEBMPACTOR, &CVTKMFCCreateBMPActorsView::OnRemoveactorsRemovebmpactor)
	ON_COMMAND(ID_NEXTACTORS_NEXTBMPACTOR, &CVTKMFCCreateBMPActorsView::OnNextactorsNextbmpactor)
//	ON_WM_CREATE()
ON_WM_TIMER()
ON_COMMAND(ID_SCANBMPACTOR_BEGINSCAN, &CVTKMFCCreateBMPActorsView::OnScanbmpactorBeginscan)
ON_COMMAND(ID_SCANBMPACTOR_ENDSCAN, &CVTKMFCCreateBMPActorsView::OnScanbmpactorEndscan)
END_MESSAGE_MAP()

// CVTKMFCCreateBMPActorsView construction/destruction

CVTKMFCCreateBMPActorsView::CVTKMFCCreateBMPActorsView()
{
	// TODO: add construction code here
	this->pvtkMFCWindow = NULL;

	this->pvtkRenderer = vtkRenderer::New();

	this->i = 1;
}

CVTKMFCCreateBMPActorsView::~CVTKMFCCreateBMPActorsView()
{
	if (this->pvtkMFCWindow) delete this->pvtkMFCWindow;
	if (this->pvtkRenderer) this->pvtkRenderer->Delete();
}

BOOL CVTKMFCCreateBMPActorsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVTKMFCCreateBMPActorsView drawing

void CVTKMFCCreateBMPActorsView::OnDraw(CDC* /*pDC*/)
{
	CVTKMFCCreateBMPActorsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//CRect vtkClient ;
	//GetClientRect(&vtkClient);
	//if (vtkClient!=NULL){
	//	this->pvtkMFCWindow->RedrawWindow(vtkClient);}

}


// CVTKMFCCreateBMPActorsView printing


void CVTKMFCCreateBMPActorsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVTKMFCCreateBMPActorsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVTKMFCCreateBMPActorsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVTKMFCCreateBMPActorsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVTKMFCCreateBMPActorsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVTKMFCCreateBMPActorsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVTKMFCCreateBMPActorsView diagnostics

#ifdef _DEBUG
void CVTKMFCCreateBMPActorsView::AssertValid() const
{
	CView::AssertValid();
}

void CVTKMFCCreateBMPActorsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVTKMFCCreateBMPActorsDoc* CVTKMFCCreateBMPActorsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVTKMFCCreateBMPActorsDoc)));
	return (CVTKMFCCreateBMPActorsDoc*)m_pDocument;
}
#endif //_DEBUG


static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}



// CVTKMFCCreateBMPActorsView message handlers


void CVTKMFCCreateBMPActorsView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	// 开始发送时钟消息
	// 开始不发送时钟消息
	// SetTimer(TIMEER_SECOND,1000,NULL);

	// 是否在这里执行view中的管线呢？
	this->ExecutePipeline();

}


void CVTKMFCCreateBMPActorsView::OnAddactorsAddbmpactor()
{
	// TODO: Add your command handler code here

		// 如果还没有创建Actor则添加无效，提示或者创建
		// 貌似这个弹窗提示不好使
		//::MessageBox(NULL,_T("Create actor first!"),_T("Warning"),MB_OK);
	
	this->GetDocument()->CreateActors();

	// 首先执行DOC中的管线，这里修改为显示i指示的图片，而不是第一张图片
	CString bmpname;
	//for(i = 1;i<=100;i++){
	if (i<10){
		bmpname.Format("%s%s%d%s","","00",i,"comp.bmp");
		//this->currentName = "00"+count;
		//this->currentName +=_T("comp.bmp");
	}else if (i <100){
		bmpname.Format("%s%s%d%s","","0",i,"comp.bmp");
		//this->currentName = "0"+image_index;
		//this->currentName +=_T("comp.bmp");
	}else {
		bmpname.Format("%s%d%s","",i,"comp.bmp");
		//this->currentName +=_T("comp.bmp");
	}
	this->GetDocument()->ExecutePipeline(bmpname);
	// 然后执行VIEW中的管线，view中的管线在OnInitialUpdate中
	// 操作actor与renderer之间的关系
	// 在VIEW中修改DOC中的数据

	this->GetDocument()->AddActors();

	//this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);
	//this->pvtkRenderer->SetBackground(0,0,0.4);

	//this->ExecutePipeline();
	/*
	if (this->GetDocument()->GetActor2D()){
		this->pvtkRenderer->AddActor(this->GetDocument()->GetActor2D());
	}
	if (this->GetDocument()->GetActor()){
		this->pvtkRenderer->AddActor(this->GetDocument()->GetActor());
	}
	*/
	// 最后重绘
	// 通知VIEW重新绘制

	CRect vtkClient ;
	GetClientRect(&vtkClient);
	this->pvtkMFCWindow->RedrawWindow(vtkClient);

}


void CVTKMFCCreateBMPActorsView::OnRemoveactorsRemovebmpactor()
{
	// TODO: Add your command handler code here

		// 如果没有actor则移除无效
	//if (!this->GetDocument()->GetActor2D()){
		// 貌似这个弹窗提示不好使
		//::MessageBox(NULL,_T("No actor need to be Removed!"),_T("Warning"),MB_OK);
	//}

	// 执行移除actors操作
	// 仍然保留除actor之外的资源，所以现在获取actor，并对actor做相应操作

	// 在VIEW中修改DOC中的数据
	this->GetDocument()->RemoveActors();
	/*
	if (this->GetDocument()->GetActor2D()){
		this->pvtkRenderer->RemoveActor(this->GetDocument()->GetActor2D());
	}
	if (this->GetDocument()->GetActor()) {
		this->pvtkRenderer->RemoveActor(this->GetDocument()->GetActor());
	}
	*/


	// 通知VIEW重新绘制
	CRect vtkClient ;
	GetClientRect(&vtkClient);
	this->pvtkMFCWindow->RedrawWindow(vtkClient);

}


// 刷新Actor的显示
bool CVTKMFCCreateBMPActorsView::RefreshActors(void)
{
	CRect vtkClient ;
	GetClientRect(&vtkClient);
	this->pvtkMFCWindow->RedrawWindow(vtkClient);
	return true;
}


void CVTKMFCCreateBMPActorsView::OnNextactorsNextbmpactor()
{
	// TODO: Add your command handler code here
	this->NextActor(this->i);

}


// 管线的剩余部分
void CVTKMFCCreateBMPActorsView::ExecutePipeline()
{
	this->pvtkMFCWindow = new vtkMFCWindow(this);
	//=======================================================================
	//改变默认的交互方式，参考vtk示例cone5
	//=======================================================================
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();

	this->pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);

	//this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);
	//this->pvtkRenderer->SetBackground(256,256,256);
	//CRect vtkClient ;
	//this->GetClientRect(&vtkClient);
	//this->pvtkRenderer->GetRenderWindow()->SetSize(vtkClient.Width(),vtkClient.Height());

	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}


// 获取下一个bmp image actor


//static int i =1;
void CVTKMFCCreateBMPActorsView::NextActor(int i)
{
	CString bmpname;
	//for(i = 1;i<=100;i++){
	if (i<10){
		bmpname.Format("%s%s%d%s","","00",i,"comp.bmp");
		//this->currentName = "00"+count;
		//this->currentName +=_T("comp.bmp");
	}else if (i <100){
		bmpname.Format("%s%s%d%s","","0",i,"comp.bmp");
		//this->currentName = "0"+image_index;
		//this->currentName +=_T("comp.bmp");
	}else {
		bmpname.Format("%s%d%s","",i,"comp.bmp");
		//this->currentName +=_T("comp.bmp");
	}
	//}

	// 这里要判断是否硬盘中是否存在以bmpname为文件名的图像文件是否存在，
	// 如果不存在,则不做任何事，下一次接着找bmpname，而不是找下一张

	if(fileFind.FindFile(bmpname)){

		this->GetDocument()->RemoveActors();
		//this->RefreshActors();
		this->GetDocument()->DestroyActors();
		// 实质是创建存放数据的动态内存
		this->GetDocument()->CreateActors();

		this->GetDocument()->ExecutePipeline(bmpname);
		this->i++;
		this->GetDocument()->AddActors();
		CRect vtkClient ;
		GetClientRect(&vtkClient);
		this->pvtkMFCWindow->RedrawWindow(vtkClient);
	}else{
		this->i--;
	}

	// 如果找到了100图片，则结束时钟
	if (this->i==101){
		KillTimer(TIMEER_SECOND);
	}

}


void CVTKMFCCreateBMPActorsView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	// 没有任何操作还是要将第一actor加上去的。



	if (this->i == 1){
		// 当时钟来临，设置renderer的大小
		this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);
		this->pvtkRenderer->SetBackground(0,0,0.4);

		//CRect vtkClient ;
		//this->GetClientRect(&vtkClient);
		//this->pvtkRenderer->GetRenderWindow()->SetSize(vtkClient.Width(),vtkClient.Height());


		this->GetDocument()->CreateActors();

		// 首先执行DOC中的管线
		this->GetDocument()->ExecutePipeline("001comp.bmp");
		// 然后执行VIEW中的管线，view中的管线在OnInitialUpdate中
		// 操作actor与renderer之间的关系
		// 在VIEW中修改DOC中的数据
		//this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);
		//this->pvtkRenderer->SetBackground(0,0,0.4);

		this->GetDocument()->AddActors();

		this->i ++;
		// 最后重绘
		// 通知VIEW重新绘制
		CRect vtkClient ;
		GetClientRect(&vtkClient);
		this->pvtkMFCWindow->RedrawWindow(vtkClient);
	}else{

		this->NextActor(this->i);

		CView::OnTimer(nIDEvent);

		CRect temprect;
		GetClientRect(&temprect);
		this->pvtkRenderer->GetRenderWindow()->SetSize(temprect.Width(),temprect.Height());
	}
}


void CVTKMFCCreateBMPActorsView::OnScanbmpactorBeginscan()
{
	// TODO: Add your command handler code here
	SetTimer(TIMEER_SECOND,1000,NULL);
}


void CVTKMFCCreateBMPActorsView::OnScanbmpactorEndscan()
{
	// TODO: Add your command handler code here
	KillTimer(TIMEER_SECOND);
}


void CVTKMFCCreateBMPActorsView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class


	// 通知VIEW重新绘制
	//CRect vtkClient ;
	//GetClientRect(&vtkClient);
	//if (vtkClient!=NULL){
	//	this->pvtkMFCWindow->RedrawWindow(vtkClient);}
}

void CVTKMFCCreateBMPActorsView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType)
{
	// TODO: Add your specialized code here and/or call the base class

	
	//this->pvtkRenderer->GetRenderWindow()->SetSize(lpClientRect->right-lpClientRect->left,lpClientRect->bottom-lpClientRect->top);

	//CView::CalcWindowRect(lpClientRect, nAdjustType);
}
