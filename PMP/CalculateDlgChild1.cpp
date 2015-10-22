// CalculateDlgChild1.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "CalculateDlgChild1.h"
#include "afxdialogex.h"

/*
 * 作者：zs
 * 功能：对话框
 * 日期：2015年10月22日
 */
// CalculateDlgChild1 dialog

IMPLEMENT_DYNAMIC(CalculateDlgChild1, CDialog)

	// 构造函数先于InitDialog调用，要设置初始状态，请到InitDialog函数
CalculateDlgChild1::CalculateDlgChild1(CWnd* pParent /*=NULL*/)
	: CDialog(CalculateDlgChild1::IDD, pParent)
{
	// 构造函数用于初始化基本类型,一般初始化为对应类型的默认值
	m_edit_dx=1.0f;
	//  m_editDy = 0.0f;
	m_edit_dy = 1.0f;
	m_edit_dz = 1.0f;
	m_edit_time_step_size = 1.0f;
	m_edit_atmmobility = 1.0f;
	m_edit_gradcoef = 1.0f;
	m_edit_noise = 0.1f;
	m_edit_random_seed = 400;
	m_combo_regsize = _T("");
	m_edit_x = _T("");
	m_edit_y = _T("");
	m_radio_new_start=FALSE;
}

CalculateDlgChild1::~CalculateDlgChild1()
{
}

void CalculateDlgChild1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DX, m_edit_dx);
	DDV_MinMaxFloat(pDX, m_edit_dx, 1.0f, 10.0f);
	DDX_Control(pDX, IDC_COMBO_REGSIZE, m_comboRegsize);
	DDX_Control(pDX, IDC_RADIO_REGSIZE, m_RadioRegSize);
	DDX_Control(pDX, IDC_SPIN_DX, m_SpinDx);
	DDX_Control(pDX, IDC_SPIN_DY, m_SpinDy);
	DDX_Control(pDX, IDC_SPIN_DZ, m_SpinDz);
	DDX_Control(pDX, IDC_EDIT_DX, m_EditDx);
	DDX_Control(pDX, IDC_EDIT_DY, m_EditDy);
	DDX_Control(pDX, IDC_EDIT_DZ, m_EditDz);
	DDX_Text(pDX, IDC_EDIT_DY, m_edit_dy);
	DDV_MinMaxFloat(pDX, m_edit_dy, 1.0f, 10.0f);
	DDX_Text(pDX, IDC_EDIT_DZ, m_edit_dz);
	DDV_MinMaxFloat(pDX, m_edit_dz, 1.0f, 10.0f);
	DDX_Text(pDX, IDC_EDIT_TIME_STEP_SIZE, m_edit_time_step_size);
	DDV_MinMaxFloat(pDX, m_edit_time_step_size, 1.0f, 10.0f);
	DDX_Text(pDX, IDC_EDIT_ATMMOBILITY, m_edit_atmmobility);
	DDV_MinMaxFloat(pDX, m_edit_atmmobility, 1.0f, 10.0f);
	DDX_Text(pDX, IDC_EDIT_GRADCOEF, m_edit_gradcoef);
	DDV_MinMaxFloat(pDX, m_edit_gradcoef, 1.0f, 10.0f);
	DDX_Control(pDX, IDC_EDIT_TIME_STEP_SIZE, m_EditTimeStepSize);
	DDX_Control(pDX, IDC_EDIT_ATMMOBILITY, m_EditATMMobility);
	DDX_Control(pDX, IDC_EDIT_GRADCOEF, m_EditGradCoef);
	DDX_Control(pDX, IDC_EDIT_NOISE, m_EidtNoise);
	DDX_Text(pDX, IDC_EDIT_NOISE, m_edit_noise);
	DDV_MinMaxFloat(pDX, m_edit_noise, 0.1f, 10.0f);
	DDX_Control(pDX, IDC_SPIN_TIME_STEP_SIZE, m_SpinTimeStepSize);
	DDX_Control(pDX, IDC_SPIN_ATMMOBILITY, m_SpinATMMobility);
	DDX_Control(pDX, IDC_SPIN_GRADCOEF, m_SpinGradCoef);
	DDX_Control(pDX, IDC_SPIN_NOISE, m_SpinNoise);
	DDX_Control(pDX, IDC_SPIN_RANDOM_SEED, m_SpinRandomSeed);
	DDX_Text(pDX, IDC_EDIT_RANDOM_SEED, m_edit_random_seed);
	DDV_MinMaxInt(pDX, m_edit_random_seed, 400, 10000);
	DDX_Control(pDX, IDC_EDIT_RANDOM_SEED, m_EditRandomSeed);
	DDX_Radio(pDX, IDC_RADIO_REGSIZE, m_radio_regsize);
	DDX_CBString(pDX, IDC_COMBO_REGSIZE, m_combo_regsize);
	DDX_Text(pDX, IDC_EDIT_X, m_edit_x);
	DDX_Text(pDX, IDC_EDIT_Y, m_edit_y);
	DDX_Control(pDX, IDC_RADIO_NEWSTART, m_RadioNewStart);
	DDX_Radio(pDX, IDC_RADIO_NEWSTART, m_radio_new_start);
}


