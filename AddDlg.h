#pragma once


// CAddDlg �Ի���

class CAddDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddDlg)

public:
	CAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
