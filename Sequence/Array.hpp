// TODO
#ifndef Array_H
#define Array_H

#define MAXN 1024

template <typename T>
class Array {
protected:
    T *pdata;
    int base;
    int size;

public:
    Array(int n_ = 0, int m_ = 0) : pdata(new T[MAXN]),
                                    base(m_),
                                    size(n_) {}

    Array(const Array<T> &Array_) : pdata(new T[MAXN]), base(Array_.base), size(Array_.size) {
        for (int i = 0; i < size; i++) {
            pdata[i] = Array_.pdata[i];
        }
    }
    
    ~Array() {
        delete[] pdata;
        pdata = nullptr;
    }
};

#endif