// ElectricModelingDLGFather.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGFather.h"
#include "afxdialogex.h"

#include "ElectricModelingDLGMoreElastic.h"

// ElectricModelingDLGFather dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGFather, CDialog)

ElectricModelingDLGFather::ElectricModelingDLGFather(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGFather::IDD, pParent)
{

	m_pelectricModelingDLGChild1 = new ElectricModelingDLGChild1();
	m_caption =_T("Dialog");
	//currentSelectedTab = 0;
	m_RunType = 0;
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
	////////////////////////////////Ŀ¼�������򴴽�Ŀ¼
	char workdir[256];
	CString workdirstr;
	GetCurrentDirectory(256,workdir);
	workdirstr = workdir;
	CString paramDir="\\piez";
	workdirstr.Append(paramDir);
	DWORD dwAttr = GetFileAttributes(workdirstr);
	if(dwAttr==-1||(dwAttr&FILE_ATTRIBUTE_DIRECTORY)==0)//Ŀ¼������
	{
		if ( !MakeDir(workdirstr))
		{
			AfxMessageBox("can't create directionary:"+workdirstr);
			PostMessage(WM_QUIT,0,0);
			//return;
		}
	}
	////////////////////////////////Ŀ¼�������򴴽�Ŀ¼
	input.Open(".\\piez\\parameter.in",CFile::modeWrite | CFile::modeCreate | CFile::typeText);
	// д����ά��
	str.Format("%d %d %d !nx ny nz\n",
		m_pelectricModelingDLGChild1->m_edit_mesh_nx,this->m_pelectricModelingDLGChild1->m_edit_mesh_ny,this->m_pelectricModelingDLGChild1->m_edit_mesh_nz);
	input.WriteString(str);
	// дϵͳ��С
	str.Format("%d %d %d !lx ly lz\n",m_pelectricModelingDLGChild1->m_edit_size_lx,m_pelectricModelingDLGChild1->m_edit_size_ly,m_pelectricModelingDLGChild1->m_edit_size_lz);
	input.WriteString(str);
	// дnp0system type���ţ�np0 1-elastic 2-dielectric 3-piezoelectric       !tuy1
	str.Format("%d !np0 1-elastic 2-dielectric 3-piezoelectric...       !tuy1\n",m_pelectricModelingDLGChild1->m_combo_sys_type_int+1);
	input.WriteString(str);
	// дphases����
	str.Format("%d !total # of phases\n",m_pelectricModelingDLGChild1->m_edit_nums_phases);
	input.WriteString(str);
	// дnp1�����ļ���ʽ����:1-order parameter array 2-phase id array
	str.Format("%d !np1: 1-order parameter array 2-phase id array\n",m_pelectricModelingDLGChild1->m_combo_file_format_int+1);
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
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c21,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
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

			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);

		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGElasticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal;
				int bndtype = e->m_combo_mechanical_boundary_int;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
				input.WriteString(str);
				// дapplied electric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дapplied magnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
			}
			break;
		}
		break;
	case 1:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGDielectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_k11,c->m_edit_k22,c->m_edit_k33,c->m_edit_k23,c->m_edit_k13,c->m_edit_k12);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGDielectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal;
				int bndtype = 0;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дapplied electric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
				input.WriteString(str);
				// дapplied magnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
			}
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
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{

				ElectricModelingDLGPiezoelectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal;
				int bndtype = e->m_combo_mechanical_boundary_int;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
				input.WriteString(str);
				// дapplied magnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
			}
			break;
		}
		break;
	case 3:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGMagnetic * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_u11,c->m_edit_u22,c->m_edit_u33,c->m_edit_u23,c->m_edit_u13,c->m_edit_u12);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGMagneticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal;
				int bndtype = 0;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дmagnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
				input.WriteString(str);
			}

			break;
		}
		break;
	case 4:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGPiezomagnetic * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i];
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
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
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
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGPiezomagneticExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal;
				int bndtype = e->m_combo_mechanical_boundary_int;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дmagnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
				input.WriteString(str);
			}

			break;
		}
		break;
	case 5:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGMagnetoelectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i];
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
		case 1:
			{
				ElectricModelingDLGMagnetoelectricExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal;
				int bndtype = e->m_combo_mechanical_boundary_int;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",e->m_edit_eq11,e->m_edit_eq22,e->m_edit_eq33,e->m_edit_eq23,e->m_edit_eq13,e->m_edit_eq12);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
				input.WriteString(str);
				// дmagnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",e->m_edit_mag_h1,e->m_edit_mag_h2,e->m_edit_mag_h3);
				input.WriteString(str);
			}

			break;
		}
		break;
	case 6:
		for (int i = 0;i<phases;i++)
		{
			// дD����
			ElectricModelingDLGDiffusivity * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_diff11,c->m_edit_diff22,c->m_edit_diff33,c->m_edit_diff23,c->m_edit_diff13,c->m_edit_diff12);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGDiffusivityExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal;
				int bndtype = 0;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
				input.WriteString(str);
				// дmagnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
			}

			break;
		}
		break;
	case 7:
		for (int i = 0;i<phases;i++)
		{
			// дk����
			ElectricModelingDLGThermal * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i];
			// дpphases���
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// д��c����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// д��k����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_k11,c->m_edit_k22,c->m_edit_k33,c->m_edit_k23,c->m_edit_k13,c->m_edit_k12);
			input.WriteString(str);
			// д��d����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дu����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дq����
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
			input.WriteString(str);
			// дa����
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t\n",0.0f,0.0f,0.0f);
			input.WriteString(str);
		}
		// дsimulation type����
		str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",simtype+1);
		input.WriteString(str);
		switch (simtype)
		{
		case 0:
		case 1:
			{
				ElectricModelingDLGThermalExternal * e= m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal;
				int bndtype = 0;
				// дboundary condition����
				str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",bndtype);
				input.WriteString(str);
				// дapplied strain/stress
				str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t         !applied strain/stress\n",0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
				input.WriteString(str);
				// дelectric field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied electric field\n",e->m_edit_ele_e1,e->m_edit_ele_e2,e->m_edit_ele_e3);
				input.WriteString(str);
				// дmagnetic field
				str.Format("%g\t\t%g\t\t%g\t\t                                          !applied magnetic field\n",0.0f,0.0f,0.0f);
				input.WriteString(str);
			}

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
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal->UpdateData(TRUE);

	// д�ļ�
	this->PersistenceParameter();

	// ��ť����Ϊ
	//CDialog::OnOK();
}

