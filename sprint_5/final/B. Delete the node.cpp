/*
ID решения - 89679115

-- ПРИНЦИП РАБОТЫ --
Алгоритм состоит из трех частей: 
1. Поиск вершины, которую нужно удалить - D
2. Поиск вершины, которая встанет на место D - P
3. Корректная замена D на P 

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Поскольку бутылочное горлышко алгоритма - операция поиска элемента, временная сложность O(H), где H - высота дерева, log(N) <= H <= N, где N - кол-во узлов в дереве

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для алгоритма требуется хранить несколько переменных, пространственная сложность O(1) 
*/

#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <utility>
#include <iostream>

using namespace std;


pair<Node*, Node*> findDNode(Node* root, int key) { // Время - O(H), память - O(1)
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr && current->value != key) {
        parent = current;
        if (key < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return make_pair(current, parent);
}

pair<Node*, Node*> findLeftPNode(Node* root) { // Время - O(H), память - O(1)
    if (root == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    if (root->left == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    Node* parent = nullptr;
    Node* current = root->left;

    if (current->right == nullptr) {
        return make_pair(current, root);
    }

    while (current != nullptr && current->right != nullptr) {
        parent = current;
        current = current->right;
    }

    return make_pair(current, parent);
}

pair<Node*, Node*> findRightPNode(Node* root) { // Время - O(H), память - O(1)
    if (root == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    if (root->right == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    Node* parent = nullptr;
    Node* current = root->right;

    if (current->left == nullptr) {
        return make_pair(current, root);
    }

    while (current != nullptr && current->left != nullptr) {
        parent = current;
        current = current->left;
    }

    return make_pair(current, parent);
}

Node* remove(Node* root, int key) {
    pair<Node*, Node*> D_pair = findDNode(root, key);
    Node* D = D_pair.first;
    Node* D_parent = D_pair.second;
    if (D == nullptr) { // не удалось найти D
        return root;
    }

    pair<Node*, Node*> P_pair;
    bool isLeft;
    if (D->left != nullptr) { // поиск P в левом поддереве
        isLeft = true;
        P_pair = findLeftPNode(D);
    }
    else if (D->right != nullptr) { // поиск P в правом поддереве
        isLeft = false;
        P_pair = findRightPNode(D);
    }
    else { // нет детей
        if (D_parent == nullptr) { // D - единсвтенный узел в дереве, нет ни детей, ни родителя
            return nullptr;
        }
        if (D->value >= D_parent->value) { // D - правый сын
            D_parent->right = nullptr;
        }
        else { // D - левый сын
            D_parent->left = nullptr;
        }
        return root;
    }

    Node* P = P_pair.first;
    Node* P_parent = P_pair.second;

    if (isLeft) {
        if (P->left != nullptr && P_parent != D) {
            P_parent->right = P->left;
        }
        else if (P->left != nullptr || P_parent != D) {
            P_parent->right = nullptr;
        }
    }
    else {
        if (P->right != nullptr && P_parent != D) {
            P_parent->left = P->right;
        }
        else if (P->right != nullptr || P_parent != D) {
            P_parent->left = nullptr;
        }
    }

    if (D_parent != nullptr) {
        if (D->value < D_parent->value) {
            D_parent->left = P;
        }
        else {
            D_parent->right = P;
        }
    }

    if (D->left != P) {
        P->left = D->left;
    }
    if (D->right != P) {
        P->right = D->right;
    }

    if (D == root) {
        return P;
    }

    return root;
}

void print_tree(Node* root) {
    if (root == nullptr) {
        return;
    }

    print_tree(root->left);
    cout << root->value << " ";
    print_tree(root->right);
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({&node1, nullptr, 3});
    Node node3({nullptr, &node2, 1});
    Node node4({nullptr, nullptr, 6});
    Node node5({&node4, nullptr, 8});
    Node node6({&node5, nullptr, 10});
    Node node7({&node3, &node6, 5});
    assert(findDNode(&node7, 10) == make_pair(&node6, &node7));
    assert(findLeftPNode(&node6) == make_pair(&node5, &node6));
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

void test2() {
    Node node10({nullptr, nullptr, 99});
    Node node9({nullptr, nullptr, 72});
    Node node8({&node9, &node10, 91});
    Node node7({nullptr, nullptr, 50});
    Node node6({nullptr, nullptr, 32});
    Node node5({nullptr, &node6, 29});
    Node node4({nullptr, nullptr, 11});
    Node node3({&node7, &node8, 65});
    Node node2({&node4, &node5, 20});
    Node node1({&node2, &node3, 41});
    assert(findDNode(&node1, 41) == make_pair(&node1, (Node*)nullptr));
//    assert(findLeftPNode(&node1) == make_pair(&node6, &node5));
    pair<Node*,Node*> P_pair = findLeftPNode(&node1);
    cout << P_pair.first->value << " " << P_pair.second->value;
    Node* newHead = remove(&node1, 41);
    assert(newHead->value == 32);
}

void test3() {
    Node node7({nullptr, nullptr, 6});
    Node node6({&node7, nullptr, 8});
    Node node5({&node6, nullptr, 10});
    Node node4({nullptr, nullptr, 2});
    Node node3({&node4, nullptr, 3});
    Node node2({nullptr, &node3, 1});
    Node node1({&node2, &node5, 5});

    Node* newHead = remove(&node1, 10);
    cout << newHead->right->value << " " <<  newHead->right->left->value <<  endl;

    print_tree(newHead);
}

int main() {
    test3();
}
#endif
