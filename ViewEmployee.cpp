#include<afxwin.h>
#include"resource.h"
#include"ViewEmployee.h"
#include "odbcinst.h"
#include "afxdb.h"

CViewEmployee::CViewEmployee() :CDialog(CViewEmployee :: IDD) {

}
CViewEmployee::~CViewEmployee() {

}
void CViewEmployee::DoDataExchange(CDataExchange* pDX) {

	DDX_Control(pDX, IDC_LIST1, EvList);
}
BEGIN_MESSAGE_MAP(CViewEmployee, CDialog)
ON_BN_CLICKED(IDD_VIEW_EMPLOYEE, &CViewEmployee::OnBnClickedViewEmployee)
END_MESSAGE_MAP()

void CViewEmployee::ResetListControl() {
	EvList.DeleteAllItems();
	/*int iNbrOfColumns = 0;
	CHeaderCtrl* pHeader = (CHeaderCtrl*)EvList.GetDlgItem(0);
	if (pHeader) {
		iNbrOfColumns = pHeader->GetItemCount();
	}
	for (int i = iNbrOfColumns; i >= 0; i--) {
		EvList.DeleteColumn(i);
	}*/
}

void CViewEmployee::OnBnClickedViewEmployee()
{
	CString strID, strName, strMID;
	CDatabase database;
	CString SqlString;
	CString conString;
	int nItem;

	conString.Format(L"Data Source = DESKTOP - D1ME8I2; Initial Catalog = company; Integrated Security = True; Encrypt = False");
	TRY{
		database.Open(NULL,false,false,conString);

		CRecordset recset(&database);
		SqlString = "SELECT * FROM Employee";

		recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
		ResetListControl();
		//ListView_SetExtendedListViewStyle(EvList, LVS_EX_GRIDLINES);
		EvList.InsertColumn(0, L"Employee ID", LVCFMT_LEFT);
		EvList.InsertColumn(1, L"Employee Name", LVCFMT_LEFT);
		EvList.InsertColumn(2, _T("Manager ID"), LVCFMT_LEFT);
		EvList.SetColumnWidth(0, 200);
		EvList.SetColumnWidth(1, 215);
		EvList.SetColumnWidth(2, 215);

		while (!recset.IsEOF()) {
			recset.GetFieldValue(L"emp_id", strID);
			recset.GetFieldValue(L"emp_name", strName);
			recset.GetFieldValue(L"manager_id", strMID);

			nItem = EvList.InsertItem(0, strID);
			EvList.SetItemText(nItem, 1, strName);
			EvList.SetItemText(nItem, 2, strMID);

			recset.MoveNext();
		}

		database.Close();
	}CATCH(CDBException, e) {
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
