
#include "stdafx.h"
#include "ViewTree.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "PMPFileViewer.h"

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
	m_moduleType = 0;
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree message handlers

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}

void CViewTree::setModuleType(int moduleType){
	this->m_moduleType = moduleType;
}

void CViewTree::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
			HTREEITEM  temp = this->GetSelectedItem();
		HTREEITEM parentitem = GetParentItem(temp);
	if (!ItemHasChildren(temp)){
		CString str = GetItemText(temp);
		CString parentname = GetItemText(parentitem);
		char path[256] ;GetCurrentDirectory(256,path);
		CString pathstring = path;
		// 根据根目录设置路径
		if (parentname.Left(4) == "SPIN"){
			pathstring.Append("\\spin\\");
		}
		if (parentname.Left(4) == "Elec"){
			pathstring.Append("\\piez\\");
		}
		//::MessageBoxA(NULL,_T(pathstring+str),_T("OK"),MB_OK);
		//POSITION pos = AfxGetApp()->m_pDocManager->GetFirstDocTemplatePosition();
		
		//CDocTemplate * temp = AfxGetApp()->m_pDocManager->GetNextDocTemplate(pos);
		// 根据后缀名决定使用哪一个模版打开
		if (str.Right(3)==_T("bmp")){
			((CPMPFileViewerApp *)AfxGetApp())->m_pBmpDocTemplate->OpenDocumentFile(pathstring+str);
		}else{
			// 其他格式一律用文本编辑器打开
			((CPMPFileViewerApp *)AfxGetApp())->m_pTxtDocTemplate->OpenDocumentFile(pathstring+str);
		}

		
		//pMainFrame->CreateDocumentWindow("Name",pMainFrame);
		//POSITION pos;
		//pos = pCurrent->GetFirstViewPosition();
		//CPMPFileViewerView * temp = (CPMPFileViewerView * )pCurrent->GetNextView(pos);

		// 希望通过发送消息告知DOC有一份文档需要打开，并告知文档的名称
		//temp->SendMessage(WM_USERMESSAGE,0,0);

	}

	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}
