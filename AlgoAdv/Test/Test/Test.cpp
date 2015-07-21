// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Graph.h"
#include "Fibonacci.h"
#include "RodCutting.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
	RodCutting::RodCuttingTest();
	getchar();
	return 0;
}

