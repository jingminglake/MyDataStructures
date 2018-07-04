#include <iostream>
using namespace std;

class Stack {
public:
    Stack() : len(10), top(0) {
        arr = new int[len];
    }
    bool isFull() {
        return top == len - 1;
    }
    bool isEmpty() {
        return top == 0;
    }
    void push(int i) {
        if (!isFull())
            arr[top++] = i;
    }
    int pop() {
        return arr[--top];
    }
private:
    int len;
    int top;
    int* arr;
};

int main() {
    Stack s;
    for (int i = 0; i < 10; i++)
        s.push(i);
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}
