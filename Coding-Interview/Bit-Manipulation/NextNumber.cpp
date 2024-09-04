/**
* BIT MANIPULATION
* Next Number: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.
*/

#include <iostream>
#include <vector>
#include "./BitOperations.h"

using namespace std;

int numberOfBits (int num) {
  int bits = 0;
  for (int i=0; i<sizeof(num)*8; i++) {
    if (getBit(num, i)) bits++;
  }
  return bits;
}

vector<int> nextNumber (int number) {
  int currHigh = number+1, currLow = number-1;
  int numBits = numberOfBits(number);

  while ( numberOfBits(currHigh) != numBits || numberOfBits(currLow) != numBits ) {
    if (numberOfBits(currHigh) != numBits) currHigh++;
    if (numberOfBits(currLow) != numBits) currLow--;

    if (currLow < 0 && numberOfBits(currHigh) == numBits) return {-1, currHigh};
  }

  return {currLow, currHigh};
}

int main ()  {

  int number = 15;
  vector<int> result = nextNumber(number);
  cout << result[0] << " " << result[1] << endl;

  return 0;
}
