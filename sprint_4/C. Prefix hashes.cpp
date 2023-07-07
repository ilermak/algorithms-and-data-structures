#include <iostream>
#include <string>
#include <vector>

using namespace std;

uint64_t fast_pow(uint64_t x, uint64_t p, uint64_t r) {
	uint64_t m = x % r;
	uint64_t t = 1;
	while (p) {
		if (p % 2) {
			t *= m;
			t %= r;
		}
		m *= m;
		m %= r;
		p /= 2;

	}
	return t % r;
}

vector<uint64_t> find_prefix_hash(const string& s, uint64_t a, uint64_t m, const vector<pair<uint64_t, uint64_t>>& segments) {
	vector<uint64_t> result;

	vector<uint64_t> hashes = {0};
	for (int i = 0; i < s.size(); ++i) {
		 hashes.push_back((hashes.back() * a  + s[i]) % m);
	}

	for (pair<long long int, long long int> segment : segments) {
		result.push_back((m + hashes[segment.second] - hashes[segment.first - 1] * (uint64_t)fast_pow(a,  segment.second - segment.first + 1, m) % m) % m);
	}

	return result;
}

void print(const vector<uint64_t>& result) {
	for (uint64_t i : result) {
		cout << i << '\n';
	}
}

int main() {
	int a;
	uint64_t m;
	cin >> a;
	cin >> m;

	string s;
	cin >> s;

	int n;
	cin >> n;

	vector<pair<uint64_t, uint64_t>> segments;
	for (int i = 0; i < n; ++i) {
		int first, second;
		cin >> first >> second;
		segments.emplace_back(first, second);
	}

	print(find_prefix_hash(s, a, m, segments));

	return 0;
}

