#include <algorithm>
#include <iostream>

struct Boy {
    static unsigned int ID;
    unsigned int id;
    double phi, time;
    long double eff;

    Boy() : id(ID++) {
        std::cin >> phi >> time;
        eff = phi * phi / time;
    }
};
unsigned int Boy::ID = 1;

int main() {
    size_t n;
    std::cin >> n;

    Boy *boys = new Boy[n];

    std::sort(boys, boys + n, [](Boy &b1, Boy &b2) {
        if (b1.eff != b2.eff) {
            return b1.eff > b2.eff;
        }

        return b1.phi > b2.phi;
    });

    std::for_each(boys, boys + n, [](Boy &b) { std::cout << b.id << ' '; });

    delete[] boys;
}
