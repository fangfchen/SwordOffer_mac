//#include"stdafx.h"
#include<iostream>
#include"List.h"
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题3（一）：找出数组中重复的数字
// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。
//==================================================================
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

/***--------------------------------------------------------------
思路：时间O(n)，空间O(1)
1. 先分别遍历两个链表得到各自的长度，算出长度差diff；
2. 让长的链表指针先走diff步，再和短链表指针一起走，直到遇到相同节点或某个遍历结束。
(注意：没有公共节点的情况！)
(另：两个链表若有公共节点，则之后的部分一定一样（不会分叉）！)
--------------------------------------------------------------***/
class Solution52 {
public:
	int countnodes(ListNode* phead) {
		int n = 0;
		while (phead != nullptr) {
			n++;
			phead = phead->next;
		}
		return n;
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
		//分别计算两个链表的长度
		int num1 = countnodes(pHead1);
		int num2 = countnodes(pHead2);
		int diff = abs(num2 - num1);
		ListNode* pshort = nullptr;
		ListNode* plong = nullptr;
		if (num1 < num2) {
			pshort = pHead1;
			plong = pHead2;
		}
		else {
			pshort = pHead2;
			plong = pHead1;
		}
		//长的指针先走diff步，再一起走，找第一个相同的节点
		for (int i = 0; i < diff; i++) {
			plong = plong->next;
		}
		while (plong != pshort && plong!=nullptr && pshort!=nullptr) {  //注意没公共节点的情况！
			plong = plong->next;
			pshort = pshort->next;
		}
		return plong;
	}

	//============================test===============================
	void Test(ListNode* phead1, ListNode* phead2) {
		ListNode* pcom = FindFirstCommonNode(phead1, phead2);
		if (pcom == nullptr)
			cout << "null"<<endl;
		else
			cout<<pcom->val<<endl;
		cout << endl;
	}

	//1->2(共)->3
	//4->5->2(共)->3
	void test1() {
		printf("Test1:\n");
		ListNode* phead1 = nullptr;
		ListNode* p1 = CreateListNode(1);
		ListNode* p2 = CreateListNode(2);
		ListNode* p3 = CreateListNode(3);
		ConnectListNodes(p1, p2);
		ConnectListNodes(p2, p3);
		phead1 = p1;
		ListNode* phead2 = nullptr;
		ListNode* p4 = CreateListNode(4);
		ListNode* p5 = CreateListNode(5);
		ConnectListNodes(p4, p5);
		ConnectListNodes(p5, p2);
		ConnectListNodes(p2, p3);
		phead2 = p4;
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("2\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	//1(共)->2->3
	//1(共)->2->3
	void test2() {
		printf("Test2:\n");
		ListNode* phead1 = nullptr;
		ListNode* p1 = CreateListNode(1);
		ListNode* p2 = CreateListNode(2);
		ListNode* p3 = CreateListNode(3);
		ConnectListNodes(p1, p2);
		ConnectListNodes(p2, p3);
		phead1 = p1;
		ListNode* phead2 = p1;
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	//1->2->3
	//4->5->6
	void test3() {
		printf("Test3:\n");
		ListNode* phead1 = nullptr;
		PushBackNode(&phead1, 1);
		PushBackNode(&phead1, 2);
		PushBackNode(&phead1, 3);
		ListNode* phead2 = nullptr;
		PushBackNode(&phead2, 4);
		PushBackNode(&phead2, 5);
		PushBackNode(&phead2, 6);
		printf("Original List:\n");
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("null\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	void run() {
		test1();
		test2();
		test3();
	}
};
//
//int main() {
//	Solution52 s;
//	s.run();
//}