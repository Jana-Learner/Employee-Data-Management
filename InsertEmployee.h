#pragma once
#include<afxwin.h>
#include"resource.h"

class CInsertEmployee : public CDialog {
public:
	enum {
		IDD = IDD_IEDLG
	};
	CInsertEmployee();
	~CInsertEmployee();
	void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedAddEmployee();
};