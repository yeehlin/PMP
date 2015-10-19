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
		m_ctrlRichEdit->MoveWindow( rcClient );// �ı�༭�ؼ����ڴ�С 
}


void CPMPTxtView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetParent()->SetWindowTextA(GetDocument()->GetTitle());
	// TODO: Add your specialized code here and/or call the base class
	CRect rcClient;GetClientRect( rcClient );// ��ȡ��ǰ��ͼ�Ŀͻ�����С
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
	//	str = str + "\r\n";// ����
	//}
	//m_ctrlEdit->SetTabStops( 16 ); // ����Tab����С
	m_ctrlRichEdit->SetWindowText( pDoc->m_text );// ���ĵ����ݴ����ؼ�
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

	// �ж�������vector���ͻ���tensor����
	CStdioFile datafile;
	datafile.Open(pathname,CFile::modeRead | CFile::shareDenyNone| CFile::typeText);
	CString datatype;
	CString datatype2;
	// �����һ�У��Ա����ڶ���
	datafile.ReadString(datatype);
	// ����ڶ��У��Ա��ж���������
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

		// scalar����
		if(in2 == 4){
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 1;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// ����Scalar1Dͼ
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pScalarDatDocTemplate;
					if (!PathFileExists(pathname+"Scalar1D.vtk"))
					{
						m_transformer.PMPTransformToVTKForScalar1D(pathname,outfilename);
					}else{
						outfilename = pathname+"Scalar1D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// ����Volumeͼ
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
		}else if (in2 == 6)// vector����
		{
			// 
			//MessageBox(_T("Vector����"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 2;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// ����Vector3Dͼ
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocTemplate;
					if (!PathFileExists(pathname+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathname,outfilename);
					}else{
							outfilename = pathname+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// ����Vector3D Streamlineͼ
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pDatDocStrmlineTemplate;
					if (!PathFileExists(pathname+"Vector3D.vtk"))
					{
						m_transformer.PMPTransformToVTKForVector3D(pathname,outfilename);
					}else{
						outfilename = pathname+"Vector3D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);
				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// ����Vector3D volumeͼ
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
		}else if (in2 == 9)// tensor����
		{

			//MessageBox(_T("tensor����"));
			CPMPVisualizationDLG visualizedlg ;
			visualizedlg.m_visualization_type = 3;
			visualizedlg.m_caption = _T("Visualization type : " + str);
			if (visualizedlg.DoModal() ==IDOK)
			{
				if (visualizedlg.m_list_visualizationtype_int == 0)
				{
					// ����tensorͼ
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocTensoTemplate;
					if (!PathFileExists(pathname+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathname,outfilename);
					}else{
						outfilename=pathname+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 1){
					// ����multiviewͼ
					CMultiDocTemplate  *docTemplate = ((CPMPApp * )AfxGetApp())->m_pTensorDatDocMultiTemplate;
					if (!PathFileExists(pathname+"Tensor33D.vtk"))
					{
						m_transformer.PMPTransformToVTKForTensor33D(pathname,outfilename);
					}else{
						outfilename=pathname+"Tensor33D.vtk";
					}
					docTemplate->OpenDocumentFile(outfilename);

				}else if(visualizedlg.m_list_visualizationtype_int == 2){
					// ����Tensorͼ
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