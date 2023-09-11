#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<float, float>> max_lessons(vector<pair<float, float>>& timetable) {
    if (timetable.empty()) return {};

    vector<pair<float, float>> timetable_by_start;
    vector<pair<float, float>> timetable_by_length;
    vector<pair<float, float>> timetable_by_finish;

    sort(timetable.begin(), timetable.end(), [](pair<float, float> first, pair<float, float> second) {
        if (first.first != second.first) {
            return first.first < second.first;
        }
        return first.second < second.second;
    });
    timetable_by_start.push_back(timetable[0]);
    for (auto i = 1; i < timetable.size(); ++i) {
        if (timetable[i].first >= timetable_by_start.back().second) {
            timetable_by_start.push_back(timetable[i]);
        }
    }

    sort(timetable.begin(), timetable.end(), [](pair<float, float> first, pair<float, float> second) {
        return first.second - first.first < second.second - second.first;
    });
    timetable_by_length.push_back(timetable[0]);
    for (auto i = 1; i < timetable.size(); ++i) {
        if (timetable[i].first >= timetable_by_length.back().second) {
            timetable_by_length.push_back(timetable[i]);
        }
    }

    sort(timetable.begin(), timetable.end(), [](pair<float, float> first, pair<float, float> second) {
        if (first.second != second.second) {
            return first.second < second.second;
        }
        return first.first < second.first;
    });
    timetable_by_finish.push_back(timetable[0]);
    for (auto i = 1; i < timetable.size(); ++i) {
        if (timetable[i].first >= timetable_by_finish.back().second) {
            timetable_by_finish.push_back(timetable[i]);
        }
    }

    if (timetable_by_start.size() > timetable_by_length.size()) {
        if (timetable_by_start.size() > timetable_by_finish.size()) {
            return timetable_by_start;
        }
        else {
            return timetable_by_finish;
        }
    }
    else {
        if (timetable_by_length.size() > timetable_by_finish.size()) {
            return timetable_by_length;
        }
        else {
            return timetable_by_finish;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<float, float>> timetable(n);

    for (auto& i : timetable) {
        cin >> i.first >> i.second;
    }

    vector<pair<float, float>> result = max_lessons(timetable);
    cout << result.size() << '\n';
    for (auto item : result) {
        cout << item.first << " " <<  item.second << '\n';
    }

    return 0;
}
