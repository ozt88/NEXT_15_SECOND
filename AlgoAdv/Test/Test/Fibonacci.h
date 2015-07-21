#pragma once

namespace Fibonacci
{
	unsigned int Fibo(unsigned int num);
	unsigned int FiboBottomUp(unsigned int num);
	unsigned int FiboMemoization(unsigned int num);

	void FiboTest();

	template < unsigned num >
	struct Fibo_t
	{
		enum
		{
			val = Fibo_t<num - 1>::val + Fibo_t<num - 2>::val
		};
	};

	template<>
	struct Fibo_t < 0 >
	{
		enum
		{
			val = 0
		};
	};

	template<>
	struct Fibo_t < 1 >
	{
		enum 
		{
			val = 1
		};
	};
};

