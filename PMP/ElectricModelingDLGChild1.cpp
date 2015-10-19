// ElectricModelingDLGChild1.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGChild1.h"
#include "ElectricModelingDLGMoreElastic.h"
#include "ElectricModelingDLGMoreDielectric.h"
#include "ElectricModelingDLGMorePiezoelectric.h"
#include "ElectricModelingDLGMoreMagnetic.h"
#include "ElectricModelingDLGMorePiezomagnetic.h"
#include "ElectricModelingDLGMoreMagnetoelectric.h"
#include "ElectricModelingDLGMoreDiffusivity.h"
#include "ElectricModelingDLGMoreThermal.h"
#include "afxdialogex.h"

#include "vtkLookupTable.h"
#include "vtkContourFilter.h"

#include "vtkProperty.h"
#include "vtkPointData.h"

#include "vtkInteractorStyleTrackballCamera.h"

#include "stdio.h"
#include "malloc.h"

#define DATA_TYPE float


// ElectricModelingDLGChild1 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGChild1, CDialog)

ElectricModelingDLGChild1::ElectricModelingDLGChild1(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGChild1::IDD, pParent)
{

	m_edit_nums_phases = 1;
	m_combo_sys_type = _T("");
	m_edit_mesh_nx = 0;
	m_edit_mesh_ny = 0;
	m_edit_mesh_nz = 0;
	m_edit_size_lx = 0;
	m_edit_size_ly = 0;
	m_edit_size_lz = 0;
	ns = 0;
	nf = 0;
	m_combo_file_format = _T("");
	m_combo_simulation_type = _T("");
	m_combo_simulation_type_int = 0;
	m_combo_sys_type_int = 0;
	m_combo_file_format_int = 1;
	// 指针的初始化
	// 初始状态是选择了Elastic的状态
	m_pelectricModelingDLGMoreElastic = new ElectricModelingDLGMoreElastic();
	m_pelectricModelingDLGMoreDielectric =new ElectricModelingDLGMoreDielectric();
	m_pelectricModelingDLGMorePiezoelectric = new ElectricModelingDLGMorePiezoelectric();
	m_pelectricModelingDLGMoreMagnetic = new ElectricModelingDLGMoreMagnetic();
	m_pelectricModelingDLGMorePiezomagnetic =new ElectricModelingDLGMorePiezomagnetic();
	m_pelectricModelingDLGMoreMagnetoelectric = new ElectricModelingDLGMoreMagnetoelectric();
	m_pelectricModelingDLGMoreDiffusivity =new ElectricModelingDLGMoreDiffusivity();
	m_pelectricModelingDLGMoreThermal = new ElectricModelingDLGMoreThermal();

	//m_pelectricModelingDLGExternal = new ElectricModelingDLGExternal();

	m_pelectricModelingDLGElasticExternal= new ElectricModelingDLGElasticExternal();
	m_pelectricModelingDLGDielectricExternal=new ElectricModelingDLGDielectricExternal();
	m_pelectricModelingDLGPiezoelectricExternal=new ElectricModelingDLGPiezoelectricExternal();
	m_pelectricModelingDLGMagneticExternal=new ElectricModelingDLGMagneticExternal();
	m_pelectricModelingDLGPiezomagneticExternal=new ElectricModelingDLGPiezomagneticExternal();
	m_pelectricModelingDLGMagnetoelectricExternal=new ElectricModelingDLGMagnetoelectricExternal();
	m_pelectricModelingDLGDiffusivityExternal=new ElectricModelingDLGDiffusivityExternal();
	m_pelectricModelingDLGThermalExternal=new ElectricModelingDLGThermalExternal();

	// show VTK
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	this->pvtkMFCWindow     = NULL;

	// set data reader to null
	this->pvtkDataSetReader = NULL;

	// Create the the renderer, window and interactor objects.
	this->pvtkRenderer    = vtkRenderer::New();

	// Create the the objects used to form the visualisation.
	this->pvtkDataSetMapper  = vtkDataSetMapper::New();
	this->pvtkActor      = vtkActor::New();
	this->pvtkActor2D    = vtkActor2D::New();
	this->pvtkTextMapper  = vtkTextMapper::New();

	this->ptBorder = CPoint(0,0);
	// vtk数据载体创建

	reader = vtkDataSetReader::New();
	actor = vtkActor::New();
	actor1 = vtkActor::New();
	actor2 = vtkActor::New();
}

