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

using namespace std;


int isStable(const Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = isStable(root->left);
    int right = isStable(root->right);

    if (left != -1 && right != -1 && (left - right == 0 || left - right == 1 || right - left == 1)) {
        return max(left, right) + 1;
    }
    else {
        return -1;
    }
}

bool Solution(const Node* root) {
    if (isStable(root) != -1) {
        return true;
    }
    else {
        return false;
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({10, nullptr, nullptr});
    Node node5({2, &node3, &node4});
    assert(Solution(&node5));
}

int main() {
    test();
}
#endif