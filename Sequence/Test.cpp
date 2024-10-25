#include <iostream>

#include "Array.hpp"
#include "Stack.hpp"

using std::cin, std::cout, std::cerr, std::endl;

struct Info {
    short A;
    double B;

    Info(const short &_A = 0, const double &_B = 0) : A(_A), B(_B) {}

    void display() {
        cout << this->A << " " << this->B << endl;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.A = a.A * b.A;
    c.B = (a.B - b.B) / 2;
    return c;
}

enum Which {
    _Array,
    _Stack,
    _Queue,
    _Dequeue,
};

void test(Which which) {
    if (which == _Array) {

        // Array test0
        Array<int, 5> a;

        a.fill(123);
        cout << a[3] << endl;

        a[2] = 1;
        a[3] = 2;
        a[4] = 1e9;

        cout << a.front() << " " << a.back() << endl;

        for (auto it = a.begin(); it != a.end(); it++) {
            cout << *it << " ";
        }
        endl(cout);

        // Array test1
        Array<Info, 3> b;
        b.front() = {1, -10};
        b[2].A = 50;
        b[2].B = 0.5;
        b[1] = b.front() + b.back();

        b[1].display();
        for (auto it = b.begin(); it != b.end(); it++) {
            it->display();
        }
        endl(cout);

    } else if (which == _Stack) {
        // Stack test0
        Stack<int> a;
        a.push(100);
        cout << a.top() << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    test(_Array);

    return 0;
}