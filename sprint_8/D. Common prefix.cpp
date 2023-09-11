#include <iostream>
#include <string>

using namespace std;

string match_prefix(const string& first, const string& second) {
    string prefix;
    for (int i = 0; i < first.size() && i < second.size() && first[i] == second[i]; ++i) {
        prefix += first[i];
    }
    return prefix;
}

int main() {
    int n;
    cin >> n;
    string prev;
    string current;
    if (n > 0) {
        cin >> prev;
    }
    for (int i = 1; i < n; ++i) {
        cin >> current;
        prev = match_prefix(prev, current);
    }
    cout << prev.size();

    return 0;
}