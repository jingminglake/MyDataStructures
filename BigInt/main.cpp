#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
  BigInt c('2');
  cout << c << endl;
  BigInt a1("12312555555554152152153123421424");
  BigInt a2("12312555555554152152153123421425");
  cout << "a1 < a2: " << (a1 < a2) << endl;
  cout << "a1 > a2: " << (a1 > a2) << endl;
  BigInt a3("12312555555554152152153123421425");
  cout << "a2 == a3: " << (a2 == a3) << endl;
  BigInt b1("954562312321312398898712142342320");
  BigInt b2("954562312321312398898712142342339");
  cout << "b1 - b2 == " << b1 - b2 << endl;
  cout << "b2 - b1 == " << b2 - b1 << endl;
  BigInt d1("1324321521352152135412312312312234243");
  BigInt d2("123213124235123131");
  cout << "d1 / d2 == " << d1 / d2 << endl;
  cout << "d1 % d2 == " << d1 % d2 << endl;
  return 0;
}
