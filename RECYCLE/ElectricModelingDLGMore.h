#pragma once


// ElectricModelingDLGMore dialog

class ElectricModelingDLGMore : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMore)

public:
	ElectricModelingDLGMore(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMore();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
