#pragma once

#include "ElectricModelingDLGElastic.h"
#include "ElectricModelingDLGMechanical.h"

// ElectricModelingDLGMoreElastic dialog

class ElectricModelingDLGMoreElastic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreElastic)
public:
	ElectricModelingDLGMoreElastic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreElastic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_ELASTIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	int m_PhaseCount;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	virtual BOOL OnInitDialog();
	CTabCtrl m_TabMoreElastic;
	// ���ж���
	//ElectricModelingDLGElastic m_electricModelingDLGElastic[6];
	//ElectricModelingDLGMechanical m_electricModelingDLGMechanical;
	// �Ż����ж���Ϊ��̬����p
	ElectricModelingDLGElastic  * m_pelectricModelingDLGElastic[6];
	ElectricModelingDLGMechanical * m_pelectricModelingDLGMechanical;
	afx_msg void OnTcnSelchangeTabMoreElastic(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditC12();
	afx_msg void OnEnChangeEditC13();
	afx_msg void OnEnChangeEditC14();
	afx_msg void OnEnChangeEditC15();
	afx_msg void OnEnChangeEditC16();
	afx_msg void OnEnChangeEditC23();
	afx_msg void OnEnChangeEditC24();
	afx_msg void OnEnChangeEditC25();
	afx_msg void OnEnChangeEditC26();
	afx_msg void OnEnChangeEditC34();
	afx_msg void OnEnChangeEditC35();
	afx_msg void OnEnChangeEditC36();
	afx_msg void OnEnChangeEditC45();
	afx_msg void OnEnChangeEditC46();
	afx_msg void OnEnChangeEditC56();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	int m_simulationType;
	CString m_caption;
};
