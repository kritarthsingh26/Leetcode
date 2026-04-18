class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        for(int k:nums)    
        {
            if(k%3!=0)
            {
                count++;
            }
        }
        return count;
    }
};