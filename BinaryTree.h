//#include"stdafx.h"
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight);
void PrintTreeNode(TreeNode* pNode);
void PrintTree(TreeNode* pRoot);
void DestroyTree(TreeNode* pRoot);