// ���Run������ģ��
void ElectricModelingDLGFather::OnBnClickedEclectricButnRun()
{
	// TODO: Add your control notification handler code here
	// �Ƿ���������֮ǰ���浱ǰ������parameter.in�ļ�
	// ���տؼ����ݵ���Ա����
	m_pelectricModelingDLGChild1->UpdateData(TRUE);
	// child1�еĺ���û��OK��ť�ڸ����ڵĸ������ύ����
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal->UpdateData(TRUE);
	this->PersistenceParameter();
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
		CREATE_NEW_CONSOLE,
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
		//::MessageBox(NULL,_T("OK"),_T("OK"),MB_OK);
	}
	//printf("���ý���");
	*/
	this->m_RunType = 2;
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
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal->UpdateData(TRUE);

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
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal->UpdateData(TRUE);
	m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal->UpdateData(TRUE);

	CDialog::OnClose();
}

// 

// �������ݣ�����������������ҲҪ����ȫ�ֱ���
void ElectricModelingDLGFather::LoadParameter(CString filename){
	FILE * fp;
	char des[256];
	ElectricModelingDLGChild1 *ch = this->m_pelectricModelingDLGChild1;
	fp = fopen(filename,"r");
	// ���������С
	int nx=0,ny=0,nz=0;
	fscanf(fp,"%d %d %d",&nx,&ny,&nz);
	// ����ע��
	fgets(des,256,fp);
	ch->m_edit_mesh_nx = nx;
	ch->m_edit_mesh_ny = ny;
	ch->m_edit_mesh_nz = nz;
	// ����ϵͳ��С
	int lx=0,ly=0,lz=0;
	fscanf(fp,"%d %d %d",&lx,&ly,&lz);
	fgets(des,256,fp);
	ch->m_edit_size_lx = lx;
	ch->m_edit_size_ly = ly;
	ch->m_edit_size_lz = lz;
	// ����np0;
	int np0=0;
	fscanf(fp,"%d",&np0);
	fgets(des,256,fp);
	ch->m_combo_sys_type_int = np0-1;
	// ����total phase
	int phases=1;
	fscanf(fp,"%d",&phases);
	fgets(des,256,fp);
	ch->m_edit_nums_phases = phases;
	// ����np1
	int np1=0;
	fscanf(fp,"%d",&np1);
	fgets(des,256,fp);
	ch->m_combo_file_format_int = np1-1;
	// ���е����ݶ�Ҫ��ȡ��ֻ��ѡ���������ѡ����Ҫ������
	// system type �� total phases������ζ���������
	// ����phase id 1
	int phaseid = 1;
	float c[6][6]={0.0f};
	float k[3][3]={0.0f};
	float d[3][6]={0.0f};
	float u[3][3]={0.0f};
	float q[3][6]={0.0f};
	float a[3][3]={0.0f};
	// ��ȡȫ�ֱ�����ָ��
	float ***gc = (float ***)ElectricModelingDLGMoreElastic::c;
	float ***gk = (float ***)ElectricModelingDLGMoreElastic::k;
	float ***gd = (float ***)ElectricModelingDLGMoreElastic::d;
	float ***gu = (float ***)ElectricModelingDLGMoreElastic::u;
	float ***gq = (float ***)ElectricModelingDLGMoreElastic::q;
	float ***ga = (float ***)ElectricModelingDLGMoreElastic::a;
	float ***gdiff = (float ***)ElectricModelingDLGMoreElastic::diff;
	float ***gther = (float ***)ElectricModelingDLGMoreElastic::ther;
	switch (np0-1)
	{
	case 0:
		{
			ElectricModelingDLGElastic ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic;
			// ��ȡ����
			for (int i=0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				e[i]->m_edit_c11 = c[0][0];e[i]->m_edit_c12 = c[0][1];e[i]->m_edit_c13 = c[0][2];e[i]->m_edit_c14 = c[0][3];e[i]->m_edit_c15 = c[0][4];e[i]->m_edit_c16 = c[0][5];
				e[i]->m_edit_c21 = c[1][0];e[i]->m_edit_c22 = c[1][1];e[i]->m_edit_c23 = c[1][2];e[i]->m_edit_c24 = c[1][3];e[i]->m_edit_c25 = c[1][4];e[i]->m_edit_c26 = c[1][5];
				e[i]->m_edit_c31 = c[2][0];e[i]->m_edit_c32 = c[2][1];e[i]->m_edit_c33 = c[2][2];e[i]->m_edit_c34 = c[2][3];e[i]->m_edit_c35 = c[2][4];e[i]->m_edit_c36 = c[2][5];
				e[i]->m_edit_c41 = c[3][0];e[i]->m_edit_c42 = c[3][1];e[i]->m_edit_c43 = c[3][2];e[i]->m_edit_c44 = c[3][3];e[i]->m_edit_c45 = c[3][4];e[i]->m_edit_c46 = c[3][5];
				e[i]->m_edit_c51 = c[4][0];e[i]->m_edit_c52 = c[4][1];e[i]->m_edit_c53 = c[4][2];e[i]->m_edit_c54 = c[4][3];e[i]->m_edit_c55 = c[4][4];e[i]->m_edit_c56 = c[4][5];
				e[i]->m_edit_c61 = c[5][0];e[i]->m_edit_c62 = c[5][1];e[i]->m_edit_c63 = c[5][2];e[i]->m_edit_c64 = c[5][3];e[i]->m_edit_c65 = c[5][4];e[i]->m_edit_c66 = c[5][5];
				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���c
				for (int m=0;m<6;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gc + i*6*6+m*6+n) = *e[i]->c[m][n];
					}
				}
			}
		}
		break;
	case 1:
		{
			ElectricModelingDLGDielectric ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡk����
				e[i]->m_edit_k11 = k[0][0];
				e[i]->m_edit_k22 = k[1][1];
				e[i]->m_edit_k33 = k[2][2];
				e[i]->m_edit_k23 = k[1][2];
				e[i]->m_edit_k13 = k[0][2];
				e[i]->m_edit_k12 = k[0][1];

				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���k
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gk + i*3*3+m*3+n) = *e[i]->k[m][n];
					}
				}
			}
		}
		break;
	case 2:
		{
			ElectricModelingDLGPiezoelectric ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡc����
				e[i]->m_edit_c11 = c[0][0];e[i]->m_edit_c12 = c[0][1];e[i]->m_edit_c13 = c[0][2];e[i]->m_edit_c14 = c[0][3];e[i]->m_edit_c15 = c[0][4];e[i]->m_edit_c16 = c[0][5];
				e[i]->m_edit_c21 = c[1][0];e[i]->m_edit_c22 = c[1][1];e[i]->m_edit_c23 = c[1][2];e[i]->m_edit_c24 = c[1][3];e[i]->m_edit_c25 = c[1][4];e[i]->m_edit_c26 = c[1][5];
				e[i]->m_edit_c31 = c[2][0];e[i]->m_edit_c32 = c[2][1];e[i]->m_edit_c33 = c[2][2];e[i]->m_edit_c34 = c[2][3];e[i]->m_edit_c35 = c[2][4];e[i]->m_edit_c36 = c[2][5];
				e[i]->m_edit_c41 = c[3][0];e[i]->m_edit_c42 = c[3][1];e[i]->m_edit_c43 = c[3][2];e[i]->m_edit_c44 = c[3][3];e[i]->m_edit_c45 = c[3][4];e[i]->m_edit_c46 = c[3][5];
				e[i]->m_edit_c51 = c[4][0];e[i]->m_edit_c52 = c[4][1];e[i]->m_edit_c53 = c[4][2];e[i]->m_edit_c54 = c[4][3];e[i]->m_edit_c55 = c[4][4];e[i]->m_edit_c56 = c[4][5];
				e[i]->m_edit_c61 = c[5][0];e[i]->m_edit_c62 = c[5][1];e[i]->m_edit_c63 = c[5][2];e[i]->m_edit_c64 = c[5][3];e[i]->m_edit_c65 = c[5][4];e[i]->m_edit_c66 = c[5][5];
				// ��ȡk����
				e[i]->m_edit_k11 = k[0][0];
				e[i]->m_edit_k22 = k[1][1];
				e[i]->m_edit_k33 = k[2][2];
				e[i]->m_edit_k23 = k[1][2];
				e[i]->m_edit_k13 = k[0][2];
				e[i]->m_edit_k12 = k[0][1];
				// ��ȡd����
				e[i]->m_edit_d11 = d[0][0];e[i]->m_edit_d12 = d[0][1];e[i]->m_edit_d13 = d[0][2];e[i]->m_edit_d14 = d[0][3];e[i]->m_edit_d15 = d[0][4];e[i]->m_edit_d16 = d[0][5];
				e[i]->m_edit_d21 = d[1][0];e[i]->m_edit_d22 = d[1][1];e[i]->m_edit_d23 = d[1][2];e[i]->m_edit_d24 = d[1][3];e[i]->m_edit_d25 = d[1][4];e[i]->m_edit_d26 = d[1][5];
				e[i]->m_edit_d31 = d[2][0];e[i]->m_edit_d32 = d[2][1];e[i]->m_edit_d33 = d[2][2];e[i]->m_edit_d34 = d[2][3];e[i]->m_edit_d35 = d[2][4];e[i]->m_edit_d36 = d[2][5];


				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���c
				for (int m=0;m<6;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gc + i*6*6+m*6+n) = *e[i]->c[m][n];
					}
				}
				// ����ȫ�ֱ���k
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gk + i*3*3+m*3+n) = *e[i]->k[m][n];
					}
				}
				// ����ȫ�ֱ���d
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gd + i*3*6+m*6+n) = *e[i]->d[m][n];
					}
				}

			}
		}
		break;
	case 3:
		{
			ElectricModelingDLGMagnetic ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡu����
				e[i]->m_edit_u11 = u[0][0];
				e[i]->m_edit_u22 = u[1][1];
				e[i]->m_edit_u33 = u[2][2];
				e[i]->m_edit_u23 = u[1][2];
				e[i]->m_edit_u13 = u[0][2];
				e[i]->m_edit_u12 = u[0][1];


				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���u
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gu + i*3*3+m*3+n) = *e[i]->u[m][n];
					}
				}

			}
		}
		break;
	case 4:
		{
			ElectricModelingDLGPiezomagnetic ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡc����
				e[i]->m_edit_c11 = c[0][0];e[i]->m_edit_c12 = c[0][1];e[i]->m_edit_c13 = c[0][2];e[i]->m_edit_c14 = c[0][3];e[i]->m_edit_c15 = c[0][4];e[i]->m_edit_c16 = c[0][5];
				e[i]->m_edit_c21 = c[1][0];e[i]->m_edit_c22 = c[1][1];e[i]->m_edit_c23 = c[1][2];e[i]->m_edit_c24 = c[1][3];e[i]->m_edit_c25 = c[1][4];e[i]->m_edit_c26 = c[1][5];
				e[i]->m_edit_c31 = c[2][0];e[i]->m_edit_c32 = c[2][1];e[i]->m_edit_c33 = c[2][2];e[i]->m_edit_c34 = c[2][3];e[i]->m_edit_c35 = c[2][4];e[i]->m_edit_c36 = c[2][5];
				e[i]->m_edit_c41 = c[3][0];e[i]->m_edit_c42 = c[3][1];e[i]->m_edit_c43 = c[3][2];e[i]->m_edit_c44 = c[3][3];e[i]->m_edit_c45 = c[3][4];e[i]->m_edit_c46 = c[3][5];
				e[i]->m_edit_c51 = c[4][0];e[i]->m_edit_c52 = c[4][1];e[i]->m_edit_c53 = c[4][2];e[i]->m_edit_c54 = c[4][3];e[i]->m_edit_c55 = c[4][4];e[i]->m_edit_c56 = c[4][5];
				e[i]->m_edit_c61 = c[5][0];e[i]->m_edit_c62 = c[5][1];e[i]->m_edit_c63 = c[5][2];e[i]->m_edit_c64 = c[5][3];e[i]->m_edit_c65 = c[5][4];e[i]->m_edit_c66 = c[5][5];
				// ��ȡu����
				e[i]->m_edit_u11 = u[0][0];
				e[i]->m_edit_u22 = u[1][1];
				e[i]->m_edit_u33 = u[2][2];
				e[i]->m_edit_u23 = u[1][2];
				e[i]->m_edit_u13 = u[0][2];
				e[i]->m_edit_u12 = u[0][1];
				// ��ȡq����
				e[i]->m_edit_q11 = q[0][0];e[i]->m_edit_q12 = q[0][1];e[i]->m_edit_q13 = q[0][2];e[i]->m_edit_q14 = q[0][3];e[i]->m_edit_q15 = q[0][4];e[i]->m_edit_q16 = q[0][5];
				e[i]->m_edit_q21 = q[1][0];e[i]->m_edit_q22 = q[1][1];e[i]->m_edit_q23 = q[1][2];e[i]->m_edit_q24 = q[1][3];e[i]->m_edit_q25 = q[1][4];e[i]->m_edit_q26 = q[1][5];
				e[i]->m_edit_q31 = q[2][0];e[i]->m_edit_q32 = q[2][1];e[i]->m_edit_q33 = q[2][2];e[i]->m_edit_q34 = q[2][3];e[i]->m_edit_q35 = q[2][4];e[i]->m_edit_q36 = q[2][5];


				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���c
				for (int m=0;m<6;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gc + i*6*6+m*6+n) = *e[i]->c[m][n];
					}
				}
				// ����ȫ�ֱ���u
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gu + i*3*3+m*3+n) = *e[i]->u[m][n];
					}
				}
				// ����ȫ�ֱ���q
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gq + i*3*6+m*6+n) = *e[i]->q[m][n];
					}
				}

			}
		}
		break;
	case 5:
		{
			ElectricModelingDLGMagnetoelectric ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡc����
				e[i]->m_edit_c11 = c[0][0];e[i]->m_edit_c12 = c[0][1];e[i]->m_edit_c13 = c[0][2];e[i]->m_edit_c14 = c[0][3];e[i]->m_edit_c15 = c[0][4];e[i]->m_edit_c16 = c[0][5];
				e[i]->m_edit_c21 = c[1][0];e[i]->m_edit_c22 = c[1][1];e[i]->m_edit_c23 = c[1][2];e[i]->m_edit_c24 = c[1][3];e[i]->m_edit_c25 = c[1][4];e[i]->m_edit_c26 = c[1][5];
				e[i]->m_edit_c31 = c[2][0];e[i]->m_edit_c32 = c[2][1];e[i]->m_edit_c33 = c[2][2];e[i]->m_edit_c34 = c[2][3];e[i]->m_edit_c35 = c[2][4];e[i]->m_edit_c36 = c[2][5];
				e[i]->m_edit_c41 = c[3][0];e[i]->m_edit_c42 = c[3][1];e[i]->m_edit_c43 = c[3][2];e[i]->m_edit_c44 = c[3][3];e[i]->m_edit_c45 = c[3][4];e[i]->m_edit_c46 = c[3][5];
				e[i]->m_edit_c51 = c[4][0];e[i]->m_edit_c52 = c[4][1];e[i]->m_edit_c53 = c[4][2];e[i]->m_edit_c54 = c[4][3];e[i]->m_edit_c55 = c[4][4];e[i]->m_edit_c56 = c[4][5];
				e[i]->m_edit_c61 = c[5][0];e[i]->m_edit_c62 = c[5][1];e[i]->m_edit_c63 = c[5][2];e[i]->m_edit_c64 = c[5][3];e[i]->m_edit_c65 = c[5][4];e[i]->m_edit_c66 = c[5][5];
				// ��ȡk����
				e[i]->m_edit_k11 = k[0][0];
				e[i]->m_edit_k22 = k[1][1];
				e[i]->m_edit_k33 = k[2][2];
				e[i]->m_edit_k23 = k[1][2];
				e[i]->m_edit_k13 = k[0][2];
				e[i]->m_edit_k12 = k[0][1];
				// ��ȡd����
				e[i]->m_edit_d11 = d[0][0];e[i]->m_edit_d12 = d[0][1];e[i]->m_edit_d13 = d[0][2];e[i]->m_edit_d14 = d[0][3];e[i]->m_edit_d15 = d[0][4];e[i]->m_edit_d16 = d[0][5];
				e[i]->m_edit_d21 = d[1][0];e[i]->m_edit_d22 = d[1][1];e[i]->m_edit_d23 = d[1][2];e[i]->m_edit_d24 = d[1][3];e[i]->m_edit_d25 = d[1][4];e[i]->m_edit_d26 = d[1][5];
				e[i]->m_edit_d31 = d[2][0];e[i]->m_edit_d32 = d[2][1];e[i]->m_edit_d33 = d[2][2];e[i]->m_edit_d34 = d[2][3];e[i]->m_edit_d35 = d[2][4];e[i]->m_edit_d36 = d[2][5];
				// ��ȡu����
				e[i]->m_edit_u11 = u[0][0];
				e[i]->m_edit_u22 = u[1][1];
				e[i]->m_edit_u33 = u[2][2];
				e[i]->m_edit_u23 = u[1][2];
				e[i]->m_edit_u13 = u[0][2];
				e[i]->m_edit_u12 = u[0][1];
				// ��ȡq����
				e[i]->m_edit_q11 = q[0][0];e[i]->m_edit_q12 = q[0][1];e[i]->m_edit_q13 = q[0][2];e[i]->m_edit_q14 = q[0][3];e[i]->m_edit_q15 = q[0][4];e[i]->m_edit_q16 = q[0][5];
				e[i]->m_edit_q21 = q[1][0];e[i]->m_edit_q22 = q[1][1];e[i]->m_edit_q23 = q[1][2];e[i]->m_edit_q24 = q[1][3];e[i]->m_edit_q25 = q[1][4];e[i]->m_edit_q26 = q[1][5];
				e[i]->m_edit_q31 = q[2][0];e[i]->m_edit_q32 = q[2][1];e[i]->m_edit_q33 = q[2][2];e[i]->m_edit_q34 = q[2][3];e[i]->m_edit_q35 = q[2][4];e[i]->m_edit_q36 = q[2][5];
				// ��ȡa����
				e[i]->m_edit_a11 = a[0][0];e[i]->m_edit_a12 = a[0][1];e[i]->m_edit_a13 = a[0][2];
				e[i]->m_edit_a21 = a[1][0];e[i]->m_edit_a22 = a[1][1];e[i]->m_edit_a23 = a[1][2];
				e[i]->m_edit_a31 = a[2][0];e[i]->m_edit_a32 = a[2][1];e[i]->m_edit_a33 = a[2][2];

				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���c
				for (int m=0;m<6;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gc + i*6*6+m*6+n) = *e[i]->c[m][n];
					}
				}
				// ����ȫ�ֱ���k
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gk + i*3*3+m*3+n) = *e[i]->k[m][n];
					}
				}
				// ����ȫ�ֱ���d
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gd + i*3*6+m*6+n) = *e[i]->d[m][n];
					}
				}
				// ����ȫ�ֱ���u
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gu + i*3*3+m*3+n) = *e[i]->u[m][n];
					}
				}
				// ����ȫ�ֱ���q
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<6;n++)
					{
						*((float *)gq + i*3*6+m*6+n) = *e[i]->q[m][n];
					}
				}
				// ����ȫ�ֱ���a
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;)
					{
						*((float *)ga + i*3*3+m*3+n) = *e[i]->a[m][n];
					}
				}
			}
		}
		break;
	case 6:
		{
			ElectricModelingDLGDiffusivity * * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ���ݵ��Ի������
				e[i]->m_edit_diff11 = k[0][0];
				e[i]->m_edit_diff22 = k[1][1];
				e[i]->m_edit_diff33 = k[2][2];
				e[i]->m_edit_diff23 = k[1][2];
				e[i]->m_edit_diff13 = k[0][2];
				e[i]->m_edit_diff12 = k[0][1];
				// �Գ����

				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���diff
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gdiff + i*3*3+m*3+n) = *e[i]->k[m][n];
					}
				}
			}
		}
		break;
	case 7:
		{
			ElectricModelingDLGThermal ** e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal;
			// ��ȡ����
			for (int i = 0;i<phases;i++)
			{
				// ����phase id
				fscanf(fp,"%d",&phaseid);
				fgets(des,256,fp);
				// ����6*6c����
				fscanf(fp,"%g %g %g %g %g %g",&c[0][0],&c[0][1],&c[0][2],&c[0][3],&c[0][4],&c[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&c[1][0],&c[1][1],&c[1][2],&c[1][3],&c[1][4],&c[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[2][0],&c[2][1],&c[2][2],&c[2][3],&c[2][4],&c[2][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[3][0],&c[3][1],&c[3][2],&c[3][3],&c[3][4],&c[3][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[4][0],&c[4][1],&c[4][2],&c[4][3],&c[4][4],&c[4][5]);
				fscanf(fp,"%g %g %g %g %g %g",&c[5][0],&c[5][1],&c[5][2],&c[5][3],&c[5][4],&c[5][5]);
				// ����3*3k����
				fscanf(fp,"%g %g %g %g %g %g",&k[0][0],&k[1][1],&k[2][2],&k[1][2],&k[0][2],&k[0][1]);
				fgets(des,256,fp);
				// ����3*6d����
				fscanf(fp,"%g %g %g %g %g %g",&d[0][0],&d[0][1],&d[0][2],&d[0][3],&d[0][4],&d[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&d[1][0],&d[1][1],&d[1][2],&d[1][3],&d[1][4],&d[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&d[2][0],&d[2][1],&d[2][2],&d[2][3],&d[2][4],&d[2][5]);
				// ����3*3u����
				fscanf(fp,"%g %g %g %g %g %g",&u[0][0],&u[1][1],&u[2][2],&u[1][2],&u[0][2],&u[0][1]);
				fgets(des,256,fp);
				// ����3*6q����
				fscanf(fp,"%g %g %g %g %g %g",&q[0][0],&q[0][1],&q[0][2],&q[0][3],&q[0][4],&q[0][5]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g %g %g %g",&q[1][0],&q[1][1],&q[1][2],&q[1][3],&q[1][4],&q[1][5]);
				fscanf(fp,"%g %g %g %g %g %g",&q[2][0],&q[2][1],&q[2][2],&q[2][3],&q[2][4],&q[2][5]);
				// ����3*3a����
				fscanf(fp,"%g %g %g",&a[0][0],&a[0][1],&a[0][2]);
				fgets(des,256,fp);
				fscanf(fp,"%g %g %g",&a[1][0],&a[1][1],&a[1][2]);
				fscanf(fp,"%g %g %g",&a[2][0],&a[2][1],&a[2][2]);

				// ��ȡ����
				// ��ȡk����
				e[i]->m_edit_k11 = k[0][0];
				e[i]->m_edit_k22 = k[1][1];
				e[i]->m_edit_k33 = k[2][2];
				e[i]->m_edit_k23 = k[1][2];
				e[i]->m_edit_k13 = k[0][2];
				e[i]->m_edit_k12 = k[0][1];

				// ���������ȫ�ֱ���
				// ����ȫ�ֱ���ther
				for (int m=0;m<3;m++)
				{
					for (int n=0;n<3;n++)
					{
						*((float *)gther + i*3*3+m*3+n) = *e[i]->k[m][n];
					}
				}
			}
		}
		break;
	}
	// ��ȡnp2��np2��ʾsimulation type
	int np2=0;
	fscanf(fp,"%d",&np2);
	fgets(des,256,fp);
	ch->m_combo_simulation_type_int = np2 -1;
	// ���е����ݶ�Ҫ��ȡ��ֻ��ѡ���������ѡ����Ҫ������
	// ����system type ��simulation type�������ݵĴ�ȡ
	int boundarycondition = 0;
	float ae[6]={0.0f};
	float ele[3]={0.0f};
	float h[3]={0.0f};
	switch (np2-1)
	{
	case 0:	
	case 1:
		{
			// �Ȱ����ݶ�ȡ��Ȼ��ֵ
			fscanf(fp,"%d",&boundarycondition);fgets(des,256,fp);
			fscanf(fp,"%g %g %g %g %g %g",&ae[0],&ae[1],&ae[2],&ae[3],&ae[4],&ae[5]);fgets(des,256,fp);
			fscanf(fp,"%g %g %g",&ele[0],&ele[1],&ele[2]);fgets(des,256,fp);
			fscanf(fp,"%g %g %g",&h[0],&h[1],&h[2]);fgets(des,256,fp);
			// �ж�����һ��system type
			switch (np0-1)
			{
			case 0:
				{
					ElectricModelingDLGElasticExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGElasticExternal;
					e->m_edit_eq11 = ae[0];e->m_edit_eq22 = ae[1];e->m_edit_eq33 = ae[2];e->m_edit_eq23 = ae[3];e->m_edit_eq13 = ae[4];e->m_edit_eq12 = ae[5];
				}
				break;
			case 1:
				{
					ElectricModelingDLGDielectricExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGDielectricExternal;
					e->m_edit_ele_e1 = ele[0];e->m_edit_ele_e2 = ele[1];e->m_edit_ele_e3 = ele[2];
				}
				break;
			case 2:
				{
					ElectricModelingDLGPiezoelectricExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezoelectricExternal;
					e->m_edit_eq11 = ae[0];e->m_edit_eq22 = ae[1];e->m_edit_eq33 = ae[2];e->m_edit_eq23 = ae[3];e->m_edit_eq13 = ae[4];e->m_edit_eq12 = ae[5];
					e->m_edit_ele_e1 = ele[0];e->m_edit_ele_e2 = ele[1];e->m_edit_ele_e3 = ele[2];
				}
				break;
			case 3:
				{
					ElectricModelingDLGMagneticExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagneticExternal;
					e->m_edit_mag_h1 = h[0];e->m_edit_mag_h2 = h[1];e->m_edit_mag_h3 = h[2];
				}
				break;
			case 4:
				{
					ElectricModelingDLGPiezomagneticExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGPiezomagneticExternal;
					e->m_edit_eq11 = ae[0];e->m_edit_eq22 = ae[1];e->m_edit_eq33 = ae[2];e->m_edit_eq23 = ae[3];e->m_edit_eq13 = ae[4];e->m_edit_eq12 = ae[5];
					e->m_edit_mag_h1 = h[0];e->m_edit_mag_h2 = h[1];e->m_edit_mag_h3 = h[2];
				}
				break;
			case 5:
				{
					ElectricModelingDLGMagnetoelectricExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMagnetoelectricExternal;
					e->m_edit_eq11 = ae[0];e->m_edit_eq22 = ae[1];e->m_edit_eq33 = ae[2];e->m_edit_eq23 = ae[3];e->m_edit_eq13 = ae[4];e->m_edit_eq12 = ae[5];
					e->m_edit_ele_e1 = ele[0];e->m_edit_ele_e2 = ele[1];e->m_edit_ele_e3 = ele[2];
					e->m_edit_mag_h1 = h[0];e->m_edit_mag_h2 = h[1];e->m_edit_mag_h3 = h[2];
				}
				break;
			case 6:
				{
					ElectricModelingDLGDiffusivityExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGDiffusivityExternal;
					e->m_edit_ele_e1 = ele[0];e->m_edit_ele_e2 = ele[1];e->m_edit_ele_e3 = ele[2];
				}
				break;
			case 7:
				{
					ElectricModelingDLGThermalExternal * e = m_pelectricModelingDLGChild1->m_pelectricModelingDLGThermalExternal;
					e->m_edit_ele_e1 = ele[0];e->m_edit_ele_e2 = ele[1];e->m_edit_ele_e3 = ele[2];
				}
				break;
			}
		}
		break;
	}
	// ��ȡelastic boundary condition


	// �ر��ļ���
	if (fp != NULL){fclose(fp);}
}

//����Ŀ¼��֧�ֶ��ش�����
BOOL ElectricModelingDLGFather::MakeDir(CString szDirName)
{
	HANDLE fFile;
	WIN32_FIND_DATA fileinfo;
	CStringArray m_arr;
	BOOL tt;
	int x1 = 0;
	CString tem = "";

	fFile = FindFirstFile(szDirName, &fileinfo);

	if (fileinfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
	{
		FindClose(fFile);
		return FALSE;
	}
	m_arr.RemoveAll();

	for(x1 = 0; x1 < szDirName.GetLength(); x1 ++)
	{
		if (szDirName.GetAt(x1) != '\\')
			tem += szDirName.GetAt(x1);
		else
		{
			m_arr.Add(tem);
			tem += "\\";
		}

		if (x1 == szDirName.GetLength() - 1)
			m_arr.Add(tem);
	}
	FindClose(fFile);

	for (x1 = 1; x1 < m_arr.GetSize(); x1++)
	{
		tem = m_arr.GetAt(x1);
		tt = CreateDirectory(tem, NULL);
		if (tt)
			SetFileAttributes(tem, FILE_ATTRIBUTE_NORMAL);
	}

	fFile = FindFirstFile(szDirName, &fileinfo);
	m_arr.RemoveAll();
	if (fileinfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
	{
		FindClose(fFile);
		return TRUE;
	}
	else
	{
		FindClose(fFile);
		return FALSE;
	}
}