
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree window
#include "PMPFileViewerView.h"

#define WM_USERMESSAGE WM_USER+100

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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	int m_moduleType;
	void setModuleType(int moduleType);
};
