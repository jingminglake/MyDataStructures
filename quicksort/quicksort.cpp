#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& a, int start, int end) {
  if (start >= end)
    return ;
  int pivot = a[start];
  int last = start;
  for (int i = start + 1; i <= end; i++) {
    if (a[i] < pivot)
      swap(a[++last], a[i]);
  }
  swap(a[last], a[start]);
  quickSort(a, start, last - 1);
  quickSort(a, last + 1, end);
}
int main() {
  vector<int> a = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1};
  quickSort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
