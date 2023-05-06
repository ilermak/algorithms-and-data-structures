//https://contest.yandex.ru/contest/22450/run-report/86871376/


#include <iostream>
#include <vector>
#include <string>

using namespace std;


int maxScore(const vector <string> &numberList, int k) {
	int result = 0;
	vector <int> quantities(9, 0);

	for (string row : numberList) {
		for (int i = 0; i < 4; ++i) {
			if (row[i] >= '1' && row[i] <= '9') {
				quantities[row[i] - '0' - 1]++;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (k * 2 >= quantities[i] && quantities[i] != 0) {
			result++;
		}
	}

	return result;
}

void print(const int &result) {
	cout << result << endl;
}

int main() {
	int k;
	cin >> k;
	vector <string> stringList(4);
	for (int i = 0; i < 4; ++i)
		cin >> stringList[i];
	print(maxScore(stringList, k));
}