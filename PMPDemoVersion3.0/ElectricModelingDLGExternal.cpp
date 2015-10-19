// ElectricModelingDLGExternal.cpp : implementation file
//

#include "stdafx.h"
#include "VTKMFCCreateBMPActors.h"
#include "ElectricModelingDLGExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGExternal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGExternal, CDialog)

ElectricModelingDLGExternal::ElectricModelingDLGExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGExternal::IDD, pParent)
{

	m_edit_e1 = 0.0f;
	m_edit_e2 = 0.0f;
	m_edit_eo3 = 0.0f;
}

ElectricModelingDLGExternal::~ElectricModelingDLGExternal()
{
}

void ElectricModelingDLGExternal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_E1, m_edit_e1);
	DDX_Text(pDX, IDC_EDIT_E2, m_edit_e2);
	DDX_Text(pDX, IDC_EDIT_E3, m_edit_eo3);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGExternal, CDialog)
END_MESSAGE_MAP()


// ElectricModelingDLGExternal message handlers


BOOL ElectricModelingDLGExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
