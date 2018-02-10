//#include "stdafx.h"
#include<iostream>
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
//==================================================================

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
class solution3 {
public:
/***--------------------------------------------------------------
思路1(不改变原数组，利用哈希表)：时间复杂度O(n)，空间复杂度O(n)
建立哈希表，遍历数组中的元素，对每个元素，如果它不在哈希表中，就加进去，如果它在哈希表中，说明已经重复出现了，则它就是答案。
这里的哈希表可以直接用一个长度为n的数组来模拟，初始值为0（或false），假如当前遍历到的数是k，则看数组下标为k的位置是否为1（或true），
如果不是则令其为k的位置是否为1（或true），如果是则说明已经重复。
注：这里找到的第一个数为第一个重复的数！
--------------------------------------------------------------***/	
	bool duplicate1(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0) {  //若数组为空指针或长度<=0，则无效
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i]<0 || numbers[i]>length - 1) {      //如果数超过范围，则无效(需单独一个循环，防止重复数的后面有无效输入)
				return false;
			}
		}

		int* record = new int[length]();  //【如果改为(0)，这种初始化方法线上编译器clang c++出错（虽然本地可以运行）！】
		//这里也可以建立bool型或vector
		for (int i = 0; i<length; i++) {
			int temp = numbers[i];
			if (record[temp] != 0) {
				*duplication = temp;
				return true;
			}
			else{
				record[temp] = 1;
			}
		}
		delete[]record;
		return false;   //若无重复数，则返回false
	}
	 
/***--------------------------------------------------------------
思路2（对原数组重排）【书】：时间复杂度O(n)，空间复杂度O(1)
因为数组长度为n，每个数都在0~n-1范围内，所以如果数组中没有重复，那么数组排序后数字i应该出现在下标i的位置。
现在重排数组，从头到尾依次扫描，扫描到数字i的时候就看它的下标是否为i，如果是说明他在正确的位置上；
如果不是，则再看下标为i的位置是否已经有数i，如果是，说明i已经有重复；如果不是，则交换i和下标为i的数。
注：这里找到的不一定是第一个重复的数！
--------------------------------------------------------------***/
	bool duplicate2(int numbers[], int length, int* duplication) {

		if (numbers == nullptr || length <= 0) {  //若数组为空指针或长度<=0，则无效
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i]<0 || numbers[i]>length - 1) {      //如果数超过范围，则无效(需单独一个循环，防止重复数的后面有无效输入)
				return false;
			}
		}
		for (int i = 0; i < length; i++) {
			while (numbers[i] != i) {
				if (numbers[numbers[i]] == numbers[i]) {
					*duplication = numbers[i];
					return true;
				}
				else {
					int temp = numbers[i];    //交换
					numbers[i] = numbers[numbers[i]];
					numbers[temp] = temp;     //这里一定要用numbers[temp]！因为numbers[i]中的值已经被改变！
				}
			}
		}
		return false;

	}

	//======================test==========================

	//1个重复
	void test1(int funclabel) {
		printf("test1:\n");
		int numbers[] = { 1,5,4,3,8,6,0,7,5 }; 
		int length = 9;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: 5\n\n");
	}

	//多个重复
	void test2(int funclabel) {
		printf("test2:\n");
		int numbers[] = {0, 1, 5, 1, 4, 5 };
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: 1 or 5\n\n");
	}

	//无重复
	void test3(int funclabel) {
		printf("test3:\n");
		int numbers[] = { 0, 1, 3, 2, 5, 4 };
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}

	//空数组
	void test4(int funclabel) {
		printf("test4:\n");
		int* numbers = nullptr;
		int length = 0;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}

	//范围越界
	void test5(int funclabel) {
		printf("test5:\n");
		int numbers[] = {2,8,3,4,2,0};
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}


	void run() {
		//bool(*func)(int* , int, int* ); //定义函数指针func，它所指向的函数带有3个参数并且返回bool
		int funclabel = 1;
		test1(funclabel);
		test2(funclabel);
		test3(funclabel);
		test4(funclabel);
		test5(funclabel);
	}
};



//int main() {
//	solution3 s;
//	s.run();
//}
