#pragma once


// CDialogTree dialog

class CDialogTree : public CDialog
{
	DECLARE_DYNAMIC(CDialogTree)

public:
	CDialogTree(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogTree();

// Dialog Data
	enum { IDD = IDD_DIALOG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
