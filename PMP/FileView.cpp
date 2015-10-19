
#include "stdafx.h"
#include "mainfrm.h"
#include "FileView.h"
#include "Resource.h"
#include "PMP.h"
#include "DialogOpenwith.h"
#include "PMPVisualizationDLG.h"

#include "PMPScalarDatDoc.h"
#include "PMPDatDoc.h"
#include "PMPTensorDatDoc.h"


#include "PMPScalarDatView.h"
#include "PMPScalarDatGridView.h"
#include "PMPDatView.h"
#include "PMPDatStreamlineView.h"
#include "PMPTensorDatView.h"
#include "PMPTensorDatTensoView.h"
#include "PMPTensorDatMultiView.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileView

CFileView::CFileView()
{
	listsize = 0;
	fortlistsize =0;
	piezlistsize = 0;
	piezfortlistsize = 0;
	piezotherlistsize = 0;
}

CFileView::~CFileView()
{
}

BEGIN_MESSAGE_MAP(CFileView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PROPERTIES, OnProperties)
	ON_COMMAND(ID_OPEN, OnFileOpen)
	ON_COMMAND(ID_OPEN_WITH, OnFileOpenWith)
	ON_COMMAND(ID_DUMMY_COMPILE, OnDummyCompile)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EXPLORER_VISUALIZE, &CFileView::OnExplorerVisualize)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar message handlers

int CFileView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// 将工作空间分发给tree view
	m_wndFileView.workspace = workspace;

	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create view:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;

	if (!m_wndFileView.Create(dwViewStyle, rectDummy, this, 4))
	{
		TRACE0("Failed to create file view\n");
		return -1;      // fail to create
	}

	// Load view images:
	m_FileViewImages.Create(IDB_FILE_VIEW, 16, 0, RGB(255, 0, 255));
	m_wndFileView.SetImageList(&m_FileViewImages, TVSIL_NORMAL);

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_EXPLORER);
	m_wndToolBar.LoadToolBar(IDR_EXPLORER, 0, 0, TRUE /* Is locked */);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// All commands will be routed via this control , not via the parent frame:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	// Fill in some static tree view data (dummy code, nothing magic here)
	FillFileView();
	AdjustLayout();

	return 0;
}

