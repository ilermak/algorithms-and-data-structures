#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void find_top_k_universities(vector<int>& universities, int k) {
	unordered_map<int, int> counts;

	for (int & universitie : universities) {
		counts[universitie]++;
	}

	vector<pair<int, int>> top(counts.begin(), counts.end());

	sort(top.begin(), top.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second != b.second) {
			return a.second > b.second;
		}
		return a.first < b.first;
	});

	for (int i = 0; i < k; ++i) {
		cout << top[i].first << " ";
	}
}

int main() {
	int n, k;
	cin >> n;

	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	cin >> k;

	find_top_k_universities(numbers, k);

	return 0;
}
