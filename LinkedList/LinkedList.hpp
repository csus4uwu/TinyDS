// TODO
#ifndef LinkedList_H
#define LinkedList_H 1

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
struct Node {
    T val;
    Node<T> *prev;
    Node<T> *next;

    Node(const T &_val = {}) : val(_val), prev(nullptr), next(nullptr) {}
    ~Node() {
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
struct LinkedList {
    LinkedList(const LinkedList &_init = {}) {
        init(_init);
    }

    void init(const LinkedList &_init = {}) {
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->prev = head;

        Node<T> *now = _init.head->next;
        while (now != _init.tail) {
            insert(tail, now->val);
            now = now->next;
        }
    }

    bool empty() {
        return head->next == tail;
    }

    void insert(Node<T> *_pos, T _val = {}) {
        Node<T> *now = new Node<T>();
        now->val = _val;
        now->next = _pos;
        now->prev = _pos->prev;

        _pos->prev->next = now;
        _pos->prev = now;
    }
    void insert(Node<T> *_pos, Node<T> *_node) {
        _now->next = _pos;
        _now->prev = _pos->prev;

        _pos->prev->next = _now;
        _pos->prev = _now;
    }
    void push_back(const T &_val) {
        insert(tail, _val);
    }
    void push_back(const Node<T> &_node) {
        insert(tail, &_node);
    }
    void push_front(const T &_val) {
        insert(head->next, _val);
    }
    void push_front(const Node<T> &_node) {
        insert(head->next, now);
    }
    void erase(Node<T> *_pos) {
        if (not empty()) {

        } else {
            throw std::out_of_range("the ")
        }
    }
    void erase(size_t _pos) {
        if (empty()) {
        }
        for (int i = 0; i < x; i++) {
        }
    }
    void pop_back() {
        erase(0);
    }
    void pop_front() {
        erase(head->next);
    }
    ~LinkedList() {
        this->clear();
        delete head;
        delete tail;
    }

    void clear() {
        while (not empty()) {
            pop_back();
        }
    }

    unsigned size() {
        unsigned siz = 0;
        Node<T> *now = head;
        while (now != tail) {
            siz++;
            now = now->next;
        }
        return siz;
    }

    LinkedList &operator=(const LinkedList &&rhs) const {
        if (this == rhs) {
            return *this;
        }

        clear();
        delete head;
        delete tail;
        init(rhs);

        return *this;
    }
    

private:
    Node<T> *head;
    Node<T> *tail;
};

#endif