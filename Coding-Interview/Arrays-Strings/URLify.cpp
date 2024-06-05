/**
* Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
* (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
  * EXAMPLE
  * Input:  "Mr John Smith", 13
  * Output: "Mr%20John%20Smith"
  * Hints: #53, #118
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// My Approach
string URLify (string & s, int len) {
  vector<char>h;
  for(const auto c : s ) {
    if(c == ' ') {
      h.push_back('%');
      h.push_back('2');
      h.push_back('0');
      continue;
    }
    h.push_back(c);
  }
  string result = "";
  for(const auto c : h) {
    result += c;
  }
  return result;
}

// Correct way to do it
string URLifyCorrect ( string s, int len) {
  for (int i=len-1, index=s.length()-1; 0<=i; i--){
    if(s[i] == ' ') {
      s[index] = '0';
      s[index - 1] = '2';
      s[index - 2] = '%';
      index-= 3;
    } else {
      s[index]=s[i];
      index--;
    }
  }
  return s;
}


int main () {
  string s = "Mr John Smith";
  string k = "Mr John Smith____";
  cout << URLify(s, 13) << endl;
  k = URLifyCorrect(k, 13);
  cout << k << endl;
  return 0;
}
