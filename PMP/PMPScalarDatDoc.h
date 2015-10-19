#pragma once

#include "PMPTransformer.h"

// CPMPScalarDatDoc document

class CPMPScalarDatDoc : public CDocument
{
	DECLARE_DYNCREATE(CPMPScalarDatDoc)

public:
	CPMPScalarDatDoc();
	virtual ~CPMPScalarDatDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();
	DECLARE_MESSAGE_MAP()
public :
	// 数据转换接口
	CPMPTransformer m_transformer;
	// 显示样式
	int m_viewType;
	CString filename;
};
