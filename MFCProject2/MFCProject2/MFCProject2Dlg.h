
// MFCProject2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

struct Info{
	CString keyWord;
	CString ID;
	DWORD thread_status;
};

// CMFCProject2Dlg �Ի���
class CMFCProject2Dlg : public CDialogEx
{
// ����
public:
	CMFCProject2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCPROJECT2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CString string_keyWord;
	CString string_id;
	Info info;
	BOOL thread_flag;

	// ���ɵ���Ϣӳ�亯��
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
