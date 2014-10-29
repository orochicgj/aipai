
// MFCProject2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCProject2.h"
#include "MFCProject2Dlg.h"
#include "afxdialogex.h"
#include "searcher.h"
#include <iostream>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCProject2Dlg 对话框




CMFCProject2Dlg::CMFCProject2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCProject2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProject2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_keyWord);
	DDX_Control(pDX, IDC_EDIT2, edit_showPage);
	DDX_Control(pDX, IDC_COMBO1, cbb_id);
	DDX_Control(pDX, IDC_BUTTON1, btn_search);
	DDX_Control(pDX, IDC_PROGRESS1, progress_search);
}

BEGIN_MESSAGE_MAP(CMFCProject2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCProject2Dlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CMFCProject2Dlg::OnNMCustomdrawProgress1)

	ON_MESSAGE(MESSAGE_UPDATE_EDIT, OnUserThreadend)
END_MESSAGE_MAP()


// CMFCProject2Dlg 消息处理程序

BOOL CMFCProject2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	/*初始化下拉列表*/
	cbb_id.AddString(_T("mr_timon"));
	cbb_id.AddString(_T("mr_pumbaa"));
	cbb_id.AddString(_T("star_patrick"));
	cbb_id.AddString(_T("乐乐是我的哦"));
	cbb_id.AddString(_T("457800643xc"));
	cbb_id.AddString(_T("lingzhiji服饰旗舰店"));
	cbb_id.AddString(_T("呢好美"));

	/*初始化进度条*/
	progress_search.SetRange(0,100);
	progress_search.SetStep(10);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCProject2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCProject2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCProject2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT ThreadBody(LPVOID lpParam)
{
	/*
	std::ofstream ffout("test");
	ffout << "test multithread";
	ffout.flush();
	ffout.close();
	return 0;//*/
	Info * info = (Info *)lpParam;
	searcher * obj = new searcher(info->keyWord,info->ID);
	for(int page = 1; page <= 100; page++){
		if(flag == false){
			info->thread_status = 0;
			flag = ture;
			 ExitThread(0);
		}
		obj->fun_main(page);
	}
	return 0;
}


void CMFCProject2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//清空控件
	SetDlgItemText(IDC_EDIT2,_T(" "));
	progress_search.SetPos(0);

	/*获取窗口数据*/
	GetDlgItemText(IDC_EDIT1,string_keyWord);
	int index = cbb_id.GetCurSel();
	cbb_id.GetLBText(index,string_id);
	info.keyWord = string_keyWord;
	info.ID = string_id;
	thread_flag

	AfxBeginThread(ThreadBody, &info);
}

 LRESULT CMFCProject2Dlg::OnUserThreadend(WPARAM wParam, LPARAM lParam){
	 SetDlgItemText(IDC_EDIT2,_T("222222"));
	 return 0;
 }


void CMFCProject2Dlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
