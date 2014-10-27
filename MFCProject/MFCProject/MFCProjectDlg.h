
// MFCProjectDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMFCProjectDlg �Ի���
class CMFCProjectDlg : public CDialogEx
{
// ����
public:
	CMFCProjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
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

	// ���ɵ���Ϣӳ�亯��
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
