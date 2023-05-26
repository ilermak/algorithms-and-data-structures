#include <iostream>
#include <vector>
#include <string>

#define INT_MAX 2147483647

using namespace std;

vector< vector<int> > transpose(vector< vector<int> > matrix, unsigned rows, unsigned cols)
{
	vector< vector<int> > transposed_matrix (cols, vector<int>(rows, 0));;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			transposed_matrix[j][i] = matrix[i][j];
		}
	}

	return transposed_matrix;
}

vector<int> split(string str, char separator) {
	vector<int> split_string;
	string word;
	for (int i = 0; i < str.size() + 1; ++i) {
		if (str[i] != separator && str[i] != '\0')
			word += str[i];
		else {
			split_string.push_back(stoi(word));
			word.clear();
		}
	}
	return split_string;
}

int main() {
    int n, m;
	cin >> n;
	cin >> m;
	cin.ignore(INT_MAX, '\n');

	vector< vector<int> > matrix(n, vector<int>(m, 0));

	string row;
	vector<int> int_row;
	for (int i = 0; i < n; i++) {
		getline(cin, row);
		matrix[i] = split(row, ' ');
	}

	matrix = transpose(matrix, n, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
