#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> previous;
vector<int> dist;

void BFS(int start_vertex, vector<vector<int>>& adjacency_list) {
    vector<int> color(adjacency_list.size(), 0);
    dist.assign(adjacency_list.size(), 0);
    previous.assign(adjacency_list.size(), 0);

    queue<int> planned;
    planned.push(start_vertex);
    color[start_vertex] = 1;
    dist[start_vertex] = 0;
    while (!planned.empty()) {
        int u = planned.front();
        planned.pop();
        for (int i = 0; i < adjacency_list[u].size(); i++) {
            int v = adjacency_list[u][i];
            if (color[v] == 0) {
                dist[v] = dist[u] + 1;
                previous[v] = u;
                color[v] = 1;
                planned.push(v);
            }
        }
        color[u] = 2;
    }
}

vector<vector<int>> list_of_edges_to_adjacency_list(const vector<pair<int, int>>& list, int n) {
    vector<vector<int>>  adjacency_list(n);
    for (auto item : list) {
        adjacency_list[item.first - 1].push_back(item.second - 1);
        adjacency_list[item.second - 1].push_back(item.first - 1);
    }

    for (auto& item : adjacency_list) {
        sort(item.begin(), item.end(), [](int first, int second) {
            return first < second;
        });
    }

    return adjacency_list;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> list;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        list.emplace_back(u, v);
    }

    int from, to;
    cin >> from >> to;

    vector<vector<int>> adjacency_list = list_of_edges_to_adjacency_list(list, n);

    BFS(from - 1, adjacency_list);

    if (dist[to - 1] != 0) {
        cout << dist[to - 1];
    }
    else if (from == to) {
        cout << 0;
    }
    else {
        cout << -1;
    }

    return 0;
}