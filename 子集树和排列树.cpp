#include<iostream>
#include<vector>
using namespace std;

void zijishu(vector<int> arr, int t, bool mark[]) {
	if (mark == nullptr)
		mark = new bool[arr.size()];
	if (t >= arr.size()) {
		for (int i = 0; i < arr.size(); ++i) {
			if (mark[i])
				cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i <= 1; ++i) {
			mark[t] = i;
			zijishu(arr, t + 1, mark);
		}
	}
}
void pailieshu(vector<int> arr, int t) {
	if (t >= arr.size()) {
		for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = t; i < arr.size(); ++i) {
			swap(arr[t],arr[i]);
			pailieshu(arr, t + 1);
			swap(arr[i], arr[t]);
		}
	}
}

int main() {
	vector<int> arr = { 1,2,3 };
	cout << "ÅÅÁÐÊ÷" << endl;
	pailieshu(arr, 0);
	cout << "×Ó¼¯Ê÷" << endl;
	//zijishu(arr, 0, nullptr);
	system("pause");
}