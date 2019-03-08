#pragma once

class BubbleSort {
public:
	static int sort(int *array, int size)
	{
		if (array == nullptr || size <= 0)
			return -1;
		bool  finished = false;// if finished!
		for (int i = 0; i < size; ++i)
		{
			finished = true;
			for (int j = size - 1; j > i; --j)
			{
				if (array[j - 1] > array[j])
				{
					finished = false;
					swap(array[j], array[j - 1]);
				}
			}
			if (finished)
				return 0;
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