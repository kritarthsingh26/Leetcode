class Solution {
public:
   long long maximumSubarraySum(vector<int>& nums, int k) 
{
    unordered_map<int, int> mp;
    long long sum = 0, ans = 0;

    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        // add element
        mp[nums[j]]++;
        sum += nums[j];

        // maintain window size k
        if (j - i + 1 > k)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);

            sum -= nums[i];
            i++;
        }

        // check valid window
        if (j - i + 1 == k && mp.size() == k)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}
};