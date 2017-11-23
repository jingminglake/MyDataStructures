// clang++ split.cpp -std=c++11
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string &str, char delim) {
  istringstream iss(str);
  vector<string> tokens;
  string token;
  while (getline(iss, token, delim)) {
    tokens.push_back(move(token));
  }
  return tokens;
}

vector<string> splitBystr(const string &str, const string& delim) {
  vector<string> tokens;
  string token;
  int index = 0, preIndex = 0;
  while ((index = str.find(delim, preIndex)) != string::npos) {
    tokens.push_back(str.substr(preIndex, index - preIndex));
    preIndex = index + delim.length();
  }
  if (preIndex != 0) { // exist at least one delim
    tokens.push_back(str.substr(preIndex, str.length() - preIndex));
  }
  return tokens;
}

int main() {
  string str = "1,2,3,4,5,6,7,8,9";
  string str2 = "1::2::3::4::5::6::7::8::9::10";
  vector<string> vec = split(str, ',');
  for (string &s : vec)
    cout << s << " ";
  cout << endl;
  vector<string> vec2 = splitBystr(str2, "::");
  for (string &s : vec2)
    cout << s << " ";
  cout << endl;
  return 0;
}
