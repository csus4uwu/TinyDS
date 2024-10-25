#ifndef CArray_H
#define CArray_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

constexpr int MAX_SIZE = 1e7;

template <typename T>
struct CArray {
    CArray() {
        elements = new T[MAX_SIZE];
    }
    ~CArray() {
        delete[] elements;
        elements = nullptr;
    }
    T const &operator[](size_t _pos) const {
        if (_pos >= MAX_SIZE) {
            throw std::out_of_range("invalid position");
        }
        return elements[_pos];
    }
    T &operator[](size_t _pos) {
        if (_pos >= MAX_SIZE) {
            throw std::out_of_range("invalid position");
        }
        return elements[_pos];
    }
    T *data() {
        return elements;
    }
    void fill(size_t _l, size_t _r, T const &_val) {
        for (size_t i = _l; i < _r; i++) {
            elements[i] = _val;
        }
    }
    void fill(T const &_val) {
        fill(0, MAX_SIZE, _val);
    }
    void clear(size_t _l = 0, size_t _r = MAX_SIZE) {
        fill(_l, _r, {});
    }
    T &front() noexcept {
        return elements[0];
    }
    T const &front() const noexcept {
        return elements[0];
    }
    T &back() noexcept {
        return elements[MAX_SIZE - 1];
    }
    T const &back() const noexcept {
        return elements[MAX_SIZE - 1];
    }
private:
    T *elements;
    size_t N;
};

#endif