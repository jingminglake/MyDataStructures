#ifndef MYHEAP__H
#define MYHEAP__H

class MyHeap
{
public:
  MyHeap();
  ~MyHeap();
  void insert(int key);
  int remove_min();
  void heapSort(int len);
private:
  int size;
  int capacity;
  int *A;
  int parent(int i);
  int lchild(int i);
  int rchild(int i);
  void sift_up(int i);
  void sift_down(int i);
};

#endif
