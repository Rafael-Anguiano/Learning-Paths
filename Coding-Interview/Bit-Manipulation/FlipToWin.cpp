/**
* BIT MANIPULATION
* Problem: Flip to Win
* You have an integer and you can flip exactly one bit from a 0 to a 1.
* Write code to find the length of the longest sequence of 1s you could create.
*
* EXAMPLE
* Input: 1775 (or: 11011101111)
* Output: 8
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "./BitOperations.h"

using namespace std;

int flipToWin (int number) {
  vector<int> consecutive;
  int curr = 0;
  int max = 0;

  int numberOfBits = sizeof(int) * 8;
  for (int i = 0; i < numberOfBits; i++) {
    curr++;
    if (getBit(number, i+1) != getBit(number, i)) {
      consecutive.push_back(getBit(number, i) ? curr : curr * -1);
      if (getBit(number, i) && curr > max) max = curr;
      curr = 0;
    }
  }

  for (int i=0; i<consecutive.size()-2; i++) {
    if (consecutive[i] < 0) continue;

    if (consecutive[i+1] == -1) {
      if (consecutive[i+2] + consecutive[i] + 1 > max)
        max = consecutive[i+2] + consecutive[i] + 1;
    }
  }
  return max;
}

int main () {

  int number = 2005;
  cout << flipToWin(number) << endl;


  return 0;
}
