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
	// ����ӶԻ����ࣨ��Ϊtabҳ���֣�
public :
	// ����tab control�ؼ����������Ӹ��Ի�����ӶԻ���
//	CTabCtrl m_tab;
	// ��������Ի����Ӵ��ڣ��⽫�����tab��
	CDialog calculateDlgChild[3];
	// ��ʶ��ǰtabҳ
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
	// �ӿڣ��ýӿڿ��Խ��Ի����еĲ���д��һ���ļ�
	void PersistenceParameter();
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedRun();
	afx_msg void OnBnClickedButtonFile();
	int m_RunType;
	CString m_RunFilePath;
};
