#include "stdafx.h"
#include "Graph.h"

#define MAX_NEIGHBOR 10

bool BFSCheck(Graph* graph, Node* src)
{
	if(graph == nullptr)
		return false;

	static std::queue<Node*> queue;

	queue.push(src);

	while(!queue.empty())
	{
		Node* curNode = queue.front();

		curNode->Print();
		curNode->mIsChecked = true;

		for(auto edge : curNode->mEdges)
		{
			auto neighbor = edge->mDst;

			if(neighbor == nullptr)
				return false;

			if(!neighbor->mIsChecked)
				queue.push(neighbor);
		}

		queue.pop();
	}

	return true;
}

bool DFSCheck(Graph* graph, Node* src)
{
	if(src == nullptr)
	{
		return false;
	}
	src->mIsChecked = true;

	for(auto edge : src->mEdges)
	{
		auto neighbor = edge->mDst;
		
		if(neighbor == nullptr)
			return false;

		if(!neighbor->mIsChecked)
			DFSCheck(graph, neighbor);
	}
	src->Print();
	return true;
}


 Node* MakeNodes(Graph* graph)
{
	static int id = 0;
	static int maxId = rand() % 100;
	if(id > maxId)
	{
		return nullptr;
	}

	Node* newNode = new Node(id++);
	graph->mNodes.push_back(newNode);

	int neighborNum = rand() % MAX_NEIGHBOR;
	for(int i = 0; i < neighborNum; ++i)
	{
		Node* neighbor = MakeNodes(graph);
		if(neighbor == nullptr)
			break;
		
		Edge* edge = new Edge();
		edge->mDst = neighbor;
		edge->mSrc = newNode;
		edge->mWeight = rand() % 100;
		newNode->mEdges.push_back(edge);
	}
	return newNode;
}

void TestBFS()
{
	Graph graph;
	Node* src = MakeNodes(&graph);
	BFSCheck(&graph, src);
}

void TestDFS()
{
	Graph graph;
	Node* src = MakeNodes(&graph);
	DFSCheck(&graph, src);
	delete src;
}

