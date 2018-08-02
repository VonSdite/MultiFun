// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MultiFun.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "MyButton.h"


// CMyDlg 对话框

IMPLEMENT_DYNAMIC(CMyDlg, CDialog)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg::OnClickedButton1)
END_MESSAGE_MAP()


// CMyDlg 消息处理程序


int CMyDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_button1.m_pButton = &m_button2;
	m_button2.m_pButton = &m_button1;
	::srand(NULL);
	// TODO:  在此添加您专用的创建代码
	CRect rc;
	GetClientRect(&rc);
	CRgn rgn;
	rgn.CreateEllipticRgn(0, 0, rc.Width(), rc.Height());
	SetWindowRgn((HRGN)rgn.m_hObject, TRUE);
	return 0;
}

void CMyDlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox("竟然被你抓到我了，不可思议，你肯定是按了回车！！", "震惊!!");
	this->SendMessage(WM_CLOSE);
}
