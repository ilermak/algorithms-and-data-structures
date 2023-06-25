#include <iostream>
#include <vector>

using namespace std;

bool is_left_number_bigger(string left, string right) { // функция-компаратор
	return left + right > right + left;
}

void find_biggest_number(vector<string>& array, bool (*less)(string, string)) {
	for (int i = 1; i < array.size(); i++) {
		string item_to_insert = array[i];
		int j = i;

		while (j > 0 && less(item_to_insert, array[j-1])) {
			array[j] = array[j-1];
			j--;
		}
		array[j] = item_to_insert;
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> numbers(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	find_biggest_number(numbers, is_left_number_bigger);

	for (const string& i : numbers) {
		cout << i;
	}

	return 0;
}
