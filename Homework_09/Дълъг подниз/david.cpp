#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct RollingHash {
    static const int mod = 1000000123;
    static vector<int> powers1;
    static vector<ull> powers2;
    static int base;

    static int diff(int a, int b) {
        return (a -= b) < 0 ? a + mod : a;
    }

    vector<int> prefixes1;
    vector<ull> prefixes2; 

    RollingHash(const string& s) : prefixes1(s.size() + 1), prefixes2(s.size() + 1) {
        const int n = s.size();

        while ((int)powers1.size() <= n) {
            powers1.push_back((ll)powers1.back() * base % mod);
            powers2.push_back(powers2.back() * base);
        }

        for (int i = 0; i < n; ++i) {
            prefixes1[i + 1] = (prefixes1[i] + 1LL * s[i] * powers1[i]) % mod;
            prefixes2[i + 1] = prefixes2[i] + s[i] * powers2[i];
        }
    }

    pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = prefixes1[pos + len] - prefixes1[pos];
        ull hash2 = prefixes2[pos + len] - prefixes2[pos];

        if (hash1 < 0) hash1 += mod;

        if (mxPow) {
            hash1 = (ll)hash1 * powers1[mxPow - (pos + len - 1)] % mod;
            hash2 *= powers2[mxPow - (pos + len - 1)];
        }

        return { hash1, hash2 };
    }
};

int RollingHash::base(1000000007);
vector<int> RollingHash::powers1{1};
vector<ull> RollingHash::powers2{1};

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size(), low = 0, high = min(n, m) + 1, mid, i, mxPow = max(n, m);
    RollingHash hash_a(s1), hash_b(s2);

    multiset<pair<int, ull>> hashes;
    while (high - low > 1) {
        mid = (low + high) / 2;

        hashes.clear();
        for (i = 0; i <= n - mid; ++i) {
            hashes.insert(hash_a(i, mid, mxPow));
        }

        for (i = 0; i <= m - mid; ++i) {
            if(hashes.find(hash_b(i, mid, mxPow)) != hashes.end()) {
                break;
            }
        }

        (i <= m - mid ? low : high) = mid;
    }

    cout << low;

    return 0;
}