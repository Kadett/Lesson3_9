
#include <iostream>

template<typename T>
class Queue {

private:
    struct Node {
        int pr;
        T data;
        Node *next;


        Node(T data = T(), int pr = 100, Node *n = nullptr) : data(data), pr(pr), next(n) {}
    };

    Node *head;
    int size;

public:
    Queue() : head(nullptr), size(0) {}

    void push(T data, int pr) {
        head = new Node(data, pr, head);
        size++;
    }

    T pop() {
        if (size <= 0) {
            std::cout << "Queue is empty";
            return -1;
        }
        T res;
        if (size == 1) {
            Node *tmp = head;
            head = head->next;
            res = tmp->data;
            delete tmp;
            size--;

        } else {

            Node *tmp = head, *result = head, *preResult = nullptr;

            for (int i = 0; i < size-1; ++i) {
                Node *t = tmp;
                tmp = tmp->next;
                if(result->pr >= tmp->pr) {
                    preResult = t;
                    result = tmp;
                }
            }
            res = result->data;
            if(preResult == nullptr) head = result->next;
            else preResult->next = result->next;
            size--;
            delete result;

        }
        return res;
    }

    int getSize(){
        return size;
    }

};



