class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        vector<int>answer;
        for(int i=0;i<=nums.size()-k;i++)
        {
            unordered_map<int,int>mp;

            for(int j=i;j<i+k;j++)
            {
                mp[nums[j]]++;

            }
            priority_queue<pair<int,int>>pq;
            for (auto [key, count] : mp)
            {
                pq.push({count,key});
            }
            int sum=0;
            for(int i=0;i<x&&!pq.empty();i++)
            {
                auto[count,key]=pq.top();
                pq.pop();
                sum=sum+key*count;
            }
            answer.push_back(sum);
            
        }
        return answer;
            
    }
};