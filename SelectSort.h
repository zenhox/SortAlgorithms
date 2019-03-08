class SelectSort {
public:
	static int sort(int *array, int size)
	{
		if (array == nullptr || size <= 0)
			return -1;
		for (int i = 0; i < size; ++i)
		{
			int index_min = i;
			for (int j = i + 1; j < size; ++j) {
				if (array[index_min] > array[j])
				{
					index_min = j;
				}
			}
			if (index_min != i)
				swap(array[i], array[index_min]);
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