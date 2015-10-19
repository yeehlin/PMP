
#pragma once

#include "ViewTree.h"

#include "PMPTransformer.h"

#define TIMER_TWO_SECOND 11
#define TIMER_PIEZ_SECOND 12

class CFileViewToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CFileView : public CDockablePane
{
// Construction
public:
	CFileView();

	void AdjustLayout();
	void OnChangeVisualStyle();

// Attributes
protected:

	CViewTree m_wndFileView;
	CImageList m_FileViewImages;
	CFileViewToolBar m_wndToolBar;

protected:
	void FillFileView();

// Implementation
public:
	virtual ~CFileView();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnProperties();
	afx_msg void OnFileOpen();
	afx_msg void OnFileOpenWith();
	afx_msg void OnDummyCompile();
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);

	DECLARE_MESSAGE_MAP()
public :
	HTREEITEM hMyRoot;
	HTREEITEM hBmp;
	HTREEITEM hFort;

	HTREEITEM hMyRootPiez;
	HTREEITEM hPiezData;
	HTREEITEM hPiezFort;
	HTREEITEM hPiezOther;

	void MoniTimer(CString str);
	void FortTimer(CString str);
	void DataTimer(CString str);
	void PiezFortTimer(CString str);
	void PiezOtherTimer(CString str);
	CString filelist;
	CStringArray fileviewlist;
	CStringArray fileviewlistFullPath;
	CStringArray fileviewlistfort;
	CStringArray fileviewlistpiez;
	CStringArray fileviewlistfortpiez;
	CStringArray fileviewlistotherpiez;
	int listsize;
	int fortlistsize;
	int piezlistsize;
	int piezfortlistsize;
	int piezotherlistsize;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 根据调用模块设置文件浏览类型
	void FillFileViewByType(int moduleType);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnExplorerVisualize();
public :
	// 数据转换接口
	CPMPTransformer m_transformer;
	// 工作空间路径
	CString workspace;
};

