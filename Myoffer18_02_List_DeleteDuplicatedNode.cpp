//#include"stdafx.h"
#include<iostream>
#include"List.h"
using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题18_02：删除链表中重复的结点
// 题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。
//==================================================================

// 参数:
//         pHead:     表头
// 返回值: 
//         ListNode*: 处理后的表头
/* 
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/

class Solution18_2 {
public:
	/***--------------------------------------------------------------
	思路1：
	1. 设两个指针，pPre指向重复节点的前一个节点；pCurrent指向当前节点，从pPre->next开始，依次和pPre->next的值比较，停在重复的最后一个节点（比较的时候用pCurrent->next和pPre->next比较）。
	为了避免从第一个节点开始就重复（此时没有pPre），故在表头前加一个“虚拟表头”，以使操作统一化。
	2. 因为可能出现连续重复多个，故用循环判断，若pCurrent->next=pPre->next则令pCurrent后移，继续比较，直到不相等或pCurrent已经是最后一个节点为止。
	此时：
	若pCurrent移动了且停在尾节点：说明有重复并一直重复到最后，故删除pPre->next开始后面所有节点，并令pPre->next=nullptr；
	若pCurrent移动了但没停在尾节点：说明中间有一段重复，故删除pPre->next到pCurrent的节点，并令pPre->next=pCurrent->next；
	若pCurrent没有移动：说明没有重复，pPre后移。
	3. 重复第2步，直到所有的节点都比完（pPre->next不为空）。
	【特点：用虚拟表头避免头部重复的判断；每次先把重复的部分找到再统一删除。】
	--------------------------------------------------------------***/
	void DeleteNode(ListNode* pstart, ListNode* pend) {
		ListNode* pnode = pstart;
		ListNode* pnext = nullptr;
		while (pnode != pend) {
			pnext = pnode->next;
			delete pnode;
			pnode = pnext;
		}
		delete pend;
	}

	ListNode* deleteDuplication1(ListNode* pHead)
	{
		if (pHead == nullptr) {
			return pHead;
		}
		else if (pHead->next == nullptr) { //只有一个节点
			return pHead;
		}
		ListNode* vhead = new ListNode();  //在head前加一个虚拟节点(注：这里需要实例化)(牛客网提交时里面要加0)
		vhead->next = pHead;     
		ListNode* pPre = vhead;  //记录重复节点的前一个节点
		ListNode* pCurrent;      //当前节点，从pPre->next开始，停在最后一个重复节点
		while (pPre->next != nullptr) {
			pCurrent = pPre->next;
			while (pCurrent->next != nullptr && pCurrent->next->val == pPre->next->val) { //比较时用pCurrent的后一个比
				pCurrent = pCurrent->next;
			}
			if (pCurrent != pPre->next) {  //如果移动了（其实这两种情况可以并到一起写！）
				////移动&&在末尾：有重复，删除后面所有
				//if (pCurrent->next == nullptr) {  
				//	DeleteNode(pPre->next, pCurrent);
				//	pPre->next = nullptr;
				//}
				//else {    
				////移动了&&不在末尾：有重复，删除中间部分
				//	ListNode* pnext = pCurrent->next;       //注：要提前存下来！否则pCurrent删了就没了！
				//	DeleteNode(pPre->next, pCurrent);
				//	pPre->next = pnext;
				//}
				ListNode* pnext = pCurrent->next;     
				DeleteNode(pPre->next, pCurrent);
				pPre->next = pnext;
			}
			else {                 
				//如果没有移动：没重复，不删，pPre后移
					pPre = pPre->next;
			}	 
		}
		return vhead->next;
		
	}
	/***--------------------------------------------------------------
	思路2【书】：
	1. 设两个指针，pPre指向重复节点的前一个节点；pNode指向当前节点，从pPre->next开始。
	2. 先判断是否有重复(pNode的值是否等于pNode->next)：
	   若没重复，pPre和pNode都后移；
	   若有重复，则用while找有多少重复，且边找边删（把第一个value先取出来），直到不重复或pNode为nullptr为止。
	   此时还需判断是否为头部重复，若是则令pHead=pNode；否则令pPre->next = pNode。
	3. 重复第2步，直到pNode=nullptr为止。
	【特点：先判断是否有重复，若有重复在找有多少重复，且边找边删。】
	--------------------------------------------------------------***/
	ListNode* deleteDuplication2(ListNode* pHead) {
		if (pHead == nullptr) {
			return pHead;
		}
		else if (pHead->next == nullptr) { //只有一个节点
			return pHead;
		}
		ListNode* pPre = nullptr;
		ListNode* pNode = pHead;
		while (pNode!=nullptr && pNode->next!=nullptr) {
			if (pNode->val != pNode->next->val) {  //若没重复
				pPre = pNode;
				pNode = pNode->next;
			}
			else{  //若有重复
				int value = pNode->val;
				while (pNode != nullptr && pNode->val == value) {
					ListNode* pnext = pNode->next;
					delete pNode;  //边找边删
					pNode = pnext;
				}
				if (pPre == nullptr) { //若第一个节点就开始重复，则直接改pHead
					pHead = pNode;
				}
				else {
					pPre->next = pNode;
				}
			}
		}
		return pHead;
	}


	//============================test===============================
	//需include"List.cpp"中的函数（因为List.cpp中已经定义stuct，这里不能再定义）
	void Test(ListNode* phead) {
		ListNode* h = deleteDuplication2(phead);
		PrintList(h);
		cout << endl;
	}

	//一般情况：1->2->2->3->4->4->5 
	void test1() {
		printf("Test1:\n");
		ListNode* pHead = nullptr; //一定要初始化为空指针！！！
		PushBackNode(&pHead, 1);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 3); 
		PushBackNode(&pHead, 4);
		PushBackNode(&pHead, 4);
		PushBackNode(&pHead, 5);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("1 3 5\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	//末尾有重复：1->2->2->2
	void test2() {
		printf("Test2:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 1);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 2);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	//开头连续有重复：1->1->2->2->2->3
	void test3() {
		printf("Test3:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 1);
		PushBackNode(&pHead, 1);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 3);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("3\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	//两个节点且重复：4->4
	void test4() {
		printf("Test4:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 4);
		PushBackNode(&pHead, 4);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	//两个节点不重复：6->4
	void test5() {
		printf("Test5:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 6);
		PushBackNode(&pHead, 4);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("6 4\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	//单节点：1
	void test6() {
		printf("Test6:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 1);
		printf("Original List:\n");
		PrintList(pHead);
		printf("Correct Answer:\n");
		printf("1\n");
		printf("My Answer:\n");
		Test(pHead);
	}

	void run() {
		test1();
		test2();
		test3();
		test4();
		test5();
		test6();
	}
};

//int main() {
//	Solution18_2 s;
//	s.run();
//}