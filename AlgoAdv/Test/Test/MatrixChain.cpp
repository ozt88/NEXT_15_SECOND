#include "stdafx.h"
#include "MatrixChain.h"

int MatrixChain::MatrixChainRecursion(int startIdx, int endIdx)
{
	if(startIdx == endIdx)
	{
		return 0;
	}

	else
	{
		int max = 0;
		int curr = 0;
		for(int i = startIdx; i < endIdx; ++i)
		{
			curr = MatrixChainRecursion(startIdx, i) + MatrixChainRecursion(i + 1, endIdx)
				+ Matrixes[startIdx].mRowNum * Matrixes[i].mColumnNum * Matrixes[endIdx].mColumnNum;

			if(max < curr)
			{
				max = curr;
			}
		}
		return max;
	}
}

int MatrixChain::MatrixChainMemo(int startIdx, int endIdx)
{
	static int result[1000][1000] = {-1, };

	if(result[startIdx][endIdx] == -1)
	{
		if(startIdx == endIdx)
		{
			result[startIdx][endIdx] = 0;
		}

		else
		{
			int max = 0;
			int curr = 0;
			for(int i = startIdx; i < endIdx; ++i)
			{
				curr = MatrixChainMemo(startIdx, i) + MatrixChainMemo(i + 1, endIdx)
					+ Matrixes[startIdx].mRowNum * Matrixes[i].mColumnNum * Matrixes[endIdx].mColumnNum;

				if(max < curr)
				{
					max = curr;
				}
			}
			result[startIdx][endIdx] = max;
		}
	}
	return result[startIdx][endIdx];
}


int MatrixChain::MatrixChainBottomUp(int startIdx, int endIdx)
{
	UINT result[1000][1000] = {0, };

	for(int sub = 1; sub < endIdx - startIdx; ++sub)
	{
		for(int subStart = startIdx; subStart < endIdx - sub; ++subStart)
		{
			int subEnd = subStart + sub;
			int min = INFINITE;
			int cur = 0;
			for(int idx = subStart; idx < subEnd; ++idx)
			{
				cur = result[subStart][idx] + result[idx + 1][subEnd]
					+ Matrixes[subStart].mRowNum * Matrixes[idx].mColumnNum * Matrixes[subEnd].mColumnNum;
				if(cur < min)
				{
					min = cur;
				}
			}
			result[subStart][subEnd] = min;
		}
	}

	return result[startIdx][endIdx];
}

