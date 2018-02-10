//#include"stdafx.h"
#include<iostream>
#include"List.h"
using namespace std;



//创建节点
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();
	pNode->val = value;
	pNode->next = nullptr;  //默认next为空
	return pNode;
}
 
//连接2个节点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == nullptr) {  //如果当前节点指针为空，则报错退出
		printf("Error to connect 2 nodes.\n");
	}
	else {
		pCurrent->next = pNext;
	}
}

//打印链表
void PrintList(ListNode* pHead) {
	//printf("PrintList starts.\n");
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->val << " ";
		pNode = pNode->next;
	}
	cout << endl;
	//printf("PrintList ends.\n");
}

//析构链表（删除所有节点）
void DestroyList(ListNode* pHead) {
	ListNode* pNode = pHead;
	ListNode* pNext;
	while (pNode != nullptr) {
		pNext = pNode->next;
		delete pNode;
		pNode = pNext;
	}
}

//在链表末尾添加一个节点（类似push_back(value)）
void PushBackNode(ListNode** ppHead, int value) {
	//新建节点
	ListNode* pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;
	//判断是否为空链表(表头为空)
	if (*ppHead == nullptr) {  
		*ppHead = pNew;  //若为空，表头指向新节点
	}
	else {
		ListNode* pNode = *ppHead;
		while (pNode->next != nullptr) {  
			pNode = pNode->next;
		}
		pNode->next = pNew;  //让末尾节点指向新节点
	}
}

//在链表中找到值为value的节点并删除(类似remove(value))
void RemoveNode(ListNode** ppHead, int value) {
	//空链表（表头为空）
	if (ppHead == nullptr || *ppHead == nullptr) {
		cout << "The List is empty.\n";
		return;
	}
	//表头指向的第一个节点就是要删除的点（需改变表头）
	ListNode* pDeleteNode = nullptr;
	if ((*ppHead)->val == value) {
		pDeleteNode = *ppHead;
		*ppHead = (*ppHead)->next;
	}
	else {
		ListNode* pNode = *ppHead;
		while (pNode->val != value && pNode != nullptr) {
			pNode = pNode->next;
		}
		if (pNode->val == value) {
			pDeleteNode = pNode;
			pNode = pNode->next;
		}
	}
	//删除节点
	if (pDeleteNode != nullptr) {
		delete pDeleteNode;
		pDeleteNode = nullptr;
	}
}

