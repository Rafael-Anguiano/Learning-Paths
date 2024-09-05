#include <iostream>

using namespace std;

bool getBit (int num, int i) {
  return num & (1 << i);
}

int setBit (int num, int i) {
  return num | (1 << i);
}

int clearBit (int num, int i) {
  int mask = ~(1 << i);
  return num & mask;
}

int clearBitsMSBthroughI (int num, int i) {
  int mask = (1 << i) - 1;
  return num & mask;
}

int clearBitsIthrough0 (int num, int i) {
  int mask = (-1 << (i + 1));
  return num & mask;
}

int toggleBit (int num, int i) {
  int mask = 1 << i;
  if ( !getBit(num, i) ) {
    return num | mask;
  }
  return num & ~mask;
}

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
