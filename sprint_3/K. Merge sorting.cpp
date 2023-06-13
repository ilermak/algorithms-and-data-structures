#include <vector>
#include <cassert>

using namespace std;

using Iterator = vector<int>::iterator;
using CIterator = vector<int>::const_iterator;

vector<int> merge(CIterator left_begin, CIterator left_end, CIterator right_begin, CIterator right_end) {
    vector<int> result(distance(left_begin, left_end) + distance(right_begin, right_end) , 0);
    int k = 0;
    while (left_begin < left_end && right_begin < right_end) {
        // выбираем, из какого массива забрать минимальный элемент
        if (*left_begin <= *right_begin) {
            result[k] = *left_begin;
            left_begin++;
        }
        else {
            result[k] = *right_begin;
            right_begin++;
        }
        k++;
    }

    // Если один массив закончился раньше, чем второй, то
    // переносим оставшиеся элементы второго массива в результирующий
    while (left_begin < left_end) {
        result[k] = *left_begin;   // перенеси оставшиеся элементы left в result
        left_begin++;
        k++;
    }
    while (right_begin < right_end) {
        result[k] = *right_begin;  // перенеси оставшиеся элементы right в result
        right_begin++;
        k++;
    }
    return result;
}

void merge_sort(Iterator begin, Iterator end) {

    if (distance(begin, end) == 1) {
        return;
    }

    merge_sort(begin, next(begin, distance(begin, end) / 2));
    merge_sort(next(begin, distance(begin, end) / 2), end);

    vector<int> result = merge(begin, next(begin, distance(begin, end) / 2),
                               next(begin, distance(begin, end) / 2), end);

    for (int i = 0; i < result.size(); ++i) {
        *next(begin, i) = result[i];
    }
}

void test_merge_sort() {
    vector<int> a = {1, 4, 9};
    vector<int> b = {2, 10, 11};
    vector<int> c = merge(a.cbegin(), a.cend(), b.cbegin(), b.cend());
    vector<int> expected = {1, 2, 4, 9, 10, 11};
    assert(c == expected);
    vector<int> d = {1, 4, 2, 10, 1, 2};
    vector<int> sorted = {1, 1, 2, 2, 4, 10};
    merge_sort(d.begin(), d.end());
    assert(d == sorted);
}
