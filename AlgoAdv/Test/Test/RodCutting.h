#pragma once
#include <map>
namespace RodCutting
{
	using Prices = std::map < unsigned int, unsigned int > ;
	static Prices UnitPrices;
	static Prices MaxPrices;
	static Prices FirstCuttingSize;

	void MakeUnitPrices();
	void RodCuttingTest();
	void CheckBestCuttingWay(unsigned int size);
	unsigned int RodCuttingRecursive(unsigned int size);
	unsigned int RodCuttingDynamic(unsigned int size);
	unsigned int RodCuttingBottomUp(unsigned int size);
	
};

