/*
 * Given two strings, determine if string1 is an anagram of string2
 * a-z
 * 
 * Example 1:
 * Input: "", "a"
 * Output: False
 * 
 * Example 2:
 * Input: "aba" "baa"
 * Output: True
 * 
 * Example 3:
 * Input: "aba" "abc"
 * Output: False
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram (string str1, string str2) {
  if (str1.length() != str2.length()) {
    return false;
	}
  unordered_map<string, int> alphabet;
  // Iterate through the first str
  for (char & c : str1) {
    alphabet[c]++;
  }
  
  // Second str
  for (char & c : str2) {
    if (!alphabet.contain(c)) return false;
    
    alphabet[c]--;
    if (alphabet[c] == 0) {
      alphabet.erase(c);
    }
  }
  
  return alphabet.empty();
}
 
/*
 * Given two strings, determine where the string1 is an anagram of a substring in string2
 * a-z strings
 * 
 * Example 1:
 * Input: "a" "abc"
 * Output: 0
 * 
 * Example 2:         ****
 * Input: "lvaa" "anitalavalatina" 
 * Output: 4
 * 
 * { } -> alph.empty() 
 * map[a]--
 * 
 * Example 3:
 * Input: "a" "bcd"
 * Output: -1
 * 
 *  { a:1, b:-1, c:-1 }
 */

int isAnagramSliding (string str1, string str2) {
  if (str2.length() < str1.length()) return -1;

  unordered_map<string, int> alpha;

  // str1
 	for (char & c : str1) {
    alpha[c]++;
  }
  
  // Slide through str2
  for (int i = 0; i<str2.length(); i++) {
    alpha[str2[i]]--;
    if (alpha[str2[i]] == 0) {
      alpha.erase(str2[i]);
    }
    if (i >= str1.length()){
      alpha[str2[i-str1.length()]]++;
      if (alpha[str2[i-str1.length()]] == 0) {
        alpha.erase(str2[i-str1.length()]);
      }
    }

    if (alpha.empty())
      return i - str1.length();
  }
  
  return -1;
}

