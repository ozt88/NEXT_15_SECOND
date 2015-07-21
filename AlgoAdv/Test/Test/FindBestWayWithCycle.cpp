#include "stdafx.h"
#include "FindBestWayWithCycle.h"


void FindBestWayWithCycle::FindBestWayWithCycleRecursion(Graph* graph)
{

}

FindBestWayWithCycle::AcyclicPolyGraph* FindBestWayWithCycle::MakeAcyclicPolyGraph(Graph* original)
{
	int size = original->mNodes.size();
	AcyclicPolyGraph* newGraph = new AcyclicPolyGraph();

	for(int idx = 0; idx < size; ++idx)
	{
		for(auto node : original->mNodes)
		{
			int id = node->mId;
			Node* newNode = new Node(id);
			newNode->mValue = idx;
			newGraph->mNodes[idx][id] = newNode;
		}

		if(idx > 0)
		{
			for(auto node : original->mNodes)
			{
				Node* checkNode = newGraph->mNodes[idx - 1][node->mId];
				for(auto edge : node->mEdges)
				{
					Edge* newEdge = new Edge();
					int dstId = edge->mDst->mId;
					int weight = edge->mWeight;

					newEdge->mDst = newGraph->mNodes[idx][dstId];
					newEdge->mSrc = checkNode;
					newEdge->mWeight = weight;

					checkNode->mEdges.push_back(newEdge);
				}
			}
		}
	}

	return newGraph;
}

