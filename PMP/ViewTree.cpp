
#include "stdafx.h"
#include "ViewTree.h"
#include "PMP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
//	ON_WM_LBUTTONDBLCLK()
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


void CViewTree::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//::MessageBox(NULL,_T("双击ViewTree"),_T("OK"),MB_OK);
	HTREEITEM  temp = this->GetSelectedItem();
	HTREEITEM parentitem = GetParentItem(temp);
	if (!ItemHasChildren(temp)){
		CString str = GetItemText(temp);
		CString parentname = GetItemText(parentitem);
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
	CTreeCtrl::OnLButtonDblClk(nFlags, point);
}
