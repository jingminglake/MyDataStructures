#include <iostream>
#include "myHeap.h"

MyHeap::MyHeap() {
  size = 0;
  capacity = 16;
  A = new int[capacity];
}

MyHeap::~MyHeap() {
  delete [] A;
}

void MyHeap::insert(int key)
{
  A[size] = key;
  sift_up(size);
  size++;
  if (size == capacity) {
    //std::cout << "-----before------capacity: " << capacity  << std::endl;
    int* tempA = new int[capacity * 2];
    for (int i = 0; i < capacity; i++)
      tempA[i] = A[i];
    delete [] A;
    A = tempA;
    capacity *= 2;
    //std::cout << "-----after------capacity: " << capacity << std::endl;
  }
}

int MyHeap::remove_min()
{
  std::swap(A[0], A[size - 1]);
  size--;
  sift_down(0);
  return A[size];
}

int MyHeap::parent(int i)
{
  return (i - 1) / 2;
}

int MyHeap::lchild(int i)
{
  return 2 * i + 1;
}

int MyHeap::rchild(int i)
{
  return 2 * i + 2;
}

void MyHeap::sift_up(int i)
{
  /*while (i > 0 && A[i] < A[parent(i)]) {
    swap(A[i], A[parent(i)]);
    }*/
  if (i > 0 && A[i] < A[parent(i)]) {
    std::swap(A[i], A[parent(i)]);
    sift_up(parent(i));
  }
}

void MyHeap::sift_down(int i)
{
  // swap A[i] with smallest child(if smaller than A[i])
  int smallest_child = i;
  if (lchild(i) < size && A[lchild(i)] < A[i])
    smallest_child = lchild(i);
  if (rchild(i) < size && A[rchild(i)] < A[smallest_child])
    smallest_child = rchild(i);
  if (smallest_child != i) {
    std::swap(A[i], A[smallest_child]);
    sift_down (smallest_child);
  }
} 
