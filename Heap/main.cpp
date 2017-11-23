#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "myHeap.h"
using namespace std;

void heapSort(vector<int>& vec)
{
  MyHeap hp;
  for (int i = 0; i < vec.size(); i++)
    hp.insert(vec[i]);
  for (int i = 0; i < vec.size(); i++)
    vec[i] =  hp.remove_min();
}

int main()
{
  vector<int> vec;
  for (int i = 0; i < 10000; i++)
    vec.push_back(rand() % 10000);
  heapSort(vec);
  for (int i : vec)
    cout << i << "\n";
  return 0;
}
