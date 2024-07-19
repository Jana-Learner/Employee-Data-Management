#pragma once
#include<afxwin.h>
#include"resource.h"
#include"afxcmn.h"

class CUpdateEmployee : public CDialog {
public:
	enum {
		IDD = IDD_VEDLG
	};
	CUpdateEmployee();
	~CUpdateEmployee();
	void DoDataExchange(CDataExchange* pDX);
};