ElectricModelingDLGChild1::~ElectricModelingDLGChild1()
{
	// 在持有者的析构函数中销毁动态内存
	if(m_pelectricModelingDLGMoreElastic != NULL){delete m_pelectricModelingDLGMoreElastic;}
	if(m_pelectricModelingDLGMoreDielectric != NULL){delete m_pelectricModelingDLGMoreDielectric;}
	if(m_pelectricModelingDLGMorePiezoelectric != NULL){delete m_pelectricModelingDLGMorePiezoelectric;}
	if(m_pelectricModelingDLGMoreMagnetic != NULL){delete m_pelectricModelingDLGMoreMagnetic;}
	if(m_pelectricModelingDLGMorePiezomagnetic != NULL){delete m_pelectricModelingDLGMorePiezomagnetic;}
	if(m_pelectricModelingDLGMoreMagnetoelectric != NULL){delete m_pelectricModelingDLGMoreMagnetoelectric;}
	if(m_pelectricModelingDLGMoreDiffusivity != NULL){delete m_pelectricModelingDLGMoreDiffusivity;}
	if(m_pelectricModelingDLGMoreThermal != NULL){delete m_pelectricModelingDLGMoreThermal;}

	if(m_pelectricModelingDLGElasticExternal != NULL){delete m_pelectricModelingDLGElasticExternal;}
	if(m_pelectricModelingDLGDielectricExternal != NULL){delete m_pelectricModelingDLGDielectricExternal;}
	if(m_pelectricModelingDLGPiezoelectricExternal != NULL){delete m_pelectricModelingDLGPiezoelectricExternal;}
	if(m_pelectricModelingDLGMagneticExternal != NULL){delete m_pelectricModelingDLGMagneticExternal;}
	if(m_pelectricModelingDLGPiezomagneticExternal != NULL){delete m_pelectricModelingDLGPiezomagneticExternal;}
	if(m_pelectricModelingDLGMagnetoelectricExternal != NULL){delete m_pelectricModelingDLGMagnetoelectricExternal;}
	if(m_pelectricModelingDLGDiffusivityExternal != NULL){delete m_pelectricModelingDLGDiffusivityExternal;}
	if(m_pelectricModelingDLGThermalExternal != NULL){delete m_pelectricModelingDLGThermalExternal;}

	// VTK
	if (this->pvtkDataSetReader)  this->pvtkDataSetReader->Delete();

	// Delete the the renderer, window and interactor objects.
	if (this->pvtkRenderer)      this->pvtkRenderer->Delete();

	// Delete the the objects used to form the visualisation.
	if (this->pvtkDataSetMapper)  this->pvtkDataSetMapper->Delete();
	if (this->pvtkActor)      this->pvtkActor->Delete();
	if (this->pvtkActor2D)      this->pvtkActor2D->Delete();
	if (this->pvtkTextMapper)    this->pvtkTextMapper->Delete();

	if (this->pvtkMFCWindow)
	{
		delete this->pvtkMFCWindow;
	}

	// vtk数据载体销毁
	if (reader!=NULL){reader->Delete();}
	if (actor!=NULL){actor->Delete();}
	if (actor1!=NULL){actor1->Delete();}
	if (actor2!=NULL){actor2->Delete();}
}

void ElectricModelingDLGChild1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SYS_TYPE, m_ComboSysType);
	DDX_Control(pDX, IDC_COMBO_FILE_FORMAT, m_ComboFileFormat);
	DDX_Control(pDX, IDC_COMBO_SIMULATION_TYPE, m_ComboSimulationType);
	DDX_Text(pDX, IDC_EDIT_NUMS_PHASES, m_edit_nums_phases);
	DDV_MinMaxInt(pDX, m_edit_nums_phases, 1, 6);
	DDX_Control(pDX, IDC_SPIN_NUMS_PHASES, m_SpinNumsPhases);
	DDX_CBString(pDX, IDC_COMBO_SYS_TYPE, m_combo_sys_type);
	DDX_Text(pDX, IDC_EDIT_MESH_NX, m_edit_mesh_nx);
	DDX_Text(pDX, IDC_EDIT_MESH_NY, m_edit_mesh_ny);
	DDX_Text(pDX, IDC_EDIT_MESH_NZ, m_edit_mesh_nz);
	DDX_Text(pDX, IDC_EDIT_SIZE_LX, m_edit_size_lx);
	DDX_Text(pDX, IDC_EDIT_SIZE_LY, m_edit_size_ly);
	DDX_Text(pDX, IDC_EDIT_SIZE_LZ, m_edit_size_lz);
	DDX_CBString(pDX, IDC_COMBO_FILE_FORMAT, m_combo_file_format);
	DDX_CBString(pDX, IDC_COMBO_SIMULATION_TYPE, m_combo_simulation_type);
	DDX_CBIndex(pDX, IDC_COMBO_SIMULATION_TYPE, m_combo_simulation_type_int);
	DDX_CBIndex(pDX, IDC_COMBO_SYS_TYPE, m_combo_sys_type_int);
	DDX_CBIndex(pDX, IDC_COMBO_FILE_FORMAT, m_combo_file_format_int);
	// very important删除控件后残留的数据校验语句导致dlgdata40错误
	//DDX_Control(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_ComboMechanicalBoundary);
	//DDX_CBString(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_combo_mechanical_boudary_string);
	//DDX_CBIndex(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_combo_mechnical_boundary_int);
	DDX_Control(pDX, IDC_EDIT_FILE_PATH, m_EditFilePath);
	DDX_Control(pDX, IDC_TAB_CHILD1, m_TabChild1);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGChild1, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_SYS_TYPE, &ElectricModelingDLGChild1::OnCbnSelchangeComboSysType)
