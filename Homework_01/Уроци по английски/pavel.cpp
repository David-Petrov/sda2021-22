#include <cstring>
#include <iostream>
#include <string>

size_t solve(const char *word, size_t count, char ch) {
    size_t wordLength       = std::strlen(word);
    size_t occurancesInWord = 0;

    for (size_t i = 0; i < wordLength; ++i) {
        if (word[i] == ch) {
            ++occurancesInWord;
        }
    }

    size_t occuranceCount = occurancesInWord * (count / wordLength);

    for (size_t i = 0; i < count % wordLength; ++i) {
        if (word[i] == ch) {
            ++occuranceCount;
        }
    }

    return occuranceCount;
}

int main() {
    std::string word;
    std::cin >> word;

    size_t count;
    std::cin >> count;

    char ch;
    std::cin >> ch;

    std::cout << solve(word.c_str(), count, ch) << std::endl;

    return 0;
}
