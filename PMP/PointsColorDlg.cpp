// PointsColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PointsColorDlg.h"
#include "afxdialogex.h"


// CPointsColorDlg dialog

IMPLEMENT_DYNAMIC(CPointsColorDlg, CDialog)

CPointsColorDlg::CPointsColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointsColorDlg::IDD, pParent)
{

	m_edit_rgb_value_point1_double = 0.0;
	m_edit_rgb_value_point2_double = 0.0;
	m_edit_rgb_value_point3_double = 0.0;
	m_edit_rgb_value_point4_double = 0.0;
	m_edit_rgb_value_point5_double = 0.0;
	m_edit_rgb_value_point6_double = 0.0;
	m_edit_rgb_value_r1 = 0.0;
	m_edit_rgb_value_r2 = 0.0;
	m_edit_rgb_value_r3 = 0.0;
	m_edit_rgb_value_r4 = 0.0;
	m_edit_rgb_value_r5 = 0.0;
	m_edit_rgb_value_r6 = 0.0;
	m_edit_rgb_value_g1 = 0.0;
	m_edit_rgb_value_g2 = 0.0;
	m_edit_rgb_value_g3 = 0.0;
	m_edit_rgb_value_g4 = 0.0;
	m_edit_rgb_value_g5 = 0.0;
	m_edit_rgb_value_g6 = 0.0;
	m_edit_rgb_value_b1 = 0.0;
	m_edit_rgb_value_b2 = 0.0;
	m_edit_rgb_value_b3 = 0.0;
	m_edit_rgb_value_b4 = 0.0;
	m_edit_rgb_value_b5 = 0.0;
	m_edit_rgb_value_b6 = 0.0;
	m_edit_min_value_points = 0.0;
	m_edit_max_value_points = 0.0;
	m_edit_min_value_opa = 0.0;
	m_edit_max_value_opa = 0.0;
	m_edit_opa_value_point1 = 0.0;
	m_edit_opa_value_point2 = 0.0;
	m_edit_opa_value_point3 = 0.0;
	m_edit_opa_value_point4 = 0.0;
	m_edit_opa_value_point5 = 0.0;
	m_edit_opa_value_point6 = 0.0;
	m_edit_opa_value1 = 0.0;
	m_edit_opa_value2 = 0.0;
	m_edit_opa_value3 = 0.0;
	m_edit_opa_value4 = 0.0;
	m_edit_opa_value5 = 0.0;
	m_edit_opa_value6 = 0.0;
	// 默认标题
	m_cation = _T("Points Color");
	////////////////////////////////////值地址获取//////////////////////////////////////
	// 颜色点值的地址
	RGBPoints [0] = &m_edit_rgb_value_point1_double;
	RGBPoints [1] = &m_edit_rgb_value_point2_double;
	RGBPoints [2] = &m_edit_rgb_value_point3_double;
	RGBPoints [3] = &m_edit_rgb_value_point4_double;
	RGBPoints [4] = &m_edit_rgb_value_point5_double;
	RGBPoints [5] = &m_edit_rgb_value_point6_double;
	RGBR[0] = &m_edit_rgb_value_r1;RGBR[1] = &m_edit_rgb_value_r2;RGBR[2] = &m_edit_rgb_value_r3;RGBR[3] = &m_edit_rgb_value_r4;RGBR[4] = &m_edit_rgb_value_r5;RGBR[5] = &m_edit_rgb_value_r6;
	RGBG[0] = &m_edit_rgb_value_g1;RGBG[1] = &m_edit_rgb_value_g2;RGBG[2] = &m_edit_rgb_value_g3;RGBG[3] = &m_edit_rgb_value_g4;RGBG[4] = &m_edit_rgb_value_g5;RGBG[5] = &m_edit_rgb_value_g6;
	RGBB[0] = &m_edit_rgb_value_b1;RGBB[1] = &m_edit_rgb_value_b2;RGBB[2] = &m_edit_rgb_value_b3;RGBB[3] = &m_edit_rgb_value_b4;RGBB[4] = &m_edit_rgb_value_b5;RGBB[5] = &m_edit_rgb_value_b6;

	// 透明点的地址
	OPAPoints [0] = &m_edit_opa_value_point1;
	OPAPoints [1] = &m_edit_opa_value_point2;
	OPAPoints [2] = &m_edit_opa_value_point3;
	OPAPoints [3] = &m_edit_opa_value_point4;
	OPAPoints [4] = &m_edit_opa_value_point5;
	OPAPoints [5] = &m_edit_opa_value_point6;
	OPA[0]=&m_edit_opa_value1;OPA[1]=&m_edit_opa_value2;OPA[2]=&m_edit_opa_value3;OPA[3]=&m_edit_opa_value4;OPA[4]=&m_edit_opa_value5;OPA[5]=&m_edit_opa_value6;
	/////////////////////////////////////值地址获取/////////////////////////////////////
	/////////////////////////////////////控件地址获取/////////////////////////////////////
	RGBEditPoints [0] = &m_EditRgbValuePoint1;RGBEditPoints [1] = &m_EditRgbValuePoint2;RGBEditPoints [2] = &m_EditRgbValuePoint3;RGBEditPoints [3] = &m_EditRgbValuePoint4;RGBEditPoints [4] = &m_EditRgbValuePoint5;RGBEditPoints [5] = &m_EditRgbValuePoint6;
	// 滑块分配地址
	RGBSlider [0] = &m_SlierRgbValue1;RGBSlider [1] = &m_SlierRgbValue2;RGBSlider [2] = &m_SlierRgbValue3;RGBSlider [3] = &m_SlierRgbValue4;RGBSlider [4] = &m_SlierRgbValue5;RGBSlider [5] = &m_SlierRgbValue6;
	RGBEditR [0] = &m_EditRgbValueR1;RGBEditR [1] = &m_EditRgbValueR2;RGBEditR [2] = &m_EditRgbValueR3;RGBEditR [3] = &m_EditRgbValueR4;RGBEditR [4] = &m_EditRgbValueR5;RGBEditR [5] = &m_EditRgbValueR6;
	RGBEditG [0] = &m_EditRgbValueG1;RGBEditG [1] = &m_EditRgbValueG2;RGBEditG [2] = &m_EditRgbValueG3;RGBEditG [3] = &m_EditRgbValueG4;RGBEditG [4] = &m_EditRgbValueG5;RGBEditG [5] = &m_EditRgbValueG6;
	RGBEditB [0] = &m_EditRgbValueB1;RGBEditB [1] = &m_EditRgbValueB2;RGBEditB [2] = &m_EditRgbValueB3;RGBEditB [3] = &m_EditRgbValueB4;RGBEditB [4] = &m_EditRgbValueB5;RGBEditB [5] = &m_EditRgbValueB6;
	// 按钮地址分配
	RGBButton [0] = &m_ButtonPoint1Add;
	RGBButton [1] = &m_ButtonPoint2Add;
	RGBButton [2] = &m_ButtonPoint3Add;
	RGBButton [3] = &m_ButtonPoint4Add;
	RGBButton [4] = &m_ButtonPoint5Add;
	RGBButton [5] = &m_ButtonPoint6Add;
	//////////////////////////////////////控件地址获取////////////////////////////////////
	/////////////////////////////////////控件地址获取/////////////////////////////////////
	OPAEditPoints [0] = &m_EditOpaValuePoint1;OPAEditPoints [1] = &m_EditOpaValuePoint2;OPAEditPoints [2] = &m_EditOpaValuePoint3;OPAEditPoints [3] = &m_EditOpaValuePoint4;OPAEditPoints [4] = &m_EditOpaValuePoint5;OPAEditPoints [5] = &m_EditOpaValuePoint6;
	OPASlider [0] = &m_SlierOpaValue1;OPASlider [1] = &m_SlierOpaValue2;OPASlider [2] = &m_SlierOpaValue3;OPASlider [3] = &m_SlierOpaValue4;OPASlider [4] = &m_SlierOpaValue5;OPASlider [5] = &m_SlierOpaValue6;
	OPAEdit [0] = &m_EditOpaValue1;OPAEdit [1] = &m_EditOpaValue2;OPAEdit [2] = &m_EditOpaValue3;OPAEdit [3] = &m_EditOpaValue4;OPAEdit [4] = &m_EditOpaValue5;OPAEdit [5] = &m_EditOpaValue6;
	OPAButton [0] = &m_ButtonOpaPoint1Add;
	OPAButton [1] = &m_ButtonOpaPoint2Add;
	OPAButton [2] = &m_ButtonOpaPoint3Add;
	OPAButton [3] = &m_ButtonOpaPoint4Add;
	OPAButton [4] = &m_ButtonOpaPoint5Add;
	OPAButton [5] = &m_ButtonOpaPoint6Add;
	//////////////////////////////////////控件地址获取////////////////////////////////////



	RGBnPoints = 0;
	OPAnPoints = 0;
	RGBFlag[0] = FALSE;RGBFlag[1] = FALSE;RGBFlag[2] = FALSE;RGBFlag[3] = FALSE;RGBFlag[4] = FALSE;RGBFlag[5] = FALSE;

	OPAFlag[0] = FALSE;OPAFlag[1] = FALSE;OPAFlag[2] = FALSE;OPAFlag[3] = FALSE;OPAFlag[4] = FALSE;OPAFlag[5] = FALSE;
}

