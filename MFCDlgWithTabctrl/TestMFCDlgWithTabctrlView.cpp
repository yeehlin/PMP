
// TestMFCDlgWithTabctrlView.cpp : implementation of the CTestMFCDlgWithTabctrlView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCDlgWithTabctrl.h"
#endif

#include "TestMFCDlgWithTabctrlDoc.h"
#include "TestMFCDlgWithTabctrlView.h"

#include "IsosurfaceDlg.h"
#include "PointsColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCDlgWithTabctrlView

IMPLEMENT_DYNCREATE(CTestMFCDlgWithTabctrlView, CView)

BEGIN_MESSAGE_MAP(CTestMFCDlgWithTabctrlView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCDlgWithTabctrlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOL_ISOSURFACEVALUE, &CTestMFCDlgWithTabctrlView::OnToolIsosurfacevalue)
	ON_COMMAND(ID_TOOL_POINTSCOLOR, &CTestMFCDlgWithTabctrlView::OnToolPointscolor)
END_MESSAGE_MAP()

// CTestMFCDlgWithTabctrlView construction/destruction

CTestMFCDlgWithTabctrlView::CTestMFCDlgWithTabctrlView()
{
	// TODO: add construction code here
	RGBnPoints = 0;
	OPAnPoints = 0;

}

CTestMFCDlgWithTabctrlView::~CTestMFCDlgWithTabctrlView()
{
}

BOOL CTestMFCDlgWithTabctrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestMFCDlgWithTabctrlView drawing

void CTestMFCDlgWithTabctrlView::OnDraw(CDC* /*pDC*/)
{
	CTestMFCDlgWithTabctrlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestMFCDlgWithTabctrlView printing


void CTestMFCDlgWithTabctrlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCDlgWithTabctrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestMFCDlgWithTabctrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestMFCDlgWithTabctrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestMFCDlgWithTabctrlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCDlgWithTabctrlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCDlgWithTabctrlView diagnostics

#ifdef _DEBUG
void CTestMFCDlgWithTabctrlView::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCDlgWithTabctrlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCDlgWithTabctrlDoc* CTestMFCDlgWithTabctrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCDlgWithTabctrlDoc)));
	return (CTestMFCDlgWithTabctrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCDlgWithTabctrlView message handlers


void CTestMFCDlgWithTabctrlView::OnToolIsosurfacevalue()
{
	// TODO: Add your command handler code here
	CIsosurfaceDlg isodlg;
	isodlg.m_edit_min_iso_value_double = 0.3;
	isodlg.m_edit_max_iso_value_double = 12.0;
	isodlg.m_edit_cur_value_double = 10.0;
	if (isodlg.DoModal() == IDOK)
	{
		CString str;
		double temp;
		temp = isodlg.m_edit_cur_value_double;
		str.Format("%e",temp);
		::MessageBox(NULL,_T(str),_T("OK"),MB_OK);
	}
}


void CTestMFCDlgWithTabctrlView::OnToolPointscolor()
{
	// TODO: Add your command handler code here

	CPointsColorDlg pcdlg ;

	// 使用视窗中的初始值初始化对话框
	///////////////////////////////////////视窗状态///////////////////////////////////
	double scalar_range [2];
	scalar_range [0] = -20.5;
	scalar_range [1] = 20.5;
	double diff = scalar_range[1]-scalar_range[0];
	// 设置透明度
	int opacityPoint=6;
	double * opValue;
	opValue = (double * )malloc(opacityPoint * sizeof(double));
	for (int i = 0;i<opacityPoint;i++)
	{
		opValue[i]=scalar_range[0]+(diff/(opacityPoint - 1))*i;
	}
	//opValue=[scalar_range[0],scalar_range[0]+diff/100,diff/100+scalar_range[0],6*diff/100+scalar_range[0],6*diff/100+scalar_range[0],scalar_range[1]]
	double * alpha;
	alpha = (double *)malloc(opacityPoint*sizeof(double));
	for (int i =0;i<opacityPoint;i++)
	{
		alpha[i] = 0.0+(1.0/(opacityPoint-1))*i;
	}
	//=[0.1,0.1,0.0,0.0,1,1]
	//for a in range(0,opacityPoint):
	//opacity.AddPoint(opValue[a],alpha[a])
	for (int i =0 ;i<opacityPoint;i++)
	{
		//opacity->AddPoint(opValue[i],alpha[i]);
	}

	// 设置颜色点
	int RGBPoint=4;
	double * RGBValue;
	RGBValue = (double *)malloc(RGBPoint*sizeof(double));
	//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
	for (int i=0;i<RGBPoint;i++)
	{
		RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
	}
	double **RGB;
	//RGB = (double **)(new double[RGBPoint][3]);
	RGB = (double **)malloc(RGBPoint*sizeof(double *));
	for (int i =0;i<RGBPoint;i++)
	{
		*(RGB + i) = (double *)malloc(3*sizeof(double));
	}
	for (int i = 0;i<RGBPoint;i++)
	{
		if (i%3==0)
		{
			RGB[i][0]=0.0;RGB[i][1]=0.0;RGB[i][2]=1.0;
		}
		if (i%3==1)
		{
			RGB[i][0]=0.0;RGB[i][1]=1.0;RGB[i][2]=0.0;
		}
		if (i%3==2)
		{
			RGB[i][0]=1.0;RGB[i][1]=0.0;RGB[i][2]=0.0;
		}

	}
	//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
	for (int i=0;i<RGBPoint;i++)
	{
		//color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
	}
	////////////////////////////////////视窗初始值//////////////////////////////////////
	////////////////////////////////////根据视窗信息初始化对话框//////////////////////////////////////

	// 颜色点最值
	pcdlg.m_edit_min_value_points = scalar_range[0];
	pcdlg.m_edit_max_value_points = scalar_range[1];
	pcdlg.m_edit_min_value_opa = pcdlg.m_edit_min_value_points;
	pcdlg.m_edit_max_value_opa = pcdlg.m_edit_max_value_points;
	pcdlg.RGBnPoints = RGBPoint;
	pcdlg.OPAnPoints = opacityPoint;
	// 给颜色点赋值
	for (int i =0;i<RGBPoint;i++)
	{
		*(pcdlg.RGBPoints[i]) = RGBValue[i];
		*(pcdlg.RGBR[i]) = RGB[i][0];
		*(pcdlg.RGBG[i]) = RGB[i][1];
		*(pcdlg.RGBB[i]) = RGB[i][2];
	}
	// 给透明点赋值

	for (int i =0;i<opacityPoint;i++)
	{
		*(pcdlg.OPAPoints[i]) = opValue[i];
		*(pcdlg.OPA [i]) = alpha[i];
	}
	if (pcdlg.DoModal() == IDOK)
	{
		//CString str;
		//str.Format("%g",pcdlg.m_edit_rgb_value_point1_double);
		//::MessageBox(NULL,_T(str),_T("真实值"),MB_OK);

		
	}
}
