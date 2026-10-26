class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0,ms=INT_MIN;
    for(int i:nums)
    {
        sum=sum+i;
        ms=max(sum,ms);
        
    
    if(sum<0)
    {
        sum=0;
    }}
    return ms;
    }
};