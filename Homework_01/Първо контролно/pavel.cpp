#include <cstring>
#include <functional>
#include <iostream>
#include <string>

template<typename T>
void printArray(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}

void solve(const char *input, char koceto) {
    size_t length = std::strlen(input);

    unsigned int output[length];

    // initialize output
    for (int i = 0; i < length; ++i) {
        output[i] = 0;
    }

    // count to the right
    unsigned int temp = 1;
    bool foundZero    = false;
    for (int i = 0; i < length; ++i) {
        // skip until the first zero
        if (!foundZero) {
            if (input[i] == koceto) {
                foundZero = true;
            }
            continue;
        }

        // reset temp if we encounter a zero
        if (input[i] == koceto) {
            temp = 1;
            continue;
        }

        output[i] = temp;
        ++temp;
    }

    // count to the left
    temp      = 1;
    foundZero = false;
    for (int i = length - 1; i >= 0; --i) {
        // skip until a zero
        if (!foundZero) {
            // set foundZero if we find a zero
            if (input[i] == koceto) {
                foundZero = true;
            }
            continue;
        }

        // reset temp if we encounter a zero
        if (input[i] == koceto) {
            temp = 1;
            continue;
        }

        // set to temp if a starting zero (00|0123) or less than prev (01234|10)
        output[i] = (output[i] == 0 ? temp : std::min(output[i], temp));
        ++temp;
    }

    printArray(output, length);
}

int main() {
    std::string input;
    std::cin >> input;

    char koceto;
    std::cin >> koceto;

    solve(input.c_str(), koceto);

    return 0;
}
