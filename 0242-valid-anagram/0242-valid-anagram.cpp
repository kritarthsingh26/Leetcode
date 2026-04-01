class Solution {
public:
    bool isAnagram(string s, string t) 
    {
            if (s.size() != t.size()) return false;
       
        int n=s.size();

        vector<int>answer(26,0);

        for(int i=0;i<n;i++)
        {
            answer[s[i]-'a']++;
            answer[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(answer[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};