#include <iostream>

template<typename T>
class Stack {
    const int32_t SIZE;
    int16_t cursor;
    T *st;
public:

    Stack() : cursor(-1), SIZE(1000) {
        st = new T[SIZE];
    }

    ~Stack() {
        delete[] st;
    }

    bool push(T data) {
        if (cursor < SIZE) {
            st[++cursor] = data;
            return true;
        } else {
            std::cout << "Stack overflow";
            return false;
        }
    }

    T pop() {
        if (cursor != -1) {
            return st[cursor--];
        } else {
            std::cout << "Stack is empty";
            return -1;
        }
    }

    int16_t getCursor() {
        return cursor;
    }
};