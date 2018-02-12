//#include"stdafx.h"
#include<iostream>
#include"List.h"
#include<set>
using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。
//==================================================================
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/

class Solution23 {
public:
	/***--------------------------------------------------------------
	思路1：从头结点开始遍历链表，利用set存下每次访问的节点，当第一次出现set中已有该节点时，说明该节点之前已经访问过，故该节点为环入口。
	若遍历到链表尾还没出现，则链表中无环。
	(注意：无环的情况！)
	--------------------------------------------------------------***/
	ListNode* EntryNodeOfLoop1(ListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		set<ListNode*> setnode;
		ListNode* pnode = pHead;
		while (pnode != nullptr && setnode.find(pnode) == setnode.end()) {  //链表没结束，且该节点不在集合中
			setnode.insert(pnode);
			pnode = pnode->next;
		}
		if (setnode.find(pnode) != setnode.end())  //如果集合中已有该节点
			return pnode;
		else
			return nullptr;
	}
	/***--------------------------------------------------------------
	思路2【书】：
	（1）先判断是否有环：用两个指针，p1一次移1个，p2一次移2个，若p2追上了p1，则有环。
	（2）判断环的长度：在环中，p1不动，p2边走边计数，回到p1位置时计数的值即为环长度。
	（3）找到环入口：p2先移n步，p1再和p2一起移动，当p1和p2重合时，该节点即为环入口。
	--------------------------------------------------------------***/
	ListNode* EntryNodeOfLoop2(ListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		//判断是否有环
		bool existloop = true;
		ListNode* p1 = pHead;
		ListNode* p2 = pHead->next;
		while (p2 != p1 && p2 != nullptr && existloop==true) {
			p1 = p1->next;             //P2一次移两个
			if (p2->next == nullptr) { //出现nullptr即说明无环
				existloop = false;
			}
			else {
				p2 = p2->next->next;   //P2一次移两个
			}			
		}
		if (p2 == nullptr) existloop = false; //出现nullptr即说明无环
		if (existloop == false) return nullptr;
		//判断环的节点个数
		int loopnum = 1;
		p2 = p2->next;
		while (p1 != p2) {
			p2 = p2->next;
			loopnum++;
		}
		//找环入口
		p1 = pHead;
		p2 = pHead;
		for (int i = 0; i < loopnum; i++) {  //p2先移动loopnum下
			p2 = p2->next;
		}
		while (p1 != p2) {
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;
	}

	//============================test===============================
	void Test(ListNode* pHead) {
		ListNode* pentry = EntryNodeOfLoop2(pHead);
		if (pentry == nullptr)
			cout << endl << endl;
		else
			cout << pentry->val << endl << endl;
	}

	//1->2->3(3再->2)
	void test1() {
		printf("Test1:\n");
		ListNode* phead = nullptr;
		ListNode* p1 = CreateListNode(1);
		ListNode* p2 = CreateListNode(2);
		ListNode* p3 = CreateListNode(3);
		ConnectListNodes(p1, p2);
		ConnectListNodes(p2, p3);
		ConnectListNodes(p3, p2);
		phead = p1;
		printf("Correct Answer:\n");
		printf("2\n");
		printf("My Answer:\n");
		Test(phead);
	}

	//1->1（自环）
	void test2() {
		printf("Test2:\n");
		ListNode* phead = nullptr;
		ListNode* p1 = CreateListNode(1);
		ConnectListNodes(p1, p1);
		phead = p1;
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(phead);
	}

	//无环
	void test3() {
		printf("Test3:\n");
		ListNode* phead = nullptr;
		PushBackNode(&phead, 1);
		PushBackNode(&phead, 2);
		PushBackNode(&phead, 3);
		printf("Correct Answer:\n");
		printf("nullptr\n");
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
//	Solution23 s;
//	s.run();
//}