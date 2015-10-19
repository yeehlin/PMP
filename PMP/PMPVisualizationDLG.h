#pragma once


// CPMPVisualizationDLG dialog

class CPMPVisualizationDLG : public CDialog
{
	DECLARE_DYNAMIC(CPMPVisualizationDLG)

public:
	CPMPVisualizationDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPMPVisualizationDLG();

// Dialog Data
	enum { IDD = IDD_DIALOG_VISUALIZATIONTYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ListVisualizationtype;
	CString m_list_visualizationtype_string;
	int m_list_visualizationtype_int;
	virtual BOOL OnInitDialog();
	int m_visualization_type;
	CString m_caption;
	CComboBox m_ComboVolume;
	int m_combo_volume_int;
	afx_msg void OnLbnSelchangeListVisualizationtype();
	afx_msg void OnBnClickedOk();
};