void CFileView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CFileView::FillFileView()
{
	// 扫描工作空间，载入列表
	FillFileViewByType(1);
	FillFileViewByType(2);

	//HTREEITEM hRoot = m_wndFileView.InsertItem(_T("FakeApp files"), 0, 0);
	//m_wndFileView.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);

	//HTREEITEM hSrc = m_wndFileView.InsertItem(_T("FakeApp Source Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeApp.rc"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeAppView.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("MainFrm.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("StdAfx.cpp"), 1, 1, hSrc);

	//HTREEITEM hInc = m_wndFileView.InsertItem(_T("FakeApp Header Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("FakeAppView.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("Resource.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("MainFrm.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("StdAfx.h"), 2, 2, hInc);

	//HTREEITEM hRes = m_wndFileView.InsertItem(_T("FakeApp Resource Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.ico"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeApp.rc2"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.ico"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeToolbar.bmp"), 2, 2, hRes);

	//m_wndFileView.Expand(hRoot, TVE_EXPAND);
	//m_wndFileView.Expand(hSrc, TVE_EXPAND);
	//m_wndFileView.Expand(hInc, TVE_EXPAND);

	//hMyRoot = m_wndFileView.InsertItem(_T("SPINODAL files"), 0, 0);
	//m_wndFileView.SetItemState(hMyRoot, TVIS_BOLD, TVIS_BOLD);

	//hBmp = m_wndFileView.InsertItem(_T("SPINODAL Bmp Files"), 0, 0, hMyRoot);

	//hFort = m_wndFileView.InsertItem(_T("SPINODAL fort Files"), 0, 0, hMyRoot);

	//m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
	//m_wndFileView.Expand(hBmp, TVE_EXPAND);
	//m_wndFileView.Expand(hFort, TVE_EXPAND);
}
// 调用不同的模块给出不同的目录结构
void CFileView::FillFileViewByType(int moduleType)
{
	switch (moduleType)
	{
	case 1:
		hMyRoot = m_wndFileView.InsertItem(_T("SPINODAL files"), 0, 0);
		m_wndFileView.SetItemState(hMyRoot, TVIS_BOLD, TVIS_BOLD);

		hBmp = m_wndFileView.InsertItem(_T("SPINODAL Bmp Files"), 0, 0, hMyRoot);

		hFort = m_wndFileView.InsertItem(_T("SPINODAL fort Files"), 0, 0, hMyRoot);

		m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
		m_wndFileView.Expand(hBmp, TVE_EXPAND);
		m_wndFileView.Expand(hFort, TVE_EXPAND);
		// 在填充之前就扫描一次
		this->MoniTimer(workspace);
		this->FortTimer(workspace);
		if (listsize != fileviewlist.GetSize()){
			for (int i=listsize;i<fileviewlist.GetSize();i++)
			{
				//c.setFileFullPath(fileviewlistFullPath.GetAt(i));
				//c.setFileName(fileviewlist.GetAt(i));
				m_wndFileView.InsertItem(_T(fileviewlist.GetAt(i)), 1, 1, hBmp);
			}
			listsize=fileviewlist.GetSize();
		}
		if (fortlistsize != fileviewlistfort.GetSize()){
			for (int i=fortlistsize;i<fileviewlistfort.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistfort.GetAt(i)), 1, 1, hFort);
			}
			fortlistsize=fileviewlistfort.GetSize();
		}
		fileviewlist.RemoveAll();
		fileviewlistfort.RemoveAll();
		break;
	case 2:
		hMyRootPiez = m_wndFileView.InsertItem(_T("Effective Property files"), 0, 0);
		m_wndFileView.SetItemState(hMyRootPiez, TVIS_BOLD, TVIS_BOLD);

		hPiezData = m_wndFileView.InsertItem(_T("Effective Property data Files"), 0, 0, hMyRootPiez);

		hPiezFort = m_wndFileView.InsertItem(_T("Effective Property fort Files"), 0, 0, hMyRootPiez);

		hPiezOther = m_wndFileView.InsertItem(_T("Effective Property other Files"), 0, 0, hMyRootPiez);

		m_wndFileView.Expand(hMyRootPiez, TVE_EXPAND);
		m_wndFileView.Expand(hPiezData, TVE_EXPAND);
		m_wndFileView.Expand(hPiezFort, TVE_EXPAND);
		m_wndFileView.Expand(hPiezOther, TVE_EXPAND);
		// 在填充之前就扫描一次
		this->DataTimer(workspace);
		this->PiezFortTimer(workspace);
		this->PiezOtherTimer(workspace);
		if (piezlistsize != fileviewlistpiez.GetSize()){
			for (int i=piezlistsize;i<fileviewlistpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistpiez.GetAt(i)), 1, 1, hPiezData);
			}
			piezlistsize=fileviewlistpiez.GetSize();
		}
		if (piezfortlistsize != fileviewlistfortpiez.GetSize()){
			for (int i=piezfortlistsize;i<fileviewlistfortpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistfortpiez.GetAt(i)), 1, 1, hPiezFort);
			}
			piezfortlistsize=fileviewlistfortpiez.GetSize();
		}
		if (piezotherlistsize != fileviewlistotherpiez.GetSize()){
			for (int i=piezotherlistsize;i<fileviewlistotherpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistotherpiez.GetAt(i)), 1, 1, hPiezOther);
			}
			piezotherlistsize=fileviewlistotherpiez.GetSize();
		}
		fileviewlistpiez.RemoveAll();
		fileviewlistfortpiez.RemoveAll();
		fileviewlistotherpiez.RemoveAll();
		break;
	}
	//HTREEITEM hRoot = m_wndFileView.InsertItem(_T("FakeApp files"), 0, 0);
	//m_wndFileView.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);

	//HTREEITEM hSrc = m_wndFileView.InsertItem(_T("FakeApp Source Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeApp.rc"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("FakeAppView.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("MainFrm.cpp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("StdAfx.cpp"), 1, 1, hSrc);

	//HTREEITEM hInc = m_wndFileView.InsertItem(_T("FakeApp Header Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("FakeAppView.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("Resource.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("MainFrm.h"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("StdAfx.h"), 2, 2, hInc);

	//HTREEITEM hRes = m_wndFileView.InsertItem(_T("FakeApp Resource Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("FakeApp.ico"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeApp.rc2"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeAppDoc.ico"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("FakeToolbar.bmp"), 2, 2, hRes);

	//m_wndFileView.Expand(hRoot, TVE_EXPAND);
	//m_wndFileView.Expand(hSrc, TVE_EXPAND);
	//m_wndFileView.Expand(hInc, TVE_EXPAND);

	//hMyRoot = m_wndFileView.InsertItem(_T("SPINODAL files"), 0, 0);
	//m_wndFileView.SetItemState(hMyRoot, TVIS_BOLD, TVIS_BOLD);

	//hBmp = m_wndFileView.InsertItem(_T("SPINODAL Bmp Files"), 0, 0, hMyRoot);

	//hFort = m_wndFileView.InsertItem(_T("SPINODAL fort Files"), 0, 0, hMyRoot);

	//m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
	//m_wndFileView.Expand(hBmp, TVE_EXPAND);
	//m_wndFileView.Expand(hFort, TVE_EXPAND);
}


