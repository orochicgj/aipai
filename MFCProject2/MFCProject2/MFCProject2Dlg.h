
// MFCProject2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


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
	CButton btn_search;
	afx_msg void OnBnClickedButton1();
};
