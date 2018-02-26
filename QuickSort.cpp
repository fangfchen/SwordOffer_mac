#include<iostream>
using namespace std;

class solution_qsort{
public:
/***--------------------------------------------------------------
思路1：填坑法（取出key，不断填坑）
1.随机选一个数为关键值，与data[end]交换，则此时参考值在末尾，把它的值取出来记为key，现在它所在位置就是第一个要填的坑；
2.设两个指针(下标)i和j，令i=start,j=end(j位置就是现在要填的坑)；
3.从左往右找到第一个>=key的数data[i]，用它填j位置的坑，即data[j]=data[i]，现在i的位置变成要填的坑；
4.从右往左找到第一个<key的数data[j]，用它填i位置的坑，即data[i]=data[j]，现在j的位置变成要填的坑；
5.重复3,4，当i>=j时，令data[i]=key(最后一个坑)，返回key的位置i。
--------------------------------------------------------------***/
    void swap(int* a,int* b){
        int temp= *a;
        *a = *b;
        *b = temp;
    }

    int Partition1(int data[], int length, int start, int end){
        srand((unsigned)time(NULL));
        int index = rand()%(end-start+1)+start;  //生成[start,end]随机数
        swap(&data[index], &data[end]);          //把key换到end位置
        int key = data[end];                     //取出key值
        int i = start;
        int j = end;
        while(i<j){
            while(i<j && data[i]<key) i++;    //从左往右找第一个>=key的
            data[j] = data[i];                //填右边的坑
            while(i<j && data[j]>=key) j--;   //从右往左找第一个<key的
            data[i] = data[j];                //填左边的坑
        }
        data[i] = key;  //最后一个坑填入key（此时i=j）
        return i;
    }

    void QuickSort(int data[], int length, int start, int end){
        if (data == nullptr || length<=0 || start<0 || end>=length)
            throw exception();
        if (start == end) return;  //只有1个数不需要排序
        int index = Partition1(data, length, start, end);
        if (index>start)
            QuickSort(data, length, start, index-1);
        if (index<end)
            QuickSort(data, length, index+1, end);
    }

    //===========================test================================
    void Test(int data[], int length){
        QuickSort(data, length, 0, length-1);
        for(int i=0; i<length; i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }

    void test1(){
        cout<<"Test1:"<<endl;
        int data[]={5,5,7,1,3,1,4,2,6,5};
        int length = 10;
        cout<<"Original Data:"<<endl;
        for(int i=0; i<length; i++)
            cout<<data[i]<<" ";
        cout<<endl;
        cout<<"Correct Answer:\n1 1 2 3 4 5 5 5 6 7"<<endl;
        cout<<"My Answer:"<<endl;
        Test(data,length);
        cout<<endl;
    }

    void test2(){
        cout<<"Test2:"<<endl;
        int data[]={1,1,1};
        int length = 3;
        cout<<"Original Data:"<<endl;
        for(int i=0; i<length; i++)
            cout<<data[i]<<" ";
        cout<<endl;
        cout<<"Correct Answer:\n1 1 1"<<endl;
        cout<<"My Answer:"<<endl;
        Test(data,length);
        cout<<endl;
    }

    void test3(){
        cout<<"Test3:"<<endl;
        int data[]={5,4,3,2,1};
        int length = 5;
        cout<<"Original Data:"<<endl;
        for(int i=0; i<length; i++)
            cout<<data[i]<<" ";
        cout<<endl;
        cout<<"Correct Answer:\n1 2 3 4 5"<<endl;
        cout<<"My Answer:"<<endl;
        Test(data,length);
        cout<<endl;
    }

    void test4(){
        cout<<"Test4:"<<endl;
        int data[]={1,2,3,4,5};
        int length = 5;
        cout<<"Original Data:"<<endl;
        for(int i=0; i<length; i++)
            cout<<data[i]<<" ";
        cout<<endl;
        cout<<"Correct Answer:\n1 2 3 4 5"<<endl;
        cout<<"My Answer:"<<endl;
        Test(data,length);
        cout<<endl;
    }

    void run(){
        test1();
        test2();
        test3();
        test4();
    }

};

//int main(){
//    solution_qsort s;
//    s.run();
//}
