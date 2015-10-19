
// TestMFCDlgWithTabctrlDoc.h : interface of the CTestMFCDlgWithTabctrlDoc class
//


#pragma once

#include "ElectricModelingDLGFather.h"

class CTestMFCDlgWithTabctrlDoc : public CDocument
{
protected: // create from serialization only
	CTestMFCDlgWithTabctrlDoc();
	DECLARE_DYNCREATE(CTestMFCDlgWithTabctrlDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTestMFCDlgWithTabctrlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnToolModelingsystem();
	// 用于回填对话框而持有对象
	//ElectricModelingDLGFather electricModelingDLGFather;
	// 持有对象将占用大量内存，更改为使用指针和动态内存分配以优化内存使用
	ElectricModelingDLGFather  * m_pelectricModelingDLGFather;
};
