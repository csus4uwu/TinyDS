// TODO
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
private:
    T *elements;
    size_t st;
    size_t ed;
};

#endif