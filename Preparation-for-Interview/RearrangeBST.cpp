/*
 * Given a binary search tree and a Node pointer, rearrange the BST so that the node is the new root. 
 * 
 * The node is guaranteed to be a member of the tree
 * 
 * Node ->  3
 * 
 * 			3
 *  	/
 * 	 2
 * 	/   
 * 	1		
 * 
 * Node -> 4
 * 
 * Root -> 6
 *       0
 *        \\
 * 			    6
 * 		   x    \ 
 * 	 2         7
 * 	/ x
 * 1	 	  4
 *       / \
 *      3   5
 *     /     \ 
 *    2       6
 *   /         \
 *  1           7
 * 
 * 
    1 2 3 4 5
    
    O(log(n))
 */

#include <iostream>
#include <vector>

using namespace std;

TreeNode* getLeftMost (TreeNode* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

TreeNode* getRightMost (TreeNode* node) {
  while (node->right != nullptr) {
    node = node->right;
  }
  return node;
}

bool findNode(TreeNode* root, TreeNode* node, pair<TreeNode*,TreeNode*>& p) {
  if (root == nullptr) return false;
  if (root == node) return true;
  
  if (findNode(root->left, node)) {
    // Add to right of node
    root->left = nullptr;
    p.second->right = root;
    p.second = getRightMost(root);
    return true;
  }
  
  if (findNode(root->right, node)) {
    // Add to left of node
    root->right = nullptr;
    p.first->left = root;
    p.first = getLeftMost(root);
    return true;
  }
  return false;
}

void fixTree (TreeNode* root, TreeNode* node) {
  findNode(root, node, pair<TreeNode*,TreeNode*>(getLeftMost(node), getRightMost(node)));
}





