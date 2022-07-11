#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_SIZE 10'000

typedef unsigned long IndexType;

template <typename T>
void swap_pointers(T *&ptr1, T *&ptr2) {
    T *temp = ptr1;
    ptr1    = ptr2;
    ptr2    = temp;
}

template <typename T>
void maxify(T &old_data, const T &new_data) {
    old_data = std::max(old_data, new_data);
}

template <typename T>
void maxify(T &old_data, const T &&new_data) {
    old_data = std::max(old_data, new_data);
}

IndexType longest_common_substring(const std::string &str1,
                                   const IndexType &length1,
                                   const std::string &str2,
                                   const IndexType &length2) {
    // Define result
    IndexType maxLength = 0;
    // Define both rows
    IndexType *last_row = new IndexType[length2 + 1] {},
              *curr_row = new IndexType[length2 + 1] {};

    // Iterate through all nodes in the dictionary
    for (IndexType row = 1; row <= length1; ++row) {
        for (IndexType col = 1; col <= length2; ++col) {
            if (str1[row] == str2[col]) {
                // Extend common prefix length (previous +1)
                curr_row[col] = last_row[col - 1] + 1;
                // Update max length if needed
                ::maxify(maxLength, curr_row[col]);
            } else {
                curr_row[col] = 0;
            }
        }

        ::swap_pointers(last_row, curr_row);
    }

    delete[] last_row;
    delete[] curr_row;

    // Return max length
    return maxLength;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Define both strings
    std::string s1, s2;

    // Input both strings
    std::cin >> s1 >> s2;

    // Start looking for longest substring
    printf("%lu", ::longest_common_substring(s1, s1.size(), s2, s2.size()));

    return 0;
}
