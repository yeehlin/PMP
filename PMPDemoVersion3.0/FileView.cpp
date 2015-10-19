
#include "stdafx.h"
#include "mainfrm.h"
#include "FileView.h"
#include "Resource.h"
#include "VTKMFCCreateBMPActors.h"

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
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar message handlers

int CFileView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
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
	hMyRoot = m_wndFileView.InsertItem(_T("SPINODAL files"), 0, 0);
	m_wndFileView.SetItemState(hMyRoot, TVIS_BOLD, TVIS_BOLD);

	hBmp = m_wndFileView.InsertItem(_T("SPINODAL Bmp Files"), 0, 0, hMyRoot);

	//m_wndFileView.InsertItem(_T("001comp.bmp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("002comp.bmp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("003comp.bmp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("004comp.bmp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("005comp.bmp"), 1, 1, hSrc);
	//m_wndFileView.InsertItem(_T("006comp.bmp"), 1, 1, hSrc);

	hFort = m_wndFileView.InsertItem(_T("SPINODAL fort Files"), 0, 0, hMyRoot);

	//m_wndFileView.InsertItem(_T("fort.1000"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("fort.2000"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("fort.3000"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("fort.4000"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("fort.5000"), 2, 2, hInc);
	//m_wndFileView.InsertItem(_T("fort.6000"), 2, 2, hInc);

	//HTREEITEM hRes = m_wndFileView.InsertItem(_T("SPINODAL Other Files"), 0, 0, hRoot);

	//m_wndFileView.InsertItem(_T("input.dat"), 2, 2, hRes);
	//m_wndFileView.InsertItem(_T("restartcomp.10000"), 2, 2, hRes);

	m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
	m_wndFileView.Expand(hBmp, TVE_EXPAND);
	m_wndFileView.Expand(hFort, TVE_EXPAND);

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
}

void CFileView::OnFileOpenWith()
{
	// TODO: Add your command handler code here
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
	//::MessageBox(NULL,_T("时钟在运行"),_T("OK"),MB_OK);
	//HTREEITEM temp;
	//while((temp = m_wndFileView.GetChildItem(hBmp))!=NULL){
	//	m_wndFileView.DeleteItem(temp);
	//}
	//hBmp = m_wndFileView.InsertItem(_T("SPINODAL Bmp Files"), 0, 0, hMyRoot);
	this->MoniTimer(".");
	this->FortTimer(".");
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

	m_wndFileView.Expand(hMyRoot, TVE_EXPAND);
	m_wndFileView.Expand(hBmp, TVE_EXPAND);
	fileviewlist.RemoveAll();
	fileviewlistfort.RemoveAll();
	//listsize = 0;

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
			//str.Format("%s\n",str);
			//filelist.Append(str);
			//printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			fileviewlist.Add(str);
			this->MoniTimer(str);
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
			this->MoniTimer(str);
		}
	}

	finder.Close();
}