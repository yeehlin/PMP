// PMPTensorDatMultiView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTensorDatMultiView.h"

#include "PMPTensorDatDoc.h"

// CPMPTensorDatMultiView

IMPLEMENT_DYNCREATE(CPMPTensorDatMultiView, CView)

CPMPTensorDatMultiView::CPMPTensorDatMultiView()
{
	this->m_pvtkMFCWindow = NULL;
	//this->m_pvtkRenderer = vtkRenderer::New();
	renderer11 = vtkRenderer::New();
	renderer12 = vtkRenderer::New();
	renderer13 = vtkRenderer::New();
	renderer21 = vtkRenderer::New();
	renderer22 = vtkRenderer::New();
	renderer23 = vtkRenderer::New();
	renderer31 = vtkRenderer::New();
	renderer32 = vtkRenderer::New();
	renderer33 = vtkRenderer::New();

	// 将上述对象放置到数组中
	rendererArray[0] = renderer11;
	rendererArray[1] = renderer12;
	rendererArray[2] = renderer13;
	rendererArray[3] = renderer21;
	rendererArray[4] = renderer22;
	rendererArray[5] = renderer23;
	rendererArray[6] = renderer31;
	rendererArray[7] = renderer32;
	rendererArray[8] = renderer33;

	pcDlg = NULL;
}

CPMPTensorDatMultiView::~CPMPTensorDatMultiView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	//if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (renderer11){renderer11->Delete();}
	if (renderer12){renderer12->Delete();}
	if (renderer13){renderer13->Delete();}
	if (renderer21){renderer21->Delete();}
	if (renderer22){renderer22->Delete();}
	if (renderer23){renderer23->Delete();}
	if (renderer31){renderer31->Delete();}
	if (renderer32){renderer32->Delete();}
	if (renderer33){renderer33->Delete();}
	if (pcDlg != NULL)
	{
		delete pcDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPTensorDatMultiView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPTensorDatMultiView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPTensorDatMultiView::OnButtonBackground256)
	ON_COMMAND(ID_VISUALIZE_POINTSCOLOR, &CPMPTensorDatMultiView::OnVisualizePointscolor)
	ON_COMMAND(ID_BUTTON_POINTS_COLOR_256, &CPMPTensorDatMultiView::OnButtonPointsColor256)
END_MESSAGE_MAP()


// CPMPTensorDatMultiView drawing

void CPMPTensorDatMultiView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPTensorDatMultiView diagnostics

#ifdef _DEBUG
void CPMPTensorDatMultiView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPTensorDatMultiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CPMPTensorDatDoc* CPMPTensorDatMultiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPTensorDatDoc)));
	return (CPMPTensorDatDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPTensorDatMultiView message handlers
static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPTensorDatMultiView::ExecutePipeline()
{
	if (this->m_pvtkMFCWindow == NULL){
		this->m_pvtkMFCWindow = new vtkMFCWindow(this);
	}
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	//this->m_pvtkRenderer->SetBackground(0.9,0.9,0.9);
	renderer11->SetBackground(0.9,0.9,0.9);
		renderer12->SetBackground(0.9,0.9,0.9);
		renderer13->SetBackground(0.9,0.9,0.9);
		renderer21->SetBackground(0.9,0.9,0.9);
		renderer22->SetBackground(0.9,0.9,0.9);
		renderer23->SetBackground(0.9,0.9,0.9);
		renderer31->SetBackground(0.9,0.9,0.9);
		renderer32->SetBackground(0.9,0.9,0.9);
		renderer33->SetBackground(0.9,0.9,0.9);

	this->m_pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	//this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->m_pvtkRenderer);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer11);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer12);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer13);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer21);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer22);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer23);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer31);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer32);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer33);
	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->m_pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}

void CPMPTensorDatMultiView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPTensorDatMultiView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetParent()->SetWindowTextA(GetDocument()->GetTitle()+_T("-Multiview"));
	CPMPTensorDatDoc* pDoc = GetDocument();
	m_visualizer.PMPVisualizeTensor33DMultiview(filename,rendererArray);
	ExecutePipeline();

}

