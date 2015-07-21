#pragma once
#include "Graph.h"
#define MAX_NODE_NUM 1000

namespace FindBestWayWithCycle
{
	struct AcyclicPolyGraph
	{
		Node* mNodes[MAX_NODE_NUM][MAX_NODE_NUM];
	};

	AcyclicPolyGraph* MakeAcyclicPolyGraph(Graph* original);
	void FindBestWayWithCycleRecursion(Graph* graph);
}