#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool arePermutations(string str1, string str2) {
  if (str1.length() != str2.length()) return false;

  vector<int> alphabet (26, 0);

  for (char c : str1) alphabet[c - 'a']++;

  for (char c : str2) alphabet[c - 'a']--;

  for (int freq_letter : alphabet) {
    if (freq_letter != 0) return false;
  }

  return true;
}



int main () {

  // Example 1 :
  string str1 = "abcda";
  string str2 = "aabcd";
  cout << boolalpha << arePermutations(str1, str2) << endl;

  // Example 2  :
  str1 = "aaabc";
  str2 = "aabc";
  cout << boolalpha << arePermutations(str1, str2) << endl;

  return 0;
}
