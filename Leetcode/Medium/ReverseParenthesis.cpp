/**
* Reverse Parenthesis
* Given a string s that consists of lower case English letters and brackets. Reverse the strings in each pair of matching parentheses, starting from the innermost one.
* Your result should not contain any brackets.
* Example 1:
* Input: s = "(abcd)"
* Output: "dcba"
* Example 2:
* Input: s = "(u(love)i)"
* Output: "iloveu"
* Example 3:
* Input: s = "(ed(et(oc))el)"
* Output: "leetcode"* 
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string reverseParenthesis (string s) {
  stack<int> stack;
  for(int i=0; i<s.length(); i++) {
    if (s[i] == '(') stack.push(i);
    else if (s[i] == ')') {
      reverse(s.begin() + stack.top(), s.begin() + i);
      stack.pop();
    }
  }
  string result = "";
  for (int i=0; i<s.length(); i++) {
    if (s[i] == '(' || s[i] == ')') continue;
    result+= s[i];
  }
  return result;
}

int main () {
  string example1 = "(abcd)";
  cout << reverseParenthesis(example1) << endl;
  string example2 = "(u(love)i)";
  cout << reverseParenthesis(example2) << endl;
  string example3 = "(ed(et(oc))el)";
  cout << reverseParenthesis(example3) << endl;
  return 0;
}
