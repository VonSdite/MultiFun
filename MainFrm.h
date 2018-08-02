
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#define US_PROGRESS WM_USER

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CToolBar          m_colorToolBar;

// 生成的消息映射函数
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


