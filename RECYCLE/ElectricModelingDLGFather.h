#pragma once

#include "ElectricModelingDLGChild1.h"
#include "ElectricModelingDLGChild2.h"
#include "ElectricModelingDLGPhaseNo2.h"
#include "ElectricModelingDLGPhaseNo3.h"
#include "ElectricModelingDLGPhaseNo4.h"
#include "ElectricModelingDLGPhaseNo5.h"
#include "ElectricModelingDLGPhaseNo6.h"
#include "ElectricModelingDLGChild3.h"

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
	//CDialog * modelingDlgChild[8];
	//int currentSelectedTab;
	ElectricModelingDLGChild1 m_electricModelingDLGChild1;
	//ElectricModelingDLGChild2 m_electricModelingDLGChild2;
	//ElectricModelingDLGChild3 m_electricModelingDLGChild3;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeModelingDlgTab(NMHDR *pNMHDR, LRESULT *pResult);
	//ElectricModelingDLGPhaseNo2 m_electricModelingDLGPhaseNo2;
	//ElectricModelingDLGPhaseNo3 m_electricModelingDLGPhaseNo3;
	//ElectricModelingDLGPhaseNo4 m_electricModelingDLGPhaseNo4;
	//ElectricModelingDLGPhaseNo5 m_electricModelingDLGPhaseNo5;
	//ElectricModelingDLGPhaseNo6 m_electricModelingDLGPhaseNo6;
//	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedOk();
	// 接口：该接口供ElectricModelingDLGFather对象将其所持有的输入数据写入文件
	void PersistenceParameter(void);
	afx_msg void OnBnClickedButtonAddTab();
	afx_msg void OnClose();
};