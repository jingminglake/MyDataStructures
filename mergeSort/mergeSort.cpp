#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedArray(vector<int>& a, int start, int mid, int end) {
    vector<int> helper(end - start + 1, 0);
    int index = 0;
    int left = start, right = mid + 1;
    while (left <= mid && right <= end) {
        helper[index++] = a[left] < a[right] ? a[left++] : a[right++];
    }
    while (left <= mid)
        helper[index++] = a[left++];
    while (right <= end)
        helper[index++] = a[right++];
    for (int i = 0; i < helper.size(); i++) {
        a[start + i] = helper[i];
    }
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
    vector<int> a = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1}; //0 1 3 8 9 12 13 23 33 88
    mergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
