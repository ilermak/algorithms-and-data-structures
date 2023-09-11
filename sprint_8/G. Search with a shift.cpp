#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(const vector<int>& text, const vector<int>& pattern, int start = 0) {
    if (text.size() < pattern.size()) {
        return -1;
    }
    for (int pos = start; pos <= text.size() - pattern.size(); pos++) {
        bool match = true;
        for (int offset = 0; offset < pattern.size(); offset++) {
            if (text[pos + offset] != pattern[offset]) {
                match = false;
                break;
            }
        }
        if (match) {
            return pos;
        }
    }
    return -1;
}


vector<int> find_all(const vector<int>& text, const vector<int>& pattern) {
    vector<int> occurrences;
    int start = 0;
    int pos;
    while ((pos = find(text, pattern, start)) != -1) {
        occurrences.push_back(pos);
        start = pos + 1;

    }
    return occurrences;
}

int main() {
    int n;
    cin >> n;
    vector<int> measurements(n);

    for (auto& i : measurements) {
        cin >> i;
    }
    vector<int> new_measurements(n - 1);
    for (int i = 1; i < measurements.size(); ++i) {
        new_measurements[i - 1] = measurements[i] - measurements[i - 1];
    }

    int m;
    cin >> m;
    vector<int> pattern(m);

    for (auto& i : pattern) {
        cin >> i;
    }
    auto minimumIt = min_element(pattern.begin(), pattern.end());
    int minimum = pattern[distance(pattern.begin(), minimumIt)];

    for (auto& i : pattern) {
        i -= minimum;
    }
    vector<int> new_pattern(m - 1);
    for (int i = 1; i < pattern.size(); ++i) {
        new_pattern[i - 1] = pattern[i] - pattern[i - 1];
    }

    vector<int> result = find_all(new_measurements, new_pattern);

    for (auto i : result) {
        cout << i + 1 << " ";
    }

    return 0;
}