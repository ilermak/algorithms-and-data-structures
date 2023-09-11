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
#include <queue>
#include <deque>


using namespace std;

bool isEqual(const Node* root1, const Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    else if (root1 == nullptr && root2 != nullptr || root1 != nullptr && root2 == nullptr) {
        return false;
    }

    bool left = isEqual(root1->left, root2->right);
    bool right = isEqual(root1->right, root2->left);

    return left && right && root1->value == root2->value;
}

bool Solution(const Node* root) {
    return isEqual(root->left, root->right);
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({3, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({4, nullptr, nullptr});
    Node node4({3, nullptr, nullptr});
    Node node5({2, &node1, &node2});
    Node node6({2, &node3, &node4});
    Node node7({1, &node5, &node6});
    assert(Solution(&node7));
}


int main() {
    test();
}
#endif