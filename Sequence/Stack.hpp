// TODO
#ifndef Stack_H
#define Stack_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

constexpr size_t MAX_SIZE = 1e7;

template <typename T>
struct Stack {
    Stack() {
        arr = new T[MAX_SIZE];
    }
    ~Stack() {
        delete[] arr;
        arr = nullptr;
    }

    T &top() {
        return arr[back - 1];
    }
    T const &top() const {
        return arr[back - 1];
    }
    void pop() {
        if (back == 0) {
            throw std::out_of_range("nothing to pop");
        }
        back--;
    }
    void push(const T &_val) {
        arr[back] = _val;
        back++;
    }
    size_t size() {
        return back;
    }
    bool empty() {
        return size() == 0;
    }

private:
    T *arr;
    size_t back;
};

#endif