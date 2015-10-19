// ElectricModelingDLGFather.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGFather.h"
#include "afxdialogex.h"


// ElectricModelingDLGFather dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGFather, CDialog)

ElectricModelingDLGFather::ElectricModelingDLGFather(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGFather::IDD, pParent)
{

	m_pelectricModelingDLGChild1 = new ElectricModelingDLGChild1();
	m_caption =_T("Dialog");
	//currentSelectedTab = 0;
}

ElectricModelingDLGFather::~ElectricModelingDLGFather()
{
	// �رմ��ڻ����ٶ�����
	//::MessageBox(NULL,_T("DLGFather"),_T("OKOK"),MB_OK);
	if (m_pelectricModelingDLGChild1 != NULL)
	{
		delete m_pelectricModelingDLGChild1;
	}
}

void ElectricModelingDLGFather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MODELING_DLG_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGFather, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_MODELING_DLG_TAB, &ElectricModelingDLGFather::OnTcnSelchangeModelingDlgTab)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGFather::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ECLECTRIC_BUTN_RUN, &ElectricModelingDLGFather::OnBnClickedEclectricButnRun)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_ELECTRIC_BUTN_FILE, &ElectricModelingDLGFather::OnBnClickedElectricButnFile)
	ON_BN_CLICKED(IDCANCEL, &ElectricModelingDLGFather::OnBnClickedCancel)
END_MESSAGE_MAP()


// ElectricModelingDLGFather message handlers


BOOL ElectricModelingDLGFather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	TCITEM  tcitemsetup;
	tcitemsetup.mask = TCIF_TEXT;
	tcitemsetup.pszText=_T("System Setup");
	this->m_tab.InsertItem(0,&tcitemsetup);
	// ���Tab�ؼ������꣬���ڷ���ѡ�
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	// ��λѡ�λ��
	tabRect.bottom -=8;
	tabRect.left +=8;
	tabRect.top +=20;
	tabRect.right-=8;
	//*/ �����ӶԻ���
	if (m_pelectricModelingDLGChild1==NULL){
		m_pelectricModelingDLGChild1 = new ElectricModelingDLGChild1();
	}
	m_pelectricModelingDLGChild1->Create(IDD_MODELING_DLG_CHILD1,GetDlgItem(IDC_MODELING_DLG_TAB));
	
	// ���ӶԻ����ƶ���ָ����λ��
	m_pelectricModelingDLGChild1->MoveWindow(&tabRect);

	// ��ʾ��ҳ�棬���ǻ��Ƶ�һ���ӶԻ��򣬶���������������
	m_pelectricModelingDLGChild1->ShowWindow(SW_SHOW);

	// ���Ի������ñ���
	this->SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGFather::OnTcnSelchangeModelingDlgTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