CPointsColorDlg::~CPointsColorDlg()
{
}

void CPointsColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT1, m_edit_rgb_value_point1_double);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT2, m_edit_rgb_value_point2_double);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT3, m_edit_rgb_value_point3_double);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT4, m_edit_rgb_value_point4_double);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT5, m_edit_rgb_value_point5_double);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_POINT6, m_edit_rgb_value_point6_double);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE1, m_SlierRgbValue1);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE2, m_SlierRgbValue2);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE3, m_SlierRgbValue3);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE4, m_SlierRgbValue4);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE5, m_SlierRgbValue5);
	DDX_Control(pDX, IDC_SLIDER_RGB_VALUE6, m_SlierRgbValue6);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE1, m_SlierOpaValue1);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE2, m_SlierOpaValue2);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE3, m_SlierOpaValue3);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE4, m_SlierOpaValue4);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE5, m_SlierOpaValue5);
	DDX_Control(pDX, IDC_SLIDER_OPA_VALUE6, m_SlierOpaValue6);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R1, m_edit_rgb_value_r1);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r1, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R2, m_edit_rgb_value_r2);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r2, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R3, m_edit_rgb_value_r3);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r3, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R4, m_edit_rgb_value_r4);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r4, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R5, m_edit_rgb_value_r5);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r5, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_R6, m_edit_rgb_value_r6);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_r6, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G1, m_edit_rgb_value_g1);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g1, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G2, m_edit_rgb_value_g2);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g2, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G3, m_edit_rgb_value_g3);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g3, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G4, m_edit_rgb_value_g4);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g4, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G5, m_edit_rgb_value_g5);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g5, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_G6, m_edit_rgb_value_g6);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_g6, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B1, m_edit_rgb_value_b1);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b1, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B2, m_edit_rgb_value_b2);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b2, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B3, m_edit_rgb_value_b3);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b3, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B4, m_edit_rgb_value_b4);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b4, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B5, m_edit_rgb_value_b5);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b5, 0, 1);
	DDX_Text(pDX, IDC_EDIT_RGB_VALUE_B6, m_edit_rgb_value_b6);
	DDV_MinMaxDouble(pDX, m_edit_rgb_value_b6, 0, 1);
	DDX_Control(pDX, IDC_BUTTON_POINT1_ADD, m_ButtonPoint1Add);
	DDX_Control(pDX, IDC_BUTTON_POINT2_ADD, m_ButtonPoint2Add);
	DDX_Control(pDX, IDC_BUTTON_POINT3_ADD, m_ButtonPoint3Add);
	DDX_Control(pDX, IDC_BUTTON_POINT4_ADD, m_ButtonPoint4Add);
	DDX_Control(pDX, IDC_BUTTON_POINT5_ADD, m_ButtonPoint5Add);
	DDX_Control(pDX, IDC_BUTTON_POINT6_ADD, m_ButtonPoint6Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT1_ADD, m_ButtonOpaPoint1Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT2_ADD, m_ButtonOpaPoint2Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT3_ADD, m_ButtonOpaPoint3Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT4_ADD, m_ButtonOpaPoint4Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT5_ADD, m_ButtonOpaPoint5Add);
	DDX_Control(pDX, IDC_BUTTON_OPA_POINT6_ADD, m_ButtonOpaPoint6Add);
	DDX_Text(pDX, IDC_EDIT_MIN_VALUE_POINTS, m_edit_min_value_points);
	DDX_Text(pDX, IDC_EDIT_MAX_VALUE_POINTS, m_edit_max_value_points);
	DDX_Text(pDX, IDC_EDIT_MIN_VALUE_OPA, m_edit_min_value_opa);
	DDX_Text(pDX, IDC_EDIT_MAX_VALUE_OPA, m_edit_max_value_opa);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT1, m_edit_opa_value_point1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT2, m_edit_opa_value_point2);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT3, m_edit_opa_value_point3);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT4, m_edit_opa_value_point4);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT5, m_edit_opa_value_point5);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE_POINT6, m_edit_opa_value_point6);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE1, m_edit_opa_value1);
	DDV_MinMaxDouble(pDX, m_edit_opa_value1, 0, 1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE2, m_edit_opa_value2);
	DDV_MinMaxDouble(pDX, m_edit_opa_value2, 0, 1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE3, m_edit_opa_value3);
	DDV_MinMaxDouble(pDX, m_edit_opa_value3, 0, 1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE4, m_edit_opa_value4);
	DDV_MinMaxDouble(pDX, m_edit_opa_value4, 0, 1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE5, m_edit_opa_value5);
	DDV_MinMaxDouble(pDX, m_edit_opa_value5, 0, 1);
	DDX_Text(pDX, IDC_EDIT_OPA_VALUE6, m_edit_opa_value6);
	DDV_MinMaxDouble(pDX, m_edit_opa_value6, 0, 1);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT1, m_EditOpaValuePoint1);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT2, m_EditOpaValuePoint2);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT3, m_EditOpaValuePoint3);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT4, m_EditOpaValuePoint4);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT5, m_EditOpaValuePoint5);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE_POINT6, m_EditOpaValuePoint6);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE1, m_EditOpaValue1);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE2, m_EditOpaValue2);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE3, m_EditOpaValue3);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE4, m_EditOpaValue4);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE5, m_EditOpaValue5);
	DDX_Control(pDX, IDC_EDIT_OPA_VALUE6, m_EditOpaValue6);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B1, m_EditRgbValueB1);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B2, m_EditRgbValueB2);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B3, m_EditRgbValueB3);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B4, m_EditRgbValueB4);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B5, m_EditRgbValueB5);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_B6, m_EditRgbValueB6);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G1, m_EditRgbValueG1);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G2, m_EditRgbValueG2);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G3, m_EditRgbValueG3);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G4, m_EditRgbValueG4);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G5, m_EditRgbValueG5);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_G6, m_EditRgbValueG6);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT1, m_EditRgbValuePoint1);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT2, m_EditRgbValuePoint2);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT3, m_EditRgbValuePoint3);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT4, m_EditRgbValuePoint4);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT5, m_EditRgbValuePoint5);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_POINT6, m_EditRgbValuePoint6);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R1, m_EditRgbValueR1);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R2, m_EditRgbValueR2);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R3, m_EditRgbValueR3);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R4, m_EditRgbValueR4);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R5, m_EditRgbValueR5);
	DDX_Control(pDX, IDC_EDIT_RGB_VALUE_R6, m_EditRgbValueR6);
}