ON_BN_CLICKED(IDC_BUTTON_MORE, &ElectricModelingDLGChild1::OnBnClickedButtonMore)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NUMS_PHASES, &ElectricModelingDLGChild1::OnDeltaposSpinNumsPhases)
ON_EN_CHANGE(IDC_EDIT_NUMS_PHASES, &ElectricModelingDLGChild1::OnEnChangeEditNumsPhases)
ON_EN_CHANGE(IDC_EDIT_SIZE_LY, &ElectricModelingDLGChild1::OnEnChangeEditSizeLy)
ON_BN_CLICKED(IDOK, &ElectricModelingDLGChild1::OnBnClickedOk)
ON_CBN_SELCHANGE(IDC_COMBO_SIMULATION_TYPE, &ElectricModelingDLGChild1::OnCbnSelchangeComboSimulationType)
ON_BN_CLICKED(IDC_BUTTON_SELECT_FILE, &ElectricModelingDLGChild1::OnBnClickedButtonSelectFile)
END_MESSAGE_MAP()



static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}

// ElectricModelingDLGChild1 message handlers
BOOL ElectricModelingDLGChild1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 设置下拉内容
	m_ComboSysType.InsertString(0,_T("Elastic"));
	m_ComboSysType.InsertString(1,_T("Dielectric"));
	m_ComboSysType.InsertString(2,_T("Piezoelectric"));
	m_ComboSysType.InsertString(3,_T("Magnetic"));
	m_ComboSysType.InsertString(4,_T("Piezomagnetic"));
	m_ComboSysType.InsertString(5,_T("Magnetoelectric"));
	m_ComboSysType.InsertString(6,_T("Diffusivity"));
	m_ComboSysType.InsertString(7,_T("Thermal conductivity"));
	// 设置下拉默认选项
	// 回填关联的值而不是固定的值
	// m_ComboSysType.SetCurSel(0);
	m_ComboSysType.SetCurSel(m_combo_sys_type_int);

	// 设置旋转控件的伙伴控件（提前设置auto buddy,set buddy integer=true）
	m_SpinNumsPhases.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_NUMS_PHASES));
	m_SpinNumsPhases.SetRange(1,6);

	// 设置下拉内容
	m_ComboFileFormat.InsertString(0,_T("Phase fraction array"));
	m_ComboFileFormat.InsertString(1,_T("Phase id array"));
	// 设置下拉默认选项
	// 回填关联的值，而不是固定的值
	// m_ComboFileFormat.SetCurSel(0);
	m_ComboFileFormat.SetCurSel(m_combo_file_format_int);

	// 设置下拉内容
	m_ComboSimulationType.InsertString(0,_T("Effective properties"));
	m_ComboSimulationType.InsertString(1,_T("Material response to an external field"));
	// 设置默认选项
	// 回填关联的值，而不是固定的值
	m_ComboSimulationType.SetCurSel(m_combo_simulation_type_int);

	// 本页面除了设置自己的初始状态之外，还用根据自身的初始状态设置Phase No.x的状态：
	// Phase num为1，System type的为elastic时的状态
	// 设置一个External Field区域
	//TCITEM  external;
	//external.mask = TCIF_TEXT;
	//external.pszText=_T("");
	//m_TabChild1.InsertItem(0,&external);


	if (m_pelectricModelingDLGElasticExternal == NULL){
		m_pelectricModelingDLGElasticExternal = new ElectricModelingDLGElasticExternal();
	}
	m_pelectricModelingDLGElasticExternal->Create(IDD_MODELING_DLG_ELASTIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGDielectricExternal == NULL){
		m_pelectricModelingDLGDielectricExternal = new ElectricModelingDLGDielectricExternal();
	}
	m_pelectricModelingDLGDielectricExternal->Create(IDD_MODELING_DLG_DIELETRIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGPiezoelectricExternal == NULL){
		m_pelectricModelingDLGPiezoelectricExternal = new ElectricModelingDLGPiezoelectricExternal();
	}
	m_pelectricModelingDLGPiezoelectricExternal->Create(IDD_MODELING_DLG_PEIZOELECTRIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGMagneticExternal == NULL){
		m_pelectricModelingDLGMagneticExternal = new ElectricModelingDLGMagneticExternal();
	}
	m_pelectricModelingDLGMagneticExternal->Create(IDD_MODELING_DLG_MAGNETIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGPiezomagneticExternal == NULL){
		m_pelectricModelingDLGPiezomagneticExternal = new ElectricModelingDLGPiezomagneticExternal();
	}
	m_pelectricModelingDLGPiezomagneticExternal->Create(IDD_MODELING_DLG_PEIZOMAGNETIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGMagnetoelectricExternal == NULL){
		m_pelectricModelingDLGMagnetoelectricExternal = new ElectricModelingDLGMagnetoelectricExternal();
	}
	m_pelectricModelingDLGMagnetoelectricExternal->Create(IDD_MODELING_DLG_MAGNETOELECTRIC_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGDiffusivityExternal == NULL){
		m_pelectricModelingDLGDiffusivityExternal = new ElectricModelingDLGDiffusivityExternal();
	}
	m_pelectricModelingDLGDiffusivityExternal->Create(IDD_MODELING_DLG_DIFFUSIVITY_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	if (m_pelectricModelingDLGThermalExternal == NULL){
		m_pelectricModelingDLGThermalExternal = new ElectricModelingDLGThermalExternal();
	}
	m_pelectricModelingDLGThermalExternal->Create(IDD_MODELING_DLG_THERMAL_EXTERNAL,GetDlgItem(IDC_TAB_CHILD1));

	// 根据system type和simulation type显示相应的external field
	int simSel = m_combo_simulation_type_int;
	switch (m_combo_sys_type_int)
	{
	case 0:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 1:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 2:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 3:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 4:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 5:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 6:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->MoveWindow(&cr);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 7:
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->MoveWindow(&cr);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_SHOW);
			}
			break;
		}
		break;
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

