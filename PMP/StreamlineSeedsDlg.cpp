// StreamlineSeedsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "StreamlineSeedsDlg.h"
#include "afxdialogex.h"


// CStreamlineSeedsDlg dialog

IMPLEMENT_DYNAMIC(CStreamlineSeedsDlg, CDialog)

CStreamlineSeedsDlg::CStreamlineSeedsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStreamlineSeedsDlg::IDD, pParent)
{

	m_edit_streamline_seeds_x_int = 10;
	m_edit_streamline_seeds_y_int = 10;
	m_edit_streamline_seeds_z_int = 10;
	m_edit_streamline_seeds_points_int = 10;
	m_edit_streamline_seeds_radius_float = 5.0f;
	m_caption = "Streamline seeds";
}

CStreamlineSeedsDlg::~CStreamlineSeedsDlg()
{
}

void CStreamlineSeedsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STREAMLINE_SEEDS_X, m_edit_streamline_seeds_x_int);
	DDX_Text(pDX, IDC_EDIT_STREAMLINE_SEEDS_Y, m_edit_streamline_seeds_y_int);
	DDX_Text(pDX, IDC_EDIT_STREAMLINE_SEEDS_Z, m_edit_streamline_seeds_z_int);
	DDX_Text(pDX, IDC_EDIT_STREAMLINE_SEEDS_POINTS, m_edit_streamline_seeds_points_int);
	DDX_Text(pDX, IDC_EDIT_STREAMLINE_SEEDS_RADIUS, m_edit_streamline_seeds_radius_float);
}


BEGIN_MESSAGE_MAP(CStreamlineSeedsDlg, CDialog)
END_MESSAGE_MAP()


// CStreamlineSeedsDlg message handlers


BOOL CStreamlineSeedsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	SetWindowText(m_caption);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