BEGIN_MESSAGE_MAP(CPointsColorDlg, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE1, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE2, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE3, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE4, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE5, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RGB_VALUE6, &CPointsColorDlg::OnNMCustomdrawSliderRgbValue6)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE1, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE2, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE3, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE4, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE5, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPA_VALUE6, &CPointsColorDlg::OnNMCustomdrawSliderOpaValue6)
	ON_BN_CLICKED(IDC_BUTTON_POINT1_ADD, &CPointsColorDlg::OnBnClickedButtonPoint1Add)
	ON_BN_CLICKED(IDC_BUTTON_POINT2_ADD, &CPointsColorDlg::OnBnClickedButtonPoint2Add)
	ON_BN_CLICKED(IDC_BUTTON_POINT3_ADD, &CPointsColorDlg::OnBnClickedButtonPoint3Add)
	ON_BN_CLICKED(IDC_BUTTON_POINT4_ADD, &CPointsColorDlg::OnBnClickedButtonPoint4Add)
	ON_BN_CLICKED(IDC_BUTTON_POINT5_ADD, &CPointsColorDlg::OnBnClickedButtonPoint5Add)
	ON_BN_CLICKED(IDC_BUTTON_POINT6_ADD, &CPointsColorDlg::OnBnClickedButtonPoint6Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT1_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint1Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT2_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint2Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT3_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint3Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT4_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint4Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT5_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint5Add)
	ON_BN_CLICKED(IDC_BUTTON_OPA_POINT6_ADD, &CPointsColorDlg::OnBnClickedButtonOpaPoint6Add)