// 相应事件并创建对象或销毁对象，但是未必显示出来，只有点击more之后才显示出来
void ElectricModelingDLGChild1::OnCbnSelchangeComboSysType()
{
	// TODO: Add your control notification handler code here
	// 根据组合框中的选项决定phase No.x中的状态
	// 根据number of phases 决定要更改几个phases
	CString numsphases ;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,numsphases);
	//::MessageBox(NULL,numsphases,_T("OKOK"),MB_OK);
	int phases = atoi(numsphases);
	int curSel = m_ComboSysType.GetCurSel();
	int simSel = m_ComboSimulationType.GetCurSel();
	switch (curSel)
	{
	case 0:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] == NULL)
			{
				m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
			}
		}
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 1:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] = new ElectricModelingDLGDielectric();
			}
		}
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 2:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] = new ElectricModelingDLGPiezoelectric();
			}
		}		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 3:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] = new ElectricModelingDLGMagnetic();
			}
		}
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 4:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] = new ElectricModelingDLGPiezomagnetic();
			}
		}		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->MoveWindow(&cr);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 5:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] = new ElectricModelingDLGMagnetoelectric();
			}
		}		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->MoveWindow(&cr);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 6:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] == NULL)
			{
				m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] = new ElectricModelingDLGDiffusivity();
			}
		}
		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->MoveWindow(&cr);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_SHOW);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			}
			break;
		}
		break;
	case 7:
		for (int i = 0;i<phases;i++)
		{
			if (m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] == NULL)
			{
				m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] = new ElectricModelingDLGThermal();
			}
		}		switch (simSel)
		{
		case 0:
			m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
			m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
			break;
		case 1:
			{
				CRect cr;
				m_TabChild1.GetClientRect(cr);
				m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
				m_pelectricModelingDLGThermalExternal->MoveWindow(&cr);
				m_pelectricModelingDLGThermalExternal->ShowWindow(SW_SHOW);
			}
			break;
		}
		break;
	}
}

