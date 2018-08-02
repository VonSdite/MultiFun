
// MultiFunView.cpp : CMultiFunView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMultiFunView ����/����

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
	, m_str_tmp(_T("������Ļ"))
{
	// TODO: �ڴ˴���ӹ������
}

CMultiFunView::~CMultiFunView()
{
}

BOOL CMultiFunView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CMultiFunView ����

void CMultiFunView::OnDraw(CDC* /*pDC*/)
{
	CMultiFunDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMultiFunView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = 800;
	sizeTotal.cy = 2000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

// CMultiFunView ��ӡ

BOOL CMultiFunView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMultiFunView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMultiFunView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMultiFunView ���

#ifdef _DEBUG
void CMultiFunView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMultiFunView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMultiFunDoc* CMultiFunView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiFunDoc)));
	return (CMultiFunDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiFunView ��Ϣ�������


void CMultiFunView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			//����������
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
			//����������
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

	// TODO:  �ڴ������ר�õĴ�������

	::srand(NULL);
	SetTimer(1, 30, NULL);
	return 0;
}

void CMultiFunView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == LINE_FLAG);
}

void CMultiFunView::OnUpdateBrush(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == BRUSH_FLAG);
}

void CMultiFunView::OnUpdateContiuousline(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == CONTIUOUS_LINE_FLAG);
}

void CMultiFunView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == RECTANGLE_FLAG);
}

void CMultiFunView::OnUpdateElasticline(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == ELASTIC_LINE_FLAG);
}

void CMultiFunView::OnUpdateElasticrectangle(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == ELASTIC_RECTANGLE_FLAG);
}

void CMultiFunView::OnUpdateBitmaprectangle(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == BITMAP_RECTANGLE_FLAG);
}

void CMultiFunView::OnBrush()
{
	// TODO: �ڴ���������������
	if (m_FlagId != BRUSH_FLAG) m_FlagId = BRUSH_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnContiuousline()
{
	// TODO: �ڴ���������������
	if (m_FlagId != CONTIUOUS_LINE_FLAG) m_FlagId = CONTIUOUS_LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnElasticline()
{
	// TODO: �ڴ���������������
	if (m_FlagId != ELASTIC_LINE_FLAG) m_FlagId = ELASTIC_LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnRectangle()
{
	// TODO: �ڴ���������������
	if (m_FlagId != RECTANGLE_FLAG) m_FlagId = RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnLine()
{
	// TODO: �ڴ���������������
	if (m_FlagId != LINE_FLAG) m_FlagId = LINE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnElasticrectangle()
{
	// TODO: �ڴ���������������
	if (m_FlagId != ELASTIC_RECTANGLE_FLAG) m_FlagId = ELASTIC_RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnBitmaprectangle()
{
	// TODO: �ڴ���������������
	if (m_FlagId != BITMAP_RECTANGLE_FLAG) m_FlagId = BITMAP_RECTANGLE_FLAG;
	else m_FlagId = -1;
}

void CMultiFunView::OnRed()
{
	// TODO: �ڴ���������������
	m_Color = RED;
	red = 255;
	green = 0;
	blue = 0;
}

void CMultiFunView::OnGreen()
{
	// TODO: �ڴ���������������
	m_Color = GREEN;
	red = 0;
	green = 255;
	blue = 0;
}

void CMultiFunView::OnBlue()
{
	// TODO: �ڴ���������������
	m_Color = BLUE;
	red = 0;
	green = 0;
	blue = 255;
}

void CMultiFunView::OnBlack()
{
	// TODO: �ڴ���������������
	m_Color = BLACK;
	red = 0;
	green = 0;
	blue = 0;
}

void CMultiFunView::OnGrayed()
{
	// TODO: �ڴ���������������
	m_Color = GRAYED;
	red = 128;
	green = 128;
	blue = 128;
}

void CMultiFunView::OnYellow()
{
	// TODO: �ڴ���������������
	m_Color = YELLOW;
	red = 255;
	green = 255;
	blue = 0;
}

void CMultiFunView::OnCyanine()
{
	// TODO: �ڴ���������������
	m_Color = CYANINE;
	red = 0;
	green =  255;
	blue = 255;
}

void CMultiFunView::OnPurple()
{
	// TODO: �ڴ���������������
	m_Color = PURPLE;
	red = 255;
	green = 0;
	blue = 255;
}

void CMultiFunView::OnWhite()
{
	// TODO: �ڴ���������������
	m_Color = WHITE;
	red = 255;
	green = 255;
	blue = 255;
}

void CMultiFunView::OnUpdateBlack(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == BLACK);
}

void CMultiFunView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == BLUE);
}

void CMultiFunView::OnUpdateGrayed(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == GRAYED);
}

void CMultiFunView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == GREEN);
}

void CMultiFunView::OnUpdatePurple(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == PURPLE);
}

void CMultiFunView::OnUpdateRed(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == RED);
}

void CMultiFunView::OnUpdateWhite(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == WHITE);
}


void CMultiFunView::OnUpdateYellow(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == YELLOW);
}

void CMultiFunView::OnUpdateCyanine(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_Color == CYANINE);
}

void CMultiFunView::OnUpdateText(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_FlagId == TEXTSET);
}

void CMultiFunView::OnText()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);

	if (m_FlagId == TEXTSET)
	{
		CFont font;
		font.CreatePointFont(200, "�����п�");
		CFont *pOldFont = dc.SelectObject(&font);				// ��������

		if (0x0d == nChar)
		{ // ��Ӧ�س����� ����
			m_str.Empty();
			TEXTMETRIC tm;
			dc.GetTextMetrics(&tm);
			m_pOrigin.y += tm.tmHeight;
		}
		else if (0x08 == nChar)
		{ // ��Ӧ�˸��
			COLORREF clr = dc.SetTextColor(dc.GetBkColor());	// ��ȡ������ɫ
			dc.TextOut(m_pOrigin.x, m_pOrigin.y, m_str);		// �ñ�����ɫˢ���ַ���
			m_str = m_str.Left(m_str.GetLength() - 1);			// ɾ�����һ���ַ�
			dc.SetTextColor(clr);
		}
		else
			m_str += (char)nChar;								// �������ַ�
		
		COLORREF clr = dc.SetTextColor(RGB(red, green, blue));	// ����������ɫ

		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);

		CPoint po;
		CSize sz = dc.GetTextExtent(m_str);
		po.y = m_pOrigin.y;
		po.x = m_pOrigin.x + sz.cx;
		SetCaretPos(po);										// �ƶ������

		dc.TextOut(m_pOrigin.x, m_pOrigin.y, m_str);			// ����ַ���

		dc.SetTextColor(clr);
		dc.SelectObject(pOldFont);
	}

	CScrollView::OnChar(nChar, nRepCnt, nFlags);
}


void CMultiFunView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nwidth += 5;
	CFont font;
	font.CreatePointFont(300, "�����п�", NULL);
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
		m_str_tmp = "������Ļ";
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	ClientToScreen(&point);
	CMenu *pPopup = menu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CScrollView::OnRButtonDown(nFlags, point);
}


void CMultiFunView::OnExit()
{
	// TODO: �ڴ���������������
	if (MessageBox("ȷ��Ҫ�˳���", "��ʾ", MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}
}


void CMultiFunView::OnClear()
{
	// TODO: �ڴ���������������
	Invalidate();
}
