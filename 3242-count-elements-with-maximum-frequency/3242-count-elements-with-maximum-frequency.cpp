class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int>mp;

        for(int x:nums)
        {
            mp[x]++;

        }
        int mx=INT_MIN;
        int sum=0;

        for(auto y:mp)
        {
            mx=max(mx,y.second);
        }
        for(auto y:mp)
        {
            if(y.second==mx)
            {
                sum=sum+mx;
            }
        }
        return sum;
    }

};