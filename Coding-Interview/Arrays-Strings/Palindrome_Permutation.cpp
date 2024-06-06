/**
* Problem: Palindrome Permutation
* Given a string, write a function to check if it is a permutation of a palindrome.
* A palindrome is a word or phrase that is the same forwards and backwards. A permutation
* is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
* Example:
* Input: Tact Coa
* Output: True (permutations: "taco cat", "atco cta", etc.)
*/

#include <iostream>
#include <map>
#include <cctype>

using namespace std;

bool isPalindromePermutation(string s) {
  map<char, int>h;
  for(char c :  s) {
    if(!h.count((char)tolower(c))) h.insert({(char)tolower(c), 0});
    h[(char)tolower(c)]++;
  }
  bool hasOddValue = false;
  for (const auto & p : h) {
    if (p.second % 2) {
      if (p.first == ' ') continue;

      if (hasOddValue) return false;
      hasOddValue = true;
    }
  }
  return true;
}

int main () {
  string s = "Tact Coc";
  cout << isPalindromePermutation(s) << endl;

  return 0;
}
