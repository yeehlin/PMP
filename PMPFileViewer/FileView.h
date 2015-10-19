
#pragma once

#include "ViewTree.h"
#include "FileViewer.h"

#define TIMER_FOR_FILEVIEW 11
#define TIMER_FOR_FILEVIEW_MDL2 12

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
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_ModuleType;
	void SetModuleType(int moduleType);
	void FillFileViewByModuleType(int moduleType);
	HTREEITEM hMyRoot;
	HTREEITEM hBmp;
	HTREEITEM hFort;

	HTREEITEM hMyRootPiez;
	HTREEITEM hPiezData;
	HTREEITEM hPiezFort;

	HTREEITEM hWorkspaceRoot;
	HTREEITEM hProjectRoot;
	HTREEITEM hModuleRoot;

	void MoniTimer(CString str);
	void FortTimer(CString str);
	void DataTimer(CString str);
	void PiezFortTimer(CString str);
	CString filelist;
	CStringArray fileviewlist;
	CStringArray fileviewlistFullPath;
	CStringArray fileviewlistfort;
	CStringArray fileviewlistpiez;
	CStringArray fileviewlistfortpiez;
	int listsize;
	int fortlistsize;
	int piezlistsize;
	int piezfortlistsize;
	CList<CFileViewer> SpinodalFileList;
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CViewTree* getFileTreeView(){
		return &m_wndFileView;
	};
	afx_msg void OnExplorerVisualize();
	// 数据转换接口
	void PMPTransformToVTKForVolume(CString filename);
	void PMPTransformToVTKForPolarization(CString filename);
	void pmpvisualizationvolume(CString filename);
	void pmpvisualizationpolarization(CString filename);

	CStringArray m_ModuleSpinBmpList;
	CStringArray m_ModuleSpinFortList;
	CStringArray m_ModuleSpinOtherList;

	CStringArray m_ModulePiezDataList;
	CStringArray m_ModulePiezFortList;
	CStringArray m_ModulePiezOtherList;

	CArray<CStringArray> ModuleSpin;
	CArray<CStringArray> ModulePiez;

	CArray<CArray<CStringArray>> ModuleList;

	CArray<CArray<CArray<CStringArray>>> ProjectList;

	
//	afx_msg void OnUpdateDummyCompile(CCmdUI *pCmdUI);
	afx_msg void OnUpdateExplorerVisualize(CCmdUI *pCmdUI);

	// 工作路径
	CString workspace;
};

