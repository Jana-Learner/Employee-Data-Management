#include<afxwin.h>
#include"resource.h"
#include"InsertEmployee.h"
#include "odbcinst.h"
#include "afxdb.h"

CInsertEmployee::CInsertEmployee():CDialog(CInsertEmployee::IDD) {

}

CInsertEmployee::~CInsertEmployee(){

}

void CInsertEmployee::DoDataExchange(CDataExchange* pDX) {

}BEGIN_MESSAGE_MAP(CInsertEmployee, CDialog)
ON_BN_CLICKED(IDD_ADD_EMPLOYEE, &CInsertEmployee::OnBnClickedAddEmployee)
END_MESSAGE_MAP()


void CInsertEmployee::OnBnClickedAddEmployee()
{
	CString emp_id;
	CString emp_name;
	CString manager_id;
	GetDlgItemText(IDD_EMP_ID, emp_id);
	GetDlgItemText(IDD_EMP_NAME, emp_name);
	GetDlgItemText(IDD_MANAGER_ID, manager_id);
	CDatabase database;
	CString SqlString;
	CString conString;
	int iRec = 0;

	conString.Format(L"Data Source = DESKTOP - D1ME8I2; Initial Catalog = company; Integrated Security = True; Encrypt = False");
	TRY{
		database.Open(NULL,false,false,conString);
		
		SqlString.Format(L"insert into employee  (emp_id,emp_name,manager_id) values (%d,'%s',%d);", _ttoi(emp_id), emp_name.GetString(), _ttoi(manager_id));
		database.ExecuteSQL(SqlString);
		
		database.Close();
	}CATCH(CDBException, e) {
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
