#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> color;

void DFS(int start_vertex, vector<vector<int>>& adjacency_list) {
    color.assign(adjacency_list.size(), 0);
    stack<int> stack;
    stack.push(start_vertex);
    while (!stack.empty()) {
        int v = stack.top();

        stack.pop();
        if (color[v] == 0) {
            color[v] = 1;
        cout << v + 1 << " ";
            stack.push(v);
            for (auto w : adjacency_list[v]) {
                if (color[w] == 0) {
                    stack.push(w);
                }
            }
        }
        else if (color[v] == 1) {
            color[v] = 2;
        }
    }
}

/*
void mainDFS(int V, vector<vector<int>>& adjacency_list) {
    color.assign(V, 0); // Инициализируем вектор цветов.
    for (int i = 0; i < V; ++i) { // Перебираем варианты стартовых вершин.
        if (color[i] == 0) {
            DFS(i, adjacency_list); // Запускаем обход, стартуя с i-й вершины.
        }
    }
}
*/

vector<vector<int>> list_of_edges_to_adjacency_list(const vector<pair<int, int>>& list, int n) {
    vector<vector<int>>  adjacency_list(n);
    for (auto item : list) {
        adjacency_list[item.first - 1].push_back(item.second - 1);
        adjacency_list[item.second - 1].push_back(item.first - 1);
    }

    for (auto& item : adjacency_list) {
        sort(item.begin(), item.end(), [](int first, int second) {
            return first > second;
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

    int start_vertex;
    cin >> start_vertex;

    vector<vector<int>> adjacency_list = list_of_edges_to_adjacency_list(list, n);

    DFS(start_vertex - 1, adjacency_list);

    return 0;
}