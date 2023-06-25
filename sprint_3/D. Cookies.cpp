#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_n_of_happy_children(vector<int> &children, vector<int> &cookies) {
	int result = 0;
	int i = 0;
	int j = 0;

	sort(children.begin(), children.end());
	sort(cookies.begin(), cookies.end());

	while(i < children.size() && j < cookies.size()) {
		if (children[i] <= cookies[j]) {
			result++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> children(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> children[i];
	}

	int m;
	cin >> m;

	vector<int> cookies(m, 0);
	for (int i = 0; i < m; ++i) {
		cin >> cookies[i];
	}

	cout << count_n_of_happy_children(children, cookies);

	return 0;
}