BEGIN_MESSAGE_MAP(CalculateDlgChild1, CDialog)
	ON_BN_CLICKED(IDC_RADIO_REGSIZE, &CalculateDlgChild1::OnBnClickedRadioRegsize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DX, &CalculateDlgChild1::OnDeltaposSpinDx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DY, &CalculateDlgChild1::OnDeltaposSpinDy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_DZ, &CalculateDlgChild1::OnDeltaposSpinDz)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_TIME_STEP_SIZE, &CalculateDlgChild1::OnDeltaposSpinTimeStepSize)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ATMMOBILITY, &CalculateDlgChild1::OnDeltaposSpinAtmmobility)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GRADCOEF, &CalculateDlgChild1::OnDeltaposSpinGradcoef)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NOISE, &CalculateDlgChild1::OnDeltaposSpinNoise)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RANDOM_SEED, &CalculateDlgChild1::OnDeltaposSpinRandomSeed)
END_MESSAGE_MAP()


// CalculateDlgChild1 message handlers

// 该函数后于构造函数调用
BOOL CalculateDlgChild1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 设置Radio Button选项按钮的默认值
	m_RadioRegSize.SetCheck(TRUE);
	m_RadioNewStart.SetCheck(TRUE);
	// 类类型的值的初始化放在OnInitDialog中完成
	// 设置一般大小下拉初始值
	this->m_comboRegsize.AddString(_T("Small"));
	this->m_comboRegsize.AddString(_T("Medium"));
	this->m_comboRegsize.AddString(_T("Large"));
	this->m_comboRegsize.AddString(_T("Ultra-Large"));
	// 设置第二个被选择
	this->m_comboRegsize.SetCurSel(1);

	// 设置网格大小 dx dy dz
	// 基本类型值的初始化放在构造函数中完成，而进一步设置可以在这里完成
	this->m_edit_dx=1.0f;

	// 格式化输出到文本框
	CString textDx;
	textDx.Format(_T("%0.1f"),m_edit_dx);
	// 通过ID或恶对话框上的控件，从而操作控件
	// 方法一：SetDlgItemText(IDC_EDIT1,strNumber);
	// 方法而：CEdit* edt=(CEdit*)GetDlgItem(IDC_EDIT1);edt->SetWindowText(strNumber);
	SetDlgItemText(IDC_EDIT_DX,textDx);
	SetDlgItemText(IDC_EDIT_DY,textDx);
	SetDlgItemText(IDC_EDIT_DZ,textDx);
	SetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,textDx);
	SetDlgItemText(IDC_EDIT_ATMMOBILITY,textDx);
	SetDlgItemText(IDC_EDIT_GRADCOEF,textDx);
	SetDlgItemText(IDC_EDIT_RANDOM_SEED,"400");
	SetDlgItemText(IDC_EDIT_NOISE,"0.1");

	// 设置Spin Control旋转控件的伙伴控件
	m_SpinDx.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_DX));
	m_SpinDy.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_DY));
	m_SpinDz.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_DZ));

	m_SpinTimeStepSize.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_TIME_STEP_SIZE));
	m_SpinATMMobility.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_ATMMOBILITY));
	m_SpinGradCoef.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_GRADCOEF));
	m_SpinRandomSeed.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_RANDOM_SEED));
	m_SpinNoise.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_NOISE));

	// 设置旋转按钮加速
	// 设置旋转按钮的范围（只对整数有效）
	m_SpinRandomSeed.SetRange(400,10000);
	m_SpinRandomSeed.SetBase(400);
	// 设置Spin Control旋转控件的可用上下箭头(通过控件属性修改（默认是可用上下箭头的）)
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

///*
void CalculateDlgChild1::OnBnClickedRadioRegsize()
{
	// TODO: Add your control notification handler code here
	// 测试控件消息是否正常
	//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
}
//*/

// 
//void CalculateDlgChild1::OnDeltaposSpinDx(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
//	// TODO: Add your control notification handler code here
//	*pResult = 0;
//}


