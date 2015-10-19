
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree window

class CViewTree : public CTreeCtrl
{
// Construction
public:
	CViewTree();

// Overrides
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

// Implementation
public:
	virtual ~CViewTree();

protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
public :
	// ¹¤×÷¿Õ¼ä
	CString workspace;
};
