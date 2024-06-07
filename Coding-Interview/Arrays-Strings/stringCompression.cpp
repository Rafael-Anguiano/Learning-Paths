/**
* String Compression
* Implement a method to perform basic string compression using the counts of repeated characters.
* For example, the string aabcccccaaa would become a2b1c5a3. 
* If the "compressed" string would not become smaller than the original string, 
* your method should return the original string.
* You can assume the string has only uppercase and lowercase letters (a-z).
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string compressString (string s) {
  if(s.length()== 1) return s;
  string result = "";
  result+=s[0];
  
  int curr = 1;
  for (int i=1; i<s.length(); i++) {
    if(s[i] == result[result.length()-1]) {
      curr++;
      if(i+1 == s.length()) result+= to_string(curr);
      continue;
    } else {
      result+= to_string(curr);
      result+=s[i];
      curr = 1;
      if(i+1 == s.length()) result+= to_string(curr);
    }
  }
  return result.length() < s.length() ? result : s;
}

int main () {
  // Test cases with respective expected results
  vector<string> testCases = {"aabcccccaaa", "abcd", "a", "aa", "aabbccdd"};
  vector<string> expectedResults = {"a2b1c5a3", "abcd", "a", "aa", "aabbccdd"};

  cout << "String Compression" << endl;
  for (int i=0; i<testCases.size(); i++) {
    cout << "Test case " << i+1 << " with input " << testCases[i] << endl;
    cout << "Expected: " << expectedResults[i] << endl;
    cout << "Result: " << compressString(testCases[i]) << endl;
    cout << "----------------------------------" << endl;
  }
  return 0;
}
