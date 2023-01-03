#include <algorithm>
#include <iostream>

struct Demon;

typedef unsigned int ui;

typedef bool (*Comparator)(Demon, Demon);

struct Demon {
    ui attack;
    ui defense;

    static auto getOperatorLessThan(bool byAttack) -> Comparator {
        if (byAttack) {
            return [](Demon d1, Demon d2) {
                return d1.attack < d2.attack;
            };
        } else {
            return [](Demon d1, Demon d2) {
                return d1.defense < d2.defense;
            };
        }
    }

    Demon(ui attack = 0, ui defense = 0) : attack(attack), defense(defense) {};

    bool operator<(const Demon &d) const {
        if (this->attack < d.attack) {
            return true;
        } else if (this->attack > d.attack) {
            return false;
        }

        return this->defense < d.defense;
    }

    bool operator==(const Demon &d) const {
        return this->attack == d.attack && this->defense == d.defense;
    }

    friend std::istream &operator>>(std::istream &is, Demon &d);

    friend std::ostream &operator<<(std::ostream &os, const Demon &d);
};

std::istream &operator>>(std::istream &is, Demon &d) {
    return is >> d.defense >> d.attack;
}

std::ostream &operator<<(std::ostream &os, const Demon &d) {
    return os << d.defense << ' ' << d.attack;
}

int CeilIndex(Demon *v, int l, int r, Demon key, Comparator comparator) {
    while (r - l > 1) {
        int m = l + ((r - l) >> 1);
        if (comparator(v[m], key)) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

int longest_incr_subseq(Demon *v, size_t size, Comparator comparator) {
    if (size == 0) {
        return 0;
    }

    Demon *tail = new Demon[size];
    int length  = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < size; ++i) {

        if (comparator(v[i], tail[0])) {
            tail[0] = v[i];
        } else if (comparator(tail[length - 1], v[i])) {
            tail[length++] = v[i];
        } else {
            tail[CeilIndex(tail, -1, length - 1, v[i], comparator)] = v[i];
        }
    }

    return length;
}

int main() {
    long n;
    std::cin >> n;

    Demon *demons = new Demon[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> demons[i];
    }

    std::sort(demons, demons + n);

    std::cout << std::min(
        longest_incr_subseq(demons, n, Demon::getOperatorLessThan(true)),
        longest_incr_subseq(demons, n, Demon::getOperatorLessThan(false)));

    delete[] demons;
    return 0;
}
