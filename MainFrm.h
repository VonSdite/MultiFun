
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#define US_PROGRESS WM_USER

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CToolBar          m_colorToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnUpdateColor(CCmdUI *pCmdUI);
	afx_msg void OnColor();
	afx_msg void OnDeleteActiveMenu();
	afx_msg LRESULT OnProgress(WPARAM, LPARAM);
	afx_msg void OnGame();
	afx_msg void OnAdd();
private:
	HICON icon[8];
	CBitmapButton m_bmp1;
	CBitmapButton m_bmp2;
	CBitmapButton m_bmp3;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CProgressCtrl m_progress;
public:
	afx_msg void OnPaint();
};


