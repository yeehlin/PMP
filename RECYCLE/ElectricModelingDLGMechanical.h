#pragma once


// ElectricModelingDLGMechanical dialog

class ElectricModelingDLGMechanical : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMechanical)

public:
	ElectricModelingDLGMechanical(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMechanical();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MECHANICAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
