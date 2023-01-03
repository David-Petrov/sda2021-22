#include <algorithm>
#include <iostream>

template<typename T>
long binary_search(T *arr,
                   long l,
                   long r,
                   T key,
                   int (*predicate)(T *arr, long l, long r, int index, T key)) {
    long m;
    while (l <= r) {
        m = r - ((r - l) >> 1);

        switch (predicate(arr, l, r, m, key)) {
            case -1:
                l = m + 1;
                continue;
            case 0:
                return m;
            case 1:
                r = m - 1;
                continue;
        }
    }

    // Edge case - not found
    return l;
}

void solve(int *A, int N, long long *S, int *P, int Q) {
    std::sort(A, A + N);

    long long *acc = new long long[N] {A[0]};

    for (int i = 1; i < N; i++) {
        acc[i] = acc[i - 1] + A[i];
    }

    long rightIndex;
    long long *leftIndex;
    for (long queryIndex = 0; queryIndex < Q; ++queryIndex) {
        rightIndex = binary_search<int>(
            A, 0, N - 1, P[queryIndex],
            [](int *arr, long l, long r, int index, int key) {
                // Too right
                if (arr[index] > key) {
                    return 1;
                }

                // Just right :D
                if (arr[index] <= key && (index == r || arr[index + 1] > key)) {
                    return 0;
                }

                // Too left
                return -1;
            });

        if (acc[rightIndex] <= S[queryIndex]) {
            printf("%ld\n", rightIndex + 1);
            continue;
        }

        if (A[rightIndex] > S[queryIndex]) {
            printf("%d\n", 0);
            continue;
        }

        leftIndex = std::upper_bound(acc, acc + rightIndex,
                                     acc[rightIndex] - S[queryIndex]);

        if (*(leftIndex - 1) == acc[rightIndex] - S[queryIndex]) {
            --leftIndex;
        }

        if (leftIndex == acc + rightIndex) {
            printf("%d\n", N);
            continue;
        }

        printf("%ld\n", rightIndex - (leftIndex - acc));
    }

    delete[] acc;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    int *A = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    long long *S = new long long[Q];
    int *P = new int[Q];

    for (int i = 0; i < Q; ++i) {
        std::cin >> S[i] >> P[i];
    }

    solve(A, N, S, P, Q);

    delete[] A;
    delete[] S;
    delete[] P;

    return 0;
}
