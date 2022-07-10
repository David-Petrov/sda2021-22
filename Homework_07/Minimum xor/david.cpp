#include <iostream>
#include <cstdio>
#include <climits>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, temp, minXOR = SIZE_MAX;
    cin >> n;

    set<size_t> numbers = { 0 };
    set<size_t>::iterator it;

    while (n-- > 0) {
        cin >> temp;
        it = numbers.insert(temp).first;
        minXOR = min(min(it != numbers.begin() ? *prev(it) ^ temp : minXOR, next(it) != numbers.end() ? *next(it) ^ temp : minXOR), minXOR);
        cout << minXOR << '\n';
    }
    
    return 0;
}