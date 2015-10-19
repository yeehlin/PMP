// PMPScalarDatView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPScalarDatView.h"


// CPMPScalarDatView

IMPLEMENT_DYNCREATE(CPMPScalarDatView, CView)

CPMPScalarDatView::CPMPScalarDatView()
{
	this->m_pvtkMFCWindow = NULL;
	this->reader = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	this->isoDlg = NULL;
	this->pcDlg = NULL;
}

CPMPScalarDatView::~CPMPScalarDatView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (this->reader !=NULL)
	{
		reader->Delete();
	}
	if(isoDlg){
		delete isoDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPScalarDatView, CView)
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPScalarDatView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_VISUALIZE_ISOSURFACEVALUE, &CPMPScalarDatView::OnVisualizeIsosurfacevalue)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPScalarDatView::OnButtonBackground256)
	ON_COMMAND(ID_BUTTON_ISOSURFACE_256, &CPMPScalarDatView::OnButtonIsosurface256)
//	ON_COMMAND(ID_VISUALIZE_SCALEFACTOR, &CPMPScalarDatView::OnVisualizeScalefactor)
//	ON_COMMAND(ID_BUTTON_SCALEFACTOR_256, &CPMPScalarDatView::OnButtonScalefactor256)
ON_COMMAND(ID_VISUALIZE_POINTSCOLOR, &CPMPScalarDatView::OnVisualizePointscolor)
ON_COMMAND(ID_BUTTON_POINTS_COLOR_256, &CPMPScalarDatView::OnButtonPointsColor256)
END_MESSAGE_MAP()


// CPMPScalarDatView drawing

void CPMPScalarDatView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPScalarDatView diagnostics

#ifdef _DEBUG
void CPMPScalarDatView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPScalarDatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CPMPScalarDatDoc* CPMPScalarDatView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPScalarDatDoc)));
	return (CPMPScalarDatDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPScalarDatView message handlers


void CPMPScalarDatView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPScalarDatView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	CPMPScalarDatDoc* pDoc = GetDocument();
	GetParent()->SetWindowTextA(pDoc->GetTitle()+_T("-Scalar"));
	m_visualizer.PMPVisualizeScalar1D(filename,m_pvtkRenderer);
	// TODO: Add your specialized code here and/or call the base class
	ExecutePipeline();
}
static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPScalarDatView::ExecutePipeline()
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

void CPMPScalarDatView::pmpvisualizationisosurface(CString filename){
	//CString file_name = "grid.vtk";

	//CString filename;
	//printf("input the name of vtk file:\n");
	//scanf("%s",filename);
	//# Read the source file.
	reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
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
	vtkActor * actor = vtkActor::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(0,0,0);
	actor->GetProperty()->SetOpacity(0.5);
	//#actor->GetProperty()->SetRepresentationToSurface()

	vtkActor *actor1 = vtkActor::New();
	actor1->SetMapper(mapper1);

	vtkActor *actor2 = vtkActor::New();
	actor2->SetMapper(mapper2);

	//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
	//# Create the Renderer
	//vtkRenderer *renderer = vtkRenderer::New();
	m_pvtkRenderer->AddActor(actor);
	m_pvtkRenderer->AddActor(actor1);
	m_pvtkRenderer->AddActor(actor2);
	m_pvtkRenderer->SetBackground(1, 1, 1);
	//# Set background to white

	//# Create the RendererWindow
	//vtkRenderWindow * renderer_window = vtkRenderWindow::New();
	//renderer_window->AddRenderer(renderer);

	//# Create the RendererWindowInteractor and display the vtk_file
	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	//interactor->SetRenderWindow(renderer_window);
	//interactor->Initialize();
	//interactor->Start();

}

void CPMPScalarDatView::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	reader->Delete();
	CView::OnClose();
}


void CPMPScalarDatView::OnVisualizeBackgroundcolor()
{
	// TODO: Add your command handler code here
	//this->m_pvtkRenderer->SetBackground(0.0,0.0,0.0);
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


void CPMPScalarDatView::OnVisualizeIsosurfacevalue()
{
	// TODO: Add your command handler code here
	if(isoDlg == NULL){
		isoDlg = new CIsosurfaceDlg();
		isoDlg->m_caption +="-"+GetDocument()->GetTitle();
	}
	double minv = m_visualizer.m_Scalar1DRange0;
	double maxv = m_visualizer.m_Scalar1DRange1;
	double range = m_visualizer.m_Scalar1DRange;
	isoDlg->m_edit_min_iso_value_double = minv;
	isoDlg->m_edit_max_iso_value_double = maxv;
	isoDlg->m_edit_cur_iso_value_double = m_visualizer.m_Scalar1DIsoValue1;
	isoDlg->m_edit_cur_iso_value2 = m_visualizer.m_Scalar1DIsoValue2;
	if (isoDlg->DoModal()==IDOK)
	{
		m_visualizer.m_pScalar1DContour->SetValue(0,isoDlg->m_edit_cur_iso_value_double);
		m_visualizer.m_Scalar1DIsoValue1 = isoDlg->m_edit_cur_iso_value_double;
		m_visualizer.m_pScalar1DContour1->SetValue(0,isoDlg->m_edit_cur_iso_value2);
		m_visualizer.m_Scalar1DIsoValue2 = isoDlg->m_edit_cur_iso_value2;
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);

	}
}


