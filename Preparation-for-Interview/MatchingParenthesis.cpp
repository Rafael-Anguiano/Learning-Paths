/*
 * https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=stack
 * Given a string a string composed of  {} [] and (), return a boolean indicating
 * if all pairs are open and closed appropriately
 * 
 * Example 1:
 * input: "[{()}]"
 * output: true
 * 
 * Example 2:
 * input: "{(})"
 * output: false
 * '[' == ']' 
 */

#include <iostream>
using namespace std;
bool validBrackets (string str) {
  vector stack;
  unordered_map<string, string> matching {
    {'}', '{'},
    {']', '['},
    {')', '('},
  };

  for (char & c : str) {
    // Adding to the stack
    if (!matching.contains(c)) {
    	stack.push_back(c);  
      continue;
    } 
    // Removing from the stack
    if (stack.empty() || matching[c] != stack.end()) {
      return false;
    }
    stack.pop_back();
  }
  
  return !stack.empty();
}
