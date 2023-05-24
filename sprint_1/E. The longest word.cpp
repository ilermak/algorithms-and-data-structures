#include <iostream>
#include <string>
#include <vector>

using namespace std;


string GetLongestWord(const string &line) {
	string result, str;
	vector < string > list;

	for (int i = 0; i < line.length() + 1; ++i) {
		if (line[i] == ' ' || line[i] == '\0') {
			list.push_back(str);
			str.clear();
		}
		else
			str += line[i];
	}
	for(string word : list) {
		if (word.length() > result.length()){
			result = word;
		}
	}

	return result;
}

void print(const string &result) {
	cout << result << endl << result.length() << endl;
}

int main() {
	int n;
	cin >> n;
	string line;
		
	getline(cin, line);
	print(GetLongestWord(line));
}