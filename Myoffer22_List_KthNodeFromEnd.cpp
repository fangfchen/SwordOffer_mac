//#include"stdafx.h"
#include<iostream>
#include"List.h"
#include<stack>
using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。
//==================================================================
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

class Solution22 {
public:
	/***--------------------------------------------------------------
	思路1：利用“栈”先把所有节点放到栈里，再依次取出。
	(注意：k<1和k>n的情况！)
	--------------------------------------------------------------***/
	ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k<1) //记得判断k<1的情况！
			return nullptr;
		ListNode* pnode = pListHead;
		stack<ListNode*> s;
		int num = 0;
		while (pnode != nullptr) {
			s.push(pnode);
			pnode = pnode->next;
			num++;
		}
		if (k > num) return nullptr; //如果k>节点总数量则返回空指针
		for (int i = 1; i < k; i++) {
			s.pop();
		}
		return s.top();
	}
	/***--------------------------------------------------------------
	思路2【书】：用两个指针p1和p2，p1遍历到第k个时p2开始遍历，当p1指向尾节点时p2指向倒数第k个。
	(注意：k<1和k>n的情况！)
	--------------------------------------------------------------***/
	ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k<1) //记得判断k<1的情况！
			return nullptr;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		int i = 0;
		while (p1!=nullptr) {
			i++;
			p1 = p1->next;
			if (i > k) p2 = p2->next;
		}
		if (k > i) return nullptr;
		return p2;
	}

	//============================test===============================
	void Test(ListNode* phead, unsigned int k) {
		ListNode* pnode = FindKthToTail2(phead, k);
		if (pnode != nullptr)
			cout << pnode->val << endl << endl;
		else
			cout << endl << endl;
	}

	void test1() {
		printf("Test1:\n");
		unsigned int k = 2;
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		PushBackNode(&phead, 2);
		PushBackNode(&phead, 3);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("2\n");
		printf("My Answer:\n");
		Test(phead,k);
	}

	//单节点
	void test2() {  
		printf("Test2:\n");
		unsigned int k = 1;
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(phead, k);
	}

	//k>n
	void test3() {
		printf("Test3:\n");
		unsigned int k = 3;
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		PushBackNode(&phead, 2);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("nullptr\n");
		printf("My Answer:\n");
		Test(phead, k);
	}

	void run() {
		test1();
		test2();
		test3();
	}
};


//int main() {
//	Solution22 s;
//	s.run();
//}