void CPMPScalarDatView::OnButtonBackground256()
{
	// TODO: Add your command handler code here
	double m_dColorRed = 0.9 ;
	double  m_dColorGreen = 0.9;
	double m_dColorBlue = 0.9;
	COLORREF color = RGB(m_dColorRed*255, m_dColorGreen*255, m_dColorBlue*255);
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	// 设置对话框标题
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


void CPMPScalarDatView::OnButtonIsosurface256()
{
	// TODO: Add your command handler code here
	if(isoDlg == NULL){
		isoDlg = new CIsosurfaceDlg();
		isoDlg->m_caption +="-"+GetDocument()->GetTitle();
	}
	double minv = m_visualizer.m_Scalar1DRange0;
	double maxv = m_visualizer.m_Scalar1DRange1;
	double range = m_visualizer.m_Scalar1DRange;
	isoDlg->m_edit_min_iso_value_double = minv;
	isoDlg->m_edit_max_iso_value_double = maxv;
	isoDlg->m_edit_cur_iso_value_double = m_visualizer.m_Scalar1DIsoValue1;
	isoDlg->m_edit_cur_iso_value2 = m_visualizer.m_Scalar1DIsoValue2;
	isoDlg->m_edit_cur_opa_value_double = m_visualizer.m_Scalar1DIso1Opacity;
	isoDlg->m_edit_cur_opa_value2_double = m_visualizer.m_Scalar1DIso2Opacity;
	if (isoDlg->DoModal()==IDOK)
	{
		m_visualizer.m_pScalar1DContour->SetValue(0,isoDlg->m_edit_cur_iso_value_double);
		m_visualizer.m_Scalar1DIsoValue1 = isoDlg->m_edit_cur_iso_value_double;
		m_visualizer.m_pScalar1DContour1->SetValue(0,isoDlg->m_edit_cur_iso_value2);
		m_visualizer.m_Scalar1DIsoValue2 = isoDlg->m_edit_cur_iso_value2;
		m_visualizer.m_pScalar1Dactor1->GetProperty()->SetOpacity(isoDlg->m_edit_cur_opa_value_double);
		m_visualizer.m_Scalar1DIso1Opacity = isoDlg->m_edit_cur_opa_value_double;
		m_visualizer.m_pScalar1Dactor2->GetProperty()->SetOpacity(isoDlg->m_edit_cur_opa_value2_double);
		m_visualizer.m_Scalar1DIso2Opacity = isoDlg->m_edit_cur_opa_value2_double;
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);

	}
}


//void CPMPScalarDatView::OnVisualizeScalefactor()
//{
//	// TODO: Add your command handler code here
//}


//void CPMPScalarDatView::OnButtonScalefactor256()
//{
//	// TODO: Add your command handler code here
//}


void CPMPScalarDatView::OnVisualizePointscolor()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}


void CPMPScalarDatView::OnButtonPointsColor256()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}

void CPMPScalarDatView::SetPointColor(){
		if(pcDlg == NULL){
		pcDlg = new CPointsColorDlg();
		pcDlg->m_cation +="-"+GetDocument()->GetTitle();
	}
	
	double minv = m_visualizer.m_Scalar1DRange0;
	double maxv = m_visualizer.m_Scalar1DRange1;
	double range = m_visualizer.m_Scalar1DRange;
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

	//for (int i =0;i<m_visualizer.opacityPoint;i++)
	//{
		//*(pcDlg->OPAPoints[i]) = m_visualizer.opValue[i];
		//*(pcDlg->OPA [i]) = m_visualizer.alpha[i];
	//}
	
	if (pcDlg->DoModal() == IDOK)
	{
		m_visualizer.RGBPoint = pcDlg->RGBnPoints;
		if (m_visualizer.RGBPoint != 0)
		{
			
			m_visualizer.RGBValue = (double *)malloc(m_visualizer.RGBPoint*sizeof(double));
			m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
			m_visualizer.m_pScalar1Dcolor->RemoveAllPoints();
			for (int i =0;i<m_visualizer.RGBPoint;i++)
			{
				*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
			}
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
						m_visualizer.m_pScalar1Dcolor->AddRGBPoint(m_visualizer.RGBValue[i],m_visualizer.RGB[i][0],m_visualizer.RGB[i][1],m_visualizer.RGB[i][2]);
					//}
					i++;
				}
			}

			CRect rc;
			GetClientRect(rc);
			m_pvtkMFCWindow->RedrawWindow(rc);
		}
	}
}