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


bool Solution(const Node* root1, const Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    else if (root1 == nullptr && root2 != nullptr || root1 != nullptr && root2 == nullptr) {
        return false;
    }

    bool left = Solution(root1->left, root2->left);
    bool right = Solution(root1->right, root2->right);


    return left && right && root1->value == root2->value;
}

#ifndef REMOTE_JUDGE
void test() {

    Node node1({1, nullptr, nullptr});
    Node node2({2, nullptr, nullptr});
    Node node3({3, &node1, &node2});

    Node node4({1, nullptr, nullptr});
    Node node5({2, nullptr, nullptr});
    Node node6({3, &node4, &node5});
    assert(Solution(&node3, &node6));
}

int main() {
    test();
}
#endif