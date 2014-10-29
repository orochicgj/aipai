
// MFCProject2Dlg.cpp : ʵ���ļ�
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


// CMFCProject2Dlg �Ի���




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


// CMFCProject2Dlg ��Ϣ�������

BOOL CMFCProject2Dlg::OnInitDialog()
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
	/*��ʼ�������б�*/
	cbb_id.AddString(_T("mr_timon"));
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCProject2Dlg::OnPaint()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��տؼ�
	SetDlgItemText(IDC_EDIT2,_T(" "));
	progress_search.SetPos(0);

	/*��ȡ��������*/
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
