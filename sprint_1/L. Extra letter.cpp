#include <iostream>
#include <string>
#include <vector>

using namespace std;

char GetExcessiveLetter(const string &shorter, const string &longer) {
	char temp;
	vector <char> s, l;

	for (int i = 0; i < shorter.length(); ++i) {
		s.push_back(shorter[i]);
	}
	for (int i = 0; i < longer.length(); ++i) {
		l.push_back(longer[i]);
	}

	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s.size() - 1; ++j) {
			if (s[j] > s[j + 1]) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < l.size(); ++i) {
		for (int j = 0; j < l.size() - 1; ++j) {
			if (l[j] > l[j + 1]) {
				temp = l[j];
				l[j] = l[j + 1];
				l[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != l[i])
			return l[i];
	}

	return l[l.size() - 1];
}

void print(char result) {
	cout << result << endl;
}

int main() {
	string shorter, longer;
	cin >> shorter >> longer;
	print(GetExcessiveLetter(shorter, longer));
}