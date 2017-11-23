#include <iostream>
#include "stringSet.h"
using namespace std;

/*int hash(string s) {
  unsigned int h = 0;
  for (char &c : s)
    h = h * 7 + c;
  return h % 1000;
}

int hashArray(string s) {
  unsigned int h = 0;
  for (int i = s.length() - 1; i >= 0; i--)
    h = (h * 7 + s[i]) % 1000;
  return h % 1000;
  }*/

int main() {
  Stringset words;
  string s, highest_str = "";
  int highest = 0;
  while (cin >> s) {
    if (s.length() == 4) {
      if (!words.find(s))
	words.insert(s);
      else
	words.get_count(s)++;
      if (words.get_count(s) > highest) {
	highest = words.get_count(s);
	highest_str = s;
      }
    }
  }
  cout << highest_str << " " << highest << "\n";
  return 0;
}
