#include "stdafx.h"

struct Node
{
	Node* left;
	Node* right;
};

int Count(Node* node)
{
	if(node == nullptr)
		return 0;

	return Count(node->left) + Count(node->right) + 1;
}

int MakeNodes(Node** output)
{
	if(rand() % 2)
	{
		*output = new Node();
		return MakeNodes(&( *output )->left) + MakeNodes(&( *output )->right) + 1;
	}
	return 0;
}

void NodeTest()
{
	Node* root = new Node();
	int realCount = MakeNodes(&root);
	int testCount = Count(root);
	printf("RealCount : %d , TestCount : %d\n", realCount, testCount);
}