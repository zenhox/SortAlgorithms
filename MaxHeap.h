#include<iostream>

class MaxHeap {
public:
	MaxHeap(int * arr,int size) {
		this->arr = new int[size + 1];
		for (int i = 0; i < size; ++i) {
			this->arr[i + 1] = arr[i];
		}
		this->size = size+1;
		int init_index = (this->size-1) / 2  ;
		while (init_index >= 1) {
			this->max_heapify(this->arr, init_index);
			init_index -= 1;
		}
	}
	void print_heap() {
		for (int i = 1; i < size; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	int * arr;
	int size;
	void max_heapify(int arr[], int index) {
		int left = index * 2;
		int right = index * 2 + 1;
		int max_index = index;
		if (arr[left] > arr[index] && left < size)
			max_index = left;
		if (arr[right] > arr[max_index] && right < size)
			max_index = right;
		if (index != max_index) {
			swap(arr[max_index], arr[index]);
			max_heapify(arr, max_index);
		}
	}
	void swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
};