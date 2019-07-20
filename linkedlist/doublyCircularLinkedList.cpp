#include <iostream>
using namespace std;

class Node {
public:
    Node(int _val) : prev(this), next(this), val(_val) {
    }
    Node(Node *_prev, Node* _next, int _val) : prev(_prev), next(_next), val(_val) {
    }
    Node* prev, *next;
    int val;
};

Node* insert(Node* head, int val) {
    if (!head) {
        Node* n = new Node(val);
        return n;
    }
    if (val < head->val) {
        Node *n = new Node(val);
        Node *cur = head->prev;
        cur->next = n;
        n->prev = cur;
        n->next = head;
        head->prev = n;
        return n;
    } else {
        Node *n = new Node(val);
        Node *cur = head;
        while (cur->next != head && cur->next->val < val)
            cur = cur->next;
        n->prev = cur;
        cur->next->prev = n;
        n->next = cur->next;
        cur->next = n;
        return head;
    }
}

Node* remove(Node* head, int val) {
    if (!head)
        return head;
    if (head->val == val) {
        Node *cur = head->next;
        if (cur == head) {
            delete cur;
            return nullptr;
        }
        head->prev->next = cur;
        cur->prev = head->prev;
        delete head;
        return cur;
    } else {
        Node *cur = head;
        while (cur->next != head && cur->next->val != val)
            cur = cur->next;
        if (cur->next == head)
            return head;
        cur = cur->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        return head;
    }
}

void traverse(Node* head) {
    Node *cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
        if (cur == head)
            break;
    }
    cout << endl;
    cur = head;
    Node *temp = nullptr;
    while (cur) {
        cout << cur->val << " ";
        temp = cur;
        cur = cur->prev;
        delete temp;
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
