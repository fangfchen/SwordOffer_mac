struct ListNode {
	int val;
	ListNode *next;
	//struct ListNode *next; 
	//ListNode(int x) :  //可以用这种方式创建值为x的节点
	//	val(x), next(NULL) {
	//}
}; 
 
ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void PushBackNode(ListNode** ppHead, int value);
void RemoveNode(ListNode** ppHead, int value);