/*
ID решения - 90141863

-- ПРИНЦИП РАБОТЫ --
Для нахождения расстояния по Левенштейну используется алгоритм Вагнера-Фишера.
Он заключается в том, что кэширует результаты рекуррентной формулы для вычисления расстояния Левенштейна с небольшой модификацией для избежания
дублирования вычислений.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(N * M), где N и M длины входных строк соответственно.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
O(N), где N длина наименьшей строки.

*/


#include <iostream>
#include <vector>

using namespace std;

int find_levenshtein_distance(string& first, string& second) {
    if (second.empty()) {
        return first.size();
    }
    else if(first.empty()) {
        return second.size();
    }

    if (first < second) {
        swap(first, second);
    }

    vector<vector<int>> distance_matrix(2, vector<int>(second.size() + 1, 0));

    for (int i = 0; i < first.size() + 1; ++i) {
        for (int j = 0; j < distance_matrix[i % 2].size(); ++j) {
            if (i == 0 && j > 0) {
                distance_matrix[0][j] = j;
            }
            else if (j == 0 && i > 0) {
                distance_matrix[1][j] = i;
            }
            else if (j > 0 && i > 0) {
                distance_matrix[1][j] = min(min(distance_matrix[0][j] + 1, distance_matrix[1][j - 1] + 1), distance_matrix[0][j - 1] + (int)(first[i - 1] != second[j - 1]));
            }
        }

        if (i > 0) {
            distance_matrix[0] = distance_matrix[1];
        }
    }

    return distance_matrix.back().back();
}

int main() {
    string first, second;
    cin >> first;
    cin >> second;

    cout << find_levenshtein_distance(first, second);

    return 0;
}