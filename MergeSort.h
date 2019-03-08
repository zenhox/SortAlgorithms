#pragma once
class MergeSort {
public:
	static int sort(int *array, int start, int end)
	{
		if (array == nullptr || end - start < 0)
			return -1;
		if (start == end)
			return 0;
		int mid = (start + end) / 2;
		sort(array,start, mid);
		sort(array,mid + 1, end);
		merge(array, start, mid, end);
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
	static void merge(int * array, int start, int mid, int end) {
		int * temp_arr = new int[end - start + 1];
		int pos_1 = start;
		int pos_2 = mid+1;
		int i = 0;
		while (pos_1 <= mid && pos_2 <= end) {
			if (array[pos_1] > array[pos_2]) {
				temp_arr[i++] = array[pos_2];
				pos_2 += 1;
			}
			else {
				temp_arr[i++] = array[pos_1];
				pos_1 += 1;
			}
		}
		while (pos_1 <= mid) {
			temp_arr[i++] = array[pos_1];
			pos_1 += 1;
		}
		while (pos_2 <= end) {
			temp_arr[i++] = array[pos_2];
			pos_2 += 1;
		}
		int index = start;
		for (int i = 0; i < end - start + 1; ++i) {
			array[index++] = temp_arr[i];
		}
	}
};