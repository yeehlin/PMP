#pragma once

#include "PMPBMPFile.h"

// CPMPBMPFileView view

class CPMPBMPFileView : public CView
{
	DECLARE_DYNCREATE(CPMPBMPFileView)

protected:
	CPMPBMPFileView();           // protected constructor used by dynamic creation
	virtual ~CPMPBMPFileView();
// Attributes
public:
	CPMPBMPFile * GetDocument() const;
public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public :
	CEdit * m_ctrlEdit;
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in PMPFileViewerView.cpp
inline CPMPBMPFile* CPMPBMPFile::GetDocument() const
{ return reinterpret_cast<CPMPBMPFile*>(m_pDocument); }
#endif