END_MESSAGE_MAP()


// CPointsColorDlg message handlers


BOOL CPointsColorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	// TODO:  Add extra initialization here

	// 根据点数决定显示几个数据
	// 对于颜色点
	for (int i= 0;i<RGBnPoints;i++)
	{
		RGBEditPoints[i]->ShowWindow(SW_SHOW);
		RGBSlider[i] ->ShowWindow(SW_SHOW);
		RGBEditR[i]->ShowWindow(SW_SHOW);
		RGBEditG[i]->ShowWindow(SW_SHOW);
		RGBEditB[i]->ShowWindow(SW_SHOW);
		RGBButton[i]->ShowWindow(SW_SHOW);
		RGBButton[i]->SetWindowText("-");
		RGBFlag [i] = TRUE;

	}
	for (int i= RGBnPoints;i<6;i++)
	{
		RGBEditPoints[i]->ShowWindow(SW_HIDE);
		// 剩余点的初值
		*(RGBPoints [i]) = m_edit_min_value_points;
		RGBSlider[i] ->ShowWindow(SW_HIDE);
		RGBEditR[i]->ShowWindow(SW_HIDE);
		RGBEditG[i]->ShowWindow(SW_HIDE);
		RGBEditB[i]->ShowWindow(SW_HIDE);
		RGBButton[i]->SetWindowText("+");
		RGBFlag [i] = FALSE;
	}

	for (int i =0 ;i<OPAnPoints;i++)
	{
		OPAEditPoints [i] ->ShowWindow(SW_SHOW);
		OPASlider [i]->ShowWindow(SW_SHOW);
		OPAEdit [i] ->ShowWindow(SW_SHOW);
		OPAButton [i] ->ShowWindow(SW_SHOW);
		OPAButton [i] ->SetWindowTextA("-");
		OPAFlag [i] = TRUE;
	}
	for (int i =OPAnPoints ;i<6;i++)
	{
		OPAEditPoints [i] ->ShowWindow(SW_HIDE);
		// 剩余点的初值
		*(OPAPoints [i]) = m_edit_min_value_points;
		OPASlider [i]->ShowWindow(SW_HIDE);
		OPAEdit [i] ->ShowWindow(SW_HIDE);
		OPAButton [i] ->ShowWindow(SW_HIDE);
		OPAButton [i] ->SetWindowTextA("+");
		OPAFlag [i]= FALSE;
	}


	for (int i = 0;i<6;i++)
	{
		RGBSlider [i]->SetRange(1,100);
		RGBSlider [i]->SetTicFreq(5);
		// 根据初值设置，滑动条的位置
		int pos = int(((*(RGBPoints[i])-m_edit_min_value_points)/(m_edit_max_value_points-m_edit_min_value_points))*100.0);
		RGBSlider [i]->SetPos(pos);
	}
	for (int i = 0;i<6;i++)
	{
		OPASlider [i]->SetRange(1,100);
		OPASlider [i]->SetTicFreq(5);
		// 根据初值设置，滑动条的位置
		int pos = int(((*(OPAPoints[i])-m_edit_min_value_points)/(m_edit_max_value_points-m_edit_min_value_points))*100.0);
		OPASlider [i]->SetPos(pos);
	}

	SetWindowText(m_cation);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue1.GetPos();
	m_edit_rgb_value_point1_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point1_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT1,str);
	UpdateData(FALSE);

	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue2.GetPos();
	m_edit_rgb_value_point2_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point2_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT2,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue3.GetPos();
	m_edit_rgb_value_point3_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point3_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT3,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue4.GetPos();
	m_edit_rgb_value_point4_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point4_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT4,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue5.GetPos();
	m_edit_rgb_value_point5_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point5_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT5,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderRgbValue6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierRgbValue6.GetPos();
	m_edit_rgb_value_point6_double = m_edit_min_value_points+(pos/100.0)*(m_edit_max_value_points-m_edit_min_value_points);
	CString str;
	str.Format("%g",m_edit_rgb_value_point6_double);
	SetDlgItemText(IDC_EDIT_RGB_VALUE_POINT6,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue1.GetPos();
	m_edit_opa_value_point1 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point1);
	SetDlgItemText(IDC_EDIT_OPA_VALUE1,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue2.GetPos();
	m_edit_opa_value_point2 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point2);
	SetDlgItemText(IDC_EDIT_OPA_VALUE2,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue3.GetPos();
	m_edit_opa_value_point3 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point3);
	SetDlgItemText(IDC_EDIT_OPA_VALUE3,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue4.GetPos();
	m_edit_opa_value_point4 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point4);
	SetDlgItemText(IDC_EDIT_OPA_VALUE4,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue5.GetPos();
	m_edit_opa_value_point5 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point5);
	SetDlgItemText(IDC_EDIT_OPA_VALUE5,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnNMCustomdrawSliderOpaValue6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SlierOpaValue6.GetPos();
	m_edit_opa_value_point6 = m_edit_min_value_opa+(pos/100.0)*(m_edit_max_value_opa-m_edit_min_value_opa);
	CString str;
	str.Format("%g",m_edit_opa_value_point6);
	SetDlgItemText(IDC_EDIT_OPA_VALUE6,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CPointsColorDlg::OnBnClickedButtonPoint1Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT1_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint1.ShowWindow(SW_SHOW);
		m_SlierRgbValue1.ShowWindow(SW_SHOW);
		m_EditRgbValueR1.ShowWindow(SW_SHOW);
		m_EditRgbValueG1.ShowWindow(SW_SHOW);
		m_EditRgbValueB1.ShowWindow(SW_SHOW);
		m_ButtonPoint1Add.SetWindowText("-");
		RGBFlag [0] = TRUE;
		RGBnPoints ++;
	}else {
		m_EditRgbValuePoint1.ShowWindow(SW_HIDE);
		m_SlierRgbValue1.ShowWindow(SW_HIDE);
		m_EditRgbValueR1.ShowWindow(SW_HIDE);
		m_EditRgbValueG1.ShowWindow(SW_HIDE);
		m_EditRgbValueB1.ShowWindow(SW_HIDE);
		m_ButtonPoint1Add.SetWindowText("+");
		RGBFlag [0] = FALSE;
		RGBnPoints --;
	}
}


