/*
ID решения - 89989595

-- ПРИНЦИП РАБОТЫ --
Фишка заключается в том, что карта считается неоптимальной в том случае, если из А в В можно добраться на дорогах разных типов.
Так же есть правило передвижения из меньшего города к большему, но если развернуть дороги одного типа, то получится,
что при неоптимальности можно добраться из A в B по дороге одного типа, и из B в A о дороге другого типа, получается,
что в таком случае в графе будет цикл, и задачу можно свести к определению наличия цикла в графе с помощью DFS.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(E + V), где E — количество рёбер в графе, а V — количество вершин.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(E + V), где E — количество рёбер в графе, а V — количество вершин.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

bool DFS(vector<vector<int>>& adjacency_list) {
    vector<int> color(adjacency_list.size(), 0);
    stack<int> stack;
    int visited_count = 0;
    int start_vertex = 0;
    while (visited_count != adjacency_list.size()) { // Время - O(N)
        if (color[start_vertex] != 2) {
            stack.push(start_vertex);
            while (!stack.empty()) {
                int v = stack.top();
                stack.pop();
                if (color[v] == 0) {
                    color[v] = 1;
                    stack.push(v);
                    for (auto w : adjacency_list[v]) {
                        if (color[w] == 0) {
                            stack.push(w);
                        }
                        else if (color[w] == 1) {
                            return false;
                        }
                    }
                }
                else if (color[v] == 1) {
                    color[v] = 2;
                    visited_count++;
                }
            }
        }
        start_vertex++;
    }

    return true;
}

vector<vector<int>> list_of_edges_to_adjacency_list(const vector<string>& list) { // Время - O(V), память - O(V + E)
    vector<vector<int>>  adjacency_list(list.size() + 1);

    for (int i = 0; i < list.size(); ++i) {
        for (int j = 0; j < list[i].size(); ++j) {
            if (list[i][j] == 'B') {
                adjacency_list[i].emplace_back(j + i + 1);
            }
            else if (list[i][j] == 'R') {
                adjacency_list[j + i + 1].emplace_back(i);
            }
        }
    }

    return  adjacency_list;
}

int main() {
    int n;
    cin >> n;

    vector<string> list;

    for (int i = 0; i < n - 1; ++i) {
        string str;
        cin >> str;
        list.push_back(str);
    }

    vector<vector<int>>  adjacency_lists = list_of_edges_to_adjacency_list(list);

    if (DFS(adjacency_lists)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}