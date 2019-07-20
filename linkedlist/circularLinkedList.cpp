#include <iostream>
using namespace std;

class Node {
public:
    Node(int _val) : next(nullptr), val(_val) {
    }
    Node(Node* _next, int _val) : next(_next), val(_val) {
    }
    Node* next;
    int val;
};

Node* insert(Node* head, int val) {
    if (!head) {
        head =  new Node(val);
        head->next = head;
        return head;
    }
    Node *cur = head;
    if (head->val > val) {
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = new Node(val);
        cur->next->next = head;
        return cur->next;
    } else {
        while (cur->next != head && cur->next->val < val) {
            cur = cur->next;
        }
        Node * h = new Node(val);
        h->next = cur->next;
        cur->next = h;
        return head;
    }
}

Node* remove(Node* head, int val) {
    if (!head)
        return head;
    Node *cur = head;
    if (head->val == val) {
        while (cur->next != head)
            cur = cur->next;
        cur->next = head->next;
        delete head;
        return cur->next;
    } else {
        while (cur->next != head && cur->next->val != val)
            cur = cur->next;
        if (cur->next != head) {
            Node *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        return head;
    }
}

void traverse(Node* head) {
    Node *cur = head;
    Node *prev = nullptr;
    while (cur) {
        cout << cur->val << " ";
        prev = cur;
        cur = cur->next;
        delete prev;
        if (cur == head)
            break;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 3);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 5);
    head = insert(head, 4);
    head = remove(head, 2);
    head = remove(head, 1);
    traverse(head);
    return 0;
}
