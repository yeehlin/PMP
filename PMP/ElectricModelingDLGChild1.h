#pragma once

#include "ElectricModelingDLGMoreElastic.h"
#include "ElectricModelingDLGMoreDielectric.h"
#include "ElectricModelingDLGMorePiezoelectric.h"
#include "ElectricModelingDLGMoreMagnetic.h"
#include "ElectricModelingDLGMorePiezomagnetic.h"
#include "ElectricModelingDLGMoreMagnetoelectric.h"
#include "ElectricModelingDLGMoreDiffusivity.h"
#include "ElectricModelingDLGMoreThermal.h"
//#include "ElectricModelingDLGExternal.h"

#include "ElectricModelingDLGElasticExternal.h"
#include "ElectricModelingDLGDielectricExternal.h"
#include "ElectricModelingDLGPiezoelectricExternal.h"
#include "ElectricModelingDLGMagneticExternal.h"
#include "ElectricModelingDLGPiezomagneticExternal.h"
#include "ElectricModelingDLGMagnetoelectricExternal.h"
#include "ElectricModelingDLGDiffusivityExternal.h"
#include "ElectricModelingDLGThermalExternal.h"

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

#include "vtkCallbackCommand.h"


// ElectricModelingDLGChild1 dialog

class ElectricModelingDLGChild1 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGChild1)

public:
	ElectricModelingDLGChild1(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGChild1();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_CHILD1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboSysType;
	CComboBox m_ComboFileFormat;
	CComboBox m_ComboSimulationType;
	virtual BOOL OnInitDialog();
	int m_edit_nums_phases;
	CSpinButtonCtrl m_SpinNumsPhases;
	afx_msg void OnCbnSelchangeComboSysType();
	afx_msg void OnBnClickedButtonMore();
	afx_msg void OnDeltaposSpinNumsPhases(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditNumsPhases();
	CString m_combo_sys_type;
	int m_edit_mesh_nx;
	int m_edit_mesh_ny;
	int m_edit_mesh_nz;
	int m_edit_size_lx;
	int m_edit_size_ly;
	int m_edit_size_lz;
	int ns;
	int nf;
	afx_msg void OnEnChangeEditSizeLy();
	CString m_combo_file_format;
	CString m_combo_simulation_type;
	// 用于回填而持有对象
	//ElectricModelingDLGMoreElastic electricModelingDLGMoreElastic;
	//ElectricModelingDLGMoreDielectric electricModelingDLGMoreDielectric;
	//ElectricModelingDLGMorePiezoelectric electricModelingDLGMorePiezoelectric;
	// 持有对象的的优化，动态内存
	ElectricModelingDLGMoreElastic * m_pelectricModelingDLGMoreElastic;
	ElectricModelingDLGMoreDielectric * m_pelectricModelingDLGMoreDielectric;
	ElectricModelingDLGMorePiezoelectric * m_pelectricModelingDLGMorePiezoelectric;
	ElectricModelingDLGMoreMagnetic * m_pelectricModelingDLGMoreMagnetic;
	ElectricModelingDLGMorePiezomagnetic * m_pelectricModelingDLGMorePiezomagnetic;
	ElectricModelingDLGMoreMagnetoelectric * m_pelectricModelingDLGMoreMagnetoelectric;
	ElectricModelingDLGMoreDiffusivity * m_pelectricModelingDLGMoreDiffusivity;
	ElectricModelingDLGMoreThermal * m_pelectricModelingDLGMoreThermal;

	//ElectricModelingDLGExternal * m_pelectricModelingDLGExternal;

	ElectricModelingDLGElasticExternal * m_pelectricModelingDLGElasticExternal;
	ElectricModelingDLGDielectricExternal * m_pelectricModelingDLGDielectricExternal;
	ElectricModelingDLGPiezoelectricExternal * m_pelectricModelingDLGPiezoelectricExternal;
	ElectricModelingDLGMagneticExternal * m_pelectricModelingDLGMagneticExternal;
	ElectricModelingDLGPiezomagneticExternal * m_pelectricModelingDLGPiezomagneticExternal;
	ElectricModelingDLGMagnetoelectricExternal * m_pelectricModelingDLGMagnetoelectricExternal;
	ElectricModelingDLGDiffusivityExternal * m_pelectricModelingDLGDiffusivityExternal;
	ElectricModelingDLGThermalExternal * m_pelectricModelingDLGThermalExternal;

	int m_combo_simulation_type_int;
	afx_msg void OnBnClickedOk();
	int m_combo_sys_type_int;
	int m_combo_file_format_int;
	afx_msg void OnCbnSelchangeComboSimulationType();
	//CComboBox m_ComboMechanicalBoundary;
	//CString m_combo_mechanical_boudary_string;
	//int m_combo_mechnical_boundary_int;
	afx_msg void OnBnClickedButtonSelectFile();
	CEdit m_EditFilePath;
	CTabCtrl m_TabChild1;

public:
	void ExecutePipeline();
	// 数据载体
	vtkDataSetReader * reader;
	vtkActor * actor;
	vtkActor *actor1;
	vtkActor *actor2;
	// 负责显示
	vtkMFCWindow          *pvtkMFCWindow;

	vtkDataSetReader        *pvtkDataSetReader;
	vtkRenderer            *pvtkRenderer;
	vtkDataSetMapper        *pvtkDataSetMapper;
	vtkActor            *pvtkActor;
	vtkActor2D            *pvtkActor2D;
	vtkTextMapper          *pvtkTextMapper;

	POINT  ptBorder;
	HICON  m_hIcon;

	bool initVTK();
	void PMPTransformToVTKForIsosurface(CString filename);
};
