#include <string>
using namespace std;
#ifndef _STRINGSET_H
#define _STRINGSET_H
struct Node {
  string key;
  int count;
  Node *next;
  Node () : key(""), count(1), next(NULL){
  }
  Node (string k) : key(k), count(1), next(NULL) {
  }
  Node (string k, Node* n) : key(k),count(1), next(n) {
  }
  Node (string k, int c, Node* n) : key(k), count(c), next(n) {
  }
};

class Stringset {
public:
  Stringset() {
    bad_result = 0;
    size = 100;
    num_elems = 0;
    head = new Node*[size];
    memset(head, 0, size * sizeof(head));
  }
  ~Stringset() {
    for (int i = 0; i < size; i++) {
      while (head[i]) {
	Node *to_delete = head[i];
	head[i] = head[i]->next;
	delete to_delete;
      }
    }
    delete [] head;
  }
  int &operator[] (string key) {
    int h = hash(key, size);
    Node *n = head[h];
    while (n) {
      if (n->key == key) return n->count;
      n = n->next;
    }
    return bad_result;
  }
  int& get_count(string key) {
    int h = hash(key, size);
    Node *n = head[h];
    while (n) {
      if (n->key == key) return n->count;
      n = n->next;
    }
    return bad_result;
  }
  bool find(string key) {
    int h = hash(key, size);
    Node *n = head[h];
    while (n) {
      if (n->key == key) return true;
      n = n->next;
    }
    return false;
  }
  void set_count(string key, int new_val) {
  }
  void insert(string key) {
    int h = hash(key, size);
    head[h] = new Node(key, head[h]);
    if (++num_elems > 0.75 * size) { //rehash
       rehash();
    }
  }
  void rehash() {
    cout << "-----before rehash------size: " << size  << endl;
    Node **newHead = new Node*[size * 2];
    memset(newHead, 0, size * 2 * sizeof(newHead));
    //copy
    for (int i = 0; i < size; i++) {
      while (head[i]) {
	Node *to_delete = head[i];
	int h = hash(head[i]->key, size * 2);
	newHead[h] = new Node(head[i]->key, head[i]->count, newHead[h]);
	head[i] = head[i]->next;
	delete to_delete;
      }
    }
    delete [] head;
    head = newHead;
    size *= 2;
    cout << "-----after rehash------size: " << size  << endl;
  }
  void remove(string key) {
  }
  void print(void) {
  }
private:
  int hash(string s, int size) {
    unsigned int h = 0;
    for (int i = s.length() - 1; i >= 0; i--)
      h = (h * 9127877 + s[i]) % size;
    return h % size;
  }
  Node** head;
  int size;
  int num_elems;
  int bad_result;
};
#endif
