#include <iostream>
#include <vector>

using namespace std;

void reverse(vector <int> &list) {
	for (int i = 0; i < list.size() / 2; ++i) {
		int temp = list[list.size() - 1 - i];
		list[list.size() - 1 - i] = list[i];
		list[i] = temp;
	}
}


vector <int> GetSum(const vector <int> &numberList, int k) {
	vector <int> result;
	vector <int> nList = numberList;
	vector <int> kList;

	while (k > 0) {
		kList.push_back(k % 10);
		k /= 10;
	}
	
	reverse(nList);

	if (kList.size() > nList.size()) {
		while (kList.size() != nList.size()) {
			nList.push_back(0);
		}
	}
	else {
		while (kList.size() != nList.size()) {
			kList.push_back(0);
		}
	}

	reverse(nList);
	reverse(kList);
	
	int overflow = 0;
	for (int i = nList.size() - 1; i >= 0; --i) {
		if (nList[i] + kList[i]  + overflow < 10) {
			result.push_back(nList[i] + kList[i] + overflow);
			overflow = 0;
		}
		else {
			result.push_back((nList[i] + kList[i] + overflow) % 10);
			overflow = (nList[i] + kList[i] + overflow) / 10;
		}
	}

	if (overflow > 0)
		result.push_back(overflow);

	reverse(result);
	
	return result;
}

void print(const vector <int> &result) {
	for (int x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector <int> numberList(n);
	for (int i = 0; i < n; ++i)
		cin >> numberList[i];
	int k;
	cin >> k;
	print(GetSum(numberList, k));
}