/*
 * You are given an integer array height of length N. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
	Find two lines that together with the x-axis form a container, such that the container contains the most water.
	Return the maximum amount of water a container can store.
	Notice that you may not slant/tilt the container.

Example 1:      
Input: height = [1,8,6,2,5,4,8,3,7] n = 9 
								 *               *  Output = 9 
                   *             *	Output = 49
                   *           *	  Output = 
                   *         * 
int maxArea = 

Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water is between 8 in index 1 and 7 in index 8, thus 49.

Example 2:
Input: height = [1,1]
Output: 1

Brute Force:
O(n2)

 * length n
 * array hight
 *
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxAreaOfContainer (vector<int> & height) {
  if (height.size() < 2) return 0;

  int maxContainer = 0;

  int left= 0;
  int right = height.size()-1;

  while (left < right) {
    maxContainer = max(maxContainer, min(height[left], height[right]) * (right - left));

    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return maxContainer;
}

/*
 * 
    Input: height = [1,8,6,2,5,4,8,3,7] n = 9 
    mC:8 l:0 r:8     *			         *
    mC:49 l:1 r:8      *  	         *   O = 49
    mC:49 l:1 r:7      *  	       *     O = 36
    mC:49 l:1 r:6      *  	     *       O = 40
    mC:49 l:1 r:5      *  	   *         O = 40

    Expected Output: 49
 *
 *
 *
 */
























