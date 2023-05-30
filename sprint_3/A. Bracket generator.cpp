#include <iostream>
#include <string>

using namespace std;

void generate_brackets(int n_of_brackets, int n_of_opens, const string& prefix) {

	if (n_of_brackets == 0 && n_of_opens == 0) {
		cout << prefix << "\n";
	}

	if (n_of_brackets == 0) {
		return;
	}

	generate_brackets(n_of_brackets - 1, n_of_opens + 1, prefix + "(");
	if (n_of_opens > 0) {
		generate_brackets(n_of_brackets - 1, n_of_opens - 1, prefix + ")");
	}
}


int main() {
	int n;
	cin >> n;

	generate_brackets(2 * n, 0, "");

	return 0;
}
