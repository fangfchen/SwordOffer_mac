//#include "stdafx.h"
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
//==================================================================

// 参数:
//        target:     待查找的数
//        array:      二维数组(用vector存储)
// 返回值:             
//        true  - 数组找到了该数
//        false - 其他

/***--------------------------------------------------------------
思路：时间复杂度O(n)或O(n+m)
从左下角（或右上角）开始，如果该位置的数>目标值，则说明它右边的值都>目标值，故这行都不考虑，位置指向它上边的数；
如果该位置的数<目标值，则说明它上边的值都<目标值，故这列都不考虑，位置指向它右边的数；
重复此过程，直到已经找到边界，无法再找下去。
注：选左下角或右上角的原因——可以控制大于和小于两种情况，而左上角（右、下都比它大）和右下角（左、上都比它大）无法控制！
--------------------------------------------------------------***/
class solution4 {
public:
	bool Find(int target, vector<vector<int> > array) {
		int n = array.size();     //行数！
		int m = array[0].size();  //列数！
		if (n <= 0 || m <= 0) {
			return false;
		}
		int i = n - 1;
		int j = 0;
		while (i >= 0 && i<n && j >= 0 && j<m) {
			if (array[i][j] == target) {
				return true;
			}
			else if (array[i][j] < target) {
				j++;
			}
			else {
				i--;
			}
		}
		return false;
	}
	 
	void test1() {
		printf("Test1:\n");
		//1 2 8  9
		//2 4 9  12
		//4 7 10 13
		//6 8 11 15
		int n = 4;
		int m = 4;
		int a[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15} };
		vector<vector<int>> v(n,vector<int>(m));  //定义二维vector！
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] = a[i][j];
			}
			//copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			//cout << endl;
		}
		if (Find(4, v) == true) {
			printf("True\n");
		}
		else {
			printf("False\n");
		}
	}

	void run() {
		test1();
	}

};

//int main() {
//	solution4 s;
//	s.run();
//
//}





