#pragma once

// CPMPTxtDoc document

class CPMPTxtDoc : public CDocument
{
	DECLARE_DYNCREATE(CPMPTxtDoc)

public:
	CPMPTxtDoc();
	virtual ~CPMPTxtDoc();
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
	CString m_text;
	CStringArray m_textContent;
	virtual void DeleteContents();
	CString m_PathName;
	CString m_realfilename;
};
