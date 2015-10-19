// DialogTree.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTextView.h"
#include "DialogTree.h"
#include "afxdialogex.h"


// CDialogTree dialog

IMPLEMENT_DYNAMIC(CDialogTree, CDialog)

CDialogTree::CDialogTree(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTree::IDD, pParent)
{

}

CDialogTree::~CDialogTree()
{
}

void CDialogTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogTree, CDialog)
END_MESSAGE_MAP()


// CDialogTree message handlers
