#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_of_houses(vector<int> &prices, int &bank) {
	int result = 0;

	sort(prices.begin(), prices.end());

	int i = 0;
	while (bank - prices[i] >= 0 && i < prices.size()) {
		bank -= prices[i];
		result++;
		i++;
	}

	return result;
}

int main() {
	int n, bank;
	cin >> n >> bank;

	vector<int> prices(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> prices[i];
	}

	cout << count_of_houses(prices, bank);

	return 0;
}
