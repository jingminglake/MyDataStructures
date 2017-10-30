#include "BigInt.h"
#include <string>
#include <algorithm>

BigInt& BigInt::operator=(const BigInt& rhs) {
  if (this == &rhs)
    return *this;
  bigInt = rhs.bigInt;
  return *this;
}

BigInt& BigInt::operator+=(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  bigInt = addHelper(bigInt, bigIntRight);
  return *this;
}

BigInt& BigInt::operator-=(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  bigInt = subHelper(bigInt, bigIntRight);
  return *this;
}

BigInt& BigInt::operator*=(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  bigInt = multiplyHelper(bigInt, bigIntRight);
  return *this;
}

BigInt& BigInt::operator/=(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  bigInt = divideHelper(bigInt, bigIntRight).first;
  return *this;
}

bool BigInt::operator==(const BigInt& rhs) {
  return bigInt == rhs.bigInt;
}

bool BigInt::operator<=(const BigInt& rhs) {
  return compareStr(bigInt, rhs.bigInt) <= 0;
}

bool BigInt::operator<(const BigInt& rhs) {
  return compareStr(bigInt, rhs.bigInt) < 0;
}

bool BigInt::operator>=(const BigInt& rhs) {
  return compareStr(bigInt, rhs.bigInt) >= 0;
}

bool BigInt::operator>(const BigInt& rhs) {
  return compareStr(bigInt, rhs.bigInt) > 0;
}

BigInt BigInt::operator+(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  BigInt res;
  res.bigInt = addHelper(bigInt, bigIntRight);
  return res;
}

BigInt BigInt::operator-(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  BigInt res;
  int cp = compareStr(bigInt, bigIntRight);
  if (cp < 0) {
    res.bigInt = "-" + subHelper(bigIntRight, bigInt);
  } else if (cp == 0) {
    res.bigInt = "0";
  } else {
    res.bigInt = subHelper(bigInt, bigIntRight);
  }
  return res;
}

BigInt BigInt::operator*(const BigInt& rhs) {
  BigInt res;
  string bigIntRight = rhs.bigInt;
  res.bigInt = multiplyHelper(bigInt, bigIntRight);
  return res;
}

BigInt BigInt::operator%(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  BigInt res;
  int cp = compareStr(bigInt, bigIntRight);
  if (cp > 0) {
    res.bigInt = divideHelper(bigInt, bigIntRight).second;
  } else if (cp == 0) {
    res.bigInt = "0";
  } else {
    res.bigInt = bigInt;
  }
  return res;
}

BigInt BigInt::operator/(const BigInt& rhs) {
  string bigIntRight = rhs.bigInt;
  BigInt res;
  int cp = compareStr(bigInt, bigIntRight);
  if (cp > 0) {
    res.bigInt = divideHelper(bigInt, bigIntRight).first;
  } else if (cp == 0) {
    res.bigInt = "1";
  } else {
    res.bigInt = "0";
  }
  return res;
}

int BigInt::compareStr(const string& num1, const string& num2) {
  int res = 0;
  int size1 = num1.size();
  int size2 = num2.size();
  if (size1 < size2) {
    res = -1;
  } else if (size1 == size2) {
      if (num1 < num2)
        res = -1;
      else if (num1 == num2)
        res = 0;
      else
        res = 1;
  } else if (size1 > size2) {
    res = 1;
  }
  return res;
}

string BigInt::addHelper(const string& num1, const string& num2) {
    int carry = 0;
    string res = "";
    int sum = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 && j >= 0) {
      sum = num1[i] - '0' + num2[j] - '0' + carry;
      i--;
      j--;
      carry = sum / 10;
      res += (sum % 10 + '0');
    }
    while (i >= 0) {
      sum = num1[i] - '0' + carry;
      i--;
      carry = sum / 10;
      res += (sum % 10 + '0');
    }
    while (j >= 0) {
      sum = num2[j] - '0' + carry;
      j--;
      carry = sum / 10;
      res += (sum%10 + '0');
    }
    if (carry == 1)
      res += "1";
    reverse(res.begin(), res.end());
    size_t startpos = res.find_first_not_of("0");
    if (string::npos != startpos) {
      res = res.substr(startpos);
    }
    return res;
  }
string BigInt::subHelper(const string& num1, const string& num2) {
  string res = "";
  int diff = 0;
  int borrow = 0;
  int i = num1.size() - 1;
  int j = num2.size() - 1;
  while (i >= 0 && j >= 0) {
    diff = (num1[i] - '0') - borrow - (num2[j] - '0');
    if (diff < 0) {
      borrow = 1;
      diff += 10;
    } else {
      borrow = 0;
    }
    i--;
    j--;
    res += (diff + '0');
  }
  while (i >= 0) {
    diff = (num1[i] - '0') - borrow;
    if (diff < 0) {
      borrow = 1;
      diff += 10;
    } else {
      borrow = 0;
    }
    i--;
    res += (diff + '0');
  }
  reverse(res.begin(), res.end());
  size_t startpos = res.find_first_not_of("0");
  if (string::npos != startpos) {
    res = res.substr(startpos);
  } else {
    res = "0";
  }
  return res;
}

string BigInt::multiplyHelper(const string& num1, const string& num2) {
  string sum(num1.size() + num2.size(), '0');  
  for (int i = num1.size() - 1; i >= 0; --i) {
    int carry = 0;
    for (int j = num2.size() - 1; j >= 0; --j) {
      int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
      sum[i + j + 1] = tmp % 10 + '0';
      carry = tmp / 10;
    }
    sum[i] += carry;
  }
    
  size_t startpos = sum.find_first_not_of("0");
  if (string::npos != startpos) {
    return sum.substr(startpos);
  }
  return "0";
}

pair<string,string> BigInt::divideHelper(const string& num1, const string& num2) {
  if (num2 == "0") {
    cout << "oops, divided by 0" << endl;
    exit(-1);
  }
  string dividend = num1;
  string quotient;
  while (compareStr(dividend, num2) >= 0) {
    string temp = num2;
    string mutiple = "1";
    while (compareStr(dividend, multiplyHelper(temp, string("2"))) >= 0) {
      temp = multiplyHelper(temp, string("2"));
      mutiple = multiplyHelper(mutiple, string("2"));
    }
    dividend = subHelper(dividend, temp);
    quotient = addHelper(quotient, mutiple);
  }
  size_t startpos = quotient.find_first_not_of("0");
  if (string::npos != startpos) {
    quotient = quotient.substr(startpos);
  } else {
    quotient = "0";
  }
  return make_pair(quotient, dividend);
}

ostream& operator<<(ostream& out, const BigInt& rhs) {
  return out << rhs.bigInt;
}
