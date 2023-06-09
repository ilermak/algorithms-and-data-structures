/*
ID решения - 88037385

-- ПРИНЦИП РАБОТЫ --
Для нахождения элемента также требуется локализовать место, где нарушается порядок сортировки.
Для этого проверяется сравнивается левый и средний элементы.
Если левый меньше среднего, то нарушения нет, то осуществляется проверка на наличие элемента в левой части массива.
Если элемента в левой части нет, то левая граница сдвигается до середины.
Если элемент есть, то правая граница сдвигается до середины.
А если левый больше среднего, то нарушение есть, и проверяется наличие элемента в правой части массива.  
Если элемента в правой части нет, то правая граница сдвигается до середины.
Если элемент есть, то левая граница сдвигается до середины.
Таким образом, на каждой итерации цикла количество элементов, которые нужно проверить, уменьшается вдвое.
Если элемент найден, то возвращается его индекс, иначе возвращается -1.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Поскольку на каждой итерации цикла количество элементов, которые нужно проверить, уменьшается вдвое, то в конце концов останется один элемент, который будет равен искомому.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
С каждой итерацией цикла количество элементов, которые нужно проверить, уменьшается вдвое, поэтому временная сложность алгоритма - O(log(n)), где n - количество элементов в массиве.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для работы алгоритмы память выделяется только на переменные, которые не зависят от размера входных данных, поэтому пространственная сложность алгоритма - O(1).
*/

#include "solution.h"
#include <vector>

int broken_search(const std::vector<int>& vec, int k) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (k == vec[mid]) {
            return mid;
        }
        else if (vec[left] <= vec[mid]) {
            if (vec[left] <= k && k < vec[mid]) {
                right = mid -  1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (vec[mid] < k && k <= vec[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
