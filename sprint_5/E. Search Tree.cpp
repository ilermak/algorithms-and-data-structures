#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

#define INT_MAX 0x7fffffff
#define INT_MIN -INT_MAX - 1

using namespace std;

bool isBST(const Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }

    if (root->value > maxValue || root->value < minValue) {
        return false;
    }

    return isBST(root->left, minValue, root->value - 1) && isBST(root->right, root->value + 1, maxValue);
}

bool Solution(const Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}


#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({1, nullptr, nullptr});
        Node node2({4, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(Solution(&node5));
    }
    {
        Node node1({1, nullptr, nullptr});
        Node node2({5, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(!Solution(&node5));
    }
}


int main() {
    test();
}
#endif