
// MFCProject2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

struct Info{
	CString keyWord;
	CString ID;
	DWORD thread_status;
};

// CMFCProject2Dlg 对话框
class CMFCProject2Dlg : public CDialogEx
{
// 构造
public:
	CMFCProject2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCPROJECT2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CString string_keyWord;
	CString string_id;
	Info info;
	BOOL thread_flag;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit edit_keyWord;
	CEdit edit_showPage;
	CComboBox cbb_id;
	afx_msg void OnBnClickedButton1();
	CButton btn_search;
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl progress_search;

	afx_msg LRESULT OnUserThreadend(WPARAM wParam, LPARAM lParam);
};
