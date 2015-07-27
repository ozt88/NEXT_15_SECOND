// OracleTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "DBHelper.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	if(false == DBHelper::Initialize("Driver={Oracle in OraDB12Home1};DSN=ODBC_ORCL;DBQ=ORCL;Database=test;UID=c##ozt88;PWD=rladusdn1"))
	{
		DBHelper::Finalize();
		return -1;
	}

	{
		DBHelper db;
		std::wstring query = L"SELECT sub.hourSum, emp.name FROM ( SELECT sum(w.hours) hourSum, w.ssn ssn FROM WorksOn w INNER JOIN Employee e ON w.ssn = e.ssn GROUP BY w.ssn ) sub INNER JOIN Employee emp ON emp.ssn = sub.ssn;";
		std::wstring result;
		std::wcout << L"Query: " << query << std::endl;
		db.Execute(query.c_str());
		
		wchar_t hourSum[128] = {0, };
		wchar_t name[128] = {0, };

		db.BindResultColumnText(hourSum);
		db.BindResultColumnText(name);
		
		std::wcout << L"===Result===\n";
		while(FetchResult::END != db.FetchRow())
		{
			result += L"Hour:";
			result += hourSum;
			result += L", Name:";
			result += name;
			result += L"\n";
		} 
		wprintf(result.c_str());
	}

	DBHelper::Finalize();
	return 0;
}

