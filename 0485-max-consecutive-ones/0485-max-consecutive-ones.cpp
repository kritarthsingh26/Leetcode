class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        int mx=0;
       for(int i=0;i<n;i++) 
       {
            if(nums[i]!=1)
            {
                sum=0;
            }
            else
            {
                sum+=1;
                mx=max(sum,mx);
            }
       }
       return mx;
    }
};