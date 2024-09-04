/**
* BIT MANIPULATION
* Pairwise Swap
* Write a program to swap odd and even bits in an integer with as few instructions as possible
* (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
*/

#include <iostream>
#include "./BitOperations.h"

using namespace std;


int bitwiseSwap (int number) {
  int newNumber = number;
  for (int i=0; i<sizeof(number)*8; i+=2) {
    if (getBit(number, i) == getBit(number, i+1)) {
      continue;
    } else {
      newNumber = toggleBit(number, i);
      newNumber = toggleBit(number, i+1);
    }
  }
  return newNumber;
}

int main () {
  int number = 0b10101010;

  cout << bitwiseSwap(number) << endl;

  return 0;
}
