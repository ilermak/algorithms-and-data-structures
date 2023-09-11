#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool compareVectors(const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    map<string, vector<int>> anagramGroups;

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        string sortedWord = words[i];
        sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(i);
    }

    vector<pair<string, vector<int>>> sortedAnagramGroups(anagramGroups.begin(), anagramGroups.end());
    sort(sortedAnagramGroups.begin(), sortedAnagramGroups.end(), compareVectors);

    for (const auto& group : sortedAnagramGroups) {
        for (auto index : group.second) {
            cout << index << " ";
        }
        cout << '\n';
    }

    return 0;
}
