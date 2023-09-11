#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif



int siftUp(std::vector<int>& heap, int index) {
    if (index == 1) {
        return index;
    }
    int result = index;
    int parent_index = index / 2;

    if (heap[parent_index] < heap[index]) {
        std::swap(heap[parent_index], heap[index]);
        result = siftUp(heap, parent_index);
    }

    return result;
}

void heapAdd(std::vector<int>& heap, int key) {
    int i = heap.size() + 1;
//    heap[i] = key;
    heap.push_back(key);
    siftUp(heap, i);
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 6, 8, 3, 15, 7};
    assert(siftUp(sample, 5) == 1);
}


int main() {
    test();
}
#endif