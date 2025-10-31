class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        vector<int>answer;
        unordered_map<int,int>mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        for(auto &it :mp)
        {
            if(it.second==2)
            {
                answer.push_back(it.first);
            }
        }
        return answer;

    }
};