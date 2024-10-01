// TODO
#ifndef Array_H
#define Array_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

template <typename T, size_t N>
struct Array {
    T elements[N];

    T &operator[](size_t _pos) noexcept {
        return elements[_pos];
    }

    T const &operator[](size_t _pos) const noexcept {
        return elements[_pos];
    }

    T &at(size_t _pos) {
        if (_pos >= N) [[__unlikely__]]
            throw std::out_of_range("array::at");
        return elements[_pos];
    }

    T const &at(size_t _pos) const {
        if (_pos >= N) [[__unlikely__]]
            throw std::out_of_range("array::at");
        return elements[_pos];
    }

    void fill(T const &_val) noexcept {
        for (size_t i = 0; i < N; i++) {
            elements[i] = _val;
        }
    }

    T &front() noexcept {
        return elements[0];
    }

    T const &front() const noexcept {
        return elements[0];
    }

    T &back() noexcept {
        return elements[N - 1];
    }

    T const &back() const noexcept {
        return elements[N - 1];
    }

    T const *data() {
        return elements;
    }

    T const *begin() const {
        return elements;
    }

    T *begin() {
        return elements;
    }

    T const *end() const {
        return elements + N;
    }

    T *end() {
        return elements + N;
    }
};

#endif