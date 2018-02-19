#include<iostream>
#include<vector>
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
//==================================================================


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *parent;  //指向父亲节点！（牛客上为next）
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), parent(NULL) {

    }
};
class Solution8 {
public:

/***--------------------------------------------------------------
思路1【书】：while实现
分类讨论：
1. 如果该节点有right：向下找第一个没有左孩子的节点
2. 如果该节点无right：
(1)无父亲：返回空（自己是根，无下一个）
(2)自己是left：返回它父亲
(3)自己是right：向上找第一个左孩子的父亲节点（注意：找到根还没找到的情况！返回空）
--------------------------------------------------------------***/
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode==nullptr) return nullptr;
        if (pNode->right != nullptr){        //1.如果有右孩子,向下找到第一个没有左孩子的节点
            TreeLinkNode* ptemp = pNode->right;
            while(ptemp->left != nullptr){
                ptemp = ptemp->left;
            }
            return ptemp;
        }
        else{                                //2.如果没有右孩子
            if (pNode->parent == nullptr)      //(1)如果是根，返回空（自己就是最后一个）
                return nullptr;
            if (pNode->parent->left == pNode){ //(2)如果自己是父亲的左孩子，返回父亲
                return pNode->parent;
            }
            else{                            //(3)如果自己是父亲的右孩子，向上找到第一个左孩子的父亲节点
                TreeLinkNode* ptemp = pNode->parent;
                while(ptemp->parent!=nullptr && ptemp->parent->left != ptemp){
                    ptemp = ptemp->parent;
                }
                if (ptemp->parent == nullptr)  //这个判断也可以不要
                    return nullptr;
                else
                    return ptemp->parent;
            }
        }
    }


/***--------------------------------------------------------------
思路2：递归实现
--------------------------------------------------------------***/
    TreeLinkNode* FindDown(TreeLinkNode* pNode){  //向下找到第一个没有左孩子的节点
        if (pNode->left == nullptr)
            return pNode;
        else
            return FindDown(pNode->left);
    }

    TreeLinkNode* FindUp(TreeLinkNode* pNode){    //向上找到第一个左孩子的父亲节点
        if (pNode->parent== nullptr) //如果没父亲，说明已经搜索到根节点，返回空（自己就是最后一个）
            return nullptr;
        if (pNode->parent->left == pNode)  //如果自己是左孩子,返回父亲
            return pNode->parent;
        else
            return FindUp(pNode->parent);
    }

    TreeLinkNode* GetNext2(TreeLinkNode* pNode)
    {
        if (pNode==nullptr) return nullptr;
        if (pNode->right != nullptr){        //如果有右孩子,向下找
            return FindDown(pNode->right);
        }
        else{                                //如果没有右孩子
            if (pNode->parent == nullptr)      //如果是根，返回空（自己就是最后一个）
                return nullptr;
            if (pNode->parent->left == pNode){ //如果自己是父亲的左孩子，返回父亲
                return pNode->parent;
            }
            else{                            //如果自己是父亲的右孩子，向上找
                return FindUp(pNode->parent);
            }
        }
    }



//============================test===============================
    TreeLinkNode* construct(const vector<int>& pre, const vector<int>& vin, int prestart, int vinstart, int length){
        //参数：
        //Root-用来记录树的根，pre-原前序，vin-原中序，
        //prestart-当前子树在pre中的起始位置,vinstart-当前子树在vin中的起始位置, length-当前子树长度

        if (length<=0) return nullptr;  //说明已经到叶子节点下
        int parent = pre[prestart];     //注：是start不是0！！
        TreeLinkNode* pParent = new TreeLinkNode(parent);

        //计算左右子树节点数量
        int num_left=-1;
        for(int i=vinstart;i<vinstart+length;i++){  //别往加start!
            if (vin[i]==parent){
                num_left = i-vinstart;
                break;
            }
        }
        if (num_left == -1) {  //若中序中没有找到父亲，则抛出异常
            throw exception();
        }
        int num_right = length - num_left -1;

        //判断是否为叶子节点，并判断异常
        if (length == 1){
            if (pre[prestart]==vin[vinstart])
                return pParent;
            else
                throw exception();
        }

        //递归生成左右子树(特别注意！起始位置要加上start！)
        TreeLinkNode* pleft = construct(pre, vin, prestart+1, vinstart, num_left);
        pParent->left  = pleft;
        if (pleft!=nullptr) pleft->parent = pParent;
        TreeLinkNode* pright = construct(pre, vin, prestart+num_left+1, vinstart+num_left+1, num_right);
        pParent->right = pright;
        if (pright!=nullptr) pright->parent = pParent;

        return pParent; //别忘了返回！！
    }

    TreeLinkNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size()==0 || vin.size()==0) return nullptr;
        return construct(pre, vin, 0, 0, pre.size()); //返回的即根节点！
    }

    void Test(TreeLinkNode* pnode)
    {
        TreeLinkNode* pnext = GetNext(pnode);
        if (pnext == nullptr)
            cout<<"nullptr"<<endl<<endl;
        else
            cout<<pnext->val<<endl<<endl;
    }

    //7
    void test1(TreeLinkNode* root){
        printf("Test1:\n");
        TreeLinkNode* pnode = root->left->left->right;
        printf("Input Node:     7\n");
        printf("Correct Answer: 2\n");
        printf("My Answer:      ");
        Test(pnode);
    }

    //3
    void test2(TreeLinkNode* root){
        printf("Test2:\n");
        TreeLinkNode* pnode = root->right;
        printf("Input Node:     3\n");
        printf("Correct Answer: 8\n");
        printf("My Answer:      ");
        Test(pnode);
    }

    //6
    void test3(TreeLinkNode* root){
        printf("Test3:\n");
        TreeLinkNode* pnode = root->right->right;
        printf("Input Node:     6\n");
        printf("Correct Answer: nullptr\n");
        printf("My Answer:      ");
        Test(pnode);
    }

    //2
    void test4(TreeLinkNode* root){
        printf("Test4:\n");
        TreeLinkNode* pnode = root->left;
        printf("Input Node:     2\n");
        printf("Correct Answer: 1\n");
        printf("My Answer:      ");
        Test(pnode);
    }


    // 普通二叉树
    //              1
    //           /     \
    //          2       3
    //         /       / \
    //        4       5   6
    //         \         /
    //          7       8
    void run()
    {
        const int length = 8;
        int apre[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
        int ain[length] =  { 4, 7, 2, 1, 5, 3, 8, 6 };
        vector<int> preorder(&apre[0], &apre[length]);
        vector<int> inorder(&ain[0], &ain[length]);
        printf("The preorder sequence is: ");
        for (int i = 0; i < length; ++i)
            printf("%d ", preorder[i]);
        printf("\n");

        printf("The inorder sequence is:  ");
        for (int i = 0; i < length; ++i)
            printf("%d ", inorder[i]);
        printf("\n");
        TreeLinkNode* root = reConstructBinaryTree(preorder, inorder);

        test1(root);
        test2(root);
        test3(root);
        test4(root);
    }

};

//int main(){
//    Solution8 s;
//    s.run();
//}
