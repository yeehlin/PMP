#pragma once


// PMPServers dialog

class PMPServers : public CDialog
{
	DECLARE_DYNAMIC(PMPServers)

public:
	PMPServers(CWnd* pParent = NULL);   // standard constructor
	virtual ~PMPServers();

// Dialog Data
	enum { IDD = IDD_SERVERS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
