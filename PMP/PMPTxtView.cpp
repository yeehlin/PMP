// PMPTxtView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTxtView.h"

#include "PMPVisualizationDLG.h"

// CPMPTxtView

IMPLEMENT_DYNCREATE(CPMPTxtView, CView)

CPMPTxtView::CPMPTxtView()
{

	m_ctrlRichEdit = NULL;
}

CPMPTxtView::~CPMPTxtView()
{
	if (m_ctrlRichEdit != NULL){
		delete m_ctrlRichEdit;
	}
}

BEGIN_MESSAGE_MAP(CPMPTxtView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_VISUALIZATION, &CPMPTxtView::OnVisualizeVisualization)
	ON_COMMAND(ID_BUTTON_VISUALIZATION_256, &CPMPTxtView::OnButtonVisualization256)
END_MESSAGE_MAP()


// CPMPTxtView drawing

void CPMPTxtView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CPMPTxtView diagnostics

#ifdef _DEBUG
void CPMPTxtView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPTxtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif

CPMPTxtDoc* CPMPTxtView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPTxtDoc)));
	return (CPMPTxtDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPTxtView message handlers


void CPMPTxtView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CRect rcClient;
	GetClientRect(rcClient );
	if ( m_ctrlRichEdit )
		m_ctrlRichEdit->MoveWindow( rcClient );// 改变编辑控件窗口大小 
}


void CPMPTxtView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowTextA(GetDocument()->GetTitle());
	// TODO: Add your specialized code here and/or call the base class
	CRect rcClient;GetClientRect( rcClient );// 获取当前视图的客户区大小
	// if ( m_ctrlEdit ) delete m_ctrlEdit;
	if (m_ctrlRichEdit == NULL){
		m_ctrlRichEdit = new CRichEditCtrl();
	}
	m_ctrlRichEdit->Create( ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_HSCROLL | ES_AUTOHSCROLL| WS_VSCROLL | ES_AUTOVSCROLL ,rcClient, this, 201);
	CPMPTxtDoc * pDoc=GetDocument();
	//CString str;
	//int nLines = (int)pDoc->m_textContent.GetSize();
	//for ( int i=0; i<nLines; i++ ) 
	//{
	//	str = str + pDoc->m_textContent.GetAt( i );
	//	str = str + "\r\n";// 换行
	//}
	//m_ctrlEdit->SetTabStops( 16 ); // 设置Tab符大小
	m_ctrlRichEdit->SetWindowText( pDoc->m_text );// 将文档内容传给控件
}


void CPMPTxtView::OnVisualizeVisualization()
{
	// TODO: Add your command handler code here
	TextVisualization();
}


void CPMPTxtView::OnButtonVisualization256()
{
	// TODO: Add your command handler code here
	TextVisualization();
}

void CPMPTxtView::TextVisualization(){
	CString pathname = ((CPMPTxtDoc * )GetDocument())->m_PathName;
	CString outfilename;
	CString str = ((CPMPTxtDoc * )GetDocument())->m_realfilename;

	// 判断数据是vector类型还是tensor类型
	CStdioFile datafile;
	datafile.Open(pathname,CFile::modeRead | CFile::shareDenyNone| CFile::typeText);
	CString datatype;
	CString datatype2;
	// 读入第一行，以便读入第二行
	datafile.ReadString(datatype);
	// 读入第二行，以便判断数据类型
	datafile.ReadString(datatype2);
	datafile.Close();
	datatype.Trim();
	datatype2.Trim();
	int in=0;
	int in2=0;
	char *p[20];
	char *p2[20];
	char *buf = (LPSTR)(LPCTSTR)datatype;
	char *buf2 = (LPSTR)(LPCTSTR)datatype2;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	while((p2[in2]=strtok(buf2," "))!=NULL) {
		in2++;
		buf2=NULL; }
	if (in ==3)
	{

		// scalar类型
		if(in2 == 4){
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 1;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制Scalar1D图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pScalarDatDocTemplate;
					if (!PathFileExists(pathname+"Scalar1D.vtk"))
					{
						m_transformer.PMPTransformToVTKForScalar1D(pathname,outfilename);
					}else{
						outfilename = pathname+"Scalar1D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制Volume图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pScalarDatDocGridTemplate;
					if (!PathFileExists(pathname+"Scalar1D1.vtk"))
					{
						m_transformer.PMPTransformToVTKForVolume(pathname,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename=pathname+"Scalar1D1.vtk";
					}
					//m_transformer.PMPTransformToVTKForVolume(pathname,visualizedlg.m_combo_volume_int+1,outfilename);
					docTemplate->OpenDocumentFile(outfilename);

				}
			}
		}else if (in2 == 6)// vector类型
		{
			// 
			//MessageBox(_T("Vector类型"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 2;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制Vector3D图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocTemplate;
					if (!PathFileExists(pathname+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathname,outfilename);
					}else{
							outfilename = pathname+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制Vector3D Streamline图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocStrmlineTemplate;
					if (!PathFileExists(pathname+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathname,outfilename);
					}else{
						outfilename = pathname+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// 绘制Vector3D volume图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocVolumeTemplate;
					CString temppathname;
					temppathname.Format("%s%s%d%s",pathname,"Vector3D",visualizedlg.m_combo_volume_int+1,".vtk");
					if (!PathFileExists(temppathname))
					{
						m_transformer.PMPTransformToVTKForVolume(pathname,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename=temppathname;
					}
					docTemplate->OpenDocumentFile(outfilename);
				}

			}
		}else if (in2 == 9)// tensor类型
		{

			//MessageBox(_T("tensor类型"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 3;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// 绘制tensor图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocTensoTemplate;
					if (!PathFileExists(pathname+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathname,outfilename);
					}else{
						outfilename=pathname+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// 绘制multiview图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocMultiTemplate;
					if (!PathFileExists(pathname+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathname,outfilename);
					}else{
						outfilename=pathname+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// 绘制Tensor图
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocTemplate;
					CString temppathname;
					temppathname.Format("%s%s%d%s",pathname,"Tensor33D",visualizedlg.m_combo_volume_int+1,".vtk");
					if (!PathFileExists(temppathname))
					{
						m_transformer.PMPTransformToVTKForVolume(pathname,visualizedlg.m_combo_volume_int+1,outfilename);
					}else{
						outfilename = temppathname;
					}
					docTemplate->OpenDocumentFile(outfilename);
				}

			}
		}
	}
}