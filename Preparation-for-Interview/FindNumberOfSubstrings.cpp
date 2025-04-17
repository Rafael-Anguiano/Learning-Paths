/**
*
* Given a string `s` and an array of strings `words`, return the number of string in `words`
* that are substrings of `s`
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubstring (string& str1, string& str2) {
  if (str2.length() == 0) return false;
  if (str2.length() > str1.length()) return false;

  // Two pointers
  int p1 = 0, p2 = 0;
  while (p1 < str1.length() && p2 < str2.length()) {
    if (str1[p1] == str2[p2]) {
      p1++;
      p2++;
    } else {
      p1++;
    }
  }

  return p2 >= str2.length();
}

int findNumberOfSequence (string s, vector<string> words) {
  int result = 0;
  for (int i = 0; i < words.size(); i++) {
    if ( isSubstring(s, words[i]) )
      result++;
  }
  return result;
}

int main () {

  cout << findNumberOfSequence("abcde", {"a", "bb", "acd", "ace"}) << endl;
  cout << findNumberOfSequence("dsahjpjauf", {"ahpjau", "ja", "ahbwzgqnuk", "tnmlanowax", "oiii", ""}) << endl;

  return 0;
}
