#pragma once


// CDialogOpenwith dialog

class CDialogOpenwith : public CDialog
{
	DECLARE_DYNAMIC(CDialogOpenwith)

public:
	CDialogOpenwith(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogOpenwith();

// Dialog Data
	enum { IDD = IDD_DIALOG_OPENWITH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ListOpenwith;
//	CString m_list_openwith;
	CString m_list_openwith_string;
	int m_list_openwith_int;
	virtual BOOL OnInitDialog();
};
