//#include"stdafx.h"
#include<iostream>
#include"BinaryTree.h"
using namespace std;

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight) {
	if (pParent != nullptr) {
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}

void PrintTreeNode(TreeNode* pNode) {
	if (pNode != nullptr) {
		cout << "Value: " << pNode->val;
		//left
		if (pNode->left != nullptr)
			cout << ", Left: " << pNode->left->val;
		else
			cout << ", Left: null";
		//right
		if (pNode->right != nullptr)
			cout << ", Right: " << pNode->right->val;
		else
			cout << ", Right: null";
	}
	else
		cout << "Null Node!";
	cout << endl;
}

void PrintTree(TreeNode* pRoot) {
	if (pRoot == nullptr)
		return;
	else
		PrintTreeNode(pRoot);

	PrintTree(pRoot->left);
	PrintTree(pRoot->right);
}

void DestroyTree(TreeNode* pRoot) {
	if (pRoot != nullptr) {
		TreeNode* pleft = pRoot->left;
		TreeNode* pright = pRoot->right;
		
		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pleft);
		DestroyTree(pright);
	}
}