// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MultiFun.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// CAddDlg 对话框

IMPLEMENT_DYNAMIC(CAddDlg, CDialog)

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ADD, pParent)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_RES1, m_num3);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialog)
	ON_BN_CLICKED(IDC_ADD, &CAddDlg::OnClickedAdd)
	ON_STN_CLICKED(IDC_NUM1, &CAddDlg::OnClickedNum1)
	ON_STN_CLICKED(IDC_NUM2, &CAddDlg::OnClickedNum2)
	ON_STN_CLICKED(IDC_RES, &CAddDlg::OnClickedRes)
END_MESSAGE_MAP()


// CAddDlg 消息处理程序


void CAddDlg::OnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_num3 = m_num1 + m_num2;
	UpdateData(false);
}


void CAddDlg::OnClickedNum1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItem(IDC_NUM1)->GetWindowText(str), str == "Number1:")
	{
		GetDlgItem(IDC_NUM1)->SetWindowText("数字1:");
	}
	else
	{
		GetDlgItem(IDC_NUM1)->SetWindowText("Number1:");
	}
}


void CAddDlg::OnClickedNum2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItem(IDC_NUM2)->GetWindowText(str), str == "Number2:")
	{
		GetDlgItem(IDC_NUM2)->SetWindowText("数字2:");
	}
	else
	{
		GetDlgItem(IDC_NUM2)->SetWindowText("Number2:");
	}
}


void CAddDlg::OnClickedRes()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItem(IDC_RES)->GetWindowText(str), str == "Result:")
	{
		GetDlgItem(IDC_RES)->SetWindowText("结果:");
	}
	else
	{
		GetDlgItem(IDC_RES)->SetWindowText("Result:");
	}
}