void CPointsColorDlg::OnBnClickedButtonPoint2Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT2_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint2.ShowWindow(SW_SHOW);
		m_SlierRgbValue2.ShowWindow(SW_SHOW);
		m_EditRgbValueR2.ShowWindow(SW_SHOW);
		m_EditRgbValueG2.ShowWindow(SW_SHOW);
		m_EditRgbValueB2.ShowWindow(SW_SHOW);
		m_ButtonPoint2Add.SetWindowText("-");
		RGBFlag [1] = TRUE;
		RGBnPoints++;
	}else {
		m_EditRgbValuePoint2.ShowWindow(SW_HIDE);
		m_SlierRgbValue2.ShowWindow(SW_HIDE);
		m_EditRgbValueR2.ShowWindow(SW_HIDE);
		m_EditRgbValueG2.ShowWindow(SW_HIDE);
		m_EditRgbValueB2.ShowWindow(SW_HIDE);
		m_ButtonPoint2Add.SetWindowText("+");
		RGBFlag [1] = FALSE;
		RGBnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonPoint3Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT3_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint3.ShowWindow(SW_SHOW);
		m_SlierRgbValue3.ShowWindow(SW_SHOW);
		m_EditRgbValueR3.ShowWindow(SW_SHOW);
		m_EditRgbValueG3.ShowWindow(SW_SHOW);
		m_EditRgbValueB3.ShowWindow(SW_SHOW);
		m_ButtonPoint3Add.SetWindowText("-");
		RGBFlag [2] = TRUE;
		RGBnPoints++;
	}else {
		m_EditRgbValuePoint3.ShowWindow(SW_HIDE);
		m_SlierRgbValue3.ShowWindow(SW_HIDE);
		m_EditRgbValueR3.ShowWindow(SW_HIDE);
		m_EditRgbValueG3.ShowWindow(SW_HIDE);
		m_EditRgbValueB3.ShowWindow(SW_HIDE);
		m_ButtonPoint3Add.SetWindowText("+");
		RGBFlag [2] = FALSE;
		RGBnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonPoint4Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT4_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint4.ShowWindow(SW_SHOW);
		m_SlierRgbValue4.ShowWindow(SW_SHOW);
		m_EditRgbValueR4.ShowWindow(SW_SHOW);
		m_EditRgbValueG4.ShowWindow(SW_SHOW);
		m_EditRgbValueB4.ShowWindow(SW_SHOW);
		m_ButtonPoint4Add.SetWindowText("-");
		RGBFlag [3] = TRUE;
		RGBnPoints++;
	}else {
		m_EditRgbValuePoint4.ShowWindow(SW_HIDE);
		m_SlierRgbValue4.ShowWindow(SW_HIDE);
		m_EditRgbValueR4.ShowWindow(SW_HIDE);
		m_EditRgbValueG4.ShowWindow(SW_HIDE);
		m_EditRgbValueB4.ShowWindow(SW_HIDE);
		m_ButtonPoint4Add.SetWindowText("+");
		RGBFlag [3] = FALSE;
		RGBnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonPoint5Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT5_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint5.ShowWindow(SW_SHOW);
		m_SlierRgbValue5.ShowWindow(SW_SHOW);
		m_EditRgbValueR5.ShowWindow(SW_SHOW);
		m_EditRgbValueG5.ShowWindow(SW_SHOW);
		m_EditRgbValueB5.ShowWindow(SW_SHOW);
		m_ButtonPoint5Add.SetWindowText("-");
		RGBFlag [4] = TRUE;
		RGBnPoints++;
	}else {
		m_EditRgbValuePoint5.ShowWindow(SW_HIDE);
		m_SlierRgbValue5.ShowWindow(SW_HIDE);
		m_EditRgbValueR5.ShowWindow(SW_HIDE);
		m_EditRgbValueG5.ShowWindow(SW_HIDE);
		m_EditRgbValueB5.ShowWindow(SW_HIDE);
		m_ButtonPoint5Add.SetWindowText("+");
		RGBFlag [4] = FALSE;
		RGBnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonPoint6Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_POINT6_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditRgbValuePoint6.ShowWindow(SW_SHOW);
		m_SlierRgbValue6.ShowWindow(SW_SHOW);
		m_EditRgbValueR6.ShowWindow(SW_SHOW);
		m_EditRgbValueG6.ShowWindow(SW_SHOW);
		m_EditRgbValueB6.ShowWindow(SW_SHOW);
		m_ButtonPoint6Add.SetWindowText("-");
		RGBFlag [5] = TRUE;
		RGBnPoints++;
	}else {
		m_EditRgbValuePoint6.ShowWindow(SW_HIDE);
		m_SlierRgbValue6.ShowWindow(SW_HIDE);
		m_EditRgbValueR6.ShowWindow(SW_HIDE);
		m_EditRgbValueG6.ShowWindow(SW_HIDE);
		m_EditRgbValueB6.ShowWindow(SW_HIDE);
		m_ButtonPoint6Add.SetWindowText("+");
		RGBFlag [5] = FALSE;
		RGBnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint1Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT1_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint1.ShowWindow(SW_SHOW);
		m_SlierOpaValue1.ShowWindow(SW_SHOW);
		m_EditOpaValue1.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint1Add.SetWindowText("-");
		OPAFlag [0] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint1.ShowWindow(SW_HIDE);
		m_SlierOpaValue1.ShowWindow(SW_HIDE);
		m_EditOpaValue1.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint1Add.SetWindowText("+");
		OPAFlag [0] = FALSE;
		OPAnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint2Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT2_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint2.ShowWindow(SW_SHOW);
		m_SlierOpaValue2.ShowWindow(SW_SHOW);
		m_EditOpaValue2.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint2Add.SetWindowText("-");
		OPAFlag [1] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint2.ShowWindow(SW_HIDE);
		m_SlierOpaValue2.ShowWindow(SW_HIDE);
		m_EditOpaValue2.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint2Add.SetWindowText("+");
		OPAFlag [1] = FALSE;
		OPAnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint3Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT3_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint3.ShowWindow(SW_SHOW);
		m_SlierOpaValue3.ShowWindow(SW_SHOW);
		m_EditOpaValue3.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint3Add.SetWindowText("-");
		OPAFlag [2] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint3.ShowWindow(SW_HIDE);
		m_SlierOpaValue3.ShowWindow(SW_HIDE);
		m_EditOpaValue3.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint3Add.SetWindowText("+");
		OPAFlag [2] = FALSE;
		OPAnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint4Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT4_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint4.ShowWindow(SW_SHOW);
		m_SlierOpaValue4.ShowWindow(SW_SHOW);
		m_EditOpaValue4.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint4Add.SetWindowText("-");
		OPAFlag [3] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint4.ShowWindow(SW_HIDE);
		m_SlierOpaValue4.ShowWindow(SW_HIDE);
		m_EditOpaValue4.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint4Add.SetWindowText("+");
		OPAFlag [3] = FALSE;
		OPAnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint5Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT5_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint5.ShowWindow(SW_SHOW);
		m_SlierOpaValue5.ShowWindow(SW_SHOW);
		m_EditOpaValue5.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint5Add.SetWindowText("-");
		OPAFlag [4] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint5.ShowWindow(SW_HIDE);
		m_SlierOpaValue5.ShowWindow(SW_HIDE);
		m_EditOpaValue5.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint5Add.SetWindowText("+");
		OPAFlag [4] = FALSE;
		OPAnPoints--;
	}
}


void CPointsColorDlg::OnBnClickedButtonOpaPoint6Add()
{
	// TODO: Add your control notification handler code here
	CString addorsub;GetDlgItemText(IDC_BUTTON_OPA_POINT6_ADD,addorsub);
	if (addorsub == "+")
	{
		m_EditOpaValuePoint6.ShowWindow(SW_SHOW);
		m_SlierOpaValue6.ShowWindow(SW_SHOW);
		m_EditOpaValue6.ShowWindow(SW_SHOW);
		m_ButtonOpaPoint6Add.SetWindowText("-");
		OPAFlag [5] = TRUE;
		OPAnPoints++;
	}else {
		m_EditOpaValuePoint6.ShowWindow(SW_HIDE);
		m_SlierOpaValue6.ShowWindow(SW_HIDE);
		m_EditOpaValue6.ShowWindow(SW_HIDE);
		m_ButtonOpaPoint6Add.SetWindowText("+");
		OPAFlag [5] = FALSE;
		OPAnPoints--;
	}
}

