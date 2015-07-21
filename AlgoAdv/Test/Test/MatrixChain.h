#pragma once

namespace MatrixChain
{
	struct Matrix{unsigned mColumnNum, mRowNum;};
	std::vector<Matrix> Matrixes;
	std::vector<UINT> Memo;
	int MatrixChainRecursion(int startIdx, int endIdx);
	int MatrixChainMemo(int startIdx, int endIdx);
	int MatrixChainBottomUp(int startIdx, int endIdx);
	void SetMemo();
}
