class Solution {
public:
    vector<vector<int>>answer;

        void helper(int k, int n,int index,vector<int>&temp)
        {
            if(temp.size()==k && n==0)
            {
                answer.push_back(temp);
                return;
            }

            if(n<0)
            {
                return;
            }

            for(int i=index;i<=9;i++)
            {
                temp.push_back(i);
                helper(k,n-i,i+1,temp);
                temp.pop_back();


            }
        }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        
        vector<int>temp;
        helper(k,n,1,temp);

        return answer;

    }
};