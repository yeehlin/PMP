#pragma once

#include "PMPTransformer.h"

// CPMPTensorDatDoc document

class CPMPTensorDatDoc : public CDocument
{
	DECLARE_DYNCREATE(CPMPTensorDatDoc)

public:
	CPMPTensorDatDoc();
	virtual ~CPMPTensorDatDoc();
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
	// ����ת���ӿ�
	CPMPTransformer m_transformer;
	// ��ʾ��ʽ
	int m_viewType;

	CString filename;
};
