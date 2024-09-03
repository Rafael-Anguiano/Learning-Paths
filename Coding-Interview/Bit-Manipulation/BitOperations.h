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

