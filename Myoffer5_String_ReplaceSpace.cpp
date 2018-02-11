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
//         length:  字符串可用的总容量
// 返回值: 无             

/***--------------------------------------------------------------
思路：时间复杂度O(n)
先遍历一遍字符串统计空格的数量，则可以算出字符串被替换后的总长度=原长度+2*空格数。
接下来从后往前来复制、替换字符串。准备两个指针p1和p2，p1指向原字符串的末尾，p2指向替换后字符串的末尾（事实上都在一个字符串中）。
如果p1上的值不是空格，则复制到p2位置上；如果是空格，则p2及前两位插入"%20"。
p1和p2不断向前移，直到p1和p2重合。
注：需要判断新长度是否<字符串总容量！
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
        int i = 0;
        while(str[i]!='\0'){  //统计字符串长度和空格个数
            if (str[i] == ' ') num_space++; //注：单引号是字符，双引号是字符串
            i++;
        }
        int strlen = i;

        int new_length = strlen + num_space * 2;
        if (new_length > length) return;  //如果新长度>总容量，则返回

        int p1 = strlen;      //原长度末尾
		int p2 = new_length;  //新长度末尾
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

    //============================test===============================
    void Test(char* str, int length){
        replaceSpace(str, length);
		cout << "My answer:\n"<<str << endl<<endl; //test
    }
    //空格在中间
	void test1() {
		cout << "Test1:" << endl;
		char str[100] = "i am chinese!";
		int length = 100;
		cout << "Correct Answer:\ni%20am%20chinese!\n";
		Test(str, length);
	}
    //只有一个空格
	void test2() {
		cout << "Test2:" << endl;
		char str[100] = " ";
		int length = 100;
        cout << "Original string:\n"<<str<<endl;
		cout << "Correct Answer:\n%20\n";
		Test(str, length);
	}
    //空格在末尾
	void test3() {
		cout << "Test3:" << endl;
		char str[100] = "wow    ";
		int length = 100;
        cout << "Original string:\n"<<str<<endl;
		cout << "Correct Answer:\nwow%20%20%20%20\n";
		Test(str, length);
	}
    //空字符串
	void test4() {
		cout << "Test4:" << endl;
		char str[100] = "";
		int length = 100;
        cout << "Original string:\n"<<str<<endl;
		cout << "Correct Answer:\n空字符串\n";
		Test(str, length);
	}
    //容量不足
    void test5() {
        cout << "Test5:" << endl;
        char str[6] = "1 2 3";
        int length = 6;
        cout << "Original string:\n"<<str<<endl;
        cout << "Correct Answer:\n1 2 3\n";
        Test(str, length);
    }
	void run() {
		test1();
		test2();
		test3();
		test4();
        test5();
	}
};

int main() {
	solution5 s;
	s.run();
}