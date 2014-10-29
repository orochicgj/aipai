// MFCProjectDlg.cpp : ʵ���ļ�
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



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CMFCProjectDlg �Ի���




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


// CMFCProjectDlg ��Ϣ�������

BOOL CMFCProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	/*��ʼ������*/
	url_spm = _T("spm=1.7274553.1997520841.1");
	url_option = _T("commend=all&ssid=s5-e&search_type=item&sourceId=tb.index");
	url_head = _T("http://s.taobao.com/search?");
	filePath = _T("dist");

	/*��ʼ�������б�*/
	//cbb_id.AddString(_T("mr_timon"));
	cbb_id.AddString(_T("mr_pumbaa"));
	cbb_id.AddString(_T("star_patrick"));
	cbb_id.AddString(_T("�������ҵ�Ŷ"));
	cbb_id.AddString(_T("457800643xc"));
	cbb_id.AddString(_T("lingzhiji�����콢��"));
	cbb_id.AddString(_T("�غ���"));

	/*��ʼ��������*/
	progress_search.SetRange(0,100);
	progress_search.SetStep(10);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

		/*   ��������Դ���ӵĻ������԰Ѷ�Ӧ����Դ��������   */
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
				showPage = _T("û���ҵ���");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//progress_search.StepIt();
	SetDlgItemText(IDC_EDIT2,_T(" "));
	progress_search.SetPos(0);

	/*��ȡ��������*/
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