#pragma once

#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkActor2D.h>
#include <vtkTextMapper.h>
#include <vtkRenderer.h>
#include <vtkWin32OpenGLRenderWindow.h>
#include <vtkWin32RenderWindowInteractor.h>
#include <vtkTextProperty.h>
#include "vtkMFCWindow.h"

#include "DlgVTKChild.h"

// DlgVTKFather dialog

class DlgVTKFather : public CDialog
{
	DECLARE_DYNAMIC(DlgVTKFather)

public:
	DlgVTKFather(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgVTKFather();

// Dialog Data
	enum { IDD = IDD_DIALOG_VTK_FATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	void ExecutePipeline();

	vtkMFCWindow *pvtkMFCWindow;
	vtkDataSetReader *pvtkDataSetReader;
	vtkRenderer *pvtkRenderer;
	vtkDataSetMapper *pvtkDataSetMapper;
	vtkActor *pvtkActor;
	vtkActor2D *pvtkActor2D;
	vtkTextMapper *pvtkTextMapper;

	POINT  ptBorder;
	HICON  m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonFile();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void PMPTransformToVTKForIsosurface(CString filename);
	bool initVTK();
	CTabCtrl m_TabVtkFather;
	DlgVTKChild * m_pdlgVTKChild;
};
