#include <iostream>
#include <vector>

using namespace std;

pair<int, string> max_flowers(const vector<string>& array, int n, int m) {
    vector<vector<int>> field(n, vector(m, 0));
    vector<vector<int>> flowers(n, vector(m, 0));
    string road;

    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array[i].size(); ++j) {
            field[i][j] = array[n - i - 1][j] - '0';
        }
    }

    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[i].size(); ++j) {
            if (i > 0 && j > 0) {
                flowers[i][j] = max(flowers[i - 1][j], flowers[i][j - 1]) + field[i][j];
            }
            else if (j == 0 && i > 0) {
                flowers[i][j] = flowers[i - 1][j] + field[i][j];
            }
            else if (i == 0 && j > 0) {
                flowers[i][j] = flowers[i][j - 1] + field[i][j];
            }
            else if (i == 0 && j == 0) {
                flowers[i][j] = field[i][j];
            }
        }
    }
    int i = n - 1;
    int j = m - 1;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0) {
            if (flowers[i - 1][j] > flowers[i][j - 1]) {
                road.push_back('U');
                i--;
            }
            else {
                road.push_back('R');
                j--;
            }
        }
        else if (j == 0 && i > 0) {
            road.push_back('U');
            i--;
        }
        else if (i == 0 && j > 0) {
            road.push_back('R');
            j--;
        }
    }

    return {flowers.back().back(), road};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> field(n);

    for (auto& i : field) {
        cin >> i;
    }

    pair<int, string> result = max_flowers(field, n, m);
    for (int i = 0; i < result.second.size() / 2; ++i) {
        swap(result.second[i], result.second[result.second.size() - i - 1]);
    }

    cout << result.first << endl << result.second;

    return 0;
}