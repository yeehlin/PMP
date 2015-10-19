#pragma once


// DlgVTKChild dialog

class DlgVTKChild : public CDialog
{
	DECLARE_DYNAMIC(DlgVTKChild)

public:
	DlgVTKChild(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgVTKChild();

// Dialog Data
	enum { IDD = IDD_DIALOG_VTK_CHILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
