#include <iostream>
#include <cmath>

using namespace std;

long long fibonacci_numbers(int n, int k) {

	long long sum_0 = 1, sum_1 = 1, temp;

	for (int i = 1; i < n; ++i) {
		temp = sum_1 % int(pow(10, k));
		sum_1 = (sum_1  + sum_0) % int(pow(10, k));
		sum_0 = temp;
	}

	return sum_1;
}

void print(int result) {
	cout << result << endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	print(fibonacci_numbers(n, k));
}