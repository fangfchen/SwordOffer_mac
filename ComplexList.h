struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(nullptr), random(nullptr) {
	}
};

void BuildNodes(RandomListNode* pNode, RandomListNode* pNext, RandomListNode* pRandom);
void PrintList(RandomListNode* pHead);


