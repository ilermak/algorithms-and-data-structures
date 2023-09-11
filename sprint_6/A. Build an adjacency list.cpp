#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, vector<int>>> list_of_edges_to_adjacency_list(const vector<pair<int, int>>& list, int n) {
    vector<pair<int, vector<int>>> adjacency_list(n);
    for (auto item : list) {
        adjacency_list[item.first - 1].second.push_back(item.second);
    }

    for (auto& item : adjacency_list) {
        item.first = item.second.size();
    }

    return adjacency_list;
}

void print_adjacency_list(const vector<pair<int, vector<int>>>& adjacency_list) {
    for (const auto& i : adjacency_list) {
        cout << i.first << " ";
        for (auto j : i.second) {
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

    print_adjacency_list(list_of_edges_to_adjacency_list(list, n));

    return 0;
}