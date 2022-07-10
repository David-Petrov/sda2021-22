/* Ultra minified, but still humanly readable version, specialno za Koceto da se poradva :D */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

struct Ball { size_t color = 0; size_t index = 0; };

size_t eraseAndCount(list<Ball>& balls, list<Ball>::iterator itBall)
{
    bool eraseBegin = false;
    auto itLeft = itBall, itRight = next(itBall);
    size_t count = 0;

    while (itRight != balls.end() && itRight->color == itBall->color) {
        ++count;
        ++itRight;
    }
    while (itLeft->color == itBall->color) {
        ++count;
        if (itLeft == balls.begin()) { eraseBegin = true; break; }
        --itLeft;
    }

    if (count < 3) return 0;

    balls.erase(eraseBegin ? itLeft : next(itLeft), itRight);

    return count + (eraseBegin || itRight == balls.end() || itLeft->color != next(itLeft)->color ? 0 : eraseAndCount(balls, itLeft));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n, q, color, index;
    list<Ball> balls;

    cin >> n;

    vector<list<Ball>::iterator> iterators(2 * n);

    for (size_t i = 0; i < n; i++) {
        cin >> color;
        balls.push_back(Ball{color, i});
        iterators[i] = prev(balls.end());
    }

    cin >> q;

    for (size_t i = 0; i < q; i++) {
        if (balls.empty()) { cout << "Game Over" << '\n'; continue; }
        cin >> index >> color;
        cout << eraseAndCount(balls, iterators[n + i] = balls.insert(next(iterators[index]), Ball{ color, n + i })) << '\n';
    }

    if (balls.empty())  cout << -1;
    else for (auto ball = balls.begin(); ball != balls.end(); ++ball) 
        cout << ball->color << ' ';
    
    return 0;
}