#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    string result;
    int n;

    cin >> str;
    cin >> n;

    vector<pair<string, int>> pairs(n);

    for (auto& item : pairs) {
        cin >> item.first >> item.second;
    }

    sort(pairs.begin(), pairs.end(), [](const pair<string, int>& first, const pair<string, int>& second) {
       return first.second < second.second;
    });

    string buf;
    int j = 0;
    for (int i = 0; i <= str.size(); ++i) {
        if (i == pairs[j].second) {
            result += buf;
            result += pairs[j].first;
            j++;
            buf.clear();
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            buf += str[i];
        }
    }
    result += buf;

    cout << result;

    return 0;
}