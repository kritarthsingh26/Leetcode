class Solution {
public:

        bool isbalanced(vector<int>&freq)
        {
            int val=0;

            for(int f:freq)
            {
                if(f==0) continue;

                if(val==0)
                {
                    val=f;
                }
                else if(f!=val)
                {
                    return false;
                }
            }
            return true;
        }
    int longestBalanced(string s) 
    {
        int n=s.size();
        int res=0;

        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);

            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                if(isbalanced(freq))
                {
                    res=max(res,j-i+1);
                }
            }
        } 
        return res;   
    }
};