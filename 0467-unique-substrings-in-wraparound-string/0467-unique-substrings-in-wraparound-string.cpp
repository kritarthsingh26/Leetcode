class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0); // dp[i] = max length ending with 'a'+i
        int k = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && (s[i] - s[i-1] + 26) % 26 == 1) {
                k++;
            } else {
                k = 1;
            }

            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }

        int result = 0;
        for (int x : dp) result += x;

        return result;
    }
};