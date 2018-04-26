#include <iostream>
#include <vector>
using namespace std;

vector<size_t> findAll(string str, string sub) {
    vector<size_t> positions;
    size_t pos = str.find(sub, 0);
    while (pos != string::npos) {
        positions.push_back(pos);
        pos = str.find(sub, pos + 1);
    }
    return positions;
}

int main() {
    string str = "abcaaaabcdacbabcaaa";
    string sub = "aa";
    for (size_t pos : findAll(str, sub))
        cout << pos << " ";
    cout << endl;
    return 0;
}
