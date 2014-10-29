// MFCProjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCProject.h"
#include "MFCProjectDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef unsigned char BYTE;
inline BYTE toHex(const BYTE &x)
{
	return x > 9 ? x + 55 : x + 48;
}



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


// CMFCProjectDlg 对话框




CMFCProjectDlg::CMFCProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCProjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_keyWord);
	DDX_Control(pDX, IDC_COMBO1, cbb_id);
	DDX_Control(pDX, IDC_PROGRESS1, progress_search);
	DDX_Control(pDX, IDC_EDIT2, edit_page);
}

BEGIN_MESSAGE_MAP(CMFCProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCProjectDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCProjectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCProjectDlg 消息处理程序

BOOL CMFCProjectDlg::OnInitDialog()
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
	/*初始化常量*/
	url_spm = _T("spm=1.7274553.1997520841.1");
	url_option = _T("commend=all&ssid=s5-e&search_type=item&sourceId=tb.index");
	url_head = _T("http://s.taobao.com/search?");
	filePath = _T("dist");

	/*初始化下拉列表*/
	//cbb_id.AddString(_T("mr_timon"));
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

void CMFCProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCProjectDlg::OnPaint()
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
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}

int CMFCProjectDlg::fun_main(){
	url_date = _T("initiative_id=tbindexz_") + generateUrlDate();
	url_keyWord = _T("q=") + generateUrlKeyWord();
	for(int i = 1; i <= 100; i++){
		url_page = generateUrlPage(i);
		if((i - 1)%10 == 0){
			progress_search.StepIt();
		}
		if(i != 1){
			URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date + _T("&") + url_page;
		}else{
			URL = url_head + url_keyWord + _T("&") + url_spm + _T("&") + url_option+ _T("&") + url_date;
		}

		/*   这里有资源链接的话，可以把对应的资源下载下来   */
		//URL = _T("http://www.jojomamanbebe.co.uk/products/images/large/B2755C.jpg");

		HRESULT result =  URLDownloadToFile(0, URL, filePath, 0, NULL);
		if(result == S_OK){
			std::cout << "down\n";
			if(!searchLocation(filePath,string_id)){
				std::cout << "            page = " << i << std::endl << std::endl << std::endl;
				showPage.Format("%d",i);
				SetDlgItemText(IDC_EDIT2,showPage);
				break;
			}else{
				if(i == 100)
					std::cout << std::endl << std::endl << "*************  sorry,we don't have found it  *************" << std::endl << std::endl << std::endl ;
				showPage = _T("没有找到！");
				SetDlgItemText(IDC_EDIT2,showPage);
			}
		}else{
			std::cout << "URLDownloadToFile failed\n";
			return 1;
		}
	}

	//std::cout << "real_url = " << URL << std::endl;

	std::ofstream fout("currentURL.txt");
	fout << URL;
	fout.flush();
	fout.close();

	//getchar();
	return 0;
}



void CMFCProjectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//progress_search.StepIt();
	SetDlgItemText(IDC_EDIT2,_T(" "));
	progress_search.SetPos(0);

	/*获取窗口数据*/
	GetDlgItemText(IDC_EDIT1,string_keyWord);

	//GetDlgItemText(IDC_COMBO1,string_id);
	int index = cbb_id.GetCurSel();
	cbb_id.GetLBText(index,string_id);

	AfxBeginThread(ThreadBody, &info);

}


CString CMFCProjectDlg::generateUrlDate(){
	CTime currentTime = CTime::GetCurrentTime();
	CString string_year;
	CString string_month;
	CString string_day;

	int year = currentTime.GetYear();
	int month = currentTime.GetMonth();
	int day = currentTime.GetDay();

	string_year.Format(_T("%d"),year);
	string_month.Format(_T("%02d"),month);
	string_day.Format(_T("%02d"),day);

	return(string_year + string_month + string_day);
}

CString CMFCProjectDlg::generateUrlKeyWord(){
	//std::cout << "key word length = " << sIn.GetLength() << std::endl;
	CString sIn = string_keyWord;
	CString sOut;
	BYTE buf[4];
	for( int ix = 0; ix < sIn.GetLength(); ix++){
		memset(buf, 0, 4);
		if( isalnum((BYTE)sIn[ix])){
			buf[0] = sIn[ix];
		}
		else if( isspace((BYTE)sIn[ix])){
			buf[0] = '+';
		}
		else{
			buf[0] = '%';
			buf[1] = toHex( (BYTE)sIn[ix] >> 4 );
			buf[2] = toHex( (BYTE)sIn[ix] % 16);
		}
		sOut += (char *)buf;
	}
	return sOut;
}

CString CMFCProjectDlg::generateUrlPage(int iPage){
	CString offset;
	CString sOut;
	offset.Format("%d",(iPage - 1)*44);
	sOut = _T("tab=all&bcoffset=1&s=") + offset;
	return sOut;
}

int CMFCProjectDlg::searchLocation(CString &filePath, CString &ID){
	std::ifstream is(filePath);
	std::streamoff length;
	char * buffer = NULL;
	char * flag = NULL;
	if(is){
		is.seekg (0, is.end);
		length = is.tellg();
		is.seekg (0, is.beg);
		buffer = new char [length];
		is.read (buffer,length);
		is.close();
		flag = std::strstr(buffer,ID);
		if(flag != NULL){
			std::cout << std::endl << std::endl << "            find it" << std::endl;

			std::ofstream ffout("current.html");
			ffout << buffer;
			ffout.flush();
			ffout.close();

		}else{
			//std::cout << "not find in this page" << std::endl;
			flag = NULL;
			return 1;
		}
	}else{
		std::cout << "            read File(dist) to buffer error" << std::endl;
		return 1;
	}
	delete [] buffer;
	flag = NULL;
	return 0;
}