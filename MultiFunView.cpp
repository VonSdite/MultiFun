
// MultiFunView.cpp : CMultiFunView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MultiFun.h"
#endif

#include "MultiFunDoc.h"
#include "MultiFunView.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiFunView

IMPLEMENT_DYNCREATE(CMultiFunView, CScrollView)

BEGIN_MESSAGE_MAP(CMultiFunView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMultiFunView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_BRUSH, &CMultiFunView::OnUpdateBrush)
	ON_UPDATE_COMMAND_UI(ID_CONTIUOUSLINE, &CMultiFunView::OnUpdateContiuousline)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CMultiFunView::OnUpdateRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELASTICLINE, &CMultiFunView::OnUpdateElasticline)
	ON_COMMAND(ID_BRUSH, &CMultiFunView::OnBrush)
	ON_COMMAND(ID_CONTIUOUSLINE, &CMultiFunView::OnContiuousline)
	ON_COMMAND(ID_ELASTICLINE, &CMultiFunView::OnElasticline)
	ON_COMMAND(ID_RECTANGLE, &CMultiFunView::OnRectangle)
	ON_COMMAND(ID_LINE, &CMultiFunView::OnLine)
	ON_COMMAND(ID_RED, &CMultiFunView::OnRed)
	ON_COMMAND(ID_GREEN, &CMultiFunView::OnGreen)
	ON_COMMAND(ID_BLUE, &CMultiFunView::OnBlue)
	ON_COMMAND(ID_BLACK, &CMultiFunView::OnBlack)
	ON_COMMAND(ID_GRAYED, &CMultiFunView::OnGrayed)
	ON_COMMAND(ID_YELLOW, &CMultiFunView::OnYellow)
	ON_COMMAND(ID_CYANINE, &CMultiFunView::OnCyanine)
	ON_COMMAND(ID_PURPLE, &CMultiFunView::OnPurple)
	ON_COMMAND(ID_WHITE, &CMultiFunView::OnWhite)
	ON_UPDATE_COMMAND_UI(ID_BLACK, &CMultiFunView::OnUpdateBlack)
	ON_UPDATE_COMMAND_UI(ID_BLUE, &CMultiFunView::OnUpdateBlue)
	ON_UPDATE_COMMAND_UI(ID_GRAYED, &CMultiFunView::OnUpdateGrayed)
	ON_UPDATE_COMMAND_UI(ID_GREEN, &CMultiFunView::OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_PURPLE, &CMultiFunView::OnUpdatePurple)
	ON_UPDATE_COMMAND_UI(ID_RED, &CMultiFunView::OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_WHITE, &CMultiFunView::OnUpdateWhite)
	ON_UPDATE_COMMAND_UI(ID_YELLOW, &CMultiFunView::OnUpdateYellow)
	ON_UPDATE_COMMAND_UI(ID_CYANINE, &CMultiFunView::OnUpdateCyanine)
	ON_UPDATE_COMMAND_UI(ID_ELASTICRECTANGLE, &CMultiFunView::OnUpdateElasticrectangle)
	ON_COMMAND(ID_ELASTICRECTANGLE, &CMultiFunView::OnElasticrectangle)
	ON_UPDATE_COMMAND_UI(ID_BITMAPRECTANGLE, &CMultiFunView::OnUpdateBitmaprectangle)
	ON_COMMAND(ID_BITMAPRECTANGLE, &CMultiFunView::OnBitmaprectangle)
	ON_UPDATE_COMMAND_UI(ID_TEXT, &CMultiFunView::OnUpdateText)
	ON_COMMAND(ID_TEXT, &CMultiFunView::OnText)
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_EXIT, &CMultiFunView::OnExit)
	ON_COMMAND(ID_CLEAR, &CMultiFunView::OnClear)
END_MESSAGE_MAP()

// CMultiFunView 构造/析构

CMultiFunView::CMultiFunView()
	: m_pOrigin(0)
	, m_pEnd(0)
	, m_FlagId(-1)
	, m_Color(BLACK)
	, m_str(_T(""))
	, red(0)
	, green(0)
	, blue(0)
	, m_nwidth(0)
	, m_r(0)
	, m_b(0)
	, m_g(0)
	, m_str_tmp(_T("滚动字幕"))
{
	// TODO: 在此处添加构造代码
}

CMultiFunView::~CMultiFunView()
{
}

BOOL CMultiFunView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CMultiFunView 绘制

