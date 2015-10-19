#pragma once


// CalculateDlgChild2 dialog

class CalculateDlgChild2 : public CDialog
{
	DECLARE_DYNAMIC(CalculateDlgChild2)

public:
	CalculateDlgChild2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CalculateDlgChild2();

// Dialog Data
	enum { IDD = IDD_CALCULATE_DLG_CHILD2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_edit_total_nums_of_steps;
	int m_edit_time_steps;
	int m_edit_time_steps_with_noise;
	CEdit m_EditTotalNumsOfSteps;
	CEdit m_EditTimeSteps;
	CEdit m_EditTimeStepsWithNoise;
	virtual BOOL OnInitDialog();
};
