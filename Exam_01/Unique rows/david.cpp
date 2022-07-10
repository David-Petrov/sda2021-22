#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    set<vector<int>> rows;
    set<vector<int>> repeated;

    int counter = 0;

    for (auto& row : matrix) {

        if (rows.insert(row).second) {
            counter++;
            
        }
        else {
            if (repeated.insert(row).second) {
                counter--;
            }
        }
    }

    cout << counter;

    return 0;
}