// �ӿڣ��ýӿڹ�ElectricModelingDLGFather�����������е���������д���ļ�
// ��ʲô����д�룬��ʲô���ĸ�ʽд�룬�����ٴν���
void ElectricModelingDLGFather::PersistenceParameter(void)
{
	CString str;
	CStdioFile input;
	input.Open(".\\piez\\parameter.in",CFile::modeWrite | CFile::modeCreate | CFile::typeText);
	// д����ά��
	str.Format("%d         %d         %d\t\t!nx ny nz\n",
		m_pelectricModelingDLGChild1->m_edit_mesh_nx,this->m_pelectricModelingDLGChild1->m_edit_mesh_ny,this->m_pelectricModelingDLGChild1->m_edit_mesh_nz);
	input.WriteString(str);
	// дϵͳ��С
	str.Format("%d         %d         %d\t\t!lx ly lz\n",m_pelectricModelingDLGChild1->m_edit_size_lx,m_pelectricModelingDLGChild1->m_edit_size_ly,m_pelectricModelingDLGChild1->m_edit_size_lz);
	input.WriteString(str);
	// дns ��nf
	//str.Format("%d         %d\t\t!ns nf\n",m_pelectricModelingDLGChild1->ns,m_pelectricModelingDLGChild1->nf);
	//input.WriteString(str);
	// дsystem type���ţ�np0 1-elastic 2-dielectric 3-piezoelectric       !tuy1
	str.Format("%d                                                                 !np0 1-elastic 2-dielectric 3-piezoelectric...       !tuy1\n",m_pelectricModelingDLGChild1->m_combo_sys_type_int+1);
	input.WriteString(str);
	// дphases����
	str.Format("%d                                                                 !total # of phases\n",m_pelectricModelingDLGChild1->m_edit_nums_phases);
	input.WriteString(str);
	// д�����ļ���ʽ����:1-order parameter array 2-phase id array
	str.Format("%d                                                                 !np1: 1-order parameter array 2-phase id array\n",m_pelectricModelingDLGChild1->m_combo_file_format_int+1);
	input.WriteString(str);
	// ѭ��д���phases�����ݵ��ļ�
	int curSel = m_pelectricModelingDLGChild1->m_combo_sys_type_int;
	int phases = m_pelectricModelingDLGChild1->m_edit_nums_phases;
	int simtype = m_pelectricModelingDLGChild1->m_combo_simulation_type_int;
	switch (curSel)
	{
	case 0:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGElastic * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGElasticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal;
			int bndtype = e->m_combo_mechanical_boundary_int;
			// дboundary condition����
			str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
			input.WriteString(str);

			// дapplied strain/stress
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
			input.WriteString(str);
			break;
		}
		break;
	case 1:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGDielectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_k11,c->m_edit_k22,c->m_edit_k33,c->m_edit_k23,c->m_edit_k13,c->m_edit_k12);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGDielectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal;
			// дelectric field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
			input.WriteString(str);
			break;
		}
		break;
	case 2:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGPiezoelectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_k11,c->m_edit_k22,c->m_edit_k33,c->m_edit_k23,c->m_edit_k13,c->m_edit_k12);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",c->m_edit_d11,c->m_edit_d12,c->m_edit_d13,c->m_edit_d14,c->m_edit_d15,c->m_edit_d16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d21,c->m_edit_d22,c->m_edit_d23,c->m_edit_d24,c->m_edit_d25,c->m_edit_d26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d31,c->m_edit_d32,c->m_edit_d33,c->m_edit_d34,c->m_edit_d35,c->m_edit_d36);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGPiezoelectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal;
			int bndtype = e->m_combo_mechanical_boundary_int;
			// дboundary condition����
			str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
			input.WriteString(str);
			// дapplied strain/stress
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
			input.WriteString(str);
			// дelectric field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
			input.WriteString(str);
			break;
		}
		break;
	case 3:
		for (int i = 0;i<phases;i++)
		{
			// дu����
			ElectricModelingDLGMagnetic * u = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i];
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",u->m_edit_u11,u->m_edit_u22,u->m_edit_u33,u->m_edit_u23,u->m_edit_u13,u->m_edit_u12);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGMagneticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal;
			// дmagnetic field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
			input.WriteString(str);
			break;
		}
		break;
	case 4:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGPiezomagnetic * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i];
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_u11,c->m_edit_u22,c->m_edit_u33,c->m_edit_u23,c->m_edit_u13,c->m_edit_u12);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q11,c->m_edit_q12,c->m_edit_q13,c->m_edit_q14,c->m_edit_q15,c->m_edit_q16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q21,c->m_edit_q22,c->m_edit_q23,c->m_edit_q24,c->m_edit_q25,c->m_edit_q26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q31,c->m_edit_q32,c->m_edit_q33,c->m_edit_q34,c->m_edit_q35,c->m_edit_q36);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGPiezomagneticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal;
			int bndtype = e->m_combo_mechanical_boundary_int;
			// дboundary condition����
			str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
			input.WriteString(str);
			// дapplied strain/stress
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
			input.WriteString(str);
			// дmagnetic field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
			input.WriteString(str);
			break;
		}
		break;
	case 5:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGMagnetoelectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i];
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_k11,c->m_edit_k22,c->m_edit_k33,c->m_edit_k23,c->m_edit_k13,c->m_edit_k12);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",c->m_edit_d11,c->m_edit_d12,c->m_edit_d13,c->m_edit_d14,c->m_edit_d15,c->m_edit_d16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d21,c->m_edit_d22,c->m_edit_d23,c->m_edit_d24,c->m_edit_d25,c->m_edit_d26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d31,c->m_edit_d32,c->m_edit_d33,c->m_edit_d34,c->m_edit_d35,c->m_edit_d36);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_u11,c->m_edit_u22,c->m_edit_u33,c->m_edit_u23,c->m_edit_u13,c->m_edit_u12);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q11,c->m_edit_q12,c->m_edit_q13,c->m_edit_q14,c->m_edit_q15,c->m_edit_q16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q21,c->m_edit_q22,c->m_edit_q23,c->m_edit_q24,c->m_edit_q25,c->m_edit_q26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_q31,c->m_edit_q32,c->m_edit_q33,c->m_edit_q34,c->m_edit_q35,c->m_edit_q36);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",c->m_edit_a11,c->m_edit_a12,c->m_edit_a13);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",c->m_edit_a21,c->m_edit_a22,c->m_edit_a23);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",c->m_edit_a31,c->m_edit_a32,c->m_edit_a33);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGMagnetoelectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal;
			int bndtype = e->m_combo_mechanical_boundary_int;
			// дboundary condition����
			str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
			input.WriteString(str);
			// дapplied strain/stress
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
			input.WriteString(str);
			// дelectric field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
			input.WriteString(str);
			// дmagnetic field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
			input.WriteString(str);
			break;
		}
		break;
	case 6:
		for (int i = 0;i<phases;i++)
		{
			// дD����
			ElectricModelingDLGDiffusivity * u = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i];
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",u->m_edit_diff11,u->m_edit_diff22,u->m_edit_diff33,u->m_edit_diff23,u->m_edit_diff13,u->m_edit_diff12);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGDiffusivityExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal;
			// дelectric field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
			input.WriteString(str);
			break;
		}
		break;
	case 7:
		for (int i = 0;i<phases;i++)
		{
			// дk����
			ElectricModelingDLGThermal * u = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i];
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",u->m_edit_k11,u->m_edit_k22,u->m_edit_k33,u->m_edit_k23,u->m_edit_k13,u->m_edit_k12);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
			break;
		case 1:
			ElectricModelingDLGThermalExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal;
			// дelectric field
			str.Format("%g\t\t%g\t\t%g\t\t\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
			input.WriteString(str);
			break;
		}
		break;
	}
	input.Close();
}