void CFileView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*) &m_wndFileView;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// Select clicked item:
		CPoint ptTree = point;
		pWndTree->ScreenToClient(&ptTree);

		UINT flags = 0;
		HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
		if (hTreeItem != NULL)
		{
			pWndTree->SelectItem(hTreeItem);
		}
	}

	pWndTree->SetFocus();
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EXPLORER, point.x, point.y, this, TRUE);
}

void CFileView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndFileView.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

void CFileView::OnProperties()
{
	AfxMessageBox(_T("Properties...."));

}

void CFileView::OnFileOpen()
{
	// TODO: Add your command handler code here
	HTREEITEM  temp = m_wndFileView.GetSelectedItem();
	HTREEITEM parentitem = m_wndFileView.GetParentItem(temp);
	if (!m_wndFileView.ItemHasChildren(temp)){
		CString str = m_wndFileView.GetItemText(temp);
		CString parentname = m_wndFileView.GetItemText(parentitem);
		char path[256] ;
		GetCurrentDirectory(256,path);
		//CString pathstring = path;
		CString pathstring = workspace;
		// 根据根目录设置路径
		if (parentname.Left(4) == "SPIN"){
			pathstring.Append("\\spin\\");
		}
		if (parentname.Left(4) == "Effe"){
			pathstring.Append("\\piez\\");
		}
		//::MessageBox(NULL,_T(pathstring+str),_T("OK"),MB_OK);
		if (str.Right(3)==_T("bmp")){
			((CPMPApp *)AfxGetApp())->m_pBmpDocTemplate->OpenDocumentFile(pathstring+str);
		}else{
			// 其他格式一律用文本编辑器打开
			((CPMPApp *)AfxGetApp())->m_pTxtDocTemplate->OpenDocumentFile(pathstring+str);
		}
	}
}

void CFileView::OnFileOpenWith()
{
	// TODO: Add your command handler code here
	HTREEITEM  temp = m_wndFileView.GetSelectedItem();
	HTREEITEM parentitem = m_wndFileView.GetParentItem(temp);
	if (!m_wndFileView.ItemHasChildren(temp)){
		CString str = m_wndFileView.GetItemText(temp);
		CString parentname = m_wndFileView.GetItemText(parentitem);
		char path[256] ;
		GetCurrentDirectory(256,path);
		//CString pathstring = path;
		CString pathstring = workspace;
		// 根据根目录设置路径
		if (parentname.Left(4) == "SPIN"){
			pathstring.Append("\\spin\\");
		}
		if (parentname.Left(4) == "Effe"){
			pathstring.Append("\\piez\\");
		}
		CDialogOpenwith openwith;
		if (openwith.DoModal() == IDOK)
		{
			if (openwith.m_list_openwith_int == 0){
				CString openfilecmd = "notepad "+pathstring +str;
				WinExec(openfilecmd,SW_SHOW);
			}
			if (openwith.m_list_openwith_int == 1){

				CString openfilecmd = "rundll32.exe shimgvw.dll imageview_fullscreen "+pathstring +str;
				WinExec(openfilecmd,SW_SHOW);
			}
		}
	}
}

void CFileView::OnDummyCompile()
{
	// TODO: Add your command handler code here
}

void CFileView::OnEditCut()
{
	// TODO: Add your command handler code here
}

void CFileView::OnEditCopy()
{
	// TODO: Add your command handler code here
}

void CFileView::OnEditClear()
{
	// TODO: Add your command handler code here
}

void CFileView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectTree;
	m_wndFileView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CFileView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndFileView.SetFocus();
}

void CFileView::OnChangeVisualStyle()
{
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_EXPLORER_24 : IDR_EXPLORER, 0, 0, TRUE /* Locked */);

	m_FileViewImages.DeleteImageList();

	UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_FILE_VIEW_24 : IDB_FILE_VIEW;

	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("Can't load bitmap: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_FileViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_FileViewImages.Add(&bmp, RGB(255, 0, 255));

	m_wndFileView.SetImageList(&m_FileViewImages, TVSIL_NORMAL);
}




