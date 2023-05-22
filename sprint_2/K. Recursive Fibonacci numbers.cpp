#include <iostream>

using namespace std;

int fibonacci_numbers(int n) {

	if (n >= 2) {
		return fibonacci_numbers(n - 1) + fibonacci_numbers(n - 2);
	}
	else if (n < 0)
		return 0;
	else
		return 1;
}

void print(int result) {
	cout << result << endl;
}

int main() {
	int n;
	cin >> n;
	print(fibonacci_numbers(n));
}