void ElectricModelingDLGChild1::OnBnClickedButtonMore()
{
	// TODO: Add your control notification handler code here
	// 点击more按钮意味这根据System Type和Numbers of phases中的值弹出不同样式和内含不同数目选项卡的对话框
	// 获取System type
	CString SystemType;
	// 获取Numbers of phases
	CString NumbersOfPhases;
	// 获取Simulation type
	int simulationtype;
	int sysType;
	int numbersOfPhases;
	sysType = m_ComboSysType.GetCurSel();
	simulationtype = m_ComboSimulationType.GetCurSel();
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,NumbersOfPhases);
	numbersOfPhases = atoi(NumbersOfPhases);
	switch(sysType){
	case 0:
		{
			// 对象被持有方可回填，将对话框对象设置为ElectricModelingDLGChild1的一个属性
			// 也就是作为调用者的属性存在，就可以回填
			//ElectricModelingDLGMoreElastic electricModelingDLGMoreElastic;
			// 设置ElectricModelingDLGMoreElastic对象的PhasesCount属性为1
			// 确保创建一次并持有该对象
			if(m_pelectricModelingDLGMoreElastic == NULL){
				//::MessageBox(NULL,_T("DLGMoreElastic分配内存"),_T("OKOK"),MB_OK);
				m_pelectricModelingDLGMoreElastic = new ElectricModelingDLGMoreElastic();
			}
			/*
			if (m_pelectricModelingDLGMoreElastic == NULL){

				//::MessageBox(NULL,_T("未分配内存"),_T("OKOK"),MB_OK);
			}
			*/
			// 设置标题
			m_pelectricModelingDLGMoreElastic->m_caption = _T("Elastic");
			m_pelectricModelingDLGMoreElastic->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreElastic->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreElastic->DoModal();
			break;
		}
	case 1:
		{

			//ElectricModelingDLGMoreDielectric electricModelingDLGMoreDielectric;
			// 设置ElectricModelingDLGMoreElastic对象的PhasesCount属性为1
			// 创建一次并持有对象
			if (m_pelectricModelingDLGMoreDielectric == NULL)
			{
				m_pelectricModelingDLGMoreDielectric= new ElectricModelingDLGMoreDielectric();
			}
			m_pelectricModelingDLGMoreDielectric->m_caption = _T("Dielectric");
			m_pelectricModelingDLGMoreDielectric->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreDielectric->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreDielectric->DoModal();
			break;
		}
	case 2:
		{

			//ElectricModelingDLGMorePiezoelectric electricModelingDLGMorePiezoelectric;
			// 设置ElectricModelingDLGMoreElastic对象的PhasesCount属性为1
			// 确保创建一次并持有该对象
			if (m_pelectricModelingDLGMorePiezoelectric == NULL)
			{
				m_pelectricModelingDLGMorePiezoelectric = new ElectricModelingDLGMorePiezoelectric();
			}
			m_pelectricModelingDLGMorePiezoelectric->m_caption = _T("Piezoelectric");
			m_pelectricModelingDLGMorePiezoelectric->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMorePiezoelectric->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMorePiezoelectric->DoModal();
			break;
		}
	case 3:
		{

			if (m_pelectricModelingDLGMoreMagnetic == NULL)
			{
				m_pelectricModelingDLGMoreMagnetic = new ElectricModelingDLGMoreMagnetic();
			}
			m_pelectricModelingDLGMoreMagnetic->m_caption = _T("Magnetic");
			m_pelectricModelingDLGMoreMagnetic->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreMagnetic->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreMagnetic->DoModal();
		}
		break;
	case 4:
		{

			if (m_pelectricModelingDLGMorePiezomagnetic == NULL)
			{
				m_pelectricModelingDLGMorePiezomagnetic = new ElectricModelingDLGMorePiezomagnetic();
			}
			m_pelectricModelingDLGMorePiezomagnetic->m_caption = _T("Piezomagnetic");
			m_pelectricModelingDLGMorePiezomagnetic->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMorePiezomagnetic->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMorePiezomagnetic->DoModal();
		}
		break;
	case 5:
		{

			if (m_pelectricModelingDLGMoreMagnetoelectric == NULL)
			{
				m_pelectricModelingDLGMoreMagnetoelectric = new ElectricModelingDLGMoreMagnetoelectric();
			}
			m_pelectricModelingDLGMoreMagnetoelectric->m_caption = _T("Magnetoelectric");
			m_pelectricModelingDLGMoreMagnetoelectric->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreMagnetoelectric->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreMagnetoelectric->DoModal();
		}
		break;
	case 6:
		{

			if (m_pelectricModelingDLGMoreDiffusivity == NULL)
			{
				m_pelectricModelingDLGMoreDiffusivity = new ElectricModelingDLGMoreDiffusivity();
			}
			m_pelectricModelingDLGMoreDiffusivity->m_caption = _T("Diffusivity");
			m_pelectricModelingDLGMoreDiffusivity->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreDiffusivity->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreDiffusivity->DoModal();
		}
		break;
	case 7:
		{

			if (m_pelectricModelingDLGMoreThermal == NULL)
			{
				m_pelectricModelingDLGMoreThermal = new ElectricModelingDLGMoreThermal();
			}
			m_pelectricModelingDLGMoreThermal->m_caption = _T("Thermal conductivity");
			m_pelectricModelingDLGMoreThermal->SetPhaseCount(numbersOfPhases);
			m_pelectricModelingDLGMoreThermal->SetSimulationType(simulationtype);
			m_pelectricModelingDLGMoreThermal->DoModal();
		}
		break;
	}
	
	/*

	// 测试在对话框中弹出对话框
	ElectricModelingDLGMore electricModelingDLGMore;
	if (electricModelingDLGMore.DoModal()==IDOK)
	{
		// 数据交换
	}
	*/

}


