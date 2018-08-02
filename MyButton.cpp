#include "stdafx.h"
#include "MyButton.h"
#include "resource.h"
#include "MyDlg.h"


CMyButton::CMyButton()
{
}


CMyButton::~CMyButton()
{
}
BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	static int cnt = 0;
	if(cnt != -1) ++cnt;
	if (cnt > 15)
	{
		MessageBox("���԰��س��������˳�", "��ܰ��ʾ");
		cnt = -1;
	}
	ShowWindow(SW_HIDE);

	static CRect windowRect, buttonRect;
	if (windowRect.IsRectEmpty())
	{
		GetParent()->GetWindowRect(&windowRect);
		GetWindowRect(&buttonRect);
	}
	m_pButton->SetWindowPos(NULL, ::rand() % (windowRect.Width() - 3 * buttonRect.Width() + 1) + buttonRect.Width(), ::rand() % (windowRect.Height() - 6 * buttonRect.Height() - 46) + 2 * buttonRect.Height(), 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	m_pButton->ShowWindow(SW_SHOW);
	CButton::OnMouseMove(nFlags, point);
}
