
// MultiFun.h : MultiFun Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMultiFunApp:
// �йش����ʵ�֣������ MultiFun.cpp
//

class CMultiFunApp : public CWinAppEx
{
public:
	CMultiFunApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMultiFunApp theApp;
