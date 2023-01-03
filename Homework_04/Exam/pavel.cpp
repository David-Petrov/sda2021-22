#include <iostream>
#include <string>

template<typename T>
class DoublyLinkedList {
    public:
    struct Node {
        Node *prev;
        T data;
        Node *next;

        Node(Node *prev, T data, Node *next)
            : prev(prev), data(data), next(next) {}
    };

    private:
    Node *head, *tail, *mid;
    size_t length;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    DoublyLinkedList(std::initializer_list<T> list) : length(0) {
        for (const T &element : list) {
            this->push_back(element);
        }
    }

    ~DoublyLinkedList() {
        if (!length) {
            return;
        }

        Node *runner = this->head, *temp;
        while (runner->next) {
            temp   = runner;
            runner = runner->next;
            this->free_node(temp);
        }
    }

    Node *getHead() { return this->head; }

    Node *getTail() { return this->tail; }

    size_t getLength() { return this->length; }

    void push_back(T data) {
        if (!this->tail) {
            this->mid = this->head = this->tail =
                new Node(nullptr, data, nullptr);
        } else {
            this->tail->next = new Node(this->tail, data, nullptr);
            this->tail       = this->tail->next;

            if (this->length >= 2) {
                if (this->length % 2 == 1) {
                    this->mid = this->mid->next;
                }
            } else {
                this->mid = this->head;
            }
        }
        ++this->length;
    }

    void pop_back() {
        if (length == 0) {
            return;
        }

        if (length == 1) {
            this->free_node(this->head);
            this->mid = this->head = this->tail = nullptr;
            this->length                        = 0;

            return;
        }

        this->tail = this->tail->prev;
        this->free_node(this->tail->next);
        this->tail->next = nullptr;

        if (this->length >= 2) {
            if (this->length % 2 == 0) {
                this->mid = this->mid->prev;
            }
        } else {
            this->mid = this->head;
        }

        --length;
    }

    void slash() {
        if (this->length < 2) {
            return;
        }

        // remember old tail (for new mid)
        Node *temp = this->tail;
        // connect old head and tail
        this->head->prev = this->tail;
        this->tail->next = this->head;
        // set new head and tail
        this->head = this->mid->next;
        this->tail = this->mid;
        // disconnet new head and tail
        this->head->prev = nullptr;
        this->tail->next = nullptr;
        // set new mid
        this->mid = (this->length % 2 ? temp->prev : temp );
    }

    static void print_list(DoublyLinkedList &list) {
        std::cout << list.getLength() << std::endl;
        for (auto runner = list.getHead(); runner; runner = runner->next) {
            std::cout << runner->data << ' ';
        }
        std::cout << std::endl;
    }

    private:
    static void free_node(Node *node) { delete node; }
};

int main() {

    size_t n;
    std::cin >> n;

    DoublyLinkedList<int> pistols;

    std::string command;
    for (size_t i = 0, operand; i < n; i++) {
        std::cin >> command;
        if (command == "add") {
            // add
            std::cin >> operand;
            pistols.push_back(operand);
        } else if (command == "gun") {
            // gun
            pistols.pop_back();
        } else if (command == "milen") {
            // milen
            pistols.slash();
        }
    }

    DoublyLinkedList<int>::print_list(pistols);

    return 0;
}