void ElectricModelingDLGChild1::OnDeltaposSpinNumsPhases(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	// 当用户输入改变numbers of phase的值时，修改各输入框的输入状态
	// 得到当前输入的数字
	CString PhaseNumString;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,PhaseNumString);
	int PhaseNum = atoi(PhaseNumString);

	// 得到System Type的选择情况
	int curSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SYS_TYPE))->GetCurSel();
	switch(curSel){
	case 0:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] == NULL)
			{
				m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
			}
		}
		break;
	case 1:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] = new ElectricModelingDLGDielectric();
			}
		}
		break;
	case 2:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] = new ElectricModelingDLGPiezoelectric();
			}
		}
		break;
	case 3:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] = new ElectricModelingDLGMagnetic();
			}
		}
		break;
	case 4:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] = new ElectricModelingDLGPiezomagnetic();
			}
		}
		break;
	case 5:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] = new ElectricModelingDLGMagnetoelectric();
			}
		}
		break;
	case 6:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] == NULL)
			{
				m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] = new ElectricModelingDLGDiffusivity();
			}
		}
		break;
	case 7:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] == NULL)
			{
				m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] = new ElectricModelingDLGThermal();
			}
		}
		break;
	}
	*pResult = 0;
}


void ElectricModelingDLGChild1::OnEnChangeEditNumsPhases()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	// 当用户输入改变numbers of phase的值时，修改各输入框的输入状态
	// 得到当前输入的数字
	CString PhaseNumString;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,PhaseNumString);
	int PhaseNum = atoi(PhaseNumString);

	// 得到System Type的选择情况
	int curSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SYS_TYPE))->GetCurSel();
	switch (curSel)
	{
	case 0:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] == NULL)
			{
				m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
			}
		}
		break;
	case 1:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i] = new ElectricModelingDLGDielectric();
			}
		}
		break;
	case 2:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i] = new ElectricModelingDLGPiezoelectric();
			}
		}
		break;
	case 3:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetic->m_pelectricModelingDLGMagnetic[i] = new ElectricModelingDLGMagnetic();
			}
		}
		break;
	case 4:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] == NULL)
			{
				m_pelectricModelingDLGMorePiezomagnetic->m_pelectricModelingDLGPiezomagnetic[i] = new ElectricModelingDLGPiezomagnetic();
			}
		}
		break;
	case 5:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] == NULL)
			{
				m_pelectricModelingDLGMoreMagnetoelectric->m_pelectricModelingDLGMagnetoelectric[i] = new ElectricModelingDLGMagnetoelectric();
			}
		}
		break;
	case 6:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] == NULL)
			{
				m_pelectricModelingDLGMoreDiffusivity->m_pelectricModelingDLGDiffusivity[i] = new ElectricModelingDLGDiffusivity();
			}
		}
		break;
	case 7:
		for (int i = 0;i<PhaseNum;i++)
		{
			if (m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] == NULL)
			{
				m_pelectricModelingDLGMoreThermal->m_pelectricModelingDLGThermal[i] = new ElectricModelingDLGThermal();
			}
		}
		break;
	default:
		// do nothing
		break;
	}

}


