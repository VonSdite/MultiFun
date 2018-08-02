#pragma once


// CAddDlg 对话框

class CAddDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAdd();
	int m_num1;
	int m_num2;
	int m_num3;
	afx_msg void OnClickedNum1();
	afx_msg void OnClickedNum2();
	afx_msg void OnClickedRes();
};
