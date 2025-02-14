/*
 * Given a binary tree, return a list of lists that contains every level of the three
 * 
 * Note: this is not a complete binary tree
 * 
 * Example 1:
 * Input: 
 *      1 -> 0
 *     /
 *    2   -> 1
 *   / \
 *  3   4    -> 2
 * Output: [[1], [2], [3, 4]] 
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) 
 * 
 * 
 * Node
 * left *Node
 * right *Node
 * val int
 */

#include <iostream>
#include <vector>
using namespace std;

void recursiveTree (Node* root, vector<vector<int>> & list, int level) {
  if (root == nullptr) return;
  
  if (list.length() == level) list.push_back({});
  	
	list[level].push_back(root->val);
  
  recursiveTree(root->left, list, level + 1);
  recursiveTree(root->right, list, level + 1);
  
  return;
}

vector<vector<int>> getValuesByLevel (Node * root) {
  vector<vector<int>> lists;
  
  recursiveTree(root, lists, 0);
  return result;
}


/* 
 * Example 1:
 * Input: 
 *      1
 *     /
 *    2
 *   / \
 *  3   4
 * Expected Output: [[1], [2], [3, 4]] 
 *  
 * 
 * recursiveTree(1, [], 0);
 * 		recursiveTree(2, [{1}], 1);
 * 				recursiveTree(3, [{1}, {2}], 2);
 * 						recursiveTree(nullptr, [{1}, {2}, {3}], 3); -> return
 * 						recursiveTree(nullptr, [{1}, {2}, {3}], 3); -> return
					recursiveTree(4, [{1}, {2}, {3, 4}], 2);
      
 * 	
 * 
 * Lists: [{1}, {2}, {3, 4}]
 * 
 * 
 * ---------------------------------------------------
 * 
 * Given a binary tree, return a list that contains every value by level in order from left to right
 * 
 * Note: this is not a complete binary tree
 * 
 * Example 1:
 * Input: 
 *      1 
 *     / \
 *    2   5
 *   / \  /\
 *  3  4 6  7 
 * 	
 * [3, 4, 6, 7]
 * 
 * Output: [1, 2, 3, 4] 
 * 
 */


#include <queue>
vector<int> listOfValues (Node* root) {
  if (!root) return {};
  vector<int> list;
  queue<Node*> nodes;
  nodes.push(root);
  Node* curr;
  
  while(!nodes.empty()) {
  	curr = nodes.pop();
    list.push_back(curr->val);
    
    if (curr->left == nullptr) nodes.push(curr->left);
    if (curr->right == nullptr) nodes.push(curr->right);
  }
  
  return list;
}

/* Example 1:
 * Input: 
 *      1 
 *     /
 *    2 
 *   / \
 *  3  4 
 * 	
 * curr: 4
 * queue: []
 * List: [1, 2, 3, 4]
 * 
 * Expected Output: [1, 2, 3, 4] 
 * 
 */










