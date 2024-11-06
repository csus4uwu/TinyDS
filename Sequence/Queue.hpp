#ifndef Queue_H
#define Queue_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

constexpr size_t MAX_SIZE = 1e7;

template <typename T>
struct Queue {
    Queue() {
        elements = new T[MAX_SIZE];
        st = 0;
        ed = 0;
    }
    ~Queue() {
        delete[] elements;
        elements = nullptr;
    }

    void push(T const &_val) {
        elements[ed++] = _val;
    }
    void pop() {
        if (this->empty()) {
            throw std::out_of_range("nothing to pop");
        }
        st++;
    }

    T const &back() const {
        if (this->empty()) {
            throw std::out_of_range("The Queue is Empty!");
        }
        return elements[ed - 1];
    }
    T &back() {
        if (this->empty()) {
            throw std::out_of_range("The Queue is Empty!");
        }
        return elements[ed - 1];
    }
    T const &front() {
        if (this->empty()) {
            throw std::out_of_range("The Queue is Empty!");
        }
        return elements[st];
    }
    T &front() {
        if (this->empty()) {
            throw std::out_of_range("The Queue is Empty!");
        }
        return elements[st];
    }

    size_t size() {
        return ed - st;
    }
    bool empty() {
        return size() == 0;
    }
private:
    T *elements;
    size_t st;
    size_t ed;
};

#endif