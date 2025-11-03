class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n=colors.length();
        int totaltime=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                totaltime=totaltime+min(neededTime[i-1],neededTime[i]);

                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return totaltime;
    }
};