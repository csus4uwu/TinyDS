// todo

/**
 * @author  postpone (github: csus4uwu)
 * @file  Tree/BinaryTree.hpp
 * TinyDS 项目地址： <https://github.com/csus4uwu/TinyDS> 
 * 欢迎 pr 或者提 issue ^v^
 */
#ifndef BinaryTree_H
#define BinaryTree_H 1

#include <cstddef>
#include <map>
#include <vector>

/**
 *  @brief  二叉搜索树的节点
 *
 *  @tparam  T  类型
 */
template <typename T>
struct Node {
    T val;
    Node<T> *leftSon;
    Node<T> *rightSon;

    Node(const T &_val = {})
        : val(_val), leftSon(nullptr), rightSon(nullptr) {}

    ~Node() {}
};

/**
 *  @brief  二叉搜索树
 *
 *  @tparam  T  元素类型
 */
template <typename T>
struct BinaryTree {
    BinaryTree()
        : n(0), root(nullptr) {}
    ~BinaryTree() {}

    Node<T> *find(const T &_x) {
        Node<T> *now = getRoot();

        while (now != nullptr and now->val != _x) {
            if (now->val < _x) {
                now = now->leftSon;
            } else {
                now = now->rightSon;
            }
        }
        return now;
    }
    Node<T> *const &find(const T &_x) const {
        Node<T> *now = getRoot();

        while (now != nullptr and now->val != _x) {
            if (now->val < _x) {
                now = now->leftSon;
            } else {
                now = now->rightSon;
            }
        }
        return now;
    }

    /**
     *  @param  _x  要找的元素
     *  @param  _parent  传入一个引用，最后变成目标元素的父节点
     */
    Node<T> *find(const T &_x, Node<T> *&_parent) {
        Node<T> *now = getRoot();

        while (now != nullptr and now->val != _x) {
            if (now->val < _x) {
                _parent = now;
                now = now->leftSon;
            } else {
                _parent = now;
                now = now->rightSon;
            }
        }
        return now;
    }

    bool insert(const T &_x) {
        Node<T> *parent;
        if (this->find(_x, parent) != nullptr) {
            return false;
        }
        Node<T> *p = Node(_x);
        if (_x < parent->val) {
            parent->leftSon = p;
        } else {
            parent->rightSon = p;
        }
        return true;
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
        return root == nullptr;
    }
    Node<T> *getRoot() {
        return this->root;
    }

protected:
    size_t n;
    Node<T> *root;
};

#endif