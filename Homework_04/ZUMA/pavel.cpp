#include <iostream>
#include <list>

struct Ball;

typedef unsigned int ui;
typedef std::list<Ball> BallList;
typedef BallList::iterator BallIter;
typedef std::pair<BallIter, int> BallIterCount;

struct Ball {
    static size_t BALL_INDEX;
    size_t index;
    ui colour;

    Ball(ui colour) : index(this->BALL_INDEX++), colour(colour) {}
};
size_t Ball::BALL_INDEX = 0;

enum Direction {
    LEFT,
    RIGHT,
};

void printBalls(BallList balls) {
    for (Ball ball : balls) {
        std::cout << ball.colour << ' ';
    }
    std::cout << std::endl;
}

BallIterCount countSame(BallList &balls, BallIter src, Direction direction) {
    BallIterCount res = std::make_pair(src, 0);

    BallIter runner = src;

    switch (direction) {
        case Direction::LEFT: {
            bool flag = false;
            while (runner->colour == src->colour) {
                ++res.second;
                if (runner == balls.begin()) {
                    flag = true;
                    break;
                }
                --runner;
            }
            if (!flag) {
                ++runner;
            }
            break;
        }
        case Direction::RIGHT: {
            while (runner->colour == src->colour) {
                ++res.second;
                ++runner;
                if (runner == balls.end()) {
                    break;
                }
            }
            break;
        }
    }

    res.first = runner;

    return res;
}

int main() {
    ui ballCount;
    std::cin >> ballCount;

    BallIter indices[2 * ballCount];

    std::list<Ball> balls;
    ui tempColour;
    for (ui i = 0; i < ballCount; ++i) {
        std::cin >> tempColour;
        balls.emplace_back(tempColour);
        indices[i] = std::prev(balls.end());
    }

    ui queryCount;
    std::cin >> queryCount;

    size_t queryPosition;
    ui queryColour;

    BallIter temp;
    BallIterCount left, right;
    size_t destroyedBallsCount, tempCount;
    for (ui queryIndex = 0; queryIndex < queryCount; ++queryIndex) {

        std::cin >> queryPosition >> queryColour;

        if (balls.empty()) {
            std::cout << "Game Over" << std::endl;
            continue;
        }

        temp = std::next(indices[queryPosition]);

        // NOTE: Insert new ball
        temp                 = balls.emplace(temp, queryColour);
        indices[temp->index] = temp;

        // NOTE: Do boom
        destroyedBallsCount = 0;
        do {
            left  = countSame(balls, temp, Direction::LEFT);
            right = countSame(balls, temp, Direction::RIGHT);

            tempCount = left.second + right.second - 1;

            if (tempCount < 3) {
                break;
            }

            temp = balls.erase(left.first, right.first);
            destroyedBallsCount += tempCount;

            if (temp->colour != std::prev(temp)->colour) {
                break;
            }
            if (balls.size() < 3) {
                break;
            }
        } while (true);

        std::cout << destroyedBallsCount << std::endl;
    }

    if (balls.empty()) {
        std::cout << -1 << std::endl;
    } else {
        printBalls(balls);
    }

    return 0;
}
