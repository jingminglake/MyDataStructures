#include <iostream>
using namespace std;

class Queue {
public:
    Queue() {
        len = 10;
        arr = new int[len];
        front = 0;
        rear = 0;
    }
    ~Queue() {
        delete [] arr;
    }
    int getFront() {
        if (!isEmpty())
            return arr[rear];
        return -1;
    }
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return (front + 1) % len == rear;
    }
    void push(int n) {
        if (isFull()) {
            cout << "is Full!" << endl;
            return;
        }
        arr[front] = n;
        front = (front + 1) % len;
    }
    int popFront() {
        if (!isEmpty()) {
            int n = arr[rear];
            rear = (rear + 1) % len;
            return n;
        }
        return -1;
    }
private:
    int len;
    int *arr;
    int front;
    int rear;
};

/*int foo(int& i) {
    return i--;
}*/

int main() {
    Queue q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    while (!q.isEmpty()) {
        cout << q.popFront() << " ";
    }
    cout << endl;

    /*   int i = 100;
    cout << foo(i) << endl;
    cout << i << endl;*/
    return 0;
}
