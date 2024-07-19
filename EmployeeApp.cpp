#include <afxwin.h>
#include "resource.h"
#include"InsertEmployee.h"
#include"ViewEmployee.h"
#include"UpdateEmployee.h"
#include"SystemInformation.h"

class CMyDialog2 : public CDialog {
public:
	enum {
		IDD = IDD_EMDLG
	};
	CMyDialog2();
	~CMyDialog2();
	void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
CMyDialog2::CMyDialog2() :CDialog(CMyDialog2::IDD) {

}

CMyDialog2::~CMyDialog2() {

}

void CMyDialog2::DoDataExchange(CDataExchange* pDX)
{

}

class CEmployeeApp : public CWinApp {
	BOOL InitInstance() {
		CMyDialog2* MyDialog = new CMyDialog2();
		m_pMainWnd = MyDialog;
		MyDialog->DoModal();
		/*CSystemInformation dlg;
		dlg.DoModal();*/
		return TRUE;
	}

};

CEmployeeApp theApp; BEGIN_MESSAGE_MAP(CMyDialog2, CDialog)
ON_BN_CLICKED(IDC_BUTTON1, &CMyDialog2::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CMyDialog2::OnBnClickedButton2)
ON_BN_CLICKED(IDD_SYSINFO, &CMyDialog2::OnBnClickedButton3)
END_MESSAGE_MAP()


void CMyDialog2::OnBnClickedButton1()
{
	CInsertEmployee* Dlg = new CInsertEmployee();
	
	Dlg->DoModal();

	//delete Dlg;
}

void CMyDialog2::OnBnClickedButton2()
{
	CViewEmployee Dlg;
	Dlg.DoModal();
	
}


void CMyDialog2::OnBnClickedButton3()
{
	CSystemInformation dlg;
	dlg.DoModal();
}
