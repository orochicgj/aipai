// WzdView.cpp : implementation of the CWzdView class
//

#include "stdafx.h"
#include "Wzd.h"

#include "WzdDoc.h"
#include "WzdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdView

IMPLEMENT_DYNCREATE(CWzdView, CView)

BEGIN_MESSAGE_MAP(CWzdView, CView)
	//{{AFX_MSG_MAP(CWzdView)
	ON_COMMAND(IDC_WZD_TYPE, OnWzdType)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzdView construction/destruction

CWzdView::CWzdView()
{
	// TODO: add construction code here

}

CWzdView::~CWzdView()
{
}

BOOL CWzdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView drawing

void CWzdView::OnDraw(CDC* pDC)
{
	CWzdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView printing

BOOL CWzdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWzdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWzdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWzdView diagnostics

#ifdef _DEBUG
void CWzdView::AssertValid() const
{
	CView::AssertValid();
}

void CWzdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWzdDoc* CWzdView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWzdDoc)));
	return (CWzdDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzdView message handlers

void CWzdView::OnWzdType() 
{
	CString sDate,sTime,sElapsedTime;

/////////////////
// CTime ////////
/////////////////
	CTime time;

	// get time
	time=CTime::GetCurrentTime();
	int year = time.GetYear();
	int month = time.GetMonth();
	int day = time.GetDay();
	int hour = time.GetHour();
	int minute = time.GetMinute();
	int second = time.GetSecond();
	int DayOfWeek = time.GetDayOfWeek();

	// set elapsed time
	CTimeSpan timespan(0,0,1,0); // days,hours,minutes,seconds

	// get elasped time
	timespan = CTime::GetCurrentTime() - time;

	// format time or timespan (see strftime in help for more formats)
	sDate = time.Format("%m/%d/%y");					//ex: 12/10/98
	sTime = time.Format("%H:%M:%S");					//ex: 9:12:02
	sElapsedTime = timespan.Format("%D:%H:%M:%S");		// %D is total elapsed days

//////////////////
// COleDateTime //
//////////////////
	COleDateTime datetime; //can also construct from a CTime

	// same member functions as CTime, but also two more:

	// get day of year to create Julian date
	int DayOfYear = datetime.GetDayOfYear();

	// read time from a character string
	datetime.ParseDateTime("12:12:23 27 January 93");

	// COleDateTime will also last past 2037 when CTime will have a meltdown
}
