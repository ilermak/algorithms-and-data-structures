#include <iostream>
#include <vector>
#include <string>

#define INT_MAX       2147483647

using namespace std;

bool find_in_array(const vector<string>& array, const string& x) {
	for (const auto& i : array) {
		if (i == x) {
			return true;
		}
	}
	return false;
}

vector<string> drop_duplicates(const vector<string>& words) {
	vector<string> result;
	for (const auto& word : words) {
		if (!find_in_array(result,word)) {
			result.push_back(word);
		}
	}
	return result;
}

void print(const vector<string>& result) {
	for (auto i : result) {
		cout << i << '\n';
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> hobbies(n, "");

	cin.ignore(INT_MAX, '\n');
	for (auto & hobby : hobbies) {
		getline(cin, hobby);
	}

	print(drop_duplicates(hobbies));

	return 0;
}