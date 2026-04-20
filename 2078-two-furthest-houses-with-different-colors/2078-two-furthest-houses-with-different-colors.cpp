class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size();
        int i=0;int j=n-1;
        int distance=INT_MIN;

        for(int i=1;i<n;i++)
        {
            int j=0;
            while(j<n)
            {
                if(colors[j]!=colors[i])
                {
                    distance=max(distance,abs(i-j));
                }
                j++;
            }
        }
        return distance;
        
    }
};