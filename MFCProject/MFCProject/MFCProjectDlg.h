
// MFCProjectDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMFCProjectDlg 对话框
class CMFCProjectDlg : public CDialogEx
{
// 构造
public:
	CMFCProjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CString URL;
	CString url_date;
	CString url_spm ;
	CString url_keyWord ;
	CString url_option;
	CString url_head;
	CString url_page;

	CString filePath;
	CString string_keyWord;
	CString string_id;
	CString showPage;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_keyWord;
	CComboBox cbb_id;
	afx_msg void OnCbnSelchangeCombo1();
	CProgressCtrl progress_search;
	afx_msg void OnBnClickedButton1();

	int fun_main();
	CString generateUrlDate();
	CString generateUrlKeyWord();
	CString generateUrlPage(int iPage);
	int searchLocation(CString &filePath, CString &keyWord);
	CEdit edit_page;
};