void ElectricModelingDLGChild1::OnEnChangeEditSizeLy()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void ElectricModelingDLGChild1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void ElectricModelingDLGChild1::OnCbnSelchangeComboSimulationType()
{
	// TODO: Add your control notification handler code here

	// 得到System Type的选择情况
	int sysTypecurSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SYS_TYPE))->GetCurSel();
	// 得到System Type的选择情况
	int simTypecurSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SIMULATION_TYPE))->GetCurSel();
	switch (simTypecurSel)
	{
	case 0:
		m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
		m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
		break;
	case 1:

		{
			switch (sysTypecurSel)
			{
			case 0:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->MoveWindow(&cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 1:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->MoveWindow(&cr);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 2:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->MoveWindow(&cr);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 3:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->MoveWindow(&cr);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 4:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->MoveWindow(&cr);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 5:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->MoveWindow(&cr);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 6:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->MoveWindow(&cr);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_SHOW);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			case 7:
				{

					CRect cr;
					m_TabChild1.GetClientRect(cr);
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->MoveWindow(&cr);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_SHOW);
				}
				break;
			default:
				{
					m_pelectricModelingDLGElasticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDielectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGPiezomagneticExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGMagnetoelectricExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGDiffusivityExternal->ShowWindow(SW_HIDE);
					m_pelectricModelingDLGThermalExternal->ShowWindow(SW_HIDE);
				}
				break;
			}
			break;
		}
		break;
	}
}


void ElectricModelingDLGChild1::OnBnClickedButtonSelectFile()
{
	// TODO: Add your control notification handler code here

	CString FilePathName;
	CString temp;
	static char BASED_CODE szFilter[] = "data Files (*.in)|*.in|All Files (*.*)|*.*||";
	CFileDialog cFileDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	//CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(cFileDialog.DoModal()==IDOK){
		FilePathName=cFileDialog.GetPathName();
		m_EditFilePath.SetWindowTextA(FilePathName);
		//SetDlgItemText(IDC_EDIT_FILE_PATH,FilePathName);

		CString filename = cFileDialog.GetPathName();
		if (!PathFileExists(filename+".vtk")){
			PMPTransformToVTKForIsosurface(filename);}
		//printf("input the name of vtk file:\n");
		//scanf("%s",filename);
		//# Read the source file.
		// 移除三个actor
		
		reader->SetFileName(filename+".vtk");
		reader->Update();
		//# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//print(id);
		//print(scalar_range);

		vtkLookupTable * colormap=vtkLookupTable::New();
		colormap->SetHueRange(0,0);
		colormap->SetSaturationRange(0,0);
		colormap->SetAlphaRange(0.5,0.5);
		colormap->SetValueRange(0,0);
		vtkContourFilter * contour = vtkContourFilter::New();
		contour->SetInput(id);
		contour->SetValue(0,1);
		contour->ComputeScalarsOn();
		vtkContourFilter * contour1 = vtkContourFilter::New();
		contour1->SetInput(id);
		contour1->ComputeScalarsOn();
		contour1->SetValue(0,2);
		//# Create the mapper that corresponds the objects of the vtk file
		//# into graphics elements
		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());
		mapper->SetScalarRange(0,0);
		mapper->SetLookupTable(colormap);

		vtkDataSetMapper * mapper1 = vtkDataSetMapper::New();
		mapper1->SetInputConnection(contour->GetOutputPort());
		mapper1->SetScalarRange(scalar_range);

		vtkDataSetMapper *mapper2 = vtkDataSetMapper::New();
		mapper2->SetInputConnection(contour1->GetOutputPort());
		mapper2->SetScalarRange(scalar_range);
		//# Create the Actor
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(0,0,0);
		actor->GetProperty()->SetOpacity(0.5);
		//#actor->GetProperty()->SetRepresentationToSurface()

		
		actor1->SetMapper(mapper1);

		actor2->SetMapper(mapper2);

		//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
		//# Create the Renderer
		//vtkRenderer *renderer = vtkRenderer::New();
		// 在添加之前，删除其他Actor
		this->pvtkRenderer->AddActor(actor);
		pvtkRenderer->AddActor(actor1);
		pvtkRenderer->AddActor(actor2);
		pvtkRenderer->SetBackground(1, 1, 1);
		initVTK();
		// update window
		if (this->pvtkMFCWindow)
			this->pvtkMFCWindow->RedrawWindow();
	}
}

