#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find_longest_draw_game(vector<int> array) {
    if (array.empty() || array.size() == 1) return 0;

    int result = 0;

    vector<int> score(array.size());
    unordered_map<int, vector<int>> counts;

    if (array[0] == 0) {
        score[0] = 1;
    }
    else if (array[0] == 1) {
        score[0] = -1;
    }
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] == 0) {
            score[i] = score[i - 1] + 1;
        }
        else if (array[i] == 1) {
            score[i] = score[i - 1] - 1;
        }
    }

    for (int i = 0; i < score.size(); ++i) {
        counts[score[i]].push_back(i);
    }


    for (const auto& count : counts) {
        if (count.second.size() != 1 && result < count.second.back() - count.second.front()) {
            result = count.second.back() - count.second.front();
        }
    }
    if (counts.contains(0)) {
        if (result < counts[0].back() + 1) {
            result = counts[0].back() + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> results(n);

    for (auto& result : results) {
        cin >> result;
    }

    cout << find_longest_draw_game(results);

    return 0;
}
