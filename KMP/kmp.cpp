#include <iostream>
#include <vector>
using namespace std;

void buildNext(vector<int>& next, string& s) {
  next[0] = -1;
  int m = s.length();
  int i = 0;
  int j = -1;
  while (i < m) {
    if (j == -1 || s[i] == s[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
  /*
  for (int i = 0; i < next.size(); i++)
    cout << next[i] << " ";
  cout << endl; 
  */
}

int kmp(string S, string s) {
  int n = S.length();
  int m = s.length();
  if (n == 0 || m == 0 || n < m)
    return -1;
  vector<int> next(m, 0);
  buildNext(next, s);
  
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (j == -1 || S[i] == s[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == m)
    return i - j;
  else
    return -1;
}

int main()
{
  string S = "abxabcabcaby";
  string s = "abcaby";
  cout << kmp(S, s) << endl;
  return 0;
}
