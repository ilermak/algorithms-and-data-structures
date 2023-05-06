#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> GetNeighbours(const vector <vector <int> > &matrix, int row, int col) {
	vector <int> result;

	if (row - 1 >= 0 )
		result.push_back(matrix[row - 1][col]);
	if (row + 1 < matrix.size() )
		result.push_back(matrix[row + 1][col]);
	if (col - 1 >= 0)
		result.push_back(matrix[row][col - 1]);
	if (col + 1 < matrix[0].size())
		result.push_back(matrix[row][col + 1]);
	
	sort(result.begin(), result.end());

	return result;
}

void print(const vector <int> &result) {
	for (int x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > matrix(n, vector <int> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrix[i][j];
	int row, col;
	cin >> row >> col;
	print(GetNeighbours(matrix, row, col));
}