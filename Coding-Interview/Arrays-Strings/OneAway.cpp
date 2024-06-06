/**
* One Away
* There are three types of edits that can be performed on strings: 
* - Insert a character
* - Remove a character
* - Replace a character. 
* Given two strings, write a function to check if they are one edit (or zero edits) away.
*
* EXAMPLE
* pale, ple -> true
* pales, pale -> true
* pale, bale -> true
* pale, bake -> false
*/

#include <iostream>
#include <vector>

using namespace std;

bool isOneAway (string str1, string str2) {
  if (abs((int)str1.length() - (int)str2.length()) > 1) return false;

  vector<int>alphabet(26, 0);
  for(char c : str1) {
    alphabet[c - 'a']++;
  }
  for(char c : str2) {
    alphabet[c - 'a']--;
  }
  int sum = 0;
  for (int v : alphabet) {
    cout << v << ' ';
  }
  cout << endl;
  for(int v : alphabet) {
    sum+=v;
  }
  return sum > 1 ? false : true;
}

int main () {
  // Test Cases
  cout << isOneAway("pale", "ple") << endl; // true
  cout << isOneAway("pales", "pale") << endl; // true
  cout << isOneAway("pale", "bale") << endl; // true
  cout << isOneAway("pale", "bake") << endl; // false
  return 0;
}
