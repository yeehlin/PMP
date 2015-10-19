#pragma once

#include "ElectricModelingDLGChild1.h"

// ElectricModelingDLGFather dialog
class ElectricModelingDLGFather : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGFather)

public:
	ElectricModelingDLGFather(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGFather();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_FATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	ElectricModelingDLGChild1 * m_pelectricModelingDLGChild1;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeModelingDlgTab(NMHDR *pNMHDR, LRESULT *pResult);
	// 接口：该接口供ElectricModelingDLGFather对象将其所持有的输入数据写入文件
	void PersistenceParameter(void);
	afx_msg void OnClose();
	// 给对话框取一个名称
	CString m_caption;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedEclectricButnRun();
	afx_msg void OnBnClickedElectricButnFile();
	afx_msg void OnBnClickedCancel();
	// 加载filename文件中的数据到对象
	void LoadParameter(CString filename);
	// 创建目录
	BOOL MakeDir(CString szDirName);
	// 标识当前正在运行的模块
	int m_RunType;
};