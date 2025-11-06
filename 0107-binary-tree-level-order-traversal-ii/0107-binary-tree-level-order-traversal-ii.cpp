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
   
         vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>answer;
            if(root==NULL)
            {
                return answer;
            }
            queue<TreeNode*>q;
            q.push(root);

            while(!q.empty())
            {
                vector<int>result;
                int k=q.size();
               
                for(int i=0;i<k;i++)
                {
                     TreeNode *r=q.front();
                    result.push_back(r->val);
                        q.pop();
                    if(r->left)
                    {
                        q.push(r->left);
                    }
                    if(r->right)
                    {
                        q.push(r->right);
                    }
                }
                answer.push_back(result);
            }
            reverse(answer.begin(),answer.end());
            return answer;

        
    }
};