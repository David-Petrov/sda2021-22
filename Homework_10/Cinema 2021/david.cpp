#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <initializer_list>
using namespace std;

struct Student { 
    int row, col; 

    bool operator==(const Student& other) const {
        return other.row == row && other.col == col;
    }
};

bool validate(const Student student, vector<vector<bool>>& students) {
    return 0 <= student.row && student.row < (int)students.size() && 0 <= student.col && student.col < (int)students[0].size();
}

int main() {
    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<vector<bool>> students(n, vector<bool>(m, false));

    Student sicko;
    deque<Student> sickos;

    size_t sickened = 0;

    while (k--) {
        cin >> sicko.row >> sicko.col;
        --sicko.row;
        --sicko.col;
        sickos.push_back(sicko);
        students[sicko.row][sicko.col] = true;
        ++sickened;
    }

    Student lastSicko;

    while (t--) {
        lastSicko = sickos.back();
        
        while (!sickos.empty()) {
            sicko = sickos.front();

            for (const Student& st : {
                Student{sicko.row - 1, sicko.col},
                Student{sicko.row + 1, sicko.col},
                Student{sicko.row, sicko.col - 1},
                Student{sicko.row, sicko.col + 1}
            }) {
                if (validate(st, students) && !students[st.row][st.col]) {
                    sickos.push_back(st);
                    students[st.row][st.col] = true;
                    sickened++;
                }
            }

            sickos.pop_front();

            if (sicko == lastSicko) {
                break;
            }
        }
    }

    cout << n * m - sickened;

    return 0;
}