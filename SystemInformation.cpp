#include<afxwin.h>
#include"iostream"
#include"resource.h"
#include"SystemInformation.h"
using namespace std;

#include <windows.h>

CSystemInformation::CSystemInformation() : CDialog(CSystemInformation::IDD) {
    
}
CSystemInformation::~CSystemInformation() {

}
void CSystemInformation::DoDataExchange(CDataExchange* pDX) {

}

BEGIN_MESSAGE_MAP(CSystemInformation, CDialog)
    ON_BN_CLICKED(GSI, &CSystemInformation::OnBnClickedOk)
END_MESSAGE_MAP()


void CSystemInformation::OnBnClickedOk()
{
    SetDlgItemText(DEVICENAMEBOX, ": " + gsi.getDeviceName());
    SetDlgItemText(PROCESSORNAMEBOX, ": " + gsi.getProcessorName());
    SetDlgItemText(RAMBOX, ": " + gsi.getRam());
    SetDlgItemText(SYSTYPEBOX, ": " + gsi.getSystemType());
}
