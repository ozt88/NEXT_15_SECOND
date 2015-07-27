#pragma once
#include <sqlext.h>
#include <sqltypes.h>

struct SQL_CONN
{
	SQLHDBC		mSqlHdbc = nullptr;
	SQLHSTMT	mSqlHstmt = nullptr;
	bool		mUsingNow = false;
};

enum class FetchResult
{
	CONTINUE,
	END,
	FETCH_ERROR,
};

class DBHelper
{
public:
	DBHelper();
	~DBHelper();

	static bool Initialize(const char* connInfoStr);
	static void Finalize();

	bool Execute(const wchar_t* sqlstmt);
	FetchResult FetchRow();


	/// 아래는 DbHelper 객체를 선언하고 사용해야 함

	bool BindParamInt(int* param);
	bool BindParamFloat(float* param);
	bool BindParamBool(bool* param);
	bool BindParamText(const wchar_t* text);

	/// FetchRow시 데이터가 있다면 반드시 차례대로 호출해야함
	void BindResultColumnInt(int* r);
	void BindResultColumnFloat(float* r);
	void BindResultColumnBool(bool* r);
	void BindResultColumnText(wchar_t* text, size_t count);

	template<size_t LEN>
	void BindResultColumnText(wchar_t(&str)[LEN])
	{
		return BindResultColumnText(str, LEN);
	};

	//TODO: log에 남기도록 바꿀 것
	void PrintSqlStmtError();

private:
	SQLHSTMT	mCurrentSqlHstmt = nullptr;
	SQLSMALLINT	mCurrentResultCol;
	SQLSMALLINT	mCurrentBindParam;

	static SQLHENV mSqlHenv;
	static SQL_CONN* mSqlConn; ///< 워커스레드수만큼
};