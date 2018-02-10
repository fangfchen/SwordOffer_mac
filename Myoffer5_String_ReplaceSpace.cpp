//#include "stdafx.h"
#include<iostream>
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
//==================================================================

// 参数:
//         str:     字符串
//         length:  字符串长度(书上与此略有差异，书上指的是可用的总容量)
// 返回值: 无             

/***--------------------------------------------------------------
思路：时间复杂度O(n)
先遍历一遍字符串统计空格的数量，则可以算出字符串被替换后的总长度=原长度+2*空格数。
接下来从后往前来复制、替换字符串。准备两个指针p1和p2，p1指向原字符串的末尾，p2指向替换后字符串的末尾（事实上都在一个字符串中）。
如果p1上的值不是空格，则复制到p2位置上；如果是空格，则p2及前两位插入"%20"。
p1和p2不断向前移，直到p1和p2重合。
--------------------------------------------------------------***/

class solution5 {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr) { return; }
		//一次性打印字符串的3个方法
		//cout << str <<endl;  
		//printf("%s\n", str);
		//puts(str);  //自带回车
		int num_space=0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') num_space++;  //注：单引号是字符，双引号是字符串
		}
		int new_length = length + num_space * 2;
		int p1 = length;  //新数组
		int p2 = new_length;


        str[p2] = '1';
		while (p1 < p2) {
			if (str[p1] != ' ') {
				str[p2] = str[p1];
			}
			else {   //str[p1]==' '
				str[p2] = '0';
				str[--p2] = '2';
				str[--p2] = '%';
			}
			p1--;
			p2--;
		}

	}

    void Test(char* str, int length){
        replaceSpace(str, length);
		cout << "My answer:\n"<<str << endl<<endl; //test
    }

	void test1() {
		cout << "Test1:" << endl;
		char str[] = "i am chinese!";
		int length = 14;
		cout << "Correct Answer:\ni%20am%20chinese!\n";
		Test(str, length);
	}

	void test2() {
		cout << "Test2:" << endl;
		char str[] = " ";
		int length = 2;
		cout << "Correct Answer:\n%20\n";
		Test(str, length);
	}

	void test3() {
		cout << "Test3:" << endl;
		char str[] = "wow    ";
		int length = 8;
		cout << "Correct Answer:\nwow%20%20%20%20\n";
		Test(str, length);
	}

	void test4() {
		cout << "Test4:" << endl;
		char str[] = "";
		int length = 1;
		cout << "Correct Answer:空字符串\n";
		Test(str, length);
	}

	void run() {
		test1();
		test2();
		test3();
		test4();
	}
};

int main() {
	solution5 s;
	s.run();
}