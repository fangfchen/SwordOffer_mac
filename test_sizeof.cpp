//#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;


int test_sizeof() {
	int a[] = {1,2,3,4,5};
	int size1 = sizeof(a);
	int size2 = sizeof(a[0]);
	int size3 = size1 / size2;
	//cout << size1 << size2 << size3;
	printf("%d, %d, %d\n", size1, size2, size3);

	int* b = a;
	int size4 = sizeof(b);
	cout << size4<< endl;
	return 0;
}

//int main() {
//	test_sizeof();
//}