// OK�󽫶Ի�������д���ļ�
void ElectricModelingDLGFather::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// ���տؼ����ݵ���Ա����
	m_pelectricModelingDLGChild1->UpdateData(TRUE);
	// child1�еĺ���û��OK��ť�ڸ����ڵĸ������ύ����
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal->UpdateData(TRUE);

	// д�ļ�
	this->PersistenceParameter();

	// ��ť����Ϊ
	//CDialog::OnOK();
}

// ���Run������ģ��
void ElectricModelingDLGFather::OnBnClickedEclectricButnRun()
{
	// TODO: Add your control notification handler code here
	/*
	CString path;
	char curpath[256];
	GetCurrentDirectory(256,curpath);
	//printf("%s\n",curpath);
	path =(CString)curpath;
	path.Append("\\piez");
	//printf ("���ÿ�ʼ\n");
	STARTUPINFO si = { sizeof(si) }; 
	PROCESS_INFORMATION pi; 

	si.dwFlags = STARTF_USESHOWWINDOW; 
	si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
	TCHAR cmdline[] =TEXT(".\\piez\\pieze.exe");
	BOOL bRet = ::CreateProcess ( 
		NULL,
		cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
		NULL,
		NULL,
		FALSE,
		CREATE_NO_WINDOW,
		NULL,
		path, 
		&si,
		&pi); 

	int error = GetLastError();
	if(bRet) 
	{ 
		::CloseHandle (pi.hThread); 
		::CloseHandle (pi.hProcess); 

		//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
		//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
	} 
	else
	{
		//printf("error code:%d\n",error );
		::MessageBox(NULL,_T("OK"),_T("OK"),MB_OK);
	}
	//printf("���ý���");
	*/
	this->m_RunType=2;
	CDialog::OnOK();
}


void ElectricModelingDLGFather::OnBnClickedElectricButnFile()
{
	
	// TODO: Add your control notification handler code here

	CString FilePathName;
	CString temp;
	CFileDialog dlg(TRUE);///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK){
		FilePathName=dlg.GetPathName();
		::MessageBox(NULL,_T(FilePathName),_T("Input from file"),MB_OK);
		temp.Format("%s %s > out.txt",".\\piez\\pieze.exe",FilePathName);
		//WinExec(temp,SW_HIDE);

		CString path;
		char curpath[256];
		GetCurrentDirectory(256,curpath);
		//printf("%s\n",curpath);
		path =(CString)curpath;
		path.Append("\\piez");
		//printf ("���ÿ�ʼ\n");
		STARTUPINFO si = { sizeof(si) }; 
		PROCESS_INFORMATION pi; 

		si.dwFlags = STARTF_USESHOWWINDOW; 
		si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
		TCHAR cmdline[] =TEXT(".\\piez\\pieze.exe > out.txt");
		BOOL bRet = ::CreateProcess ( 
			NULL,
			cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
			NULL,
			NULL,
			FALSE,
			CREATE_NO_WINDOW,
			NULL,
			path, 
			&si,
			&pi); 

		int error = GetLastError();
		if(bRet) 
		{ 
			::CloseHandle (pi.hThread); 
			::CloseHandle (pi.hProcess); 

			//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
			//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
		} 
		else
		{
			//printf("error code:%d\n",error );
		}
		//printf("���ý���");

		CDialog ::OnOK();
	}

}


void ElectricModelingDLGFather::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	// ȡ��ǰ��������
	m_pelectricModelingDLGChild1->UpdateData(TRUE);
	// child1�еĺ���û��OK��ť�ڸ����ڵĸ������ύ����
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal->UpdateData(TRUE);

	CDialog::OnCancel();
}

void ElectricModelingDLGFather::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// ���տؼ����ݵ���Ա����
	// �û��ر�����Ի���ͬ���������������û������δ����
	m_pelectricModelingDLGChild1->UpdateData(TRUE);
	// child1�еĺ���û��OK��ť�ڸ����ڵĸ������ύ����
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal->UpdateData(TRUE);

	CDialog::OnClose();
}