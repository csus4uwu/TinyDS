// TODO
#ifndef BinaryTree_H
#define BinaryTree_H 1

#include <cstddef>
#include <map>

template <typename T>
struct Node {
    T val;
    Node<T> *prev;
    Node<T> *next;

    Node(const T &_val = {}) : val(_val), prev(nullptr), next(nullptr) {}

    ~Node() {}
};

template <typename T>
struct BinaryTree {
    BinaryTree() {}
    ~BinaryTree() {}

    auto insert() {
        bool success = true;
        Node now = new Node<T>;
        return std::make_pair(now, success);
    }
    T find(const T &_x) {
        Node<T> res = new Node;

        while (res != nullptr) {

        }
        return {};
    }
    void erase(const T &_x) {

    }
    bool contains(const T &_x) {
        return find(_x) != nullptr;
    }

    size_t size() {
        return n;
    }
    bool empty() {
        return size() == 0;
    }
private:
    size_t n;
    T *root;
};

#endif