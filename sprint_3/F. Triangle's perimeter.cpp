#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_the_biggest_square(vector<int> &lengths) {
	int a = 2;
	int b = 1;
	int c = 0;

	sort(lengths.begin(), lengths.end(), [](int left, int right){
		return left > right;
	});

	while (a < lengths.size()) {
		if (lengths[c] < lengths[a] + lengths[b])
			return lengths[a] + lengths[b] + lengths[c];

		a++;
		b++;
		c++;
	}

	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<int> lengths(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> lengths[i];
	}
	cout << find_the_biggest_square(lengths);

	return 0;
}
