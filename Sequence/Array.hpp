// TODO
#ifndef Array_H
#define Array_H 1

#include <cstddef>   // size_t
#include <stdexcept> // std::out_of_range

template <typename T, size_t N>
struct Array {
    T &operator[](size_t _pos) noexcept {
        if (_pos >= N) {
            throw std::out_of_range("invalid position");
        }
        return elements[_pos];
    }
    T const &operator[](size_t _pos) const noexcept {
        if (_pos >= N) {
            throw std::out_of_range("invalid position");
        }
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
    T const *data() const noexcept {
        return elements;
    }
    T *data() noexcept {
        return elements;
    }
    T const *begin() const noexcept {
        return elements;
    }
    T *begin() noexcept {
        return elements;
    }
    T const *end() const noexcept {
        return elements + N;
    }
    T *end() noexcept {
        return elements + N;
    }
private:
    T elements[N];
};

#endif