void CFileView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 11:
		this->MoniTimer(workspace);
		this->FortTimer(workspace);
		//::MessageBox(NULL,_T(filelist),_T("OK"),MB_OK);
		if (listsize != fileviewlist.GetSize()){
			for (int i=listsize;i<fileviewlist.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlist.GetAt(i)), 1, 1, hBmp);;
			}
			listsize=fileviewlist.GetSize();
		}
		if (fortlistsize != fileviewlistfort.GetSize()){
			for (int i=fortlistsize;i<fileviewlistfort.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistfort.GetAt(i)), 1, 1, hFort);;
			}
			fortlistsize=fileviewlistfort.GetSize();
		}
	
		//m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
		//m_wndFileView.Expand(hBmp, TVE_EXPAND);
		fileviewlist.RemoveAll();
		fileviewlistfort.RemoveAll();

		break;
	case 12:
		this->DataTimer(workspace);
		this->PiezFortTimer(workspace);
		this->PiezOtherTimer(workspace);
		//::MessageBox(NULL,_T(filelist),_T("OK"),MB_OK);
		if (piezlistsize != fileviewlistpiez.GetSize()){
			for (int i=piezlistsize;i<fileviewlistpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistpiez.GetAt(i)), 1, 1, hPiezData);
			}
			piezlistsize=fileviewlistpiez.GetSize();
		}
		if (piezfortlistsize != fileviewlistfortpiez.GetSize()){
			for (int i=piezfortlistsize;i<fileviewlistfortpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistfortpiez.GetAt(i)), 1, 1, hPiezFort);
			}
			piezfortlistsize=fileviewlistfortpiez.GetSize();
		}
		if (piezotherlistsize != fileviewlistotherpiez.GetSize()){
			for (int i=piezotherlistsize;i<fileviewlistotherpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistotherpiez.GetAt(i)), 1, 1, hPiezOther);
			}
			piezotherlistsize=fileviewlistotherpiez.GetSize();
		}
		fileviewlistpiez.RemoveAll();
		fileviewlistfortpiez.RemoveAll();
		fileviewlistotherpiez.RemoveAll();
		break;
	}

	CDockablePane::OnTimer(nIDEvent);
}
void CFileView::MoniTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\spin\\*.bmp");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			CString fullPath;
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlist.Add(str);
			fileviewlistFullPath.Add(fullPath);
			//this->MoniTimer(str);
		}
	}

	finder.Close();
}

void CFileView::FortTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\spin\\fort.*");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlistfort.Add(str);
			//this->FortTimer(str);
		}
	}

	finder.Close();
}
void CFileView::DataTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\piez\\*.dat");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlistpiez.Add(str);
			//this->DataTimer(str);
		}
	}

	finder.Close();
}
void CFileView::PiezFortTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\piez\\fort.*");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlistfortpiez.Add(str);
			//this->MoniTimer(str);
		}
	}

	finder.Close();
}

void CFileView::PiezOtherTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\piez\\*.in");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlistotherpiez.Add(str);
			//this->MoniTimer(str);
		}
	}

	finder.Close();
}


void CFileView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//::MessageBox(NULL,_T("FileView"),_T("OK"),MB_OK);
	HTREEITEM  temp = this->m_wndFileView.GetSelectedItem();
	HTREEITEM parentitem = m_wndFileView.GetParentItem(temp);
	if (!m_wndFileView.ItemHasChildren(temp)){
		CString str = m_wndFileView.GetItemText(temp);
		CString parentname = m_wndFileView.GetItemText(parentitem);
		char path[256] ;
		GetCurrentDirectory(256,path);
		CString pathstring = workspace;
		// 根据根目录设置路径
		if (parentname.Left(4) == "SPIN"){
			pathstring.Append("\\spin\\");
		}
		if (parentname.Left(4) == "Effe"){
			pathstring.Append("\\piez\\");
		}
		//::MessageBox(NULL,_T(pathstring+str),_T("OK"),MB_OK);
		if (str.Right(3)==_T("bmp")){
			((CPMPApp *)AfxGetApp())->m_pBmpDocTemplate->OpenDocumentFile(pathstring+str);
		}else{
			// 其他格式一律用文本编辑器打开
			((CPMPApp *)AfxGetApp())->m_pTxtDocTemplate->OpenDocumentFile(pathstring+str);
		}
	}
	CDockablePane::OnLButtonDblClk(nFlags, point);
}


