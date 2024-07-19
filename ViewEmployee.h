#pragma once
#include<afxwin.h>
#include"resource.h"
#include"afxcmn.h"


class CViewEmployee : public CDialog {
public:
	enum {
		IDD = IDD_VEDLG
	};
	CViewEmployee();
	~CViewEmployee();
	void DoDataExchange(CDataExchange* pDX);
	void ResetListControl();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedViewEmployee();
	CListCtrl EvList;
};