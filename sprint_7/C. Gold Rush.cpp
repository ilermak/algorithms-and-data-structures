#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long max_profit(vector<pair<long long, long long>>& heaps, long long m) {
    long long result = 0;
    sort(heaps.begin(), heaps.end(), [](pair<long long, long long> first, pair<long long, long long> second) {
        return -first.first < -second.first;
    });

    for (auto item : heaps) {
        if (item.second < m) {
            m -= item.second;
            result += item.first * item.second;
        }
        else {
            result += item.first * m;
            m = 0;
        }
    }

    return result;
}


int main() {
    long long n, m;
    cin >> m;
    cin >> n;

    vector<pair<long long, long long>> heaps(n);

    for (auto& i : heaps) {
        cin >> i.first >> i.second;
    }

    cout << max_profit(heaps, m);

    return 0;
}