void CPMPTensorDatMultiView::pmpvisualizationmultiview(CString filename){

	//CString filename;
	//printf("input the name of vtk file:\n");
	//scanf("%s",filename);

	//# Read the source file.
	vtkDataSetReader * reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
	reader->Update();
	vtkDataSet * id = reader->GetOutput();
	float scalar_range[2]={10e-8,0.0001};

	//#Reduce the amount of points to be plotted, using maskPoints
	vtkMaskPoints * mask = vtkMaskPoints::New();
	mask->SetInputConnection(reader->GetOutputPort());
	mask->SetOnRatio(2);
	mask->SetMaximumNumberOfPoints(10000000);
	mask->RandomModeOn();
	mask->Update();

	//#Making tensor glyph with superquadratic glyph

	vtkExtractTensorComponents * tensor11=vtkExtractTensorComponents::New();
	tensor11->SetInputConnection(reader->GetOutputPort());
	tensor11->ExtractScalarsOn();
	tensor11->PassTensorsToOutputOff();
	tensor11->SetScalarComponents(0,0);
	tensor11->Update();
	std::cout<<(tensor11->GetOutput());

	vtkExtractTensorComponents * tensor12=vtkExtractTensorComponents::New();
	tensor12->SetInputConnection(reader->GetOutputPort());
	tensor12->ExtractScalarsOn();
	tensor12->SetScalarComponents(0,1);

	vtkExtractTensorComponents * tensor13=vtkExtractTensorComponents::New();
	tensor13->SetInputConnection(reader->GetOutputPort());
	tensor13->ExtractScalarsOn();
	tensor13->SetScalarComponents(0,2);

	vtkExtractTensorComponents * tensor22=vtkExtractTensorComponents::New();
	tensor22->SetInputConnection(reader->GetOutputPort());
	tensor22->ExtractScalarsOn();
	tensor22->SetScalarComponents(1,1);

	vtkExtractTensorComponents * tensor23=vtkExtractTensorComponents::New();
	tensor23->SetInputConnection(reader->GetOutputPort());
	tensor23->ExtractScalarsOn();
	tensor23->SetScalarComponents(1,2);

	vtkExtractTensorComponents * tensor33=vtkExtractTensorComponents::New();
	tensor33->SetInputConnection(reader->GetOutputPort());
	tensor33->ExtractScalarsOn();
	tensor33->SetScalarComponents(2,2);
	//#tensor glyph mapper
	vtkSmartVolumeMapper * mapper11 = vtkSmartVolumeMapper::New();
	mapper11->SetInputConnection(tensor11->GetOutputPort());

	vtkSmartVolumeMapper * mapper12 = vtkSmartVolumeMapper::New();
	mapper12->SetInputConnection(tensor12->GetOutputPort());
	vtkSmartVolumeMapper * mapper13 = vtkSmartVolumeMapper::New();
	mapper13->SetInputConnection(tensor13->GetOutputPort());
	vtkSmartVolumeMapper * mapper22 = vtkSmartVolumeMapper::New();
	mapper22->SetInputConnection(tensor22->GetOutputPort());
	vtkSmartVolumeMapper * mapper23 = vtkSmartVolumeMapper::New();
	mapper23->SetInputConnection(tensor23->GetOutputPort());
	vtkSmartVolumeMapper * mapper33 = vtkSmartVolumeMapper::New();
	mapper33->SetInputConnection(tensor33->GetOutputPort());


	vtkColorTransferFunction * colormap=vtkColorTransferFunction::New();
	colormap->SetColorSpaceToDiverging();
	colormap->AddRGBPoint(scalar_range[0],0,0,1);
	colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/4,0,1,0);
	colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,1,0,0);
	colormap->Build();
	//# mapper11->SetLookupTable(colormap)
	//# mapper12->SetLookupTable(colormap)
	//# mapper13->SetLookupTable(colormap)
	//# mapper21->SetLookupTable(colormap)


	vtkVolume * actor11 = vtkVolume::New();
	actor11->SetMapper(mapper11);
	vtkVolume * actor12 = vtkVolume::New();
	actor12->SetMapper(mapper12);
	vtkVolume * actor13 = vtkVolume::New();
	actor13->SetMapper(mapper13);
	vtkVolume * actor21 = vtkVolume::New();
	actor21->SetMapper(mapper12);
	vtkVolume * actor22 = vtkVolume::New();
	actor22->SetMapper(mapper22);
	vtkVolume * actor23 = vtkVolume::New();
	actor23->SetMapper(mapper23);
	vtkVolume * actor31 = vtkVolume::New();
	actor31->SetMapper(mapper13);
	vtkVolume * actor32 = vtkVolume::New();
	actor32->SetMapper(mapper23);
	vtkVolume * actor33 = vtkVolume::New();
	actor33->SetMapper(mapper33);



	vtkVolumeProperty * volumeProperty=vtkVolumeProperty::New();
	vtkColorTransferFunction * color=vtkColorTransferFunction::New();
	color->SetColorSpaceToLab();
	color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
	color->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,0,1,0);
	color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);
	volumeProperty->SetColor(color);
	volumeProperty->SetInterpolationTypeToNearest();

	actor11->SetProperty(volumeProperty);
	actor12->SetProperty(volumeProperty);
	actor13->SetProperty(volumeProperty);
	actor21->SetProperty(volumeProperty);
	actor22->SetProperty(volumeProperty);
	actor23->SetProperty(volumeProperty);
	actor31->SetProperty(volumeProperty);
	actor32->SetProperty(volumeProperty);
	actor33->SetProperty(volumeProperty);

	//#create the outer boundary of the data
	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInput(reader->GetOutput());
	vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	vtkActor * outlineActor=vtkActor::New();
	outlineActor->SetMapper(outlineMapper);
	outlineActor->GetProperty()->SetColor(0,0,0);



	double xmins[3]={0,0.333333,0.666667};
	double xmaxs[3]={0.333333,0.666667,1};
	double ymins[3]={0,0.333333,0.666667};
	double ymaxs[3]={0.333333,0.666667,1};

	vtkCamera *camera=vtkCamera::New();
	camera->SetPosition(0,0,100);
	camera->SetFocalPoint(0,0,0);
	//vtkRenderer * renderer11 = vtkRenderer::New();
	//vtkRenderer * renderer12 = vtkRenderer::New();
	//vtkRenderer * renderer13 = vtkRenderer::New();
	//vtkRenderer * renderer21 = vtkRenderer::New();
	//vtkRenderer * renderer22 = vtkRenderer::New();
	//vtkRenderer * renderer23 = vtkRenderer::New();
	//vtkRenderer * renderer31 = vtkRenderer::New();
	//vtkRenderer * renderer32 = vtkRenderer::New();
	//vtkRenderer * renderer33 = vtkRenderer::New();

	renderer11->SetActiveCamera(camera);
	renderer12->SetActiveCamera(camera);
	renderer13->SetActiveCamera(camera);
	renderer21->SetActiveCamera(camera);
	renderer22->SetActiveCamera(camera);
	renderer23->SetActiveCamera(camera);
	renderer31->SetActiveCamera(camera);
	renderer32->SetActiveCamera(camera);
	renderer33->SetActiveCamera(camera);

	renderer11->SetViewport(xmins[0],ymins[2],xmaxs[0],ymaxs[2]);
	renderer12->SetViewport(xmins[1],ymins[2],xmaxs[1],ymaxs[2]);
	renderer13->SetViewport(xmins[2],ymins[2],xmaxs[2],ymaxs[2]);
	renderer21->SetViewport(xmins[0],ymins[1],xmaxs[0],ymaxs[1]);
	renderer22->SetViewport(xmins[1],ymins[1],xmaxs[1],ymaxs[1]);;
	renderer23->SetViewport(xmins[2],ymins[1],xmaxs[2],ymaxs[1]);
	renderer31->SetViewport(xmins[0],ymins[0],xmaxs[0],ymaxs[0]);
	renderer32->SetViewport(xmins[1],ymins[0],xmaxs[1],ymaxs[0]);
	renderer33->SetViewport(xmins[2],ymins[0],xmaxs[2],ymaxs[0]);

	renderer11->AddActor(actor11);
	renderer11->AddActor(outlineActor);
	renderer11->SetBackground(1, 1, 1); //# Set background to white

	renderer12->AddActor(actor12);
	renderer12->AddActor(outlineActor);
	renderer12->SetBackground(1, 1, 1); //# Set background to white

	renderer13->AddActor(actor13);
	renderer13->AddActor(outlineActor);
	renderer13->SetBackground(1, 1, 1) ;//# Set background to white

	renderer21->AddActor(actor21);
	renderer21->AddActor(outlineActor);
	renderer21->SetBackground(1, 1, 1); //# Set background to white

	renderer22->AddActor(actor22);
	renderer22->AddActor(outlineActor);
	renderer22->SetBackground(1, 1, 1) ;//# Set background to white

	renderer23->AddActor(actor23);
	renderer23->AddActor(outlineActor);
	renderer23->SetBackground(1, 1, 1) ;//# Set background to white

	renderer31->AddActor(actor31);
	renderer31->AddActor(outlineActor);
	renderer31->SetBackground(1, 1, 1) ;//# Set background to white

	renderer32->AddActor(actor32);
	renderer32->AddActor(outlineActor);
	renderer32->SetBackground(1, 1, 1); //# Set background to white

	renderer33->AddActor(actor33);
	renderer33->AddActor(outlineActor);
	renderer33->SetBackground(1, 1, 1) ;//# Set background to white

	//vtkRenderWindow * renWin = vtkRenderWindow::New();
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer11);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer12);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer13);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer21);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer22);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer23);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer31);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer32);
	//m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(renderer33);

	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New() ;
	//interactor->SetRenderWindow(renWin);

	//interactor->Initialize();

	//renWin->Render();

	//interactor->Start();
}

void CPMPTensorDatMultiView::OnVisualizeBackgroundcolor()
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
	renderer11->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer12->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer13->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer21->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer22->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer23->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer31->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer32->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer33->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPTensorDatMultiView::OnButtonBackground256()
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
	renderer11->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer12->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer13->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer21->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer22->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer23->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer31->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer32->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	renderer33->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPTensorDatMultiView::OnVisualizePointscolor()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}


void CPMPTensorDatMultiView::OnButtonPointsColor256()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}
void CPMPTensorDatMultiView::SetPointColor(){
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