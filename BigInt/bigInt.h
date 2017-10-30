#include <iostream>
using namespace std;

class BigInt{
public:
  BigInt(){}
  BigInt(const char *c): bigInt(c) {
  }
  BigInt(const char c): bigInt(string(1, c)) {
  }
  BigInt(const string& s) : bigInt(s){
  }
  BigInt(const BigInt& b) : bigInt(b.bigInt){
  }
  BigInt& operator=(const BigInt& rhs);
  BigInt& operator+=(const BigInt& rhs);
  BigInt& operator-=(const BigInt& rhs);
  BigInt& operator*=(const BigInt& rhs);
  BigInt& operator/=(const BigInt& rhs);
  bool operator==(const BigInt& rhs);
  bool operator<=(const BigInt& rhs);
  bool operator<(const BigInt& rhs);
  bool operator>=(const BigInt& rhs);
  bool operator>(const BigInt& rhs);
  BigInt operator+(const BigInt& rhs);
  BigInt operator-(const BigInt& rhs);
  BigInt operator*(const BigInt& rhs);
  BigInt operator%(const BigInt& rhs);
  BigInt operator/(const BigInt& rhs);
  friend ostream& operator<<(ostream& out, const BigInt& rhs);
private:
  string bigInt;
  int compareStr(const string& num1, const string& num2);
  string addHelper(const string& num1, const string& num2);
  string subHelper(const string& num1, const string& num2);
  string multiplyHelper(const string& num1, const string& num2);
  pair<string,string> divideHelper(const string& num1, const string& num2);
};