void CalculateDlgChild1::OnDeltaposSpinDx(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DX,tempText);
		this->m_edit_dx= (float)_ttof(tempText);

		if (this->m_edit_dx>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			this->m_edit_dx=10.0f;
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}else if (this->m_edit_dx<=1.0){
			tempText.Format(_T("%0.1f"),1.0);
			this->m_edit_dx=1.0f;
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}else{
			this->m_edit_dx-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dx);
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DX,tempText);
		this->m_edit_dx= (float)_ttof(tempText);

		if (this->m_edit_dx<1.0f){
			tempText.Format(_T("%0.1f"),1.0);
			this->m_edit_dx=1.0f;
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}else if(this->m_edit_dx>=10.0f){
			tempText.Format(_T("%0.1f"),10.0);
			this->m_edit_dx=10.0f;
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}else{
			this->m_edit_dx+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dx);
			SetDlgItemText(IDC_EDIT_DX,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinDy(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DY,tempText);
		this->m_edit_dy= (float)_ttof(tempText);

		if (this->m_edit_dy>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_DY,tempText);
		}
		if(this->m_edit_dy>1.0){
			this->m_edit_dy-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dy);
			SetDlgItemText(IDC_EDIT_DY,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DY,tempText);
		this->m_edit_dy= (float)_ttof(tempText);

		if (this->m_edit_dy<1.0){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_DY,tempText);
		}
		if (this->m_edit_dy<10.0){
			this->m_edit_dy+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dy);
			SetDlgItemText(IDC_EDIT_DY,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinDz(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DZ,tempText);
		this->m_edit_dz= (float)_ttof(tempText);

		if (this->m_edit_dz>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_DZ,tempText);
		}
		if(this->m_edit_dz>1.0){
			this->m_edit_dz-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dz);
			SetDlgItemText(IDC_EDIT_DZ,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_DZ,tempText);
		this->m_edit_dz=(float) _ttof(tempText);

		if (this->m_edit_dz<1.0){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_DZ,tempText);
		}
		if (this->m_edit_dz<10.0){
			this->m_edit_dz+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_dz);
			SetDlgItemText(IDC_EDIT_DZ,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinTimeStepSize(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		this->m_edit_time_step_size=(float) _ttof(tempText);

		if (this->m_edit_time_step_size>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		}
		if(this->m_edit_time_step_size>1.0){
			this->m_edit_time_step_size-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_time_step_size);
			SetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		this->m_edit_time_step_size= (float)_ttof(tempText);

		if (this->m_edit_time_step_size<1.0){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		}
		if (this->m_edit_time_step_size<10.0){
			this->m_edit_time_step_size+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_time_step_size);
			SetDlgItemText(IDC_EDIT_TIME_STEP_SIZE,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinAtmmobility(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		this->m_edit_atmmobility= (float)_ttof(tempText);

		if (this->m_edit_atmmobility>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		}
		if(this->m_edit_atmmobility>1.0){
			this->m_edit_atmmobility-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_atmmobility);
			SetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		this->m_edit_atmmobility= (float)_ttof(tempText);

		if (this->m_edit_atmmobility<1.0){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		}
		if (this->m_edit_atmmobility<10.0){
			this->m_edit_atmmobility+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_atmmobility);
			SetDlgItemText(IDC_EDIT_ATMMOBILITY,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinGradcoef(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		this->m_edit_gradcoef= (float)_ttof(tempText);

		if (this->m_edit_gradcoef>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		}
		if(this->m_edit_gradcoef>1.0){
			this->m_edit_gradcoef-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_gradcoef);
			SetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		this->m_edit_gradcoef= (float)_ttof(tempText);

		if (this->m_edit_gradcoef<1.0){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		}
		if (this->m_edit_gradcoef<10.0){
			this->m_edit_gradcoef+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_gradcoef);
			SetDlgItemText(IDC_EDIT_GRADCOEF,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinNoise(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_NOISE,tempText);
		this->m_edit_noise= (float)_ttof(tempText);

		if (this->m_edit_noise>10.0){
			tempText.Format(_T("%0.1f"),10.0);
			SetDlgItemText(IDC_EDIT_NOISE,tempText);
		}
		if(this->m_edit_noise>0.1){
			this->m_edit_noise-=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_noise);
			SetDlgItemText(IDC_EDIT_NOISE,tempText);
		}
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_NOISE,tempText);
		this->m_edit_noise= (float)_ttof(tempText);

		if (this->m_edit_noise<0.1){
			tempText.Format(_T("%0.1f"),1.0);
			SetDlgItemText(IDC_EDIT_NOISE,tempText);
		}
		if (this->m_edit_noise<10.0){
			this->m_edit_noise+=0.1f;
			tempText.Format(_T("%0.1f"),this->m_edit_noise);
			SetDlgItemText(IDC_EDIT_NOISE,tempText);
		}
	}
	//*/

	*pResult = 0;
}


void CalculateDlgChild1::OnDeltaposSpinRandomSeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	//*
	if(pNMUpDown->iDelta > 0){
		// 响应点击向下
		//::MessageBox(NULL,_T("OKOK"),_T("OKOK"),MB_OK);
		CString tempText ;
		GetDlgItemText(IDC_EDIT_RANDOM_SEED,tempText);
		this->m_edit_random_seed= atoi(tempText)-1;
		if(this->m_edit_random_seed<400) this->m_edit_random_seed=400;
	}
	else if(pNMUpDown->iDelta < 0){
		// 相应点击向上
		CString tempText ;
		GetDlgItemText(IDC_EDIT_RANDOM_SEED,tempText);
		this->m_edit_random_seed= atoi(tempText)+1;
		if(this->m_edit_random_seed>10000) this->m_edit_random_seed=10000;
		
	}
	//*/

	*pResult = 0;
}
