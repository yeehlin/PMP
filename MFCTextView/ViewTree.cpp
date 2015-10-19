
#include "stdafx.h"
#include "ViewTree.h"

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
	ON_WM_KEYDOWN()
//	ON_WM_SYSKEYDOWN()
//ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDOWN()
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


void CViewTree::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CTreeCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CViewTree::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if  (pMsg->message  ==  WM_KEYDOWN)  
	{  
		switch  (pMsg->lParam)
		{
		case  VK_ESCAPE:
			SetFocus  ();
			return  TRUE;
		case  VK_CONTROL:
			if(::GetKeyState(VK_LBUTTON)  <  0)//如果是Shift+X这里就  
				//改成VK_SHIFT
				MessageBox("hello");
			return  TRUE;
		}
	}
	return CTreeCtrl::PreTranslateMessage(pMsg);
}


//void CViewTree::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CTreeCtrl::OnSysKeyDown(nChar, nRepCnt, nFlags);
//}


//void CViewTree::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CTreeCtrl::OnLButtonDown(nFlags, point);
//}


void CViewTree::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (::GetKeyState(VK_LCONTROL)  <  0){
		//MessageBox("hello");
		
	}


	CTreeCtrl::OnLButtonDown(nFlags, point);
}
