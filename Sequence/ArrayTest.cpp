#include <iostream>
#include "Array.hpp"

using std::cin, std::cout, std::cerr, std::endl;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Array<int, 5> a;

    a.fill(123);
    cout << a[3] << endl;

    a[2] = 1;
    a[3] = 2;
    a[4] = 1e9;
    cout << a[4] << endl;

    cout << a.front() << " " << a.back() << endl;

    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    endl(cout);

    return 0;
}