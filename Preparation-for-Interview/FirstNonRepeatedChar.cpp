#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char firstNonRepeatedChar (string str) {
  unordered_map<char, int> table;
  for(char c : str) table[c]++;

  for(char c : str) {
    if (table[c] == 1) return c;
  }
  return ' ';
}

int main () {
  cout << firstNonRepeatedChar("bacc") << endl;
  cout << firstNonRepeatedChar("") << endl;
  cout << firstNonRepeatedChar("abcadc") << endl;
  return 0;
}
