#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedArray(vector<int>& a, int start, int mid, int end) {
  int n1 = mid - start + 1;
  int n2 = end - mid;
  vector<int> tempL(n1, 0);
  vector<int> tempR(n2, 0);
  for (int i = 0; i < n1; i++)
    tempL[i] = a[start + i];
  for (int i = 0; i < n2; i++)
    tempR[i] = a[mid + 1 + i];
  int index = start, i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (tempL[i] < tempR[j])
      a[index++] = tempL[i++];
    else
      a[index++] = tempR[j++];
  }
  while (i < n1)
    a[index++] = tempL[i++];
  while (j < n2)
    a[index++] = tempR[j++];
}

void mergeSort(vector<int>& a, int start, int end) {
  if (start >= end)
    return ;
  int mid = start + (end - start) / 2;
  mergeSort(a, start, mid);
  mergeSort(a, mid + 1, end);
  mergeTwoSortedArray(a, start, mid, end);
}

int main() {
  vector<int> a = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1};
  mergeSort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
