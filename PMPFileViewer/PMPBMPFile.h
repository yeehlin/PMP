#pragma once

// CPMPBMPFile document

class CPMPBMPFile : public CDocument
{
	DECLARE_DYNCREATE(CPMPBMPFile)

public:
	CPMPBMPFile();
	virtual ~CPMPBMPFile();
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
};
