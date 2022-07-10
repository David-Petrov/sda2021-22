#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList
{
    struct Node { T data; Node* previous = nullptr; Node* next = nullptr; } * head, * tail, * mid;
    size_t size;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), mid(nullptr), size(0) {}
    ~DoublyLinkedList() {
        if (size == 0) return;
        Node* temp;
        for (Node* node = head->next; node != nullptr;) {
            temp = node->next;
            delete node;
            node = temp;
        }
    }

    void push_back(T data) {
        tail = (tail == nullptr ? head : tail->next) = new Node{ data, tail };
        mid = (++size == 2 ? head : size % 2 == 0 ? mid->next : mid);
    }

    void pop_back() {
        if (tail == head) {
            delete tail;
            tail = head = nullptr;
        } else {
            Node* secondToLast = tail->previous;
            delete tail;
            (tail = secondToLast)->next = nullptr;
        }
        if (--size % 2 && mid != nullptr) mid = mid->previous;
    }

    const Node* getMid() const { return mid; }

    void switchMid() {
        if (mid == nullptr) return;
        (tail->next = head)->previous = tail;
        mid->next = (head = mid->next)->previous = nullptr;
        swap(mid, tail);
        if (size % 2) mid = mid->previous;
    }

    void print(ostream& os) const {
        os << size << '\n';
        for (Node* node = head; node != nullptr; node = node->next) os << node->data << ' ';
        os << '\n';
    }
};

int main()
{
    DoublyLinkedList<size_t> guns;
    string command;
    size_t n, gun;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> command;
        if (command == "add") { cin >> gun; guns.push_back(gun); }
        else if (command == "gun") guns.pop_back();
        else guns.switchMid();
    } guns.print(cout);
    return 0;
}