class Solution {
public:
        int t[101];
        int solve(vector<int>& nums,int n,int i)
        {
            if(i>=n)
            {
                return 0;
            }
            if(t[i]!=-1)
            {
                return t[i];
            }

            int take=nums[i]+solve(nums,n,i+2);
            int skip=solve(nums,n,i+1);

            return t[i]=max(take,skip);
        }
    int rob(vector<int>& nums) 
    {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return solve(nums,n,0);   
    }
};