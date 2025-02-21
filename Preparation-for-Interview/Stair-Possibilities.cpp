/*
 * You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Recursively: 
	
  n = n-1 && n-2

	unordered_map<n, result>

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 * 
 *  
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int possibilities (int sizeStair) {
  vector<int> steps (sizeStair, 0);
  steps[0] = 1; // Size: 0
  if (sizeStair > 1) steps[1] = 2; // Size: 1
  
  for (size_t i = 2; i < steps.size(); i++) {
    steps[i] = steps[i - 1] + steps[i - 2];
  }
  
  return steps[sizeStair - 1];
}



int possibilities (int sizeStair) {
  vector<int> steps (2, 0);
  steps[0] = 1;
  steps[1] = 1;
  int result = 0;
  
  for (int i = 1; i < sizeStair; i++) {
    result = steps[0] + steps[1];
    steps[0] = steps[1];
    steps[1] = result;
  }
  
  return step[1];
}


// if (i % 2 == 0) steps[0] = result; 
// else steps[1] = result;


/**
 * 
Example 2:
Input: n = 3

steps: { 1, 2 , 3 }
steps[2] = 2 + 1

Output: 3



Expected Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

/** 
 * 
 * 
 
Example 1:
Input: n = 2

vector: {1, 1}


First Numbers : 0  1 / 1  2  3  5  5 
Index:          0  1  2  3  4

1 + 1 + 1 + 1
2 + 1 + 1
1 + 2 + 1
1 + 1 + 2
2 + 2

0 1 1 2 3 5

Expector Output: 2

*/

