void CMultiFunView::OnDraw(CDC* /*pDC*/)
{
	CMultiFunDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMultiFunView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = 800;
	sizeTotal.cy = 2000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

// CMultiFunView 打印

BOOL CMultiFunView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMultiFunView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMultiFunView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMultiFunView 诊断

#ifdef _DEBUG
void CMultiFunView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMultiFunView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMultiFunDoc* CMultiFunView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiFunDoc)));
	return (CMultiFunDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiFunView 消息处理程序


void CMultiFunView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (m_FlagId)
	{
	case LINE_FLAG:
	case BRUSH_FLAG:
	case CONTIUOUS_LINE_FLAG:
	case ELASTIC_LINE_FLAG:
	case RECTANGLE_FLAG:
	case ELASTIC_RECTANGLE_FLAG:
	case BITMAP_RECTANGLE_FLAG:
		m_pEnd = m_pOrigin = point;
		break;
	case TEXTSET:
		SetCaretPos(point);
		m_pOrigin = point;
		m_str.Empty();
		break;
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CMultiFunView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_SOLID, 3, RGB(red, green, blue));
	CPen *pOldPen = dc.SelectObject(&pen);
	switch (m_FlagId)
	{
	case LINE_FLAG:
	{
		dc.MoveTo(m_pOrigin);
		dc.LineTo(point);
	}
	break;
	case BRUSH_FLAG:
	{
		CBrush brush(RGB(red, green, blue));
		dc.FillRect(CRect(m_pOrigin, point), &brush);
	}
	break;
	case RECTANGLE_FLAG:
	{
		CBrush* pOldBrush = (CBrush*)dc.SelectStockObject(HOLLOW_BRUSH);
		dc.Rectangle(CRect(m_pOrigin, point));
		dc.SelectObject(pOldBrush);
	}
	break;
	case BITMAP_RECTANGLE_FLAG:
	{
		CBitmap bmp;
		bmp.LoadBitmap(IDB_SMILE);
		CBrush brush(&bmp);
		dc.FillRect(CRect(m_pOrigin, point), &brush);
	}
	break;
	default:
		break;
	}
	dc.SelectObject(pOldPen);
	CScrollView::OnLButtonUp(nFlags, point);
}

void CMultiFunView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format("%dx%d", point.x, point.y);
	GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowText(str);

	CClientDC dc(this);
	CPen pen(PS_SOLID, 3, RGB(red, green, blue));
	CPen *pOldPen = dc.SelectObject(&pen);
	switch (m_FlagId)
	{
	case CONTIUOUS_LINE_FLAG:
		if (nFlags == MK_LBUTTON)
		{
			dc.MoveTo(m_pOrigin);
			dc.LineTo(point);
			m_pOrigin = point;
		}
		break;
	case ELASTIC_LINE_FLAG:
		if (nFlags == MK_LBUTTON)
		{
			//pixel = NOT(pen XOR screen pixel)
			dc.SetROP2(R2_NOTXORPEN);
			dc.MoveTo(m_pOrigin);
			dc.LineTo(m_pEnd);
			//绘制新线条
			m_pEnd = point;
			dc.MoveTo(m_pOrigin);
			dc.LineTo(m_pEnd);
		}
		break;
	case ELASTIC_RECTANGLE_FLAG:
		if (nFlags == MK_LBUTTON)
		{
			//pixel = NOT(pen XOR screen pixel)
			dc.SetROP2(R2_NOTXORPEN);
			CBrush *pOldBrush = (CBrush *)dc.SelectStockObject(HOLLOW_BRUSH);
			dc.Rectangle(CRect(m_pOrigin, m_pEnd));
			//绘制新线条
			m_pEnd = point;
			dc.Rectangle(CRect(m_pOrigin, m_pEnd));
			dc.SelectObject(pOldBrush);
		}
		break;

	}
	dc.SelectObject(pOldPen);
	CScrollView::OnMouseMove(nFlags, point);
}

int CMultiFunView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	::srand(NULL);
	SetTimer(1, 30, NULL);
	return 0;
}

void CMultiFunView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == LINE_FLAG);
}

void CMultiFunView::OnUpdateBrush(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == BRUSH_FLAG);
}

void CMultiFunView::OnUpdateContiuousline(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == CONTIUOUS_LINE_FLAG);
}

void CMultiFunView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == RECTANGLE_FLAG);
}

void CMultiFunView::OnUpdateElasticline(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == ELASTIC_LINE_FLAG);
}

void CMultiFunView::OnUpdateElasticrectangle(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == ELASTIC_RECTANGLE_FLAG);
}

void CMultiFunView::OnUpdateBitmaprectangle(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == BITMAP_RECTANGLE_FLAG);
}

void CMultiFunView::OnBrush()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != BRUSH_FLAG) m_FlagId = BRUSH_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnContiuousline()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != CONTIUOUS_LINE_FLAG) m_FlagId = CONTIUOUS_LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnElasticline()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != ELASTIC_LINE_FLAG) m_FlagId = ELASTIC_LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != RECTANGLE_FLAG) m_FlagId = RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != LINE_FLAG) m_FlagId = LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnElasticrectangle()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != ELASTIC_RECTANGLE_FLAG) m_FlagId = ELASTIC_RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnBitmaprectangle()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != BITMAP_RECTANGLE_FLAG) m_FlagId = BITMAP_RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnRed()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = RED;
	red = 255;
	green = 0;
	blue = 0;
}

void CMultiFunView::OnGreen()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = GREEN;
	red = 0;
	green = 255;
	blue = 0;
}

void CMultiFunView::OnBlue()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = BLUE;
	red = 0;
	green = 0;
	blue = 255;
}

