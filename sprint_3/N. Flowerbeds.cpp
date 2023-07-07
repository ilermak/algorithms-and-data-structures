#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> find_sections(vector<pair<int, int>>& flowerbeds) {
    vector<pair<int, int>> result;

    sort(flowerbeds.begin(), flowerbeds.end(), [](pair<int, int> left, pair<int, int> right) {
        if (left.first != right.first)
            return left.first < right.first;
        return left.second < right.second;
    });

    for (auto flowerbed : flowerbeds) {
        if (result.empty()) {
            result.push_back(flowerbed);
        }
        else if (result.back().second <= flowerbed.second && flowerbed.first <= result.back().second) {
            result.back().second = flowerbed.second;
        }
        else if (result.back().second > flowerbed.second && flowerbed.first > result.back().first) {
            continue;
        }
        else {
            result.push_back(flowerbed);
        }
    }

    return result;
}

void print(const vector<pair<int, int>>& result) {
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].first << " " << result[i].second << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> flowerbeds;

    for (int i = 0; i < n; ++i) {
        int first, second;
        cin >> first >> second;
        flowerbeds.emplace_back(first, second);
    }

    print(find_sections(flowerbeds));

    return 0;
}