// TODO
#ifndef Array_H
#define Array_H

#define MAXN 1024

using uint = unsigned int;

template <typename T, uint N>
struct Array {
    T *pdata;
    uint base;
    uint size;

    Array(uint size_ = 0, uint base_ = 0) : pdata(new T[N]), base(base_), size(size_) {
        static_assert(0 < N && N <= MAXN);
    }

    Array(const Array<T, N> &Array_) : pdata(new T[N]), base(Array_.base), size(Array_.size) {
        for (uint i = 0; i < size; i++) {
            pdata[i] = Array_.pdata[i];
        }
    }

    ~Array() {
        delete[] pdata;
        pdata = nullptr;
    }

    T operator[](uint x) {
    }

    T *data() const {
        return this->pdata;
    }

    uint getSize() {
        return this->size;
    }

    uint getBase() {
        return this->base;
    }
};

#endif