#include <iostream>
#include <vector>

int main() {
    short rows, cols;
    std::cin >> rows >> cols;

    short duration, ill_count;
    std::cin >> duration >> ill_count;

    std::vector<std::vector<short>> seats(rows, std::vector<short>(cols, -1));

    for (short i = 0, row, col; i < ill_count; ++i) {
        std::cin >> row >> col;
        seats[row - 1][col - 1] = 0;
    }

    for (short minute = 0; minute < duration; ++minute) {
        for (short row = 0; row < rows; ++row) {
            for (short col = 0; col < cols; ++col) {
                if (seats[row][col] == minute) {
                    // Up
                    if (row > 0 && seats[row - 1][col] == -1) {
                        seats[row - 1][col] = minute + 1;
                    }

                    // Right
                    if (col < cols - 1 && seats[row][col + 1] == -1) {
                        seats[row][col + 1] = minute + 1;
                    }

                    // Down
                    if (row < rows - 1 && seats[row + 1][col] == -1) {
                        seats[row + 1][col] = minute + 1;
                    }

                    // Left
                    if (col > 0 && seats[row][col - 1] == -1) {
                        seats[row][col - 1] = minute + 1;
                    }
                }
            }
        }
    }

    int not_ill_count = 0;
    for (short row = 0; row < rows; ++row) {
        for (short col = 0; col < cols; ++col) {
            if (seats[row][col] == -1) {
                ++not_ill_count;
            }
        }
    }

    printf("%d", not_ill_count);

    return 0;
}
