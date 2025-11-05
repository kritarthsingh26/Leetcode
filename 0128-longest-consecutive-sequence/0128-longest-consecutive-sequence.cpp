class Solution {
public:
   int longestConsecutive(vector<int>& nums) 
{
    if (nums.empty()) return 0;

    // Use an ordered set (balanced BST) to remove duplicates and sort
    set<int> s;
    for (int k : nums)
        s.insert(k);

    int longest = 1;
    int currLen = 1;

    auto prev = s.begin();
    for (auto it = next(s.begin()); it != s.end(); ++it)
    {
        if (*it == *prev + 1) {
            currLen++;
        } else {
            longest = max(longest, currLen);
            currLen = 1;
        }
        prev = it;
    }
    longest = max(longest, currLen);

    return longest;
}
};