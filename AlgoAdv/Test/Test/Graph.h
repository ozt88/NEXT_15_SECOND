#pragma once


struct Edge;
struct Node;
struct Graph;

bool BFSCheck(Graph* root, Node* src);
bool DFSCheck(Graph* root, Node* src);

Node* MakeNodes(Graph* graph);
void TestBFS();
void TestDFS();


struct Edge
{
	int mWeight;
	Node* mSrc;
	Node* mDst;
};

struct Node
{
	Node()
		:mId(-1), mIsChecked(false), mValue(0)
	{
	}

	Node(int id)
		:mId(id), mIsChecked(false), mValue(0)
	{
	}

	~Node()
	{
		for(auto edge : mEdges)
		{
			delete edge;
		}
		mEdges.clear();
	}

	void Print()
	{
		printf("Node id: %d Checked\n");
	}

	int mId;
	int mValue;
	bool mIsChecked;
	std::vector<Edge*> mEdges;
};

struct Graph
{
	~Graph()
	{
		for(auto node : mNodes)
		{
			delete node;
		}
		mNodes.clear();
	}
	std::vector<Node*> mNodes;
};

