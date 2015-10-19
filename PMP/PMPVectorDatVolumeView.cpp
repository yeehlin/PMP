// PMPVectorDatVolumeView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPVectorDatVolumeView.h"


// CPMPVectorDatVolumeView

IMPLEMENT_DYNCREATE(CPMPVectorDatVolumeView, CView)

CPMPVectorDatVolumeView::CPMPVectorDatVolumeView()
{
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	pcDlg = NULL;
}

CPMPVectorDatVolumeView::~CPMPVectorDatVolumeView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (pcDlg != NULL)
	{
		delete pcDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPVectorDatVolumeView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPVectorDatVolumeView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPVectorDatVolumeView::OnButtonBackground256)
	ON_COMMAND(ID_VISUALIZE_POINTSCOLOR, &CPMPVectorDatVolumeView::OnVisualizePointscolor)
	ON_COMMAND(ID_BUTTON_POINTS_COLOR_256, &CPMPVectorDatVolumeView::OnButtonPointsColor256)
END_MESSAGE_MAP()


// CPMPVectorDatVolumeView drawing

void CPMPVectorDatVolumeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPVectorDatVolumeView diagnostics

#ifdef _DEBUG
void CPMPVectorDatVolumeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPVectorDatVolumeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif

CPMPDatDoc* CPMPVectorDatVolumeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPDatDoc)));
	return (CPMPDatDoc*)m_pDocument;
}

#endif //_DEBUG


// CPMPVectorDatVolumeView message handlers

static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPVectorDatVolumeView::ExecutePipeline()
{
	if (this->m_pvtkMFCWindow == NULL){
		this->m_pvtkMFCWindow = new vtkMFCWindow(this);
	}
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	this->m_pvtkRenderer->SetBackground(0.9,0.9,0.9);
	this->m_pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->m_pvtkRenderer);
	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->m_pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}

void CPMPVectorDatVolumeView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPVectorDatVolumeView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	CPMPDatDoc* pDoc = GetDocument();
	GetParent()->SetWindowTextA(GetDocument()->GetTitle()+_T("-Volume"));
	m_visualizer.PMPVisualizeVolumn(filename,m_pvtkRenderer);
	ExecutePipeline();
}


void CPMPVectorDatVolumeView::OnVisualizeBackgroundcolor()
{
	// TODO: Add your command handler code here
	double m_dColorRed = 0.9 ;
	double  m_dColorGreen = 0.9;
	double m_dColorBlue = 0.9;
	COLORREF color = RGB(m_dColorRed*255, m_dColorGreen*255, m_dColorBlue*255);
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	if(cdlg.DoModal() == IDOK)
		color = cdlg.GetColor();

	m_dColorRed = GetRValue(color)/255.0;
	m_dColorGreen = GetGValue(color)/255.0;
	m_dColorBlue = GetBValue(color)/255.0;
	m_pvtkRenderer->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPVectorDatVolumeView::OnButtonBackground256()
{
	// TODO: Add your command handler code here
	double m_dColorRed = 0.9 ;
	double  m_dColorGreen = 0.9;
	double m_dColorBlue = 0.9;
	COLORREF color = RGB(m_dColorRed*255, m_dColorGreen*255, m_dColorBlue*255);
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	if(cdlg.DoModal() == IDOK)
		color = cdlg.GetColor();

	m_dColorRed = GetRValue(color)/255.0;
	m_dColorGreen = GetGValue(color)/255.0;
	m_dColorBlue = GetBValue(color)/255.0;
	m_pvtkRenderer->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPVectorDatVolumeView::OnVisualizePointscolor()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}


void CPMPVectorDatVolumeView::OnButtonPointsColor256()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}

