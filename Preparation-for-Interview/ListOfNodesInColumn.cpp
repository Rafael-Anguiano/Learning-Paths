/*
 * Given a binary tree and an int representing a column, return a list with all the values in that column
 * 
 * The column 0 represents all the nodes that vertically align with the root.
 * 
 * Example 1:
 * Input: Col: 1
 * 
 *       1
 *      / \
 *     2   3
 *    /   / \
 *   4   5   6
 *          /
 *          7
 * 
 * Output: [3, 7]
 * 
 * Example 2:
 * Input: Col: -1
 * 
 *       1
 *      / \
 *     2   3
 *    /   / \
 *   4   5   6
 *      /   /
 *     8    7
 * 
 * Output: [2, 8]
 * 
 * // Q: The returning list should have an order? Inorder
 * // Q: List or array ? Vector
 
 struct Node
 left *Node
 rigth *Node
 val int
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> getColumn (Node* root,int cTarget,vector<int> & list,int col) {
  if (root == nullptr) return list;
  
  getColumn(root->left, cTarget, list, col - 1);
  
  if (col == cTarget) list.push_back(root->val);
  
  getColumn(root->right, cTarget, list, col + 1);
  
  return list;
}

vector<int> getColumnOfTree (Node* root, int cTarget) {
	  vector<int> list;
  	int col = 0;
  
  	return getColumn(root, cTarget, list, col);
}

// como lo haria dario
void getColumn (Node* root, vector<int>list,int col) {
  if (root == nullptr)
    return
  
  getColumn(root->left, cTarget, list, col + 1);
  if (col == 0) 
    list.push_back(root->val);
  
  getColumn(root->right, cTarget, list, col - 1);
}

vector<int> getColumnOfTree (Node* root, int col) {
	  vector<int> list;
  	getColumn(root, list, col);
  	return list
}

