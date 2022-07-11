#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

struct Coordinates {
    int row;
    int col;

    Coordinates() : row(), col() {}
    Coordinates(int row, int col) : row(row), col(col) {}

    bool operator<(const Coordinates &coordinates) const {
        return (this->row == coordinates.row ? this->col < coordinates.col
                                             : this->row < coordinates.row);
    }
};

struct Room {
    Coordinates coordinates;
    char value;

    Room() : coordinates(), value() {}
    Room(int row, int col, char value) : coordinates(row, col), value(value) {}

    const Coordinates *operator->() const { return &this->coordinates; }

    bool operator<(const Room &room) const {
        return this->coordinates < room.coordinates;
    }
};

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<Room> dungeon(rows * cols);

    std::function<char(Coordinates)> at = [&](Coordinates coordinates) {
        return dungeon[coordinates.row * cols + coordinates.col].value;
    };
    std::function<bool(char)> traversable = [&](char ch) {
        return ch != 'x';
    };
    std::function<bool(Coordinates)> traversable_at =
        [&](Coordinates coordinates) {
            return traversable(at(coordinates));
        };

    int totalRooms = 1;

    char ch;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cin >> ch;
            dungeon[row * cols + col] = Room(row, col, ch);

            if (ch == '-') {
                ++totalRooms;
            }
        }
    }

    std::map<Coordinates, std::vector<Coordinates>> adjacency_list;
    std::set<Coordinates> visited;
    int visitedRooms = 0;
    int finishes     = 0;

    std::function<void(Coordinates)> dfs = [&](Coordinates coordinates) {
        if (at(coordinates) == 'e') {
            if (visitedRooms == totalRooms) {
                ++finishes;
                return;
            }
        }

        ++visitedRooms;
        visited.insert(coordinates);

        for (auto runner : adjacency_list[coordinates]) {
            if (visited.find(runner) == visited.end()) {
                dfs(runner);
            }
        }

        visited.erase(coordinates);
        --visitedRooms;
    };

    Coordinates start;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (row > 0 && traversable_at({row - 1, col})) {
                adjacency_list[{row, col}].push_back({row - 1, col});
            }
            if (row < rows - 1 && traversable_at({row + 1, col})) {
                adjacency_list[{row, col}].push_back({row + 1, col});
            }
            if (col > 0 && traversable_at({row, col - 1})) {
                adjacency_list[{row, col}].push_back({row, col - 1});
            }
            if (col < cols - 1 && traversable_at({row, col + 1})) {
                adjacency_list[{row, col}].push_back({row, col + 1});
            }

            if (at({row, col}) == 's') {
                start = {row, col};
            }
        }
    }

    dfs(start);

    printf("%d", finishes);
}
