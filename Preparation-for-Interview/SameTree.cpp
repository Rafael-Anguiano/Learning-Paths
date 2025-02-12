/*
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 * 
 * Example 1:
 * Input:
 * p =  1     q=   1
 *     / \        / \
 *    2   3      2   3
 * Output: true
 * 
 * Example 2:
 * Input:
 * p =  1     q=   1
 *     /            \
 *    2              2
 * Output: false
 * 
 * Example 3:
 * Input:
 * p =  1     q=   1
 *     /          /
 *    2          3
 * Output: false
 */


bool sameTree (Node * p, Node * q) {
  if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)) return false;
  if (p == nullptr && q == nullptr) return true;
  if (p->val != q->val) return false;
  
	bool result = true;
  result = sameTree(p->left, q->left);
  if (!result) return false;
  result = sameTree(p->right, q->right);
  if (!result) return false;
  min(sameTree(p->left, q->left), sameTree(p->right, q->right))
  return true;
}

// dario
bool sameTree (Node * p, Node * q) {
  if (p == nullptr && q == nullptr) return true;
  if (p == nullptr || q == nullptr) return false;
  return p->val != q->val && sameTree(p->left, q->left) && sameTree(p->right, q->right);
}

/* Example 1:
 * Input:
 * p =  1     q=   1
 *     / \        / \
 *    2   3      2   3
 * 
 * Output: true

visited: p:1 q:1
result: true

sameTree(1, 1)
	sameTree(2, 2)
  	sameTree(null, null)

*/


