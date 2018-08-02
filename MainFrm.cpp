
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MultiFun.h"

#include "MainFrm.h"
#include "MyDlg.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_COLOR, &CMainFrame::OnUpdateColor)
	ON_COMMAND(ID_COLOR, &CMainFrame::OnColor)
	ON_COMMAND(5000, &CMainFrame::OnDeleteActiveMenu)
ON_COMMAND(ID_GAME, &CMainFrame::OnGame)
ON_COMMAND(ID_ADD, &CMainFrame::OnAdd)
ON_WM_TIMER()
ON_MESSAGE(US_PROGRESS, OnProgress)
ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	IDS_TIMER,
	IDS_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//{
	//	TRACE0("未能创建工具栏\n");
	//	return -1;      // 未能创建
	//}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	if (!m_colorToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |  CBRS_LEFT | WS_VISIBLE | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_colorToolBar.LoadToolBar(IDR_COLORTOOLBAR))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}
	m_colorToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_colorToolBar);

	CBitmap bmp1, bmp2;
	bmp1.LoadBitmap(IDB_BITMAP2);
	bmp2.LoadBitmap(IDB_BITMAP1);
	GetMenu()->GetSubMenu(3)->SetMenuItemBitmaps(1, MF_BYPOSITION, &bmp1, &bmp2);
	GetMenu()->GetSubMenu(3)->SetMenuItemBitmaps(2, MF_BYPOSITION, &bmp1, &bmp2);

	bmp1.Detach();
	bmp2.Detach();

	CMenu my_menu;
	my_menu.CreatePopupMenu();
	GetMenu()->AppendMenu(MF_POPUP, (UINT)my_menu.m_hMenu, "这是动态创建的菜单");
	my_menu.Detach();
	GetMenu()->GetSubMenu(4)->AppendMenu(MF_STRING, 5000, "Hello, World!");

	for (size_t ID = IDI_ICON1; ID <= IDI_ICON8; ID++)
	{
		icon[ID - IDI_ICON1] = ::LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(ID));
	}

	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(IDS_TIMER), IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIMER), str, TRUE);

	SetClassLong(m_hWnd, GCL_HICON, (LONG)icon[0]);
	SetTimer(1, 80, NULL);
	SetTimer(2, 1000, NULL);

	PostMessage(US_PROGRESS);

	CRect rc(100, 0, 120, 20);
	if (!m_bmp1.Create("", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(90, 4, 101, 15), &m_wndStatusBar, 0))
		return false;
	if (!m_bmp1.LoadBitmaps(IDB_BITMAP3, NULL, NULL, NULL))
		return false;
	if (!m_bmp2.Create("", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(105, 4, 116, 15), &m_wndStatusBar, 0))
		return false;
	if (!m_bmp2.LoadBitmaps(IDB_BITMAP4, NULL, NULL, NULL))
		return false;
	if (!m_bmp3.Create("", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CRect(120, 4, 131, 15), &m_wndStatusBar, 0))
		return false;
	if (!m_bmp3.LoadBitmaps(IDB_BITMAP5, NULL, NULL, NULL))
		return false;
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	cs.cx = 1300;
	cs.cy = 800;
	cs.lpszName = "课程作业";
	cs.style &= ~FWS_ADDTOTITLE;
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序


void CMainFrame::OnUpdateColor(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_colorToolBar.IsVisible());
}


void CMainFrame::OnColor()
{
	// TODO: 在此添加命令处理程序代码
	ShowControlBar(&m_colorToolBar, !m_colorToolBar.IsVisible(), FALSE);
}

void CMainFrame::OnDeleteActiveMenu()
{
	GetMenu()->DeleteMenu(4, MF_BYPOSITION);
	MessageBox("成功删除动态创建的菜单");
	Invalidate();
}


void CMainFrame::OnGame()
{
	// TODO: 在此添加命令处理程序代码
	CMyDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	CAddDlg dlg;
	dlg.DoModal();
}


void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	static int index = 1;
	switch (nIDEvent)
	{
	case 1:
		SetClassLong(m_hWnd, GCL_HICON, (LONG)icon[index]);
		index = (index + 1) % 8;
		m_progress.StepIt();
		break;
	case 2:
		CTime t = CTime::GetCurrentTime();
		CString str = t.Format("%H:%M:%S");
		CClientDC dc(this);
		CSize sz = dc.GetTextExtent(str);
		m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(IDS_TIMER), IDS_TIMER, SBPS_NORMAL, sz.cx);
		m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIMER), str, TRUE);
		break;
	}
	CFrameWnd::OnTimer(nIDEvent);
}

LRESULT CMainFrame::OnProgress(WPARAM wparm, LPARAM lparm)
{
	CRect rect;
	m_wndStatusBar.GetItemRect(m_wndStatusBar.CommandToIndex(IDS_PROGRESS), &rect);
	if (!m_progress.m_hWnd)
	{
		m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 1);
		m_progress.SetStep(1);
	}
	else
	{
		m_progress.MoveWindow(rect);
	}
	return true;
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFrameWnd::OnPaint()
	PostMessage(US_PROGRESS);
}
