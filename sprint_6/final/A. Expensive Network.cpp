/*
ID решения - 89955713

-- ПРИНЦИП РАБОТЫ --
Алгоритм состоит из 3 шагов:
1. Выбор случайной стартовой вершины
2. Поиск ребра с наибольшим весом
3. Добавление потенциальных ребер
4. Повторение пункта 2, 3 до тех пор, пока в дереве не будет n вершин и n - 1 ребер.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(E*log(V)), где E — количество рёбер в графе, а V — количество вершин.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(E + V), где E — количество рёбер в графе, а V — количество вершин.

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct edge {
    int from;
    int to;
    int weight;
};

bool compare(const edge& first, const edge& second) {
    return first.weight < second.weight;
}

void sift_down(vector<edge>& heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (heap.size() <= left) {
        return;
    }

    int largest_index;

    if (right < heap.size() && compare(heap[left], heap[right])) {
        largest_index = right;
    } else {
        largest_index = left;
    }

    if (compare(heap[index], heap[largest_index]) == 1) {
        swap(heap[index], heap[largest_index]);
        sift_down(heap, largest_index);
    }
}

edge pop_max(vector<edge>& heap) {
    edge result = {0, 0, 0};
    if (!heap.empty()) {
        result = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        sift_down(heap, 0);
    }
    return result;
}

void sift_up(vector<edge>& heap, int index) {
    if (index == 0) {
        return;
    }

    int parent_index = (index - 1) / 2;
    if (!heap.empty()) {
        if (compare(heap[parent_index], heap[index])) {
            swap(heap[parent_index], heap[index]);
            sift_up(heap, parent_index);
        }
    }
}

void heap_add(vector<edge>& heap, const edge& key) {
    heap.push_back(key);
    sift_up(heap, heap.size() - 1);
}

vector<edge> find_MST(const vector<vector<pair<int, int>>>& adjacency_list) {
    vector<edge> maximum_staining_tree;
    unordered_set<int> not_added;
    vector<edge> edges;

    // добавление всех вершин
    for (int i = 0; i < adjacency_list.size(); ++i) { // Время - O(V), память - O(V)
        not_added.insert(i);
    }

    // берем первую вершину
    vector<pair<int, int>> start_vertex = adjacency_list[0];

    // добавляем эту вершину удаляем из not_added
    not_added.erase(0);
    // добавляем все инцидентные к ней ребра в массив
    for (auto edge : adjacency_list[0]) {
        if (not_added.contains(edge.first)) {
            heap_add(edges, {0, edge.first, edge.second});
        }
    }

    while (!not_added.empty() && !edges.empty()) {
        // нахождение максимума среди ребер
        edge max_edge = pop_max(edges);
        if (not_added.contains(max_edge.to)) {
            maximum_staining_tree.push_back(max_edge);


            not_added.erase(max_edge.to);
            for (auto edge : adjacency_list[max_edge.to]) {
                if (not_added.contains(edge.first)) {
                    heap_add(edges, {max_edge.to, edge.first, edge.second});
                }
            }
        }
    }

    if (!not_added.empty()) {
        return {};
    }
    return maximum_staining_tree;
}

vector<vector<pair<int, int>>> list_of_edges_to_adjacency_list(const vector<edge>& list, int n) { // Время - O(V), память - O(V + E)
    vector<vector<pair<int, int>>>  adjacency_list(n);
    for (auto item : list) {
        adjacency_list[item.from - 1].emplace_back(item.to - 1, item.weight);
        adjacency_list[item.to - 1].emplace_back(item.from - 1, item.weight);
    }

    return adjacency_list;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 0) {
        cout << 0;
        return 0;
    }

    vector<edge> list;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        list.push_back({u, v, w});
    }

    vector<vector<pair<int, int>>> adjacency_list = list_of_edges_to_adjacency_list(list, n);

    vector<edge> maximum_staining_tree = find_MST(adjacency_list);

    int sum_of_weights = 0;

    for (auto edge : maximum_staining_tree) {
        sum_of_weights += edge.weight;
    }
    if (sum_of_weights == 0) {
        cout << "Oops! I did it again";
    }
    else {
        cout << sum_of_weights;

    }

    return 0;
}