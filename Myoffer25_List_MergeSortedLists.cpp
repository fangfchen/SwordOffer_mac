//#include"stdafx.h"
#include<iostream>
#include"List.h"
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。
//==================================================================
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/


class Solution25 {
public:
	/***--------------------------------------------------------------
	思路1：
	用两个指针p1和p2分别指向两个链表当前的节点，用p3指向合并后的链表当前节点。
	先从phead1和phead2中取较小的一个作为合并后链表的头结点。
	然后依次比较p1和p2，每次把较小的一个赋给p3，同时后移一位（p1、p2中较小的那个后移，p3后移），直到某个链表遍历完。
	把另一个链表（没遍历完的）剩余的部分复制给新链表。
	(注意：注意某个为空链表的情况。)
	--------------------------------------------------------------***/
	ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr) return pHead2;
		if (pHead2 == nullptr) return pHead1;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode* phmer = nullptr;
		//先给头指针赋值
		if (p1->val < p2->val) {
			phmer = p1;
			p1 = p1->next;
		}
		else {
			phmer = p2;
			p2 = p2->next;
		}
		//每次把p1和p2中较小的一个赋值给p3，并后移（注：P1/P2和P3都要后移！）
		ListNode* p3 = phmer;
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->val < p2->val) {
				p3->next = p1;
				p3 = p3->next;  
				p1 = p1->next;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
				p2 = p2->next;
			}
		}
		//若循环结束时某个链表已遍历完，则把另一个链表剩下的加进来
		if (p1 == nullptr) {  //只需指一次！不用一次次的赋值！（因为后面天然连接在一起，不用改结构）
			p3->next = p2;
		}
		else {
			p3->next = p1;
		}
		//if (p1 == nullptr) {
		//	while (p2 != nullptr) {
		//		p3->next = p2;
		//		p3 = p3->next;
		//		p2 = p2->next;
		//	}
		//}
		//else {
		//	while (p1 != nullptr) {
		//		p3->next = p1;
		//		p3 = p3->next;
		//		p1 = p1->next;
		//	}
		//}
		return phmer;
	}

	/***--------------------------------------------------------------
	思路2【书】：
	用递归实现：每次都看作合并两个链表的剩余部分（参数为两个链表剩余部分的头结点），返回的为剩余部分合并后的头结点。
	(注意：注意某个为空链表的情况。)
	--------------------------------------------------------------***/
	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr) return pHead2;
		if (pHead2 == nullptr) return pHead1;
		//ListNode* p1 = pHead1;
		//ListNode* p2 = pHead2;
		ListNode* phmer = nullptr;
		if (pHead1->val < pHead2->val) {
			phmer = pHead1;
			phmer->next = Merge2(pHead1->next, pHead2);
		}
		else{
			phmer = pHead2;
			phmer->next = Merge2(pHead1, pHead2->next);
		}
		return phmer;
	}

	//============================test===============================
	void Test(ListNode* phead1, ListNode* phead2) {
		ListNode* phmer = Merge1(phead1, phead2);
		PrintList(phmer);
		cout << endl;
	}

	//3->4->8
	//1->2->6
	void test1() {
		printf("Test1:\n");
		ListNode* phead1 = nullptr;
		PushBackNode(&phead1, 3);
		PushBackNode(&phead1, 4);
		PushBackNode(&phead1, 8);
		ListNode* phead2 = nullptr;
		PushBackNode(&phead2, 1);
		PushBackNode(&phead2, 2);
		PushBackNode(&phead2, 6);
		printf("Original List:\n");
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("1 2 3 4 6 8\n");
		printf("My Answer:\n");
		Test(phead1,phead2);
	}

	//7
	//3
	void test2() {
		printf("Test2:\n");
		ListNode* phead1 = nullptr;
		PushBackNode(&phead1, 7);
		ListNode* phead2 = nullptr;
		PushBackNode(&phead2, 3);
		printf("Original List:\n");
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("3 7\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	//1->3
	//空
	void test3() {
		printf("Test3:\n");
		ListNode* phead1 = nullptr;
		PushBackNode(&phead1, 1);
		PushBackNode(&phead1, 3);
		ListNode* phead2 = nullptr;
		printf("Original List:\n");
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("1 3\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	//1->2->3
	//1->2->3
	void test4() {
		printf("Test4:\n");
		ListNode* phead1 = nullptr;
		PushBackNode(&phead1, 1);
		PushBackNode(&phead1, 2);
		PushBackNode(&phead1, 3);
		ListNode* phead2 = nullptr;
		PushBackNode(&phead2, 1);
		PushBackNode(&phead2, 2);
		PushBackNode(&phead2, 3);
		printf("Original List:\n");
		PrintList(phead1);
		PrintList(phead2);
		printf("Correct Answer:\n");
		printf("1 1 2 2 3 3\n");
		printf("My Answer:\n");
		Test(phead1, phead2);
	}

	void run() {
		test1();
		test2();
		test3();
		test4();
	}
};

//int main() {
//	Solution25 s;
//	s.run();
//}
