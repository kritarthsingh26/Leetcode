/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr; // Base case: empty tree
        
        // If the current node's value is less than low, 
        // then we discard the left subtree and trim the right one.
        if (root->val < low)
            return trimBST(root->right, low, high);
        
        // If the current node's value is greater than high,
        // we discard the right subtree and trim the left one.
        if (root->val > high)
            return trimBST(root->left, low, high);
        
        // Otherwise, trim both subtrees and keep this node.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};