void CMultiFunView::OnBlack()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = BLACK;
	red = 0;
	green = 0;
	blue = 0;
}

void CMultiFunView::OnGrayed()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = GRAYED;
	red = 128;
	green = 128;
	blue = 128;
}

void CMultiFunView::OnYellow()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = YELLOW;
	red = 255;
	green = 255;
	blue = 0;
}

void CMultiFunView::OnCyanine()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = CYANINE;
	red = 0;
	green =  255;
	blue = 255;
}

void CMultiFunView::OnPurple()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = PURPLE;
	red = 255;
	green = 0;
	blue = 255;
}

void CMultiFunView::OnWhite()
{
	// TODO: 在此添加命令处理程序代码
	m_Color = WHITE;
	red = 255;
	green = 255;
	blue = 255;
}

void CMultiFunView::OnUpdateBlack(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == BLACK);
}

void CMultiFunView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == BLUE);
}

void CMultiFunView::OnUpdateGrayed(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == GRAYED);
}

void CMultiFunView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == GREEN);
}

void CMultiFunView::OnUpdatePurple(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == PURPLE);
}

void CMultiFunView::OnUpdateRed(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == RED);
}

void CMultiFunView::OnUpdateWhite(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == WHITE);
}


void CMultiFunView::OnUpdateYellow(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == YELLOW);
}

void CMultiFunView::OnUpdateCyanine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Color == CYANINE);
}

void CMultiFunView::OnUpdateText(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_FlagId == TEXTSET);
}

void CMultiFunView::OnText()
{
	// TODO: 在此添加命令处理程序代码
	if (m_FlagId != TEXTSET)
	{
		CClientDC dc(this);
		/*TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);*/

		CBitmap bmp;
		bmp.LoadBitmap(IDB_DRAGON);
		CreateCaret(&bmp);
		m_FlagId = TEXTSET;
		ShowCaret();
		bmp.Detach();
	}
	else
	{
		m_FlagId = -1;
		DestroyCaret();
	}
}

void CMultiFunView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	if (m_FlagId == TEXTSET)
	{
		CFont font;
		font.CreatePointFont(200, "华文行楷");
		CFont *pOldFont = dc.SelectObject(&font);				// 设置字体

		if (0x0d == nChar)
		{ // 响应回车键， 换行
			m_str.Empty();
			TEXTMETRIC tm;
			dc.GetTextMetrics(&tm);
			m_pOrigin.y += tm.tmHeight;
		}
		else if (0x08 == nChar)
		{ // 响应退格键
			COLORREF clr = dc.SetTextColor(dc.GetBkColor());	// 获取背景颜色
			dc.TextOut(m_pOrigin.x, m_pOrigin.y, m_str);		// 用背景颜色刷掉字符串
			m_str = m_str.Left(m_str.GetLength() - 1);			// 删除最后一个字符
			dc.SetTextColor(clr);
		}
		else
			m_str += (char)nChar;								// 新增的字符
		
		COLORREF clr = dc.SetTextColor(RGB(red, green, blue));	// 设置字体颜色

		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);

		CPoint po;
		CSize sz = dc.GetTextExtent(m_str);
		po.y = m_pOrigin.y;
		po.x = m_pOrigin.x + sz.cx;
		SetCaretPos(po);										// 移动插入符

		dc.TextOut(m_pOrigin.x, m_pOrigin.y, m_str);			// 输出字符串

		dc.SetTextColor(clr);
		dc.SelectObject(pOldFont);
	}

	CScrollView::OnChar(nChar, nRepCnt, nFlags);
}


void CMultiFunView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nwidth += 5;
	CFont font;
	font.CreatePointFont(300, "华文行楷", NULL);
	CClientDC dc(this);
	CFont *OldFont = dc.SelectObject(&font);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top = 550;
	rect.right = m_nwidth;
	rect.bottom = rect.top + tm.tmHeight;
	COLORREF OldClr;
	OldClr = dc.SetTextColor(RGB(m_r, m_g, m_b));
	dc.DrawText(m_str_tmp, &rect, DT_LEFT);

	CSize sz = dc.GetTextExtent(m_str_tmp);

	if (m_nwidth > sz.cx)
	{
		m_nwidth = 0;
		m_str_tmp = "滚动字幕";
		int tm_r = (m_r + ::rand()) % 256;
		int tm_g = (m_g + ::rand()) % 256;
		int tm_b = (m_b + ::rand()) % 256;
		m_r = (tm_r == m_r) ? (m_r + 10) % 256 : tm_r;
		m_g = (tm_g == m_g) ? (m_g + 30) % 256 : tm_g;
		m_b = (tm_b == m_b) ? (m_b + 50) % 256 : tm_b;
	}
	
	dc.SelectObject(OldFont);
	dc.SetTextColor(OldClr);
	CScrollView::OnTimer(nIDEvent);
}


void CMultiFunView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	ClientToScreen(&point);
	CMenu *pPopup = menu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CScrollView::OnRButtonDown(nFlags, point);
}


void CMultiFunView::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox("确定要退出吗？", "提示", MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}
}


void CMultiFunView::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}
