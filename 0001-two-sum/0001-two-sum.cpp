class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
            unordered_map<int,int>mp;
            vector<int>answer;

            for(int i=0;i<nums.size();i++)
            {
                int first=nums[i];
                int second=target-first;

                if(mp.find(second)!=mp.end())
                {
                    answer.push_back(i);
                    answer.push_back(mp[second]);
                    return answer;

                }
                mp[first]=i;
            }
            return answer;
    }
};