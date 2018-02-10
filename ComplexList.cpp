//#include"stdafx.h"
#include <iostream>
#include "ComplexList.h"
using namespace std;

//连接pNode,pNext,pRandom
void BuildNodes(RandomListNode* pNode, RandomListNode* pNext, RandomListNode* pRandom)
{
	if (pNode != nullptr)
	{
		pNode->next = pNext;
		pNode->random = pRandom;
	}
}

//输出链表（每个点的label(val)和ramdom(sibling)）
void PrintList(RandomListNode* pHead)
{
	if (pHead == nullptr) {
		cout << "Empty List!" << endl;
		return;
	}
	cout << pHead->label;
	if (pHead->random != nullptr)
		cout << "(" << pHead->random->label << ")";
	else
		cout << "(null)";
	RandomListNode* pNode = pHead->next;
	while (pNode != nullptr)
	{
		//printf("The value of this node is: %d.\n", pNode->label);

		//if (pNode->random != nullptr)
		//	printf("The value of its sibling is: %d.\n", pNode->random->label);
		//else
		//	printf("This node does not have a sibling.\n");

		cout << "->"<<pNode->label;
		if (pNode->random != nullptr)
			cout << "(" << pNode->random->label << ")";
		else
			cout << "(null)";
		pNode = pNode->next;
	}
	cout << endl;
}