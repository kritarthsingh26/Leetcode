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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> answer;
        if (root == NULL) return answer;  // base case

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;  // true = left to right

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode* f = q.front();
                q.pop();

                int index = flag ? i : (size - 1 - i);
                level[index] = f->val;

                if (f->left != NULL)
                    q.push(f->left);
                if (f->right != NULL)
                    q.push(f->right);
            }

            // after one full level
            flag = !flag;  
            answer.push_back(level);
        }

        return answer;
    
   }
};