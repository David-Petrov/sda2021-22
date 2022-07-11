#include <iostream>

template<typename T>
void merge(T *arr, int l, int m, int r) {
    int sizeL = m - l + 1;
    int sizeR = r - m;

    int *arrL = new int[sizeL];
    int *arrR = new int[sizeR];

    for (int i = 0; i < sizeL; ++i) {
        arrL[i] = arr[l + i];
    }
    for (int i = 0; i < sizeR; ++i) {
        arrR[i] = arr[m + i + 1];
    }

    int srcL = 0, srcR = 0, dest = 0;
    while (srcL < sizeL && srcR < sizeR) {
        if (arrL[srcL] <= arrR[srcR]) {
            arr[l + dest] = arrL[srcL];
            ++srcL;
        } else {
            arr[l + dest] = arrR[srcR];
            ++srcR;
        }
        ++dest;
    }

    while (srcL < sizeL) {
        arr[l + dest] = arrL[srcL];
        ++srcL;
        ++dest;
    }
    while (srcR < sizeR) {
        arr[l + dest] = arrR[srcR];
        ++srcR;
        ++dest;
    }

    delete[] arrL;
    delete[] arrR;
}

template<typename T>
void merge_sort(T *arr, size_t l, size_t r) {
    if (l < r) {
        long m = (l + r) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

template<typename T>
size_t binary_search(T *arr, size_t size, T x) {
    long l = 0, r = size - 1, m;
    while (l <= r) {
        m = r - ((r - l) >> 1);
        if (arr[m] == x) {
            return m;
        }

        if (arr[m] < x) {
            l = m + 1;
            continue;
        }

        if (arr[m] > x) {
            r = m - 1;
            continue;
        }
    }

    // Edge case - not found
    return l;
}

unsigned int absDiff(size_t a, size_t b) {
    int diff = (int) a - (int) b;
    return (diff < 0 ? -diff : diff);
}

void solve(size_t *projects,
           size_t projectCount,
           size_t *teams,
           size_t teamCount) {
    merge_sort(projects, 0, projectCount - 1);

    for (size_t i = 0, index; i < teamCount; ++i) {
        index = binary_search(projects, projectCount, teams[i]);
        if (projects[index] == teams[i]) {
            // nice
        } else if (index == 0) {
            // No smaller element - index 0 is the closest
        } else if (index == projectCount) {
            // No bigger element - index size-1 is the closest
            --index;
        } else {
            // Not at edge and no exact element - we choose the close of the two
            // neighbours
            index = (absDiff(projects[index - 1], teams[i]) <=
                         absDiff(projects[index], teams[i])
                         ? index - 1
                         : index);
        }
        std::cout << projects[index] << std::endl;
    }
}

int main() {
    size_t *projects, projectCount, *teams, teamCount;

    std::cin >> projectCount >> teamCount;

    projects = new size_t[projectCount];
    for (size_t i = 0; i < projectCount; ++i) {
        std::cin >> projects[i];
    }

    teams = new size_t[teamCount];
    for (size_t i = 0; i < teamCount; ++i) {
        std::cin >> teams[i];
    }

    solve(projects, projectCount, teams, teamCount);

    delete[] projects;
    delete[] teams;

    /* projectCount = 5;
    projects     = new size_t[projectCount] {2, 4, 6, 8, 10};

    teamCount    = 7;
    teams        = new size_t[teamCount] {1, 10, 5, 3, 17, 7, 9};

    solve(projects, projectCount, teams, teamCount); */

    /* projectCount = 9;
    projects     = new size_t[projectCount] {1, 2, 3, 4, 5, 7, 8, 9, 11};
    teamCount    = 6;
    teams        = new size_t[teamCount] {0, 1, 6, 7, 11, 12};

    solve(projects, projectCount, teams, teamCount);

    delete[] projects;
    delete[] teams; */

    /* int *arr = new int[9] {1, 2, 3, 4, 5, 7, 8, 9, 11};

    std::cout << "\n0  " << binary_search(arr, 9, 0);
    std::cout << "\n1  " << binary_search(arr, 9, 1);
    std::cout << "\n6  " << binary_search(arr, 9, 6);
    std::cout << "\n7  " << binary_search(arr, 9, 7);
    std::cout << "\n11 " << binary_search(arr, 9, 11);
    std::cout << "\n12 " << binary_search(arr, 9, 12);

    delete[] arr; */

    return 0;
}
