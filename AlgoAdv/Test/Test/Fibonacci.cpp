#include "stdafx.h"
#include "Fibonacci.h"

unsigned int Fibonacci::FiboBottomUp(unsigned int num)
{
	static std::vector<unsigned int> fiboResult;
	fiboResult.push_back(0);
	fiboResult.push_back(1);

	for(unsigned i = 0; i <= num; ++i)
	{
		if(i < fiboResult.size())
		{
			continue;
		}
		else
		{
			_ASSERT(i > 1);
			unsigned int newResult = 
				fiboResult[i - 1] + fiboResult[i - 2];
			fiboResult.push_back(newResult);
		}
	}

	return fiboResult[num];
}

unsigned int Fibonacci::Fibo(unsigned int num)
{

	if(num < 2)
		return num;
	else
		return Fibo(num - 1) + Fibo(num - 2);

}

unsigned int Fibonacci::FiboMemoization(unsigned int num)
{
	static std::map<unsigned int, unsigned int> fiboResult;
	
	if(fiboResult.find(num) != fiboResult.end())
		return fiboResult[num];

	if(num < 2)
	{
		fiboResult[num] = num;
	}
	else
	{
		fiboResult[num] = 
			FiboMemoization(num - 1) + FiboMemoization(num - 2);
	}

	return fiboResult[num];
}

void Fibonacci::FiboTest()
{
	unsigned int input = rand() % 10;
	unsigned int result = FiboBottomUp(input);
	printf("FiboBottomUp(%u) = %u\n", input, result);

	result = FiboMemoization(input);
	printf("FiboMemoization(%u) = %u\n", input, result);
}
