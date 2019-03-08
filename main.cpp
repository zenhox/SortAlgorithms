#include<iostream>
using namespace std;
#include"BubbleSort.h"
#include"SelectSort.h"
#include"InsertSort.h"
#include"QuickSort.h"
#include "MergeSort.h"

int main() {
	int a[] = { -3,2,5,2,1,6,4,-10,43,11,-5,4,6,1,7 };
	//int a[] = { -3,2,-5 ,1};
	MergeSort::sort(a, 0, size(a)-1);
	for (auto i : a)
		cout << i << " ";
	cout << endl;
	getchar();
}