/*
ID решения - 89781517

-- ПРИНЦИП РАБОТЫ --
В своей основе пирамидальная сортировка использует свойства бинарной кучи
Алгоритм состоит из 3 шагов:
1. Создание пустой бинарной неубывающей кучи
2. Вставка в нее элементов массива с сохранением свойств кучи
3. Извлечение наиболее приоритетных элементов из кучи и запись в результирующий массив

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Временная сложность пирамидальной сортировки O(n*log(n)), где n - количество элементов в массиве.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Пространственная сложность пирамидальной сортировки O(n), где n - количество элементов в массиве.
*/

#include <vector>
#include <iostream>
#include <string>

#define INT_MAX 2147483647

using namespace std;

struct triple {
    string name;
    int mark{};
    int fine{};
};


int compare(const triple& first, const triple& second) {
    if (first.mark > second.mark) {
        return 0;
    }
    else if (first.mark == second.mark) {
        if (first.fine < second.fine) {
            return 0;
        }
        else if (first.fine == second.fine) {
            if (first.name > second.name) {
                return 1;
            }
            else if (first.name == second.name) {
                return 2;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 1;
    }
}

triple split(string str, char separator) {
    triple split_string;
    string word;
    int counter = 0;
    for (int i = 0; i < str.size() + 1; ++i) {
        if (str[i] != separator && str[i] != '\0')
            word += str[i];
        else {
            if (counter == 0) {
                split_string.name = word;
                word.clear();
            }
            else if (counter == 1) {
                split_string.mark = stoi(word);
                word.clear();
            }
            else if (counter == 2) {
                split_string.fine = stoi(word);
                word.clear();
            }
            counter++;
        }
    }
    return split_string;
}

void sift_down(vector<triple>& heap, int index) { // O(log(N)) O(log(N))
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (heap.size() <= left) {
        return;
    }

    int largest_index;

    if (right < heap.size() && compare(heap[left], heap[right]) == 1) {
        largest_index = right;
    } else {
        largest_index = left;
    }

    if (compare(heap[index], heap[largest_index]) == 1) {
        swap(heap[index], heap[largest_index]);
        sift_down(heap, largest_index);
    }
}

triple pop_max(vector<triple>& heap) {
    triple result = {"0", 0, 0};
    if (!heap.empty()) {
        result = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        sift_down(heap, 0);
    }
    return result;
}

void sift_up(vector<triple>& heap, int index) {
    if (index == 0) {
        return;
    }

    int parent_index = (index - 1) / 2;
    if (!heap.empty()) {
        if (compare(heap[parent_index], heap[index]) == 1) {
            swap(heap[parent_index], heap[index]);
            sift_up(heap, parent_index);
        }
    }
}

void heap_add(vector<triple>& heap, const triple& key) {
    heap.push_back(key);
    sift_up(heap, heap.size() - 1);
}

vector<triple> heapsort(const vector<triple>& array) {
    vector<triple> heap;

    for (const auto& item : array) {
        heap_add(heap, item);
    }

    vector<triple> sorted_array;

    for (int i = 0; !heap.empty(); ++i) {
        triple max = pop_max(heap);
        sorted_array.push_back(max);
    }

    return sorted_array;
}

int main() {
    int n;
    cin >> n;
    string row;
    cin.ignore(INT_MAX, '\n');
    vector<triple> top;

    for (int i = 0; i < n; ++i) {
        getline(cin, row);
        top.push_back(split(row, ' '));
    }

    top = heapsort(top);

    for (const auto& i : top) {
        cout << i.name << endl;
    }

    return 0;
}