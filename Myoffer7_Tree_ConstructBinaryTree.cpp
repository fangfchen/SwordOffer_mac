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

/***--------------------------------------------------------------
思路：递归
1. 前序的第一个即为根（父亲），在中序中找到根的位置，则左边是左子树的，右边是右子树的，只要知道数量，则可以把前序也化为左子树和右子树。
2. 划分后，每部分的操作和上述一样，固可以用递归实现。
注：
1. 因为带入的是当前子树在原前序和原中序的起始坐标，所以所有操作都要考虑到起始坐标！！！
2. 记得return！
--------------------------------------------------------------***/
class Solution7 {
public:
    TreeNode* construct(const vector<int>& pre, const vector<int>& vin, int prestart, int vinstart, int length){
        //参数：
        //Root-用来记录树的根，pre-原前序，vin-原中序，
        //prestart-当前子树在pre中的起始位置,vinstart-当前子树在vin中的起始位置, length-当前子树长度

        if (length<=0) return nullptr;  //说明已经到叶子节点下
        int parent = pre[prestart];     //注：是start不是0！！
        TreeNode* pParent = new TreeNode(parent);

        //计算左右子树节点数量
        int num_left=-1;
        for(int i=vinstart;i<vinstart+length;i++){  //别往加start!
            if (vin[i]==parent){
                num_left = i-vinstart;
                break;
            }
        }
		if (num_left == -1) {  //若中序中没有找到父亲，则抛出异常
			throw exception();
		}
        int num_right = length - num_left -1;

		//判断是否为叶子节点，并判断异常
		if (length == 1){
			if (pre[prestart]==vin[vinstart])
				return pParent;
			else
				throw exception();
		}

        //递归生成左右子树(特别注意！起始位置要加上start！)
        pParent->left  = construct(pre, vin, prestart+1, vinstart, num_left);
        pParent->right = construct(pre, vin, prestart+num_left+1, vinstart+num_left+1, num_right);

		return pParent; //别忘了返回！！
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size()==0 || vin.size()==0) return nullptr;
        return construct(pre, vin, 0, 0, pre.size()); //返回的即根节点！
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
		cout<<endl;
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
		int ain[length] =  { 4, 7, 2, 1, 5, 3, 8, 6 };
		vector<int> preorder(&apre[0], &apre[length]);
		vector<int> inorder(&ain[0], &ain[length]);
		Test(preorder, inorder);
	}

//	只有右子树
//			1
//			 \
//			  2
//			   \
//			    3
	void test2()
	{
		printf("Test2:\n");
		const int length = 3;
		int apre[length] = { 1, 2, 3};
		int ain[length] =  { 1, 2, 3};
		vector<int> preorder(&apre[0], &apre[length]);
		vector<int> inorder(&ain[0], &ain[length]);
		Test(preorder, inorder);
	}

//	只有一个根节点
	void test3()
	{
		printf("Test3:\n");
		const int length = 1;
		int apre[length] = { 1 };
		int ain[length] =  { 1 };
		vector<int> preorder(&apre[0], &apre[length]);
		vector<int> inorder(&ain[0], &ain[length]);
		Test(preorder, inorder);
	}

	void run() {
		test1();
		test2();
		test3();
	}

};

//int main() {
//	Solution7 s;
//	s.run();
//}