void ElectricModelingDLGChild1::ExecutePipeline()
{
	if (pvtkDataSetReader)  // have file
	{
		this->pvtkDataSetMapper->SetInputConnection(pvtkDataSetReader->GetOutputPort());
		this->pvtkActor->SetMapper(this->pvtkDataSetMapper);

		this->pvtkTextMapper->SetInput(pvtkDataSetReader->GetFileName());
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(12);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);

		this->pvtkRenderer->SetBackground(0.0,0.0,0.4);
		this->pvtkRenderer->AddActor(this->pvtkActor);
		this->pvtkRenderer->AddActor(this->pvtkActor2D);
	}
	else  // have no file
	{
		this->pvtkTextMapper->SetInput("Hello World");
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(24);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);

		this->pvtkRenderer->SetBackground(0.0,0.0,0.4);
		this->pvtkRenderer->AddActor(this->pvtkActor2D);
	}
	this->pvtkRenderer->ResetCamera();
}
void ElectricModelingDLGChild1::PMPTransformToVTKForIsosurface(CString filename){
	
	//CString datafilename="struct.in";
	//CString str = "    48    48    36     2";
	//CStdioFile stdfile;
	//CString datalinestr;
	//stdfile.Open(datafilename,CStdioFile::modeRead | CStdioFile::typeText);
	//stdfile.ReadString(datalinestr);
	//int x,y,z,v;
	//
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// 该数据空间超过了VS栈空间，使用C语言关键字malloc创建动态数组
	//int data[MAX_POINTS][4];
	// 先创建指针的指针，再创建指针的指针
	DATA_TYPE **data;
	int x=0,y=0,z=0,v=0;
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"a+"); 
	str.Format("%s.vtk",filename);
	vtk = fopen(str,"w+"); 
	if(NULL == fp) {
		//printf("error open the file");
	} else { 
		fscanf(fp,"%d%d%d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// 不采用这种方式，规则是数据行数据等于维数相乘
		/*
		while((charTemp=fgetc(fp))!=EOF) 
		{ 
			if( charTemp == '\n') Row++; 
		}
		*/
		Row = nx*ny*nz;
		data = (DATA_TYPE * *)malloc(Row*sizeof(DATA_TYPE *));
		for (int i=0;i<Row;i++)
		{
			*(data + i) = (DATA_TYPE *)malloc(4*sizeof(DATA_TYPE));
		}
		//printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%f%f%f%f",*(data+0)+0,*(data+0)+1,*(data+0)+2,*(data+0)+3); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		dex++;
		//printf("%f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%f%f%f%f",*(data+i)+0,*(data+i)+1,*(data+i)+2,*(data+i)+3); 
			dex++;
		}

	}//读取值
	// 可以选择输出数据，但是数据太多，不宜输出
	//for(int i=0;i<100;i++){
		//printf("%d %d %d %d\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2),*(*(data+i)+3));
	//}
	//建立vtk要求的输入文件，采用最普通的structured_points的格式
	
	fprintf(vtk,"%s\n","# vtk DataFile Version 3.0");
	fprintf(vtk,"%s\n","Structured Points");
	fprintf(vtk,"%s\n","ASCII");
	fprintf(vtk,"\n");
	fprintf(vtk,"%s\n","DATASET STRUCTURED_POINTS");
	fprintf(vtk,"DIMENSIONS %d %d %d\n",nx,ny,nz);
	fprintf(vtk,"ORIGIN 1 1 1\n");
	fprintf(vtk,"SPACING 1 1 1\n");
	fprintf(vtk,"\n");
	fprintf(vtk,"POINT_DATA %d\n",Row);
	fprintf(vtk,"SCALARS scalars float\n");
	fprintf(vtk,"LOOKUP_TABLE default\n");
	for (int i=0;i<Row;i++)
	{
		fprintf(vtk,"%0.1f\n",*(*(data+i)+3));
	}
	if(vtk != NULL){	fclose(vtk);}



	// 二维动态数据显然不能这样释放
	//free(data);
	//先撤销元素的指针，再撤销指针的指针
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL){	fclose(fp);}//OK 了 
	//stdfile.Close();
	//printf("结束转化\n");
}

bool ElectricModelingDLGChild1::initVTK(){
	if (this->pvtkMFCWindow == NULL){
		this->pvtkMFCWindow = new vtkMFCWindow(this->GetDlgItem(IDC_PIC_VTK_WINDOW));}
	// get double click events
	vtkCallbackCommand* callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();


	CRect cRectVTK;
	this->pvtkMFCWindow->GetClientRect(&cRectVTK);

	CRect cRectClient;
	GetClientRect(&cRectClient);

	this->ptBorder.x = cRectClient.Width()  - cRectVTK.Width();
	this->ptBorder.y = cRectClient.Height() - cRectVTK.Height();

	// set the vtk renderer, windows, etc
	this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	this->pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	// execute object pipeline
	//ExecutePipeline();
	return true;
}