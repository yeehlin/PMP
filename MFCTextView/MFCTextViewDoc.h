
// MFCTextViewDoc.h : interface of the CMFCTextViewDoc class
//


#pragma once


class CMFCTextViewDoc : public CDocument
{
protected: // create from serialization only
	CMFCTextViewDoc();
	DECLARE_DYNCREATE(CMFCTextViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCTextViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public :
	char * temp;
	CString m_Text;
	CStringArray m_textContent;
	virtual void DeleteContents();

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	virtual BOOL SaveModified();
	
};
