#include <iostream>
#include <stack>
using namespace std;

struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

public:
    Node* head, * tail;
    int size;
};

void solve(LinkedList& num1, LinkedList& num2) {
    int sum = 0;
    Node* curr1 = num1.head, *curr2 = num2.head;
    stack<int> result;

    while (curr1 != nullptr && curr2 != nullptr) {
        sum = curr1->data + curr2->data + sum / 10;
        result.push(sum % 10);

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    for(; curr1 != nullptr; curr1 = curr1->next) {
        sum = curr1->data + sum / 10;
        result.push(sum % 10);
    }

    for (; curr2 != nullptr; curr2 = curr2->next) {
        sum = curr2->data + sum / 10;
        result.push(sum % 10);
    }

    if (sum / 10 != 0) {
        result.push(sum / 10);
    }

    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}