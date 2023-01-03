#include <iostream>
#include <list>

typedef std::list<int>::iterator PersonIter;
typedef std::list<PersonIter>::iterator PersonIterIter;

int main() {
    size_t n;
    std::cin >> n;

    std::list<int> people;
    std::list<PersonIter> seqs;

    int temp;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> temp;

        people.push_back(temp);

        if (i && *std::prev(std::prev(people.end())) < temp) {
            seqs.push_back(std::prev(people.end()));
        }
    }

    PersonIterIter runner;
    size_t day = 0;
    bool battleOccurred;
    while (!seqs.empty()) {
        ++day;

        battleOccurred = false;
        runner         = std::prev(seqs.end());
        while (true) {
            if (**runner > *std::prev(*runner)) {
                // Battle at edge
                battleOccurred = true;

                // Move seq beg +1
                ++*runner;

                // Remove dead person
                people.erase(std::prev(*runner));

                // Remove seq beg if colliding with next seq
                if (std::next(runner) != seqs.end() &&
                    *runner == *std::next(runner)) {
                    seqs.erase(std::next(runner));

                    // BUG: EMERGENCY MERGE
                    if (**runner <= *std::prev(*runner)) {
                        runner = seqs.erase(runner);
                    }
                } else if (*runner == people.end()) {
                    runner = seqs.erase(runner);
                }
            } else {
                // No battle - combine

                runner = seqs.erase(runner);
            }

            if (runner == seqs.begin()) {
                break;
            }
            --runner;
        }

        if (!battleOccurred) {
            --day;
        }
    }

    std::cout << day << std::endl;

    return 0;
}
