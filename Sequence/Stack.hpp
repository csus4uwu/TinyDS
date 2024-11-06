#ifndef Stack_H
#define Stack_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

constexpr size_t MAX_SIZE = 1e7;

template <typename T>
struct Stack {
    Stack() {
        elements = new T[MAX_SIZE];
    }
    ~Stack() {
        delete[] elements;
        elements = nullptr;
    }

    T &top() {
        return elements[back - 1];
    }
    T const &top() const {
        return elements[back - 1];
    }
    void pop() {
        if (back == 0) {
            throw std::out_of_range("nothing to pop");
        }
        back--;
    }
    void push(const T &_val) {
        elements[back] = _val;
        back++;
    }
    size_t size() {
        return back;
    }
    bool empty() {
        return size() == 0;
    }

private:
    T *elements;
    size_t back;
};

#endif