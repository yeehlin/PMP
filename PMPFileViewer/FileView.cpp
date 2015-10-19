
#include "stdafx.h"
#include "mainfrm.h"
#include "FileView.h"
#include "Resource.h"
#include "PMPFileViewer.h"

#include "stdio.h"
#include "malloc.h"

#define MAX_POINTS 110592
#define DATA_TYPE float

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
//	ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_EXPLORER_VISUALIZE, &CFileView::OnExplorerVisualize)
//ON_UPDATE_COMMAND_UI(ID_DUMMY_COMPILE, &CFileView::OnUpdateDummyCompile)
ON_UPDATE_COMMAND_UI(ID_EXPLORER_VISUALIZE, &CFileView::OnUpdateExplorerVisualize)
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
	// ɨ��ָ��Ŀ¼�µĹ��̣�һ���ļ�����Ϊһ������
	// ���빤������Ŀ¼
	FillFileViewByModuleType(1);
	FillFileViewByModuleType(2);
}

void CFileView::FillFileViewByModuleType(int moduleType)
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
		// �����֮ǰ��ɨ��һ��
		this->MoniTimer(".");
		this->FortTimer(".");
		//::MessageBox(NULL,_T(filelist),_T("OK"),MB_OK);
		if (listsize != fileviewlist.GetSize()){
			for (int i=listsize;i<fileviewlist.GetSize();i++)
			{
				CFileViewer c ;
				c.setFileFullPath(fileviewlistFullPath.GetAt(i));
				c.setFileName(fileviewlist.GetAt(i));
				SpinodalFileList.AddTail(c);
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
		hMyRootPiez = m_wndFileView.InsertItem(_T("Electric files"), 0, 0);
		m_wndFileView.SetItemState(hMyRootPiez, TVIS_BOLD, TVIS_BOLD);

		hPiezData = m_wndFileView.InsertItem(_T("Electric data Files"), 0, 0, hMyRootPiez);

		hPiezFort = m_wndFileView.InsertItem(_T("Electric fort Files"), 0, 0, hMyRootPiez);

		m_wndFileView.Expand(hMyRootPiez, TVE_EXPAND);
		m_wndFileView.Expand(hPiezData, TVE_EXPAND);
		m_wndFileView.Expand(hPiezFort, TVE_EXPAND);
		// �����֮ǰ��ɨ��һ��
		this->DataTimer(".");
		this->PiezFortTimer(".");
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
		fileviewlistpiez.RemoveAll();
		fileviewlistfortpiez.RemoveAll();
		break;
	}
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
	switch (nIDEvent)
	{
	case 11:
		this->MoniTimer(".");
		this->FortTimer(".");
		//::MessageBox(NULL,_T(filelist),_T("OK"),MB_OK);
		if (listsize != fileviewlist.GetSize()){
			for (int i=listsize;i<fileviewlist.GetSize();i++)
			{
				CFileViewer c ;
				c.setFileFullPath(fileviewlistFullPath.GetAt(i));
				c.setFileName(fileviewlist.GetAt(i));
				SpinodalFileList.AddTail(c);
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
	case 12:
		this->DataTimer(".");
		this->PiezFortTimer(".");
		//::MessageBox(NULL,_T(filelist),_T("OK"),MB_OK);
		if (piezlistsize != fileviewlistpiez.GetSize()){
			for (int i=listsize;i<fileviewlistpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistpiez.GetAt(i)), 1, 1, hPiezData);
			}
			piezlistsize=fileviewlistpiez.GetSize();
		}
		if (piezfortlistsize != fileviewlistfortpiez.GetSize()){
			for (int i=listsize;i<fileviewlistfortpiez.GetSize();i++)
			{
				m_wndFileView.InsertItem(_T(fileviewlistfortpiez.GetAt(i)), 1, 1, hPiezFort);
			}
			piezfortlistsize=fileviewlistfortpiez.GetSize();
		}
		fileviewlistpiez.RemoveAll();
		fileviewlistfortpiez.RemoveAll();
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

void CFileView::SetModuleType(int moduleType){
	this->m_ModuleType = moduleType;
}

//void CFileView::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//	HTREEITEM temp = m_wndFileView.GetSelectedItem();
//	::MessageBoxA(NULL,_T("OK"),_T("OK"),MB_OK);
//
//	CDockablePane::OnLButtonDblClk(nFlags, point);
//}


void CFileView::OnExplorerVisualize()
{
	// TODO: Add your command handler code here
	HTREEITEM temp =  m_wndFileView.GetSelectedItem();
	if (!m_wndFileView.ItemHasChildren(temp)){
		CString str = m_wndFileView.GetItemText(temp);
		char path[256] ;GetCurrentDirectory(256,path);
		CString pathstring = path;
		pathstring.Append("\\piez\\");
		//::MessageBoxA(NULL,_T(pathstring+str),_T("OK"),MB_OK);
		CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
		CDocument * pCurrent = pMainFrame->GetActiveDocument();
		//POSITION pos = AfxGetApp()->m_pDocManager->GetFirstDocTemplatePosition();

		//CDocTemplate * temp = AfxGetApp()->m_pDocManager->GetNextDocTemplate(pos);
		//AfxGetApp()->m_pDocManager->OpenDocumentFile(pathstring+str);
		((CPMPFileViewerApp * )AfxGetApp())->m_pDatDocTemplate->OpenDocumentFile(pathstring+str);
		//pMainFrame->CreateDocumentWindow("Name",pMainFrame);
		//POSITION pos;
		//pos = pCurrent->GetFirstViewPosition();
		//CPMPFileViewerView * temp = (CPMPFileViewerView * )pCurrent->GetNextView(pos);

		// ϣ��ͨ��������Ϣ��֪DOC��һ���ĵ���Ҫ�򿪣�����֪�ĵ�������
		//temp->SendMessage(WM_USERMESSAGE,0,0);

	}
}

//void CFileView::OnUpdateDummyCompile(CCmdUI *pCmdUI)
//{
//	// TODO: Add your command update UI handler code here
//}


void CFileView::OnUpdateExplorerVisualize(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

}
