#include <iostream>
#include <vector>

using namespace std;

vector<int> color_sort(std::vector<int>& array) {
	vector<int> counted_values(3, 0);
	for (int value : array) {
		counted_values[value]++;
	}

	int index = 0;
	for (int value = 0; value < 3; value++) {
		for (int amount = 0; amount < counted_values[value]; amount++) {
			array[index] = value;
			index++;
		}
	}
	return array;
}

void print(const vector<int>& array) {
	for (int i : array) {
		cout << i << " ";
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> colors(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> colors[i];
	}

	print(color_sort(colors));

	return 0;
}
