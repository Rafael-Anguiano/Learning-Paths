/**
* Binary To String :
* Given a real number between 0 and 1 (e.g., 0.72)
* that is passed in as a double, print the binary representation.
* If the number cannot be represented accurately in binary with at 
* most 32 characters, print "ERROR."
*/

#include <iostream>
#include <string>
#include "./BitOperations.h"

using namespace std;

string intToBinaryString (int num) {
  string resultString = "";
  for (int i=0; i < sizeof(num) * 8; i++ ) {
    if (getBit(num, i)) {
      resultString = "1" + resultString;
    } else {
      resultString = "0" + resultString;
    }
  }

  return resultString;
}


string doubleToBinaryString (double num) {
  if (num >= 1 || num <= 0) return "ERROR";

  string resultString = ".";
  double frac = 0.5;

  while (num > 0) {
    if (resultString.length() > 32) return resultString;

    if (num >= frac) {
      resultString.append("1");
      num -= frac;
    } else {
      resultString.append("0");
    }
    frac /= 2;
  }

  return resultString;
}

int main () {

  int value = 72;

  cout << intToBinaryString(value) << endl;

  double value1 = 0.35;

  cout << doubleToBinaryString(value1) << endl;

  return 0;
}
