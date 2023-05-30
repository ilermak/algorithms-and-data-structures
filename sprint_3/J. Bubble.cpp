#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& arr) {
	int swap_flag = 0;
	int cout_flag = 0;
	for (int i = 0; i < arr.size() - 1; ++i) {
		swap_flag = 0;
		for (int j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swap_flag = 1;
			}
		}
		if (swap_flag) {
			for (int j : arr) {
				cout << j << " ";
			}
			cout << "\n";
			cout_flag = 1;
		}

	}
	if (!cout_flag) {
		for (int j : arr) {
			cout << j << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	bubble_sort(numbers);

	return 0;
}
