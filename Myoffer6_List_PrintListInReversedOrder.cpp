//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include"List.h"
using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
//==================================================================

// 参数:
//         head:    表头
// 返回值: 
//         vector<int>: 把链表按从尾到头的顺序排列

 
//struct ListNode {  //"List.cpp"中已经定义
//    int val;
//    ListNode *next;
//	//struct ListNode *next; 
//    //ListNode(int x) :
//    //        val(x), next(NULL) {
//    //}
//};
 
class Solution6 {
public:
/***--------------------------------------------------------------
思路1：利用“栈”的先进后出的性质。
--------------------------------------------------------------***/
	vector<int> printListFromTailToHead1(ListNode* phead) {
		vector<int> v;
		if (phead == nullptr) return v;
		stack<int> s;
		ListNode* pnode = phead;
		while (pnode != nullptr) {
			s.push(pnode->val);
			pnode = pnode->next; //记得继续往下指啊！！（老忘记！！）
		}
		while (!s.empty()) {
            int temp = s.top();
			v.push_back(temp);
			s.pop();
		}
		return(v);
	}

/***--------------------------------------------------------------
思路2：利用递归的“压栈”性质。
注：如果链表太长可能会"栈溢出"。
--------------------------------------------------------------***/
	void reverse_order_recursive(ListNode* pnode, vector<int>& v) {
		if (pnode->next != nullptr) {
			reverse_order_recursive(pnode->next, v);
		}
		v.push_back(pnode->val);  //要放在if外面！！否则末尾元素放不进去！
	}
	
	vector<int> printListFromTailToHead2(ListNode* phead) {
		vector<int> v;
		if (phead == nullptr) return v;
		reverse_order_recursive(phead, v);
		return(v);
	}
	
	//============================test===============================
	//需include"List.cpp"中的函数（因为List.cpp中已经定义stuct，这里不能再定义）
	void Test(ListNode* phead) {
		vector<int> v = printListFromTailToHead1(phead);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	//1->2->3->4
	void test1() {
		printf("Test1:\n");
		ListNode* pHead = nullptr; //一定要初始化为空指针！！！
		PushBackNode(&pHead, 1); 
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 3);
		PushBackNode(&pHead, 4);
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	//只有一个节点1
	void test2() {
		printf("Test2:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 1);
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	//空链表
	void test3() {
		printf("Test3:\n");
		ListNode* pHead = nullptr;
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	void run() {
		test1();
		test2();
		test3();
	}
};
//int main() {
//    Solution6 s;
//    s.run();
//}


