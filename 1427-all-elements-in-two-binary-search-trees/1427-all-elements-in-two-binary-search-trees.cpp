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
        void inorder(TreeNode* root,vector<int>&answer)
        {
           
            if(root==NULL)
            {
                return;
            }
            inorder(root->left,answer);
            answer.push_back(root->val);
            inorder(root->right,answer);
        }


    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>list1;
        vector<int>list2;
        vector<int>result;

        inorder(root1,list1);
        inorder(root2,list2);
        int n=list1.size();
        int m=list2.size();
        int i=0;
        int j=0;
        
            while(i<n && j<m)
            {
            if(list1[i]<list2[j])
            {
                result.push_back(list1[i]);
                i++;
            }
            else
            {
                result.push_back(list2[j]);
                j++;
            }
            }
            while(j<m)
            {
                result.push_back(list2[j]);
                j++;
            }
             while(i<n)
            {
                result.push_back(list1[i]);
                i++;
            }


        
        return result;

    }
};