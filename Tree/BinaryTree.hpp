// TODO
#include <cstddef>

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

    void insert() {

    }
    void find(const T &_x) {

    }
    void erase() {

    }
    bool contains(const T &_x) {
        return find(_x) != nullptr;
    }

    size_t size() {
        return Size();
    }
    bool empty() {
        return size() == 0;
    }
private:
    size_t Size;
};