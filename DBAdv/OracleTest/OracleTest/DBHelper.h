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


	/// �Ʒ��� DbHelper ��ü�� �����ϰ� ����ؾ� ��

	bool BindParamInt(int* param);
	bool BindParamFloat(float* param);
	bool BindParamBool(bool* param);
	bool BindParamText(const wchar_t* text);

	/// FetchRow�� �����Ͱ� �ִٸ� �ݵ�� ���ʴ�� ȣ���ؾ���
	void BindResultColumnInt(int* r);
	void BindResultColumnFloat(float* r);
	void BindResultColumnBool(bool* r);
	void BindResultColumnText(wchar_t* text, size_t count);

	template<size_t LEN>
	void BindResultColumnText(wchar_t(&str)[LEN])
	{
		return BindResultColumnText(str, LEN);
	};

	//TODO: log�� ���⵵�� �ٲ� ��
	void PrintSqlStmtError();

private:
	SQLHSTMT	mCurrentSqlHstmt = nullptr;
	SQLSMALLINT	mCurrentResultCol;
	SQLSMALLINT	mCurrentBindParam;

	static SQLHENV mSqlHenv;
	static SQL_CONN* mSqlConn; ///< ��Ŀ���������ŭ
};