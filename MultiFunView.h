
// MultiFunView.h : CMultiFunView 类的接口
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"

#define LINE_FLAG				0		
#define BRUSH_FLAG				1
#define RECTANGLE_FLAG			2
#define CONTIUOUS_LINE_FLAG		3
#define ELASTIC_LINE_FLAG		4
#define ELASTIC_RECTANGLE_FLAG  5
#define BITMAP_RECTANGLE_FLAG   6

#define RED						20
#define GREEN					21
#define BLUE					22
#define BLACK					23
#define WHITE					24
#define GRAYED					25
#define YELLOW					26
#define CYANINE					27
#define PURPLE					28

#define TEXTSET					40

class CMultiFunView : public CScrollView
{
protected: // 仅从序列化创建
	CMultiFunView();
	DECLARE_DYNCREATE(CMultiFunView)

// 特性
public:
	CMultiFunDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMultiFunView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnBlack();
	afx_msg void OnGrayed();
	afx_msg void OnYellow();
	afx_msg void OnCyanine();
	afx_msg void OnPurple();
	afx_msg void OnWhite();
	afx_msg void OnUpdateBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGrayed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePurple(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCyanine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElasticrectangle(CCmdUI *pCmdUI);
	afx_msg void OnElasticrectangle();
	afx_msg void OnUpdateBitmaprectangle(CCmdUI *pCmdUI);
	afx_msg void OnBitmaprectangle();
	afx_msg void OnUpdateText(CCmdUI *pCmdUI);
	afx_msg void OnText(); 
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrush(CCmdUI *pCmdUI);
	afx_msg void OnUpdateContiuousline(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElasticline(CCmdUI *pCmdUI);
	afx_msg void OnBrush();
	afx_msg void OnContiuousline();
	afx_msg void OnElasticline();
	afx_msg void OnRectangle();
	afx_msg void OnLine();
private:
	int m_FlagId;
	int m_Color;
	CPoint m_pEnd;
	CPoint m_pOrigin;
	CString m_str;
	int red;
	int green;
	int blue;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int m_nwidth;
	int m_r;
	int m_b;
	int m_g;
	CString m_str_tmp;
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnExit();
	afx_msg void OnClear();
};

#ifndef _DEBUG  // MultiFunView.cpp 中的调试版本
inline CMultiFunDoc* CMultiFunView::GetDocument() const
   { return reinterpret_cast<CMultiFunDoc*>(m_pDocument); }
#endif

