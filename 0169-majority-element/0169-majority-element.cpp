class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int answer=0;
        unordered_map<int,int>mp;
        for(int a:nums)
        {
            mp[a]++;

        }    
        for(auto x:mp)
        {
            if(x.second>nums.size()/2)
            {
                answer=x.first;
                break;
            }
        }
        return answer;
    }
};