#include "stdafx.h"
#include "LongestCommonSubsequence.h"

int LongestCommonSubsequence::LCSRecursion(int* arr1, int* arr2, int m, int n)
{
	int result = 0;
	if(m == 0 || n == 0)
	{
		result = 0;
	}
	else if(arr1[m] == arr2[n])
	{
		result = LCSRecursion(arr1, arr2, m - 1, n - 1) + 1;
	}
	else
	{
		int result1 = LCSRecursion(arr1, arr2, m, n-1);
		int result2 = LCSRecursion(arr1, arr2, m - 1, n);
		result = result1 > result2 ? result1 : result2;
	}
	return result;
}

int LongestCommonSubsequence::LCSMemo(int* arr1, int* arr2, int m, int n)
{
	static int Memo[1000][1000] = {-1, };

	if(Memo[m][n] != -1)
		return Memo[m][n];
	
	if(m == 0 || n == 0)
	{
		Memo[m][n] = 0;
	}
	else if(arr1[m] == arr2[n])
	{
		Memo[m][n] = LCSMemo(arr1, arr2, m - 1, n - 1) + 1;
	}
	else
	{
		int result1 = LCSMemo(arr1, arr2, m - 1, n);
		int result2 = LCSMemo(arr1, arr2, m, n - 1);
		Memo[m][n] = ( result1 > result2 ) ? result1 : result2;
	}
	return Memo[m][n];
}

int LongestCommonSubsequence::LCSBottomup(int* arr1, int* arr2, int m , int n)
{
	int Memo[1000][1000] = {0, };

	for(int mIdx = 0; mIdx <= m; mIdx++)
	{
		for(int nIdx = 0; nIdx <= n; nIdx++)
		{
			if(mIdx == 0 || nIdx == 0)
			{
				Memo[mIdx][nIdx] = 0;
			}
			else if(arr1[mIdx] == arr2[nIdx])
			{
				Memo[mIdx][nIdx] = Memo[mIdx - 1][nIdx - 1] + 1;
			}
			else
			{
				int result1 = Memo[mIdx-1][nIdx];
				int result2 = Memo[mIdx][nIdx-1];
				Memo[mIdx][nIdx] = ( result1 > result2 ) ? result1 : result2;
			}
		}
	}
	return Memo[m][n];
}

