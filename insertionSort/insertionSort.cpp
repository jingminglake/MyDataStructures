#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int start, int end) {
    if (start >= end)
        return;
    for (int i = start + 1; i <= end; i++) {
        int num = a[i];
        int j = i - 1;
        while (j >= start && a[j] > num) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = num;
    }
}

int main() {
    vector<int> a = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1};
    insertionSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
