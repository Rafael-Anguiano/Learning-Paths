/**
* Lowest Common Ancestor of Deepest Leaves
* Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
*/

class Solution {
    void dfs (TreeNode* root, vector<priority_queue<TreeNode*>> & nodesByLevel, int level) {
        if (root == nullptr) return;

        if (nodesByLevel.size() == level) nodesByLevel.push_back(priority_queue<TreeNode*>());
        nodesByLevel[level].push(root);

        if (root->left) dfs(root->left, nodesByLevel, level+1);
        if (root->right) dfs(root->right, nodesByLevel, level+1);
        return;
    }

    pair<int, TreeNode*> searchParent (TreeNode* root, int & found, unordered_set<TreeNode*> deepest) {
        if (!root) return pair<int,TreeNode*>(0, nullptr);
        
        pair<int, TreeNode*> left= searchParent(root->left, found, deepest);
        if (left.second) return left;

        pair<int, TreeNode*> right = searchParent(root->right, found, deepest);
        if (right.second) return right;

        if (left.first + right.first == deepest.size()) return pair<int, TreeNode*>(deepest.size(), root);

        return pair<int,TreeNode*>(left.first + right.first + deepest.count(root), nullptr);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<priority_queue<TreeNode*>> numberOfNodes;
        dfs(root, numberOfNodes, 0);

        if (numberOfNodes[numberOfNodes.size()-1].size() == 1) return numberOfNodes[numberOfNodes.size()-1].top(); 
        unordered_set<TreeNode*> deepest;
        while (!numberOfNodes[numberOfNodes.size()-1].empty()) {
            cout << numberOfNodes[numberOfNodes.size()-1].top()->val << endl;
            deepest.insert(numberOfNodes[numberOfNodes.size()-1].top());
            numberOfNodes[numberOfNodes.size()-1].pop();
        }
        int found = 0;
        return searchParent(root, found, deepest).second;
    }
};
