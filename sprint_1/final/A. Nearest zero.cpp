//https://contest.yandex.ru/contest/22450/run-report/86916520/


#include <iostream>
#include <vector>

#define INT_MAX 2147483647

using namespace std;


vector <int> nearestZero(const vector <int> &numberList) {
	vector <int> result;
	int counter = 0;
	int zeroFlag = 0;

	for (int i = 0; i < numberList.size(); ++i) {
		if (numberList[i] == 0) {
			zeroFlag = 1;
			counter = 0;
		}
		if (zeroFlag == 0) {
			result.push_back(INT_MAX);
		}
		else {
			result.push_back(counter);
			counter++;
		}
	}

	counter = 0;
	zeroFlag = 0;
	for (int i = numberList.size() - 1; i >= 0 ; --i) {
		if (numberList[i] == 0) {
			zeroFlag = 1;
			counter = 0;
		}
		if (zeroFlag == 1) {
			if (counter < result[i])
				result[i] = counter;
			counter++;
		}
	}

	return result;
}

void print(const vector <int> &result) {
	for (int x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector <int> numberList(n);
	for (int i = 0; i < n; ++i)
		cin >> numberList[i];
	print(nearestZero(numberList));
}