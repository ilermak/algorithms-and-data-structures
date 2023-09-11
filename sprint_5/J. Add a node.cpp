#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>




Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key, nullptr, nullptr);
    }
    Node* current = root;
    Node* parent = nullptr;


    while (current != nullptr) {
        parent = current;
        if (key < parent->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (parent->value > key) {
        parent->left = new Node(key, nullptr, nullptr);
    }
    else {
        parent->right = new Node(key, nullptr, nullptr);
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1(7, nullptr, nullptr);
    Node node2(8, &node1, nullptr);
    Node node3(7, nullptr, &node2);
    Node* newHead = insert(&node3, 6);
    assert(newHead->left->value == 6);
    assert(newHead == &node3);
}

int main() {
    test();
}
#endif