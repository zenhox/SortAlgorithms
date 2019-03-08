#pragma once
class QuickSort {
public:
	static int sort(int *array, int start, int end)
	{
		if (array == nullptr || end - start <= 0)
			return -1;
		int index = partition(array, start, end);
		sort(array ,start, index - 1);
		sort(array ,index + 1, end);
		return 0;
	}
private:
	static void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// return the last position of pivot element
	static int partition(int *array, int start, int end) {
		//选第一个元素为pivot
		int pivot_index = start;
		int pivot = array[start];
		while (start < end) {
			// 3 1 2 5 4
			// 3 1 5 2 4
			// 5 1 3 2 4
			while (start < end && array[end] >= pivot)
				end--;
			while (start < end && array[start] <= pivot)
				start++;
			swap(array[start], array[end]);
		}
		swap(array[end], array[pivot_index]);
		return end;
	}
};