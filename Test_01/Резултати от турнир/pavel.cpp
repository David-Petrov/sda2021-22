#include <algorithm>
#include <iostream>

struct Team {
    static unsigned int ID;
    unsigned int id;
    double teamSize, enemyTeamSize;
    long double finalPoints;

    Team() : id(ID++) {
        std::cin >> teamSize >> enemyTeamSize;
        finalPoints = teamSize * teamSize / enemyTeamSize;
    }
};
unsigned int Team::ID = 1;

int main() {
    size_t n;
    std::cin >> n;

    Team *boys = new Team[n];

    std::sort(boys, boys + n, [](Team &b1, Team &b2) {
        if (b1.finalPoints != b2.finalPoints) {
            return b1.finalPoints > b2.finalPoints;
        }

        return b1.teamSize > b2.teamSize;
    });

    std::for_each(boys, boys + n, [](Team &b) { std::cout << b.id << ' '; });

    delete[] boys;
}
