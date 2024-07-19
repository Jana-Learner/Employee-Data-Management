#pragma once
#include<afxwin.h>
#include"resource.h"
#include"GetSysInformation.h"

class CSystemInformation : public CDialog {
public:
	enum {
		IDD = IDD_SIDLG
	};
	GetSysInformation gsi;
	CSystemInformation();
	~CSystemInformation();
	void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};