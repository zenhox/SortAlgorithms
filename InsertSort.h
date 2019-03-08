#pragma once
class InsertSort {
public:
	static int sort(int *array, int size)
	{
		if (array == nullptr || size <= 0)
			return -1;
		for (int i = 1; i < size; ++i)
		{
			int index = i;
			while (index>0 && array[index - 1] > array[index]) {
				swap(array[index - 1], array[index]);
				index--;
			}
		}
		return 0;
	}
private:
	static void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};