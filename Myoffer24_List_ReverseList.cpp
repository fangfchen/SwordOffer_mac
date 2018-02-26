//#include"stdafx.h"
#include<iostream>
#include"List.h"

using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
//==================================================================
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution24 {
public:
	/***--------------------------------------------------------------
	思路1【书】：定义3个指针：p1,p2,pnext分别依次指向连续的3个节点（即p2=p1->next;pnext=p2->next），每次先取出p2->next存在pnext中，再把p2->next改为p1。
	依次往后重复这个操作，直到p2为nullptr为止。
	(注意：
	 1个节点的情况;
	 别忘了令pHead->next=nullptr)
	--------------------------------------------------------------***/
	ListNode* ReverseList1(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;     //空链表
		if (pHead->next == nullptr) return pHead; //单节点链表
		ListNode* p1 = pHead;
		ListNode* p2 = pHead->next;
		pHead->next = nullptr; //令头结点下一个为nullptr（因为反转后为尾节点）
		while (p2 != nullptr) {
			ListNode* pnext = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = pnext;
		}
		return p1;
	}

	/***--------------------------------------------------------------
	思路2：利用递归实现。
	(注意：1个节点/2个节点的情况！)
	--------------------------------------------------------------***/
	void reverse(ListNode* pnode, ListNode** phrev) {  //该函数会令pnode的下一个节点的next指向pnode
		if (pnode->next == nullptr) {      //若pnode为尾节点，则令反转后的表头=pnode
			*phrev = pnode;
		}
		else {
			reverse(pnode->next, phrev);  //先递归再反转，否则后面无法获得正确的next
			ListNode* pn = pnode->next;
			pn->next = pnode;
		}
	}

	ListNode* ReverseList2(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;     //空链表
		if (pHead->next == nullptr) return pHead; //单节点链表
		ListNode* phrev = nullptr;
		reverse(pHead,&phrev);  //因为需要直到反转后的表头，所以带入&phrev
		pHead->next = nullptr;
		return phrev;
	}
	//============================test===============================
	void Test(ListNode* phead) {
		ListNode* phrev = ReverseList2(phead);
		PrintList(phrev);
		cout << endl;
	}

	//1->2->3
	void test1() {
		printf("Test1:\n");
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		PushBackNode(&phead, 2);
		PushBackNode(&phead, 3);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("3 2 1\n");
		printf("My Answer:\n");
		Test(phead);
	}

	//1->2
	void test2() {
		printf("Test2:\n");
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		PushBackNode(&phead, 2);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("2 1\n");
		printf("My Answer:\n");
		Test(phead);
	}

	//单节点
	void test3() {
		printf("Test3:\n");
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		printf("Original List:\n");
		PrintList(phead);
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(phead);
	}

	void run() {
		test1();
		test2();
		test3();
	}
};


//int main() {
//	Solution24 s;
//	s.run();
//}
