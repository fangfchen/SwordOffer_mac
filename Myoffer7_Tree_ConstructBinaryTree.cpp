//#include"stdafx.h"
#include<iostream>
#include<vector>
#include"BinaryTree.h"
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
// {1, 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建
// 出二叉树并输出它的头结点。
//==================================================================

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution7 {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

		TreeNode* pRoot = new TreeNode(0);
		return pRoot;
	}

	//============================test===============================
	void Test(vector<int> preorder, vector<int> inorder)
	{
		int length = preorder.size();
		printf("The preorder sequence is: ");
		for (int i = 0; i < length; ++i)
			printf("%d ", preorder[i]);
		printf("\n");

		printf("The inorder sequence is:  ");
		for (int i = 0; i < length; ++i)
			printf("%d ", inorder[i]);
		printf("\n");

		try
		{
			TreeNode* root = reConstructBinaryTree(preorder, inorder);
			PrintTree(root);
			DestroyTree(root);
		}
		catch (std::exception& exception)
		{
			printf("Invalid Input.\n");
		}
	}

	// 普通二叉树
	//              1
	//           /     \
	//          2       3  
	//         /       / \
	//        4       5   6
	//         \         /
	//          7       8
	void test1()
	{
		printf("Test1:\n");
		const int length = 8;
		int apre[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
		int ain[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
		vector<int> preorder(&apre[0], &apre[length]);
		vector<int> inorder(&ain[0], &ain[length]);
		Test(preorder, inorder);
	}

	void run() {
		test1();
	}
};

//int main() {
//	Solution7 s;
//	s.run();
//}