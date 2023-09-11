#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> list_of_edges_to_adjacency_list(const vector<pair<int, int>>& list, int n) {
    vector<unordered_set<int>>  adjacency_list(n);
    for (auto item : list) {
        if (item.first != item.second) {
            adjacency_list[item.first - 1].insert(item.second - 1);
            adjacency_list[item.second - 1].insert(item.first - 1);
        }
    }

    return adjacency_list;
}

bool is_full(const vector<unordered_set<int>>& adjacency_list, int n) {
    for (const auto& i : adjacency_list) {
        if (i.size() != n - 1) {
            return false;
        }
    }
    return true;
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

    if (is_full(list_of_edges_to_adjacency_list(list, n), n)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}