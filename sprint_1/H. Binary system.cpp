#include <iostream>
#include <string>

using namespace std;

string GetSum(const string &firstNumber, const string &secondNumber) {
	string result;
	string fN = firstNumber;
	string sN = secondNumber;
	int overflow = 0;

	int firstNumberLen = fN.length();
	int secondNumberLen = sN.length();
	if (firstNumberLen > secondNumberLen) {
		for (int i = 0; i < firstNumberLen - secondNumberLen; ++i)
			sN = '0' + sN;
	}
	else {
		for (int i = 0; i < secondNumberLen - firstNumberLen; ++i)
			fN = '0' + fN;
	}

	for (int i = fN.length() - 1; i >= 0; --i) {
		if ((fN[i] - '0') + (sN[i] - '0') + overflow < 2) {
			result = char((fN[i] - '0') + (sN[i] - '0') + (overflow + '0')) + result;
			overflow = 0;
		}
		else {
			result = char(((fN[i] - '0') + (sN[i] - '0') + overflow) % 2 + '0') + result;
			overflow = 1;
		}
	}

	if (overflow != 0) {
		result = '1' + result;
	}


	return result;
}

void print(const string &result) {
	cout << result << endl;
}

int main() {
	string firstNumber, secondNumber;
	cin >> firstNumber >> secondNumber;
	print(GetSum(firstNumber, secondNumber));
}