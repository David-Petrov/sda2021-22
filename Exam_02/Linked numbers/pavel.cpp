/**
* NOTE: 90.91/100 - 1 WA
*/

#include <iostream>
#include <iterator>
#include <list>
#include <stack>

typedef unsigned char u8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    u8 carry = 0;

    std::list<u8> num1, num2;

    short digit;

    int len1;
    std::cin >> len1;
    for (int i = 0; i < len1; i++) {
        std::cin >> digit;

        num1.push_back(digit);
    }

    int len2;
    std::cin >> len2;
    for (int i = 0; i < len2; i++) {
        std::cin >> digit;

        num2.push_back(digit);
    }

    std::list<u8> sum;

    auto num1_runner = num1.begin();
    auto num2_runner = num2.begin();

    short digit1, digit2;
    for (int i = 0; i < len1 || i < len2; ++i) {
        if (i < len1) {
            digit1 = *num1_runner;
            ++num1_runner;
        } else {
            digit1 = 0;
        }

        if (i < len2) {
            digit2 = *num2_runner;
            ++num2_runner;
        } else {
            digit2 = 0;
        }

        sum.push_front((digit1 + digit2 + carry) % 10);
        carry = (digit1 + digit2 + carry) / 10;
    }

    if (!len1 && !len2) {
        printf("0");
    }

    for (auto runner = sum.begin(); runner != sum.end(); ++runner) {
        if (runner == std::prev(sum.end()) && *runner == 0) {
            continue;
        }
        printf("%c", *runner + '0');
    }

    return 0;
}
