#include <iostream>

using namespace std;

bool CheckParity(int a, int b, int c) {
	return (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) || (a % 2 != 0 && b % 2 != 0 && c % 2 != 0);
}

void print(bool result) {
	if (result)
		cout << "WIN" << endl;
	else
		cout << "FAIL" << endl;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	print(CheckParity(a, b, c));
}