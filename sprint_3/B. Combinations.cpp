#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string> alphabet = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

void find_combinations(string number, int i, const string& prefix) {

	if (i == number.size()) {
		cout << prefix << " ";
		return;
	}
	else {
		for (char j : alphabet[number[i] - '0']) {
			find_combinations(number, i + 1, prefix + j);
		}
	}
}

int main() {
	string number;
	cin >> number;
	
	find_combinations(number, 0, "");

	return 0;
}
	