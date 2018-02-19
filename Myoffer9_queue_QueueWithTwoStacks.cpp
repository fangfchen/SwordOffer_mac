#include<iostream>
#include<stack>
using namespace std;

class Solution9
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        /***--------------------------------------------------------------
        思路1：
         若stack2不为空，直接pop;
         若stack2为空，把stack1->stack2，再pop;
         注：非法pop（队列中无元素时pop！）
        --------------------------------------------------------------***/
        int wait_pop;
        if (!stack2.empty()){  //若stack2不为空，直接pop;
            wait_pop = stack2.top();
            stack2.pop();
        }
        else{   // 若stack2为空，把stack1->stack2，再pop;
            while(!stack1.empty()){
                int temp = stack1.top();  //这里必须分2步写！
                stack2.push(temp);
                stack1.pop();
            }
            if (stack2.empty()){
                cout<<"Invalid pop!"<<endl;
                throw exception();
            }
            wait_pop = stack2.top();
            stack2.pop();
        }
        return wait_pop;

        /***--------------------------------------------------------------
        思路2：把stack1->stack2，pop stack2, stack2->stack1（每次都要移回去，太冗余！）
              注：非法pop（队列中无元素时pop！）
        --------------------------------------------------------------***/
//        if (stack1.empty()){
//            cout<<"Invalid pop!"<<endl;
//            throw exception();
//        }
//
//        while (!stack1.empty()){  //依次把stack1的顶端取出，压入stack2(相当于逆序)
//            int temp = stack1.top();
//            stack2.push(temp);
//            stack1.pop();
//        }
//
//        int wait_pop = stack2.top();//待返回的元素
//        stack2.pop();
//
//        while (!stack2.empty()){  //把stack2里的元素放回stack2
//            int temp = stack2.top();
//            stack1.push(temp);
//            stack2.pop();
//        }
//        return wait_pop;
    }





//============================test===============================
    void test1(){
        cout<<"Test1:\n";
        cout<<"Correct Answer:\n1 2 3\n";
        cout<<"My Answer:\n";
        push(1);
        push(2);
        cout<<pop()<<" ";
        push(3);
        cout<<pop()<<" ";
        cout<<pop()<<" ";
        cout<<"\n\n";
    }

    void test2(){
        cout<<"Test2:\n";
        cout<<"Correct Answer:\n1 2 3\n";
        cout<<"My Answer:\n";
        push(1);
        cout<<pop()<<" ";
        push(2);
        cout<<pop()<<" ";
        push(3);
        cout<<pop()<<" ";
        cout<<"\n\n";
    }

    void test3(){
        cout<<"Test3:\n";
        cout<<"Correct Answer:\n1 2 3\n";
        cout<<"My Answer:\n";
        push(1);
        push(2);
        push(3);
        cout<<pop()<<" ";
        cout<<pop()<<" ";
        cout<<pop()<<" ";
        cout<<"\n\n";
    }

    //非法pop
    void test4(){
        cout<<"Test4:\n";
        cout<<"Correct Answer:Invalid pop!\n\n";
        cout<<"My Answer:\n";
        cout<<pop()<<" ";
        cout<<"\n\n";
    }

    void run(){
        test1();
        test2();
        test3();
        test4();
    }
};
//
//int main(){
//    Solution9 s;
//    s.run();
//}

