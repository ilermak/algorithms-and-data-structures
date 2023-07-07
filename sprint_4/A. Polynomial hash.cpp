#include <iostream>
#include <string>

using namespace std;

unsigned long find_polynomial_hash(const string& s, int a, unsigned long m) {
	unsigned long result = 0;

	for (char i : s) {
		result = (result * a  + i) % m;
	}

	return result;
}

int main() {
	int a;
	unsigned long m;
	cin >> a;
	cin >> m;

	string s;
	cin >> s;

	cout << find_polynomial_hash(s, a, m);

	return 0;
}
