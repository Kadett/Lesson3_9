#include <iostream>
#include "Queue.cpp"
#include "Stack.cpp"

using namespace std;

void decToBinPrint(int num ) {
    Stack<int> st;
    while (num != 0) {
        st.push(num % 2);
        num /= 2;
    }
    while (st.getCursor() != -1) {
        cout << st.pop() << ' ';
    }
}


int main() {

    //Task 1
    Queue<int> q;
    q.push(4, 4);
    q.push(11, 1);
    q.push(3, 3);
    q.push(2, 2);
    q.push(111, 1);
    q.push(33, 3);
    q.push(1, 1);
    while (q.getSize())
        cout << q.pop() << endl;

    //Task 2
    cout << endl << endl;
    decToBinPrint(65);

}