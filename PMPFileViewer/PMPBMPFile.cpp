// PMPBMPFile.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "PMPBMPFile.h"


#include "vtkActor2D.h"
#include "vtkTextMapper.h"
#include "vtkBMPReader.h"
#include "vtkImageActor.h"
#include "vtkTextProperty.h"

// for visualization
#include "vtkDataSetReader.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCommand.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkPointData.h"
#include "vtkContourFilter.h"
#include "vtkDataSetMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkArrowSource.h"
#include "vtkMaskPoints.h"
#include "vtkOutlineFilter.h"
#include "vtkGlyph3D.h"
#include "vtkTransform.h"
#include "vtkAxesActor.h"
#include "vtkCaptionActor2D.h"
#include "vtkProperty2D.h"
#include "vtkLookupTable.h"
#include "vtkSmartVolumeMapper.h"
#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"

#include "PMPFileViewerView.h"

#include "stdio.h"
#include "malloc.h"

#define MAX_POINTS 110592
#define DATA_TYPE float

// CPMPBMPFile

IMPLEMENT_DYNCREATE(CPMPBMPFile, CDocument)

CPMPBMPFile::CPMPBMPFile()
{
}

BOOL CPMPBMPFile::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPBMPFile::~CPMPBMPFile()
{
}


BEGIN_MESSAGE_MAP(CPMPBMPFile, CDocument)
END_MESSAGE_MAP()


// CPMPBMPFile diagnostics

#ifdef _DEBUG
void CPMPBMPFile::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPBMPFile::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPBMPFile serialization

void CPMPBMPFile::Serialize(CArchive& ar)
{
	CString str;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		int nLines = (int)m_textContent.GetSize();
		for(int i=0; i<nLines; i++ ) 
		{
			str = m_textContent.GetAt( i );
			ar.WriteString( str ); // 将字符串集合类对象中文本保存到硬盘
		}

	}
	else
	{
		// TODO: add loading code here
		//CString str = ar.GetFile()->GetFileName().Right(3);
		if(ar.GetFile()->GetLength()<1024){

			while(ar.ReadString(m_text)){
				m_textContent.Add(m_text);
			}
		}else{
			::MessageBox(NULL,_T("Too large to open"),_T("Message"),MB_OK);
		}
	}
}
#endif


// CPMPBMPFile commands


void CPMPBMPFile::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	m_textContent.RemoveAll();
	CDocument::DeleteContents();
}
