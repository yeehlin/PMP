#pragma once

#include "CalculateDlgChild1.h"
#include "CalculateDlgChild2.h"
#include "CalculateDlgChild3.h"

// CalculateDlgFather dialog

class CalculateDlgFather : public CDialog
{
	DECLARE_DYNAMIC(CalculateDlgFather)

public:
	CalculateDlgFather(CWnd* pParent = NULL);   // standard constructor
	virtual ~CalculateDlgFather();

// Dialog Data
	enum { IDD = IDD_CALCULATE_DLG_FATHER };
	// 添加子对话框类（作为tab页出现）
public :
	// 增加tab control控件，用于连接父对话框和子对话框
//	CTabCtrl m_tab;
	// 存放三个对话框子窗口，这将存放在tab中
	CDialog calculateDlgChild[3];
	// 标识当前tab页
	int currentSelectedTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeCalculateDlgTab(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tab;
	CalculateDlgChild1 * m_calculateDlgChild1;
	CalculateDlgChild2 * m_calculateDlgChild2;
	CalculateDlgChild3 * m_calculateDlgChild3;
	// 接口：该接口可以将对话框中的参数写入一个文件
	void PersistenceParameter();
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedRun();
	afx_msg void OnBnClickedButtonFile();
	int m_RunType;
	CString m_RunFilePath;
};
