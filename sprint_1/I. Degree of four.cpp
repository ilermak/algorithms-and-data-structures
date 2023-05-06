#include <iostream>

using namespace std;

bool IsPowerOfFour(int number) {
	
	while (number > 0) {
		if (number == 1)
			return true;
		if (number % 4 != 0)
			return false;
		number /= 4;
	} 
	return true;
}

void print(bool result) {
	if (result)
		cout << "True";
	else
		cout << "False";
	cout << endl;
}

int main() {
	int number;
	cin >> number;
	print(IsPowerOfFour(number));
}