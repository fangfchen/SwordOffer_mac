//#include "stdafx.h"
#include<iostream>
#include<vector>
#include <iterator> 
using namespace std;

int test_sizeof() {  //sizeof
	int a[] = { 1,2,3,4,5 };
	int size1 = sizeof(a);
	int size2 = sizeof(a[0]);
	int size3 = size1 / size2;
	//cout << size1 << size2 << size3;
	printf("%d, %d, %d\n", size1, size2, size3);

	int* b = a;
	int size4 = sizeof(b);
	cout << size4 << endl;
	return 0;
}

void test1() {  //数组 sizeof memset初始化
	int a[10];
	cout << a[2] << endl;   //随机数
	memset(a, 0, sizeof(a));
	cout << a[2] << endl;   //0

	int length = 10;
	int* const b = (int*)malloc(sizeof(int)*length);
	cout << sizeof(b) << endl;  //4（虽然给b数组分配了内存，但是因为他现在是int指针，所以sizeof(b)是4！！！！！）
	cout << b[2] << endl;	//随机数
	memset(b, 0, sizeof(b));
	cout << b[2] << endl;	//随机数
	cout << b[0] << endl;   //0
	memset(b, 0, sizeof(int)*length);   //用malloc后进行memset不能直接用sizeof(b)！要写sizeof(int)*length！！！
	cout << b[2] << endl;

	int* const c = (int*)calloc(length,sizeof(int));  //calloc(连续分配n个大小一样的内存空间)会自动初始化为0！！！！！
	cout << c[2] << endl;
	
}

void swap(int& a, int& b) {   //引用
	int c = a;
	a = b;
	b = c;
}

void test2() {  //引用
	int a = 1;
	int b = 2;
	printf("Original: a = %d, b = %d\n", a, b);   //1 2
	swap(a, b);
	printf("After swap: a = %d, b = %d\n", a, b); //2 1 用了引用后，swap中变化，这里也会变化！
}


void test3() {  //引用
	int a = 1;
	int& b = a;
	printf("a = %d, b = %d\n", a, b); //1 1
	b = 3;
	printf("a = %d, b = %d\n", a, b); //3 3
	a = 5;
	printf("a = %d, b = %d\n", a, b); //5 5 （引用后，a,b的值始终保持一致！！）
	int& c = a;
	c = 7;
	printf("a = %d, b = %d, c= %d\n", a, b, c);
	int& d = b;
	d = 9;
	printf("a = %d, b = %d, c= %d, d= %d\n", a, b, c, d);
}

void test4() {  //bool型动态数组初始化
	bool* hash = new bool[5]();
	for (int i = 0; i < 5; i++) {
		if (hash[i] == true) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

void test5() {   //vector初始化
	int a[5] = { 3, 2, 5, 7, 8 };
	int length = sizeof(a)/sizeof(int);
	//用push_back逐一加入
	vector<int> v1;       //若直接再这里定义(length)，则会都初始化为0，push_back会在已有的0后继续往后加！(0 0 0 0 0 3 2 5 7 8)
	v1.reserve(length);   //不写这句也行,但写了可以减少内存分配次数
	for (int i = 0; i < length; i++) {
		v1.push_back(a[i]);
	}
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));  //打印vector！！
	cout << endl;
	
	//【最方便】定义时直接带入已知数组的头、尾指针
	vector<int> v2(&a[0], &a[length]);
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//定义后再insert已知数组的头、尾指针
	vector<int> v3;	     //若直接再这里定义(length)，则会都初始化为0，insert后会有一串0(3 2 5 7 8 0 0 0 0 0)
	v3.reserve(length);  //不写这句也行,但写了可以减少内存分配次数
	v3.insert(v3.begin(), &a[0], &a[length]);
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//二维vector
	//1 2 8  9
	//2 4 9  12
	//4 7 10 13
	//6 8 11 15
	int n = 4;
	int m = 4;
	int a4[4][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	vector<vector<int>> v4(n, vector<int>(m));  //定义二维vector！
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v4[i][j] = a4[i][j];
		}
		copy(v4[i].begin(), v4[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

void test6() {		//vector
	vector<int> v(10);
	//vector<double> v(10);       //定义大小为10（并初始化为0，若此时用push_back则会放在v[10]）
	//vector<double> v(10, 2.5);  //初始化每个数为2.5
	//vector<int> v2(v1);         //拷贝创建

	//v.push_back(3);        //在末尾添加3
	//v.insert(v.end(), 10); //在末尾插入10（需指定一个迭代器）
	//v[i] = 5;              //把第i位赋值为5


	//v.size()    //vector大小（元素个数）
	//v.empyt()   //判断队列是否为空，若为空返回1，不空返回0
	//v.clear()   //清空队列
	//v.front()   //vector的第一个元素值
	//v.back()    //vector的最后一个元素值
	//v.push_back(a);    //在末尾添加一个新元素a
	//v.pop_back();      //删除末尾元素 注：队列为空时不能用pop！
	//if (!v.empty()) v.pop_back();  //判断不为空再删除
	//v.erase(v.begin()) //删除开头的元素
		
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	vector<int>::iterator i;
	for (i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}
}
 

//int main() {
//	test6();
//}
