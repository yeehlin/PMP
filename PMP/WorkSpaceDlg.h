#pragma once


// CWorkSpaceDlg dialog

class CWorkSpaceDlg : public CDialog
{
	DECLARE_DYNAMIC(CWorkSpaceDlg)

public:
	CWorkSpaceDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWorkSpaceDlg();

// Dialog Data
	enum { IDD = IDD_WORKSPACE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelectWorkspace();
public:
	//����һ��ѡ���ļ��еĶԻ��򣬷�����ѡ·��
	static CString Show()
	{
		TCHAR			szFolderPath[MAX_PATH] = {0};
		CString			strFolderPath = TEXT("");

		BROWSEINFO		sInfo;
		::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
		sInfo.pidlRoot   = 0;
		sInfo.lpszTitle   = _T("��ѡ��һ���ļ��У�");
		sInfo.ulFlags   = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
		sInfo.lpfn     = NULL;

		// ��ʾ�ļ���ѡ��Ի���
		LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo); 
		if (lpidlBrowse != NULL)
		{
			// ȡ���ļ�����
			if (::SHGetPathFromIDList(lpidlBrowse,szFolderPath))  
			{
				strFolderPath = szFolderPath;
			}
		}
		if(lpidlBrowse != NULL)
		{
			::CoTaskMemFree(lpidlBrowse);
		}

		return strFolderPath;

	};
public :
	CString folderpath;
	virtual BOOL OnInitDialog();
	CComboBox m_ComboWorkspace;
	CString m_combo_workspace_string;
};