void CFileView::OnExplorerVisualize()
{
	// TODO: Add your command handler code here
	HTREEITEM temp =  m_wndFileView.GetSelectedItem();
	HTREEITEM parentitem = m_wndFileView.GetParentItem(temp);
	if (!m_wndFileView.ItemHasChildren(temp)){
		CString str = m_wndFileView.GetItemText(temp);
		CString parentname = m_wndFileView.GetItemText(parentitem);
		CString outfilename;
		char path[256] ;GetCurrentDirectory(256,path);
		CString pathstring = workspace;
		// 根据根目录设置路径
		if (parentname.Left(4) == "SPIN"){
			pathstring.Append("\\spin\\");
		}
		if (parentname.Left(4) == "Effe"){
			pathstring.Append("\\piez\\");
		}

		// 判断数据是vector类型还是tensor类型
		CStdioFile datafile;
		datafile.Open(pathstring+str,CFile::modeRead | CFile::shareDenyNone| CFile::typeText);
		CString datatype;
		// 读入第一行，以便读入第二行
		datafile.ReadString(datatype);
		// 读入第二行，以便判断数据类型
		datafile.ReadString(datatype);
		datafile.Close();
		datatype.Trim();
		int in=0;
		char *p[20];
		char *buf = (LPSTR)(LPCTSTR)datatype;
		while((p[in]=strtok(buf," "))!=NULL) {
			in++;
			buf=NULL; }
		// scalar类型
		if(in == 4){
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 1;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制Scalar1D图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pScalarDatDocTemplate;
					if (!PathFileExists(pathstring+str+"Scalar1D.vtk"))
					{
						m_transformer.PMPTransformToVTKForScalar1D(pathstring+str,outfilename);
					}else{
						outfilename = pathstring+str+"Scalar1D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制Volume图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pScalarDatDocGridTemplate;
					CString temppathname ;
					temppathname.Format("%s%s%d%s",pathstring+str,"Scalar1D",visualizedlg.m_combo_volume_int+1,".vtk");
					if (!PathFileExists(temppathname))
					{
						m_transformer.PMPTransformToVTKForVolume(pathstring+str,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename = temppathname;
					}
					docTemplate->OpenDocumentFile(outfilename);
					
				}
			}
		}else if (in == 6)// vector类型
		{
			// 
			//MessageBox(_T("Vector类型"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 2;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制Vector3D图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocTemplate;
					if (!PathFileExists(pathstring+str+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathstring+str,outfilename);
					}else{
						outfilename=pathstring+str+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制Vector3D Streamline图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocStrmlineTemplate;
					if (!PathFileExists(pathstring+str+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathstring+str,outfilename);
					}else{
						outfilename=pathstring+str+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// 绘制Vector3D volume图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocVolumeTemplate;
					CString temppathname ;
					temppathname.Format("%s%s%d%s",pathstring+str,"Vector3D",visualizedlg.m_combo_volume_int+1,".vtk");
					if (!PathFileExists(temppathname))
					{
						m_transformer.PMPTransformToVTKForVolume(pathstring+str,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename = temppathname;
					}
					//m_transformer.PMPTransformToVTKForVolume(pathstring+str,visualizedlg.m_combo_volume_int+1,outfilename);
					docTemplate->OpenDocumentFile(outfilename);
				}

			}
		}else if (in == 9)// tensor类型
		{

			//MessageBox(_T("tensor类型"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 3;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制tensor图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocTensoTemplate;
					if (!PathFileExists(pathstring+str+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathstring+str,outfilename);
					}else{
						outfilename = pathstring+str+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制multiview图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocMultiTemplate;
					if (!PathFileExists(pathstring+str+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathstring+str,outfilename);
					}else{
						outfilename = pathstring+str+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// 绘制Tensor图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocTemplate;
					CString temppathname ;
					temppathname.Format("%s%s%d%s",pathstring+str,"Vector3D",visualizedlg.m_combo_volume_int+1,".vtk");
					if (!PathFileExists(temppathname))
					{
						m_transformer.PMPTransformToVTKForVolume(pathstring+str,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename = temppathname;
					}
					//m_transformer.PMPTransformToVTKForVolume(pathstring+str,visualizedlg.m_combo_volume_int+1,outfilename);
					CPMPTensorDatDoc * pDoc = (CPMPTensorDatDoc *)docTemplate->OpenDocumentFile(outfilename);
				}

			}
		}
		
		
	}
}
