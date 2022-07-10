#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    size_t n;
    cin >> n;

    unordered_map<int, int> occurrences;

    int temp;
    for (size_t i = 0; i < n; ++i) {
        cin >> temp;
        ++occurrences[temp];
    }

	//there was a problematic test which turned out to be expecting 
	//an integer sum variable to overflow... so, technically this should've 
	//been a long long, but yeah... :D 
	
    int sum = 0; //int, ama ne trqa da e int :D
    for (auto it = occurrences.begin(); it != occurrences.end(); ++it) {
        sum += it->first * (it->second % 2) * it->second;
    }

    cout << sum;


    return 0;
}
