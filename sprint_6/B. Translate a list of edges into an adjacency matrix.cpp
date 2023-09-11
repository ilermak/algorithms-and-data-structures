#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> list_to_matrix(const vector<pair<int, int>>& list, int n) {
    vector<vector<int>> matrix(n, vector<int> (n, 0));

    for (auto item : list) {
        matrix[item.first - 1][item.second - 1] = 1;
    }

    return matrix;
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> list;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        list.emplace_back(u,v);
    }

    print_matrix(list_to_matrix(list, n));

    return 0;
}