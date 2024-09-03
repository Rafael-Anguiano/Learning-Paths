/**
* BIT MANIPULATION
* Conversion
* Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
* EXAMPLE
* Input: 29 (or: 11101), 15 (or: 01111)
* Output: 2
*/

#include <iostream>
#include "./BitOperations.h"

using namespace std;

int changeBit (int num, int i) {
  int mask = 1 << i;
  if (getBit(num, i) == false) {
    return num | mask;
  }
  return num & ~mask;
}

int conversion (int a, int b) {
  int count = 0, i = 0;

  while (a != b) {
    if (getBit(a, i) != getBit(b, i)) {
      b = changeBit(b, i);
      count++;
    }
    i++;
  }

  return count;
}

int main () {
  int a = 29;
  int b = 15;

  cout << conversion(a, b) << endl;
}
