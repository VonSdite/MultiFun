#pragma once
#include "afxwin.h"
class CMyButton :
	public CButton
{
public:
	CMyButton();
	~CMyButton();
	CMyButton *m_pButton;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

