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
	// �ӿڣ��ýӿڹ�ElectricModelingDLGFather�����������е���������д���ļ�
	void PersistenceParameter(void);
	afx_msg void OnClose();
	// ���Ի���ȡһ������
	CString m_caption;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedEclectricButnRun();
	afx_msg void OnBnClickedElectricButnFile();
	afx_msg void OnBnClickedCancel();
	// ����filename�ļ��е����ݵ�����
	void LoadParameter(CString filename);
	// ����Ŀ¼
	BOOL MakeDir(CString szDirName);
	// ��ʶ��ǰ�������е�ģ��
	int m_RunType;
};