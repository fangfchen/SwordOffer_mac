//#include"stdafx.h"
#include<iostream>
#include"ComplexList.h"
#include<map>
using namespace std;

// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

/*
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {
	}
};
*/
class Solution35 {
public:
	/***--------------------------------------------------------------
	思路1:时间O(n),空间O(n)
	Step1. 按next复制链表主体，并用哈希表存下对应节点（先不复制random(sibling)，因为可能出现前指后）。
	Step2. 遍历链表，按哈希表复制random(sibling)。
	（注：random为nullptr的情况！）
	--------------------------------------------------------------***/
	RandomListNode* Clone1(RandomListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		//step1:按next复制链表主体（不含random，因为可能有指向后面的），并用哈希表存下对应节点
		RandomListNode* p1 = pHead;
		RandomListNode* p2 = nullptr;
		RandomListNode* phclone = nullptr;
		map<RandomListNode*, RandomListNode*> nodemap;
		while (p1 != nullptr) {
			RandomListNode* ptemp = new RandomListNode(p1->label);
			if (p1 == pHead) {
				phclone = ptemp;  //复制表头
				p2 = ptemp;
			}
			else {
				p2->next = ptemp;
				p2 = p2->next;
			}
			nodemap[p1] = p2;   //节点哈希表
			p1 = p1->next;
		}
		//step2:依次遍历链表，按哈希表复制random
		p1 = pHead;
		p2 = phclone;
		while (p1 != nullptr) {
			RandomListNode* pr = p1->random;
			if (pr == nullptr)
				p2->random = nullptr;
			else
				p2->random = nodemap[pr];
			p1 = p1->next;
			p2 = p2->next;
		}
		return phclone;
	}

	/***--------------------------------------------------------------
	思路2【书】:时间O(n),空间O(1)
	Step1. 按next顺序复制节点，并把复制节点都接在原节点后面。eg:A->A'->B->B'...
	Step2. 遍历链表，A'->random = A->random->next;
	Step3. 把原链表和复制链表拆开。
	（注：random为nullptr的情况！）
	--------------------------------------------------------------***/
	RandomListNode* Clone2(RandomListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		//Step1.按next顺序复制节点，并把复制节点都接在原节点后面。
		RandomListNode* p1 = pHead;
		while (p1 != nullptr) {
			RandomListNode* p2 = new RandomListNode(p1->label);
			RandomListNode* pnext = p1->next;
			p1->next = p2;
			p2->next = pnext;  //插入p2

			p1 = pnext;
		}
		//Step2.遍历链表，A'->random = A->random->next;
		p1 = pHead;
		while (p1 != nullptr) {
			RandomListNode* p2 = p1->next;
			if (p1->random == nullptr) {
				p2->random = nullptr;
			}
			else {
				p2->random = p1->random->next;
			}
			p1 = p1->next->next;
		}
		//Step3.把原链表和复制链表拆开。(注：这里要把两个表都拆了，只把复制后的接上提交会报错！)
		RandomListNode* phclone = pHead->next;
		p1 = pHead;
		while (p1->next != nullptr) {
			RandomListNode* pnext = p1->next;
			p1->next = p1->next->next;
			p1 = pnext;
		}
		return phclone;
	}


	//============================test===============================
	void Test(RandomListNode* phead) {
		RandomListNode* phclone = Clone2(phead);
		PrintList(phclone);
		cout << endl;
	}

	//1(3)->2(2)->3(null)->4(1)

	void test1() {
		printf("Test1:\n");
		RandomListNode* phead = nullptr;
		RandomListNode* p1 = new RandomListNode(1);
		RandomListNode* p2 = new RandomListNode(2);
		RandomListNode* p3 = new RandomListNode(3);
		RandomListNode* p4 = new RandomListNode(4);
		BuildNodes(p1, p2, p3);
		BuildNodes(p2, p3, p2); 
		BuildNodes(p3, p4, nullptr);
		BuildNodes(p4, nullptr, p1);
		phead = p1;
		printf("Original List:\n");
		PrintList(phead);
		printf("My Answer:\n");
		Test(phead);
	}

	void run() {
		test1();
	}
};
//
//int main() {
//	Solution35 s;
//	s.run();
//}