void CPMPVectorDatVolumeView::SetPointColor(){
	if(pcDlg == NULL){
		pcDlg = new CPointsColorDlg();
		pcDlg->m_cation +="-"+GetDocument()->GetTitle();
	}
	
	double minv = m_visualizer.scalar_range[0];
	double maxv = m_visualizer.scalar_range[1];
	double range = m_visualizer.diff;
	pcDlg->m_edit_min_value_points = minv;
	pcDlg->m_edit_max_value_points = maxv;
	pcDlg->m_edit_min_value_opa = minv;
	pcDlg->m_edit_max_value_opa = maxv;
	pcDlg->RGBnPoints = m_visualizer.RGBPoint;
	pcDlg->OPAnPoints = m_visualizer.opacityPoint;
	// 给颜色点赋值
	for (int i =0;i<m_visualizer.RGBPoint;i++)
	{
		*(pcDlg->RGBPoints[i]) = m_visualizer.RGBValue[i];
		*(pcDlg->RGBR[i]) = m_visualizer.RGB[i][0];
		*(pcDlg->RGBG[i]) = m_visualizer.RGB[i][1];
		*(pcDlg->RGBB[i]) = m_visualizer.RGB[i][2];
	}
	// 给透明点赋值

	for (int i =0;i<m_visualizer.opacityPoint;i++)
	{
		*(pcDlg->OPAPoints[i]) = m_visualizer.opValue[i];
		*(pcDlg->OPA [i]) = m_visualizer.alpha[i];
	}
	
	if (pcDlg->DoModal() == IDOK)
	{
		m_visualizer.RGBPoint = pcDlg->RGBnPoints;
		m_visualizer.opacityPoint = pcDlg->OPAnPoints;
		if (m_visualizer.RGBPoint != 0)
		{
			m_visualizer.RGBValue = (double *)malloc(m_visualizer.RGBPoint*sizeof(double));
			m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
			for (int i =0;i<m_visualizer.RGBPoint;i++)
			{
				*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
			}
			m_visualizer.color->RemoveAllPoints();
			for (int k = 0,i = 0;k<6 || i<m_visualizer.RGBPoint;k++)
			{
				// 已经关闭了，无法得到控件上的内容
				//CString p;(pcDlg->RGBButton[k])->GetWindowText(p);
				if (pcDlg->RGBFlag[k] == TRUE)
				{
					//::MessageBox(NULL,_T("OK"),_T("OK"),MB_OK);
					m_visualizer.RGBValue[i] = *(pcDlg->RGBPoints[k]);
					//double **RGB;
					//RGB = (double **)(new double[RGBPoint][3]);
					//m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
					//for (int i =0;i<m_visualizer.RGBPoint;i++)
					//{
						//*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
					//}
					//for (int i = 0;i<m_visualizer.RGBPoint;i++)
					//{
							m_visualizer.RGB[i][0]=*(pcDlg->RGBR[k]);
							m_visualizer.RGB[i][1]=*(pcDlg->RGBG[k]);
							m_visualizer.RGB[i][2]=*(pcDlg->RGBB[k]);

					//}
					//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
					//for (int i=0;i<m_visualizer.RGBPoint;i++)
					//{
						m_visualizer.color->AddRGBPoint(m_visualizer.RGBValue[i],m_visualizer.RGB[i][0],m_visualizer.RGB[i][1],m_visualizer.RGB[i][2]);
					//}
					i++;
				}
			}
			m_visualizer.scaleBar->SetNumberOfLabels(m_visualizer.RGBPoint);
			CRect rc;
			GetClientRect(rc);
			m_pvtkMFCWindow->RedrawWindow(rc);
		}

		if (m_visualizer.opacityPoint != 0)
		{

			m_visualizer.opValue = (double * )malloc(m_visualizer.opacityPoint * sizeof(double));
			m_visualizer.alpha = (double *)malloc(m_visualizer.opacityPoint*sizeof(double));
			m_visualizer.opacity->RemoveAllPoints();
			for (int k = 0,i = 0;k<6 || i<m_visualizer.opacityPoint;k++)
			{
				if (pcDlg->OPAFlag[k] == TRUE)
				{
					//::MessageBox(NULL,_T("OK"),_T("OK"),MB_OK);
					m_visualizer.opValue[i] = *(pcDlg->OPAPoints[k]);
					//double **RGB;
					//RGB = (double **)(new double[RGBPoint][3]);
					//m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
					//for (int i =0;i<m_visualizer.RGBPoint;i++)
					//{
						//*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
					//}
					//for (int i = 0;i<m_visualizer.RGBPoint;i++)
					//{
					m_visualizer.alpha[i] = *(pcDlg->OPA[k]);

					//}
					//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
					//for (int i=0;i<m_visualizer.RGBPoint;i++)
					//{
						m_visualizer.opacity->AddPoint(m_visualizer.opValue[i],m_visualizer.alpha[i]);
					//}
					i++;
				}
			}


			m_visualizer.scaleBar->SetNumberOfLabels(m_visualizer.RGBPoint);
			CRect rc;
			GetClientRect(rc);
			m_pvtkMFCWindow->RedrawWindow(rc);
		}
	}
}