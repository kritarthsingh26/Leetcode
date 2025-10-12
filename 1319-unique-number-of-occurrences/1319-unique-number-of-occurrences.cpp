class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        int answer=0;
        unordered_map<int,int>mp;
        for(int i:arr)
        {
            mp[i]++;
        }
        unordered_set<int>st;

        for(auto &k:mp)
        {
            st.insert(k.second);

        }
        if(st.size()==mp.size())
        {
            return 1;
        }
        else
        {
            return 0;
        }

        